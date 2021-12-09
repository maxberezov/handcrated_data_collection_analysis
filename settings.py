import os

PROJECT_PATH = os.path.dirname(os.path.abspath(__file__))


class Benchmark:
    def __init__(self):
        self.path = ''
        self.benchmark = ''
        self.functions = ''
        self.results = ''
        self.utilities = ''
        self.source_code = ''
        self.tiled = ''


polybench_tiling_benchmark = Benchmark()
polybench_tiling_benchmark.path = os.path.join(PROJECT_PATH, 'Benchmarks', 'Polybench', 'poly_tiling')
polybench_tiling_benchmark.utilities = os.path.join(polybench_tiling_benchmark.path, 'utilities')
polybench_tiling_benchmark.functions = polybech_kernel_list_tiling = os.path.join(polybench_tiling_benchmark.utilities,
                                                                                  'benchmark_list_tiling')
polybench_tiling_benchmark.source_code = os.path.join(polybench_tiling_benchmark.utilities, 'polybench.c')
polybench_tiling_benchmark.tiled = os.path.join(PROJECT_PATH, 'Benchmarks', 'Polybench', 'poly_tiled')
polybench_tiling_benchmark.results = os.path.join(polybench_tiling_benchmark.tiled, 'results.txt')

size_ranges_tiling = range(1, 3)
sizes_cubic_search = [2, 4, 16]

threads = [4]
max_unrolling = 16
no_optimization = '-O0'
just_vectorization = '-ftree-vectorize '
aggressive_optimization = '-O3'
number_of_repetitions = 1
cache_sizes = ['EXTRALARGE_DATASET']

tile_directions_general = ['TS', 'TP', 'TI']
local_tile_directions_general = ['LS', 'LP', 'LI']

tile_directions_rectangular = ['TP', 'TI']
local_tile_directions_rectangular = ['LP', 'LI']
