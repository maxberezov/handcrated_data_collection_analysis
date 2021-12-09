# 64 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
static
void print_array(int n,
                 double w[ 4000 + 0])
{
        int i;

        fprintf(
# 70 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c" 3 4
       stderr
# 70 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
       , "==BEGIN DUMP_ARRAYS==\n");
        fprintf(
# 71 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c" 3 4
       stderr
# 71 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
       , "begin dump: %s", "w");
        for (i = 0; i < n; i++) {
                if (i % 20 == 0) fprintf (
# 73 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c" 3 4
                                         stderr
# 73 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
                                                              , "\n");
                fprintf (
# 74 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c" 3 4
                        stderr
# 74 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
                                             , "%0.2lf ", w[i]);
        }
        fprintf(
# 76 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c" 3 4
       stderr
# 76 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
       , "\nend   dump: %s\n", "w");
        fprintf(
# 77 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c" 3 4
       stderr
# 77 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
       , "==END   DUMP_ARRAYS==\n");
}
