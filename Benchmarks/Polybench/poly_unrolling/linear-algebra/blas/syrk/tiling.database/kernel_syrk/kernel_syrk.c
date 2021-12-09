# 67 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/syrk/syrk.c"
void kernel_syrk(int n, int m,
                 double alpha,
                 double beta,
                 double C[ 30 + 0][30 + 0],
                 double A[ 30 + 0][20 + 0])
{
        int i, j, k;

//BLAS PARAMS
//TRANS = 'N'
//UPLO  = 'L'
// =>  Form  C := alpha*A*A**T + beta*C.
//A is NxM
//C is NxN
#pragma scop
        polybench_timer_start();;

        for (i = 0; i < n; i++) {
                for (j = 0; j <= i; j++) {
                        C[i][j] *= beta;
                }
 l1: for (k = 0; k < m; k++) {
                        for (j = 0; j <= i; j++) {
                                C[i][j] += alpha * A[i][k] * A[j][k];
                        }
                }
        }
        polybench_timer_stop();;

        polybench_timer_print();;

#pragma endscop

}
