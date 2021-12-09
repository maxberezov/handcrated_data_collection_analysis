# 63 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/heat_3d/heat_3d.c"
void kernel_heat_3d(int tsteps,
                    int n,
                    double A[ 40 + 0][40 + 0][40 + 0],
                    double B[ 40 + 0][40 + 0][40 + 0])
{
        int t, i, j, k;

#pragma scop
        polybench_timer_start();;

                for (i = 1; i < n-1; i++) {
loop_1: for (j = 1; j < n-1; j++) {
                                for (k = 1; k < n-1; k++) {
                                        B[i][j][k] = 0.125 * (A[i+1][j][k] - 2.0 * A[i][j][k] + A[i-1][j][k])
                                                     + 0.125 * (A[i][j+1][k] - 2.0 * A[i][j][k] + A[i][j-1][k])
                                                     + 0.125 * (A[i][j][k+1] - 2.0 * A[i][j][k] + A[i][j][k-1])
                                                     + A[i][j][k];
                                }
                        }
          }
        polybench_timer_stop();;

        polybench_timer_print();;

#pragma endscop

}
