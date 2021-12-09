import os
from auxiliary_functions import get_content
from auxiliary_functions import rewrite
from settings import polybench_tiling_benchmark
from tiling_parameters_generation import generate_shapes_directions
from tpips_files import create_tpips_tiling, create_file_preprocessing, create_tpips_unrolling
from settings import cache_sizes
from typing import List, Callable

shapes_directions = generate_shapes_directions()


def get_idx_for_encoding(direction_to_encode, matrix_to_encode):
    corresponding, matrices = shapes_directions

    base = []
    for directions in corresponding.values():
        if len(directions) == 9:
            base = directions
            break

    matrix_idx = matrices.index(matrix_to_encode)
    direction_idx = base.index(direction_to_encode)
    return direction_idx, matrix_idx


def generate_tpips_file(source_files, optimization, *optimization_parameters):
    """
    This function creates a tpips file based on a given optimization function
    :param source_files: paths to source files
    :param optimization: function function to generate a tpips file (e.g. generate_tiling)
    :param optimization_parameters: parameters of a optimization function
    """
    file_to_optimize = source_files[0]
    tpips_file = optimization(source_files, *optimization_parameters)
    kernel_name = file_to_optimize[file_to_optimize.rfind('/') + 1:-2]
    kernel_path = file_to_optimize[:file_to_optimize.rfind('/') + 1]
    names = {create_file_preprocessing: lambda: 'preprocessing%',
             create_tpips_unrolling: lambda: 'unrolling%{}%'.format(optimization_parameters[1]),
             create_tpips_tiling: lambda: 'tiling%{}%{}%{}%'.format(*get_idx_for_encoding(optimization_parameters[1], optimization_parameters[2]),
                                                                    cache_sizes.index(optimization_parameters[-1]))}
    filename = names[optimization]() + kernel_name + '.tpips'
    rewrite(os.path.join(kernel_path, filename), tpips_file)


def generate_tiling(files, flags, function, cache):
    """
    This function generates tpips file for tiling
    :param files: paths to source files
    :param flags: list of compilation flags
    :param function: function to apply tiling
    :param cache: cache size
    """
    corresponding, matrices = shapes_directions
    for k, v in corresponding.items():
        matrix = matrices[k]
        directions = v
        label = 'tiling_{}D'.format(len(matrix))
        for direction in directions:
            generate_tpips_file(files, create_tpips_tiling, flags, direction, matrix, label, function, cache)


def generate_unrolling_files(files, max_factor, label, function):
    """
    This function generates tpips file for unrolling
    :param files: [str, str] - list of paths to source files
    :param max_factor: int, max possible unrolling factor
    :param label: str, label to apply unrolling
    :param function: str, function to apply tiling
    """
    for factor in range(2, max_factor + 1):
        generate_tpips_file(files, create_tpips_unrolling, factor, label, function)


def preprocess_file(tpips_file: str) -> None:
    """
    This function generates a file after preprocessing
    :param tpips_file: path for the tpips file for preprocessing
    """
    input_path = tpips_file[:tpips_file.rfind('/') + 1]
    filename = tpips_file[tpips_file.rfind('%') + 1:-5] + 'c'
    preprocessed_file = os.path.join(input_path, 'generated.database', 'Src', filename)
    original_file_to_rewrite = os.path.join(input_path, filename)
    os.system("tpips {}".format(tpips_file))
    os.system('mv {} {}'.format(preprocessed_file, original_file_to_rewrite))


def generate_tiling_for_polybench():
    """
    This function generates tpips files for polybench kernels that were mentioned in polybech_kernel_list_tiling file
    """
    content = get_content(polybench_tiling_benchmark.functions)
    for kernel in content:
        kernel_path = os.path.join(polybench_tiling_benchmark.path, kernel[2:])
        header_path = os.path.join(polybench_tiling_benchmark.path, kernel[2:kernel.rfind('/') + 1])
        poly_header = polybench_tiling_benchmark.utilities
        function = 'kernel_' + kernel[kernel.rfind('/') + 1:-2]
        for cache in cache_sizes:
            generate_tiling([kernel_path, polybench_tiling_benchmark.source_code],
                            ['-I {}'.format(header_path), '-I {}'.format(poly_header), '-DPOLYBENCH_TIME',
                             '-D {}'.format(cache)], function, cache)
