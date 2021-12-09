import os
from settings import polybench_tiling_benchmark
from auxiliary_functions import do_for_all_files_in_directory
from settings import threads
from settings import number_of_repetitions


def execute_single_file(file, results=polybench_tiling_benchmark.results, timeout=60):
    """
    This function executes given executable file with a given timeout and saves results to the file
    :param results: path, file with results
    :param file: path, executable file
    :param timeout: int, timeout in seconds
    """
    os.system('cd {}'.format(file[:file.rfind('/')]))
    relative_path = file[file.rfind('/') + 1:]
    if file[-5] == '0':
        os.system('echo {} >> {}'.format(relative_path, results))
        os.system('timeout {} ./{} >> {}'.format(timeout, relative_path, results))
    else:
        for thread in threads:
            os.environ['OMP_NUM_THREADS'] = '{:d}'.format(thread)
            os.system('echo {} >> {}'.format(relative_path, results))
            os.system("echo THREADS $OMP_NUM_THREADS >> {}".format(results))
            os.system('timeout {} ./{} >> {}'.format(timeout, relative_path, results))


def execute_all(directory=polybench_tiling_benchmark.tiled):
    """
    This function executes all exe files in a directory
    :param directory: path, directory with exe files
    """
    for i in range(number_of_repetitions):
        do_for_all_files_in_directory(directory, '.out', execute_single_file)
