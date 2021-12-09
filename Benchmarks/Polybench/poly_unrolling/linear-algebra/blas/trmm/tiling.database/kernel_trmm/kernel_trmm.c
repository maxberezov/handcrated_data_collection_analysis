# 69 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
void kernel_trmm(int m, int n,
                 double alpha,
                 double A[ 20 + 0][20 + 0],
                 double B[ 20 + 0][30 + 0])
{
        int i, j, k,z;

//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
#pragma scop
        polybench_timer_start();;

l1: for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {

   z = 0;
                        for (k = i+1; k < m; k++) {
                                B[i][j] += A[k][i] * B[k][j];
                        }
                        B[i][j] = alpha * B[i][j] + z;
                }
        }
        polybench_timer_stop();;

        polybench_timer_print();;

#pragma endscop

}
