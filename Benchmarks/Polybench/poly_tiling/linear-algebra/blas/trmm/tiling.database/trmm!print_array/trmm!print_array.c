# 49 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
static
void print_array(int m, int n,
                 double B[ 20 + 0][30 + 0])
{
        int i, j;

        fprintf(
# 55 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c" 3 4
       stderr
# 55 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
       , "==BEGIN DUMP_ARRAYS==\n");
        fprintf(
# 56 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c" 3 4
       stderr
# 56 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
       , "begin dump: %s", "B");
        for (i = 0; i < m; i++)
                for (j = 0; j < n; j++) {
                        if ((i * m + j) % 20 == 0) fprintf (
# 59 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c" 3 4
                                                           stderr
# 59 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
                                                                                , "\n");
                        fprintf (
# 60 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c" 3 4
                                stderr
# 60 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
                                                     , "%0.2lf ", B[i][j]);
                }
        fprintf(
# 62 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c" 3 4
       stderr
# 62 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
       , "\nend   dump: %s\n", "B");
        fprintf(
# 63 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c" 3 4
       stderr
# 63 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
       , "==END   DUMP_ARRAYS==\n");
}
