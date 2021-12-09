# 63 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
void kernel_seidel_2d(int tsteps,
                      int n,
                      double A[ 2000 + 0][2000 + 0][2000 + 0])
{
        int t, i, j;

#pragma scop
        polybench_timer_start();;

        for (t = 1; t <= n - 1; t++) {
loop_1: for (i = 1; i<= n - 2; i++) {
                        for (j = 1; j <= n - 2; j++) {
                                A[t][i][j] = (A[t-1][i-1][j-1] + A[t-1][i-1][j])/9.0;
                        }
                }
        }
        polybench_timer_stop();;

        polybench_timer_print();;

#pragma endscop

}
