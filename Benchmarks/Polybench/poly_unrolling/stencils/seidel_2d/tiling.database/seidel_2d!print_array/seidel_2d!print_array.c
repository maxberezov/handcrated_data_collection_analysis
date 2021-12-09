# 41 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
static
void print_array(int n,
                 double A[ 2000 + 0][2000 + 0][2000 + 0])

{
        int i, j, k;

        fprintf(
# 48 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c" 3 4
       stderr
# 48 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
       , "==BEGIN DUMP_ARRAYS==\n");
        fprintf(
# 49 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c" 3 4
       stderr
# 49 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
       , "begin dump: %s", "A");
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        for (k = 0; k < n; k++) {
                                if ((i * n * n + j * n + k) % 20 == 0) fprintf(
# 53 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c" 3 4
                                                                              stderr
# 53 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
                                                                                                   , "\n");
                                fprintf(
# 54 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c" 3 4
                                       stderr
# 54 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
                                                            , "%0.2lf ", A[i][j][k]);
                        }
        fprintf(
# 56 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c" 3 4
       stderr
# 56 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
       , "\nend   dump: %s\n", "A");
        fprintf(
# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c" 3 4
       stderr
# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
       , "==END   DUMP_ARRAYS==\n");
}
