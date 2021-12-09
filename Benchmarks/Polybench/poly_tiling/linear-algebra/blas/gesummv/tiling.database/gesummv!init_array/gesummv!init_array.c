# 25 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/gesummv/gesummv.c"
static
void init_array(int n,
                double *alpha,
                double *beta,
                double A[ 30 + 0][30 + 0],
                double B[ 30 + 0][30 + 0],
                double x[ 30 + 0])
{
        int i, j;

        *alpha = 1.5;
        *beta = 1.2;
        for (i = 0; i < n; i++)
        {
                x[i] = (double)( i % n) / n;
                for (j = 0; j < n; j++) {
                        A[i][j] = (double) ((i*j+1) % n) / n;
                        B[i][j] = (double) ((i*j+2) % n) / n;
                }
        }
}
