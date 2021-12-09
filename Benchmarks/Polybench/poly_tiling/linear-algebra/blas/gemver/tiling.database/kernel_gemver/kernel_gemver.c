# 83 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
void kernel_gemver(int n,
                   double alpha,
                   double beta,
                   double A[ 4000 + 0][4000 + 0],
                   double u1[ 4000 + 0],
                   double v1[ 4000 + 0],
                   double u2[ 4000 + 0],
                   double v2[ 4000 + 0],
                   double w[ 4000 + 0],
                   double x[ 4000 + 0],
                   double y[ 4000 + 0],
                   double z[ 4000 + 0])
{
        int i, j;

#pragma scop

        polybench_timer_start();;

l0: for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        A[i][j] = A[i][j] + u1[i] * v1[j] + u2[i] * v2[j];
                }
        }

        polybench_timer_stop();;

        polybench_timer_print();;



#pragma endscop
}
