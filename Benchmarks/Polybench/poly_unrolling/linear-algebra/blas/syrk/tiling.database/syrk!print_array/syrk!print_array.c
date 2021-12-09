# 47 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
static
void print_array(int n,
                 double C[ 30 + 0][30 + 0])
{
        int i, j;

        fprintf(
# 53 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c" 3 4
       stderr
# 53 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
       , "==BEGIN DUMP_ARRAYS==\n");
        fprintf(
# 54 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c" 3 4
       stderr
# 54 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
       , "begin dump: %s", "C");
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++) {
                        if ((i * n + j) % 20 == 0) fprintf (
# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c" 3 4
                                                           stderr
# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
                                                                                , "\n");
                        fprintf (
# 58 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c" 3 4
                                stderr
# 58 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
                                                     , "%0.2lf ", C[i][j]);
                }
        fprintf(
# 60 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c" 3 4
       stderr
# 60 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
       , "\nend   dump: %s\n", "C");
        fprintf(
# 61 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c" 3 4
       stderr
# 61 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
       , "==END   DUMP_ARRAYS==\n");
}
