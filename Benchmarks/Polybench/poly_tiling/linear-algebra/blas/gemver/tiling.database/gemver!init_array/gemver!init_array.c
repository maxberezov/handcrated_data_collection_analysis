# 25 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/blas/gemver/gemver.c"
static
void init_array (int n,
                 double *alpha,
                 double *beta,
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

        *alpha = 1.5;
        *beta = 1.2;

        double fn = (double)n;

        for (i = 0; i < n; i++)
        {
                u1[i] = i;
                u2[i] = ((i+1)/fn)/2.0;
                v1[i] = ((i+1)/fn)/4.0;
                v2[i] = ((i+1)/fn)/6.0;
                y[i] = ((i+1)/fn)/8.0;
                z[i] = ((i+1)/fn)/9.0;
                x[i] = 0.0;
                w[i] = 0.0;
                for (j = 0; j < n; j++)
                        A[i][j] = (double) (i*j % n) / n;
        }
}
