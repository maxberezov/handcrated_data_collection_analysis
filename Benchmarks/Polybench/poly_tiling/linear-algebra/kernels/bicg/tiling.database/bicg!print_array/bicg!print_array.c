# 57 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
static
void print_array(int m, int n,
double s[ 1800 + 0],
double q[ 2200 + 0])

{
int i;

fprintf(
# 65 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
stderr
# 65 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
, "==BEGIN DUMP_ARRAYS==\n");
fprintf(
# 66 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
stderr
# 66 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
, "begin dump: %s", "s");
for (i = 0; i < m; i++) {
if (i % 20 == 0) fprintf (
# 68 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
                         stderr
# 68 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
                                              , "\n");
fprintf (
# 69 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
        stderr
# 69 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
                             , "%0.2lf ", s[i]);
}
fprintf(
# 71 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
stderr
# 71 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
, "\nend   dump: %s\n", "s");
fprintf(
# 72 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
stderr
# 72 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
, "begin dump: %s", "q");
for (i = 0; i < n; i++) {
if (i % 20 == 0) fprintf (
# 74 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
                         stderr
# 74 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
                                              , "\n");
fprintf (
# 75 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
        stderr
# 75 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
                             , "%0.2lf ", q[i]);
}
fprintf(
# 77 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
stderr
# 77 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
, "\nend   dump: %s\n", "q");
fprintf(
# 78 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c" 3 4
stderr
# 78 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
, "==END   DUMP_ARRAYS==\n");
}
