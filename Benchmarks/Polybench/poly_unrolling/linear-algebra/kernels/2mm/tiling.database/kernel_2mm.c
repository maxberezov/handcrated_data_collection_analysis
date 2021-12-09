# 75 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/kernels/2mm/2mm.c"
void kernel_2mm(int ni, int nj, int nk, int nl,
double alpha,
double beta,
double tmp[ 1600 + 0][1800 + 0],
double A[ 1600 + 0][2200 + 0],
double B[ 2200 + 0][1800 + 0],
double C[ 1800 + 0][2400 + 0],
double D[ 1600 + 0][2400 + 0])
{
int i, j, k;

#pragma scop
/* D := alpha*A*B*C + beta*D */
polybench_timer_start();;

loop_1: for (i = 0; i < ni; i++){
 for (j = 0; j < nj; j++)
  {
   tmp[i][j] = 0.0;
  for (k = 0; k < nk; ++k)
  tmp[i][j] += alpha * A[i][k] * B[k][j];
       }
        }
polybench_timer_stop();;

polybench_timer_print();;

polybench_timer_start();;

for (i = 0; i < ni; i++){
 for (j = 0; j < nl; j++)
 {
  D[i][j] *= beta;
loop_2:
  for (k = 0; k < nj; ++k)
   D[i][j] += tmp[i][k] * C[k][j];
 }
  }
polybench_timer_stop();;

polybench_timer_print();;

#pragma endscop

}
