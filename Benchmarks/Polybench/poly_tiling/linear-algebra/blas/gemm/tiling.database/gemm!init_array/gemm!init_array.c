# 25 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemm/gemm.c"
static
void init_array(int ni, int nj, int nk,
                double *alpha,
                double *beta,
                double C[ 2000 + 0][2300 + 0],
                double A[ 2000 + 0][2600 + 0],
                double B[ 2600 + 0][2300 + 0])
{
        int i, j;

        *alpha = 1.5;
        *beta = 1.2;
        for (i = 0; i < ni; i++)
                for (j = 0; j < nj; j++)
                        C[i][j] = (double) ((i*j+1) % ni) / ni;
        for (i = 0; i < ni; i++)
                for (j = 0; j < nk; j++)
                        A[i][j] = (double) (i*(j+1) % nk) / nk;
        for (i = 0; i < nk; i++)
                for (j = 0; j < nj; j++)
                        B[i][j] = (double) (i*(j+2) % nj) / nj;
}
