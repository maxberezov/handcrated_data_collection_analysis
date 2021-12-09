# 55 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
static
void print_array(int ni, int nl,
double D[ 1600 + 0][2400 + 0])
{
int i, j;

fprintf(
# 61 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c" 3 4
stderr
# 61 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
, "==BEGIN DUMP_ARRAYS==\n");
fprintf(
# 62 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c" 3 4
stderr
# 62 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
, "begin dump: %s", "D");
for (i = 0; i < ni; i++)
for (j = 0; j < nl; j++) {
if ((i * ni + j) % 20 == 0) fprintf (
# 65 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c" 3 4
                                    stderr
# 65 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
                                                         , "\n");
fprintf (
# 66 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c" 3 4
        stderr
# 66 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
                             , "%0.2lf ", D[i][j]);
}
fprintf(
# 68 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c" 3 4
stderr
# 68 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
, "\nend   dump: %s\n", "D");
fprintf(
# 69 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c" 3 4
stderr
# 69 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/2mm/2mm.c"
, "==END   DUMP_ARRAYS==\n");
}
