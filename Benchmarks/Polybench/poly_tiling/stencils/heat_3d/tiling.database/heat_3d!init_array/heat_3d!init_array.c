# 25 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/heat_3d/heat_3d.c"
static
void init_array (int n,
                 double A[ 40 + 0][40 + 0][40 + 0],
                 double B[ 40 + 0][40 + 0][40 + 0])
{
        int i, j, k;

        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        for (k = 0; k < n; k++)
                                A[i][j][k] = B[i][j][k] = (double) (i + j + (n-k))* 10 / (n);
}
