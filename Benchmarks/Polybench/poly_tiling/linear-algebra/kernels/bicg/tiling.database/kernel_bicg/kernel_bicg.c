# 84 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
void kernel_bicg(int m, int n,
double A[ 2200 + 0][1800 + 0],
double s[ 1800 + 0],
double q[ 2200 + 0],
double p[ 1800 + 0],
double r[ 2200 + 0])
{
int i, j;

#pragma scop




polybench_timer_start();;

l0: for (i = 0; i < n; i++)
 {
 for (j = 0; j < m; j++)
 {
  s[j] = s[j] + r[i] * A[i][j];
  q[i] = q[i] + A[i][j] * p[j];
 }
  }
polybench_timer_stop();;

polybench_timer_print();;

#pragma endscop

}
