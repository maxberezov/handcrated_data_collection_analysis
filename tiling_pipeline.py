from tpips_files_generation import generate_tiling_for_polybench
from file_compilation import apply_transformations_for_all_files, clean_exe, clean_tpips, compile_baseline_polybench
from execution_logic import execute_all
from settings import just_vectorization, aggressive_optimization, no_optimization


def tiling_pipeline():
    """
    This function specify a sequence of functions that form tiling pipeline
    """
    compile_baseline_polybench(aggressive_optimization)
    generate_tiling_for_polybench()
    apply_transformations_for_all_files(aggressive_optimization)
    execute_all()


if __name__ == '__main__':
    tiling_pipeline()
