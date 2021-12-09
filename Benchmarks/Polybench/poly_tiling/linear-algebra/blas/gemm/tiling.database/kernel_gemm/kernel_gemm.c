# 71 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
void kernel_gemm(int ni, int nj, int nk,
                 double alpha,
                 double beta,
                 double C[ 2000 + 0][2300 + 0],
                 double A[ 2000 + 0][2600 + 0],
                 double B[ 2600 + 0][2300 + 0])
{
        int i, j, k;

//BLAS PARAMS
//TRANSA = 'N'
//TRANSB = 'N'
// => Form C := alpha*A*B + beta*C,
//A is NIxNK
//B is NKxNJ
//C is NIxNJ
#pragma scop


        for (i = 0; i < ni; i++) {
                for (j = 0; j < nj; j++) {
                        C[i][j] *= beta;
                } }


        polybench_timer_start();;

tiling_3D: for (i = 0; i < ni; i++) {

tiling_2D: for (k = 0; k < nk; k++) {

                        for (j = 0; j < nj; j++) {
                                C[i][j] += alpha * A[i][k] * B[k][j];
                        }
                }
        }
        polybench_timer_stop();;

        polybench_timer_print();;

#pragma endscop

}
