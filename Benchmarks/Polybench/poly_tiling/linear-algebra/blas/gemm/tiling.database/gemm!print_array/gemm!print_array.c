# 51 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
static
void print_array(int ni, int nj,
                 double C[ 2000 + 0][2300 + 0])
{
        int i, j;

        fprintf(
# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c" 3 4
       stderr
# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
       , "==BEGIN DUMP_ARRAYS==\n");
        fprintf(
# 58 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c" 3 4
       stderr
# 58 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
       , "begin dump: %s", "C");
        for (i = 0; i < ni; i++)
                for (j = 0; j < nj; j++) {
                        if ((i * ni + j) % 20 == 0) fprintf (
# 61 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c" 3 4
                                                            stderr
# 61 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
                                                                                 , "\n");
                        fprintf (
# 62 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c" 3 4
                                stderr
# 62 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
                                                     , "%0.2lf ", C[i][j]);
                }
        fprintf(
# 64 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c" 3 4
       stderr
# 64 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
       , "\nend   dump: %s\n", "C");
        fprintf(
# 65 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c" 3 4
       stderr
# 65 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
       , "==END   DUMP_ARRAYS==\n");
}
