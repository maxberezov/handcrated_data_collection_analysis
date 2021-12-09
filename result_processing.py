from settings import polybench_tiling_benchmark
from auxiliary_functions import get_content
from tiling_parameters_generation import generate_2d_matrices, generate_3d_matrices
from settings import size_ranges_tiling
import pandas as pd
import numpy as np

from settings import tile_directions_general, local_tile_directions_general


def parse_name_string(name):
    """
    !!!!!!!!!!!!TO REWRITE, VERY VERY BAD!!!!!!!!!!!!!!!

    This function returns some parameters of a given code based on its name
    :param name: string, filename
    :return: values of parameters
    """
    line = name.strip()
    parallel_version = int(line[-5])
    direction = int(line[line.find('%') + 1:line.find('%') + 2])
    matrix = int(line[line.find('%') + 3:][:line[line.find('%') + 3:].find('%')])
    cache = int(line[:-6][line[:-6].rfind('%') - 1:line[:-6].rfind('%')])
    name = line[:line.rfind('%')][line[:line.rfind('%')].rfind('%') + 1:]
    return parallel_version, direction, matrix, cache, name


def process_baseline_string(baseline_dict, idx, raw_data):
    """
    This function provides a logic to process a baseline result in the output file
    :param baseline_dict: dict, dict with results of baseline
    :param idx: int, index of a current line
    :param raw_data: list, list of lines of output file
    """
    line = raw_data[idx]
    kernel = line[line.index('_') + 1:line.index('%')]
    if idx + 1 < len(raw_data):
        if '%' not in raw_data[idx + 1]:
            baseline_dict[kernel] = float(raw_data[idx + 1])


def process_result_not_baseline_line(results, idx, raw_data):
    """
    This function provides a logic to process a not baseline result in the output file
    :param results: dict, dict with results
    :param idx: int, index of a current line
    :param raw_data: list, list of lines of output file
    """
    line = raw_data[idx]
    parallel_version, direction, matrix, cache, name = parse_name_string(line)
    if not name in results.keys():
        results[name] = {}

    if parallel_version == 1:
        thread_line = raw_data[idx + 1]
        threads = int(thread_line[thread_line.index(' ') + 1:])
        if idx + 2 < len(raw_data):
            if '%' not in raw_data[idx + 2]:
                time = float(raw_data[idx + 2])
                results[name][(threads, direction, matrix, cache)] = time
    else:
        if '%' not in raw_data[idx + 1]:
            time = float(raw_data[idx + 1])
            results[name][(0, direction, matrix, cache)] = time


def get_initial_dictionary(file):
    """
    This function process initial file and returns a dictionary
    :param file: path, file with results
    :return: dict, value is exec. time, key is (threads, direction, matrix, cache)
    """
    results = {}
    baseline = {}
    raw_data = get_content(file)
    for idx, line in enumerate(raw_data):
        if '.out' in line:
            if 'baseline' in line:
                process_baseline_string(baseline, idx, raw_data)
            else:
                process_result_not_baseline_line(results, idx, raw_data)
    return results, baseline


def process_dictionary(results):
    """
    This function processes a list from get_initial_dictionary and return a dict, where
    kernel is a key, [dict_1,dict_2,.. ] is value

    dict_i corresponds to i combination of threads and cache
    key of dict_i is (matrix, direction), value is exec. time
    :param results: dict, dict from get_initial_dictionary
    :return: dict, processed dictionary
    """
    #  combinations_threads_cache = [(0, 0), (0, 1), (1, 0), (1, 1), (6, 0), (6, 1), (12, 0),
    #                              (12, 1)]
    combinations_threads_cache = [(4, 0)]
    # all possible combinations of threads and cache
    processed_results = {}
    for kernel in results.keys():
        processed_results[kernel] = [{} for _ in range(len(combinations_threads_cache))]
        for k, v in results[kernel].items():
            threads = k[0]
            cache = k[3]
            direction = k[1]
            matrix = k[2]
            combination_index = combinations_threads_cache.index((threads, cache))
            processed_results[kernel][combination_index][(direction, matrix)] = v
    return processed_results


def get_matrix_dimensions_and_shape(dict_rect, dict_diamond, matrix, value):
    """
    This function helps to fill in dict_rect and dict_diamond which key are dimension of corresponding matrix,
    value - exec. time. Each kernel has 8 corresponding matrices for each matrix shape (different combinations of
    cache and threads)
    :param dict_rect: dict, dict of results for rect shape
    :param dict_diamond: dict, dict of results for diamond shape
    :param matrix: str, matrix that were applied for this piece of data
    :param value: float, exec. time
    """
    dict_to_update = dict_diamond

    if '0' in matrix[0]:  # rectangular case
        dimension_1 = int(matrix[0][:matrix[0].index(' ')])
        dimension_2 = int(matrix[1][matrix[1].index(' ') + 1:])
        dict_to_update = dict_rect
    else:
        dimension_1 = int(matrix[0][:matrix[0].index(' ')])
        dimension_2 = int(matrix[0][matrix[0].index(' ') + 1:])

    update_dict(dict_to_update, dimension_1, dimension_2, value)


def update_dict(dict_to_update, dim1, dim2, value):
    """
    This function updates the best exec time for given shape and dimensions
    :param dict_to_update: dict, dict with results (either dict_rect or dict_diamond from get_matrix_dimensions_and_shape)
    :param dim1: int, first dimension
    :param dim2: int, second dimension
    :param value: float, exec. time
    """
    if (dim1, dim2) in dict_to_update.keys():
        dict_to_update[(dim1, dim2)].append(value)
    else:
        dict_to_update[(dim1, dim2)] = [value]


def scanning_directions():
    tile_directions = tile_directions_general
    local_tile_directions = local_tile_directions_general
    directions = []
    for tile_dir in tile_directions:
        for loc_dir in local_tile_directions:
            directions.append(tile_dir + '_' + loc_dir)
    return directions


scanning_dir = scanning_directions()


def fill_in_result_matrix(dict_rect, dict_diamond, result_rect, result_diamond,
                          dims, baseline, kernel):
    """
    This function fills in lists that will be converted to dataframes later. Lists are filled in based on corresponding dicts

    :param result_rect: list, list of results for rect shape
    :param result_diamond: list, list of results for diamond shape
    :param dims: list, list of possible dimensions under consideration
    :param baseline: dict, baseline results
    :param kernel: string, kernel name
    :param index: int, index to understand cache size
    """

    baseline_result = baseline[kernel]

    for key, value in dict_rect.items():
        result_rect[dims.index(key[0])][dims.index(key[1])] = baseline_result / value

    for key, value in dict_diamond.items():
        result_diamond[dims.index(key[0])][dims.index(key[1])] = baseline_result / value


def fill_in_result_matrix_3D(dict_rect, result_rect, dims, baseline, kernel):
    baseline_result = baseline[kernel]

    for key, value in dict_rect.items():
        result_rect[dims.index(key[0])][dims.index(key[1])][dims.index(key[1])] = baseline_result / value


def get_avg_of_the_dictionary(dict_to_process):
    for k, v in dict_to_process.items():
        if len(dict_to_process[k]) > 0:
            dict_to_process[k] = sum(dict_to_process[k]) / len(dict_to_process[k])
        else:
            dict_to_process[k] = 0


def get_avg_of_all_dictionaries(rect_dict, diamond_dict):
    for idx in range(len(rect_dict)):
        get_avg_of_the_dictionary(rect_dict[idx])
        get_avg_of_the_dictionary(diamond_dict[idx])


def get_avg_of_all_dictionaries_3D(rect_dict):
    for idx in range(len(rect_dict)):
        get_avg_of_the_dictionary(rect_dict[idx])


def get_direction_profitability_metrics(initial_list):
    counter = 0
    total = 0
    max_element = 0
    for dim1 in range(len(initial_list)):
        for dim2 in range(len(initial_list[0])):
            tmp_value = initial_list[dim1][dim2]
            if tmp_value != 0:
                total += tmp_value
                counter += 1
                if tmp_value > max_element:
                    max_element = tmp_value
    if total > 0:
        return total / counter, max_element
    else:
        return 0, max_element


def get_profitability_metrics_for_all(rect_results, diamond_results):
    profitability_rect = [(0, 0) for i in range(len(scanning_dir))]
    profitability_diamond = [(0, 0) for i in range(len(scanning_dir))]

    for idx in range(len(rect_results)):
        profitability_rect[idx] = get_direction_profitability_metrics(rect_results[idx])
        profitability_diamond[idx] = get_direction_profitability_metrics(diamond_results[idx])

    return profitability_rect, profitability_diamond


def get_matrix_dimensions_and_shape_3D(dict_rect, matrix, value):
    dict_to_update = dict_rect
    dimension_1 = int(matrix[0][:matrix[0].index(' ')])
    dimension_2 = int(matrix[1][matrix[1].index(' ') + 1: matrix[1].rfind(' ')])
    dimension_3 = int(matrix[2][matrix[2].rfind(' ') + 1:])
    update_dict_3D(dict_to_update, dimension_1, dimension_2, dimension_3, value)


def update_dict_3D(dict_to_update, dim1, dim2, dim3, value):
    if (dim1, dim2, dim3) in dict_to_update.keys():
        dict_to_update[(dim1, dim2, dim3)].append(value)
    else:
        dict_to_update[(dim1, dim2, dim3)] = [value]


def get_speedup_matrix_3D_tiling(processed_result, baseline, kernel):
    matrices = generate_3d_matrices()
    speedups = []
    profitability = []

    for idx, thread_cache_dict in enumerate(processed_result):

        rectangular_3D = [{} for i in range(len(scanning_dir))]
        for key, value in thread_cache_dict.items():
            matrix = matrices[key[1]]
            direction = key[0]
            get_matrix_dimensions_and_shape_3D(rectangular_3D[direction], matrix, value)

        get_avg_of_all_dictionaries_3D(rectangular_3D)
        dims = [2 ** x for x in size_ranges_tiling]

        result_rect = [[[[0] * len(size_ranges_tiling) for _ in range(len(size_ranges_tiling))] for _ in
                        range(len(size_ranges_tiling))] for i in
                       range(len(scanning_dir))]

        fill_in_all_matrices_3D(rectangular_3D, result_rect, dims, baseline, kernel)

        single_kernel_speedups = fill_in_aggregated_speedups_3D(result_rect, dims)
        speedups.append({'Threads_cache': idx, 'Speedups': single_kernel_speedups})
    return speedups


def get_speedup_matrix(processed_result, baseline, kernel):
    """
    This function returns list of dataframes. One dataframe for each possible combination of cache/threads/matrix shape
    :param processed_result: dict, results
    :param baseline: dict, baseline results
    :param kernel: string, kernel for which we want to get dataframes
    :return: list, list of Dataframes
    """
    matrices = generate_2d_matrices()
    speedups = []
    profitability = []

    for idx, thread_cache_dict in enumerate(processed_result):

        dict_rectangular = [{} for i in range(len(scanning_dir))]
        dict_diamond = [{} for i in range(len(scanning_dir))]
        for key, value in thread_cache_dict.items():
            matrix = matrices[key[1]]
            direction = key[0]
            get_matrix_dimensions_and_shape(dict_rectangular[direction], dict_diamond[direction], matrix, value)

        get_avg_of_all_dictionaries(dict_rectangular, dict_diamond)
        dims = [2 ** x for x in size_ranges_tiling]
        result_rect = [[[0] * len(size_ranges_tiling) for _ in range(len(size_ranges_tiling))] for i in
                       range(len(scanning_dir))]
        result_diamond = [[[0] * len(size_ranges_tiling) for _ in range(len(size_ranges_tiling))] for i in
                          range(len(scanning_dir))]

        fill_in_all_matrices(dict_rectangular, dict_diamond, result_rect, result_diamond, dims, baseline, kernel)

        tmp_profitability = get_profitability_metrics_for_all(result_rect, result_diamond)
        profitability.append(tmp_profitability)
        single_kernel_speedups = fill_in_aggregated_speedups(result_rect, result_diamond, dims)
        speedups.append({'Threads_cache': idx, 'Speedups': single_kernel_speedups})
    return speedups, profitability


def fill_in_all_matrices(dict_rectangular, dict_diamond, result_rect, result_diamond, dims, baseline, kernel):
    for idx in range(len(dict_rectangular)):
        fill_in_result_matrix(dict_rectangular[idx], dict_diamond[idx], result_rect[idx], result_diamond[idx], dims,
                              baseline, kernel)


def fill_in_all_matrices_3D(dict_rectangular, result_rect, dims, baseline, kernel):
    for idx in range(len(dict_rectangular)):
        fill_in_result_matrix_3D(dict_rectangular[idx], result_rect[idx], dims,
                                 baseline, kernel)


def fill_in_aggregated_speedups(result_rect, result_diamond, dims):
    speedups = []
    for idx in range(len(result_rect)):
        speedups.append({'Shape': 'rectangular', 'Direction': scanning_dir[idx],
                         'Data': pd.DataFrame(result_rect[idx],
                                              columns=[i for i in dims], index=[i for i in dims])})
        speedups.append({'Shape': 'diamond', 'Direction': scanning_dir[idx],
                         'Data': pd.DataFrame(result_diamond[idx],
                                              columns=[i for i in dims], index=[i for i in dims])})
    return


def fill_in_aggregated_speedups_3D(result_rect, dims):
    speedups = []
    for idx in range(len(result_rect)):
        speedups.append({'Shape': 'rectangular', 'Direction': scanning_dir[idx],
                         'Data': pd.DataFrame(result_rect[idx],
                                              columns=[i for i in dims], index=[i for i in dims])})
    return speedups


def get_final_results():
    """
    Whole pipeline
    :return: dict, dict from process_dictionary function
    """
    file = polybench_tiling_benchmark.results
    init_dict, baseline = get_initial_dictionary(
        '/home/maksim/Desktop/results/ex3/results.txt')
    processed_dictionary = process_dictionary(init_dict)
    return processed_dictionary, baseline


def get_avg_for_each_direction(results):
    processed_results = {}
    for k, v in results.items():
        kernel = k
        directions = [{} for _ in range(len(scanning_dir))]
        result_dict = v[0]
        for direction_matrix, time in result_dict.items():
            direction_idx = direction_matrix[0]

            symbolic_direction_name = scanning_dir[direction_idx]

            directions[scanning_dir[direction_idx]].append(time)
        processed_results[kernel] = directions
    return processed_results


results, baseline = get_final_results()
z = get_speedup_matrix_3D_tiling(results['1606131442388994'], baseline, '1606131442388994')
x = 5


avg_profit_data = []


def choose_avg_data_profit(profits):
    avg_data = []
    for profit in profits:
        tmp_avg = profit[1]
        avg_data.append(tmp_avg)

    zipbObj = zip(scanning_dir, avg_data)
    avg_scanning_direction = dict(zipbObj)
    return avg_scanning_direction


def get_direction_profitability(results, baseline_results):
    global_profitability = {}
    for kernel in results.keys():
        current_performance, tmp_profitability = get_speedup_matrix(results[kernel], baseline_results, kernel)
        for thread_idx, perf_elem in enumerate(current_performance):
            threads = current_performance[thread_idx]['Threads_cache']
            rectangular_profit, diamond_profit = tmp_profitability[thread_idx]
            rectangular_profit_avg = choose_avg_data_profit(rectangular_profit)
            diamond_profit_avg = choose_avg_data_profit(diamond_profit)
            global_profitability[(kernel, threads, 'rectangular')] = rectangular_profit_avg
            global_profitability[(kernel, threads, 'diamond')] = diamond_profit_avg

    return global_profitability


def get_shape_profitability(global_profitability, alpha='default'):
    shape_profitability = {}
    for k, v in global_profitability.items():
        direction_speedups = list(global_profitability[k].values())
        not_legal_directions = sum([1 for a in direction_speedups if a == 0])

        if not_legal_directions == len(direction_speedups):
            shape_profitability[k] = 0
        else:
            if alpha == 'default':
                alpha = 1 / len(direction_speedups)
                additional_terms = 1 / len(direction_speedups)
            else:
                additional_terms = (1 - alpha) / (len(direction_speedups) - 1)

        max_element_idx = np.argmax(direction_speedups)

        total = 0

        for speedup_idx in range(len(direction_speedups)):
            if direction_speedups[speedup_idx] > 0:
                if speedup_idx == max_element_idx:
                    total += direction_speedups[speedup_idx] * alpha
                else:
                    total += direction_speedups[speedup_idx] * additional_terms

        shape_profitability[k] = total

    return shape_profitability


def choose_data_inside_one_thread(data, thread_idx):
    processed_data = {}
    for k, v in data.items():
        kernel, thread, shape = k
        if thread == thread_idx:
            processed_data[kernel, shape] = v
    return processed_data


def form_data_for_binary_shape_classification(data, thread_idx):
    data = choose_data_inside_one_thread(data, thread_idx)
    processed_data = {}
    for k, v in data.items():
        kernel, shape = k
        if kernel in processed_data.keys():
            pass
        else:
            if data[kernel, 'rectangular'] > data[kernel, 'diamond']:
                processed_data[kernel] = 1
            else:
                processed_data[kernel] = 0
    return processed_data


def prepare_data_for_shape_classification(final_results, baseline):
    data_source = [[[] for _ in range(len(scanning_dir))], [[] for _ in range(len(scanning_dir))]]
    for kernel in final_results.keys():
        shapes = ['rectangular', 'diamond']
        tmp_speedup_matrix = get_speedup_matrix(final_results[kernel], baseline, kernel)
        for elem in tmp_speedup_matrix[0]:
            if elem['Threads_cache'] == 0:
                tmp_speedup = elem['Speedups']
        for matrix in tmp_speedup:
            matrix_shape_idx = shapes.index(matrix['Shape'])
            matrix_direction_idx = scanning_dir.index(matrix['Direction'])
            data = matrix['Data']
            sum_of_all_values = data.values.sum()
            if sum_of_all_values > 0:
                data = data.applymap(lambda x: 100 * x / sum_of_all_values)
            data_source[matrix_shape_idx][matrix_direction_idx].append([kernel, data])

    return data_source


final_results, baseline = get_final_results()
data_source = prepare_data_for_shape_classification(final_results, baseline)


def convert_speedup_df_to_dict(kernel, df):
    features = []
    df = df.to_dict()
    for first_key in df.keys():
        for second_key in df[first_key].keys():
            if df[first_key][second_key] != 0:
                features.append({'kernel': 'kernel_' + kernel, 'First_dim': first_key, 'Second_dim': second_key,
                                 'Speedup': df[first_key][second_key]})
    return features


def convert_all_df_to_dict(data_source):
    for shape_list in data_source:
        for direction_list in shape_list:
            for idx_element in range(len(direction_list)):
                direction_list[idx_element] = convert_speedup_df_to_dict(*direction_list[idx_element])

    for shape_list in data_source:
        for idx_direction in range(len(shape_list)):
            shape_list[idx_direction] = sum(shape_list[idx_direction], [])


def form_data_for_direction_classification(data, thread_idx):
    data = choose_data_inside_one_thread(data, thread_idx)
    processed_data = {}
    for k, v in data.items():
        speedups = list(v.values())
        best_direction_idx = np.argmax(speedups)
        best_direction = scanning_dir[best_direction_idx]
        processed_data[k] = best_direction
    return processed_data


'''final_results, baseline = get_final_results()
z = get_direction_profitability(final_results, baseline)
sgape_profit = get_shape_profitability(z, 1 / 3)
y = form_data_for_direction_classification(z, 0)
k = form_data_for_binary_shape_classification(sgape_profit, 0)

x = 5'''

'''for kernel in results.keys():
    current_performance, profitability = get_speedup_matrix(results[kernel], baseline, kernel)
    for thread_idx, perf_elem in enumerate(current_performance):
        threads = current_performance[thread_idx]['Threads_cache']
        for direction_idx, direction_elem in enumerate(current_performance[thread_idx]['Speedups']):
            shape = direction_elem['Shape']
            direction = direction_elem['Direction']

            rectangular_profit, diamond_profit = profitability[thread_idx]

            rectangular_profit_avg = choose_avg_data_profit(rectangular_profit)
            diamond_profit_avg = choose_avg_data_profit(diamond_profit)

            x = 5'''
