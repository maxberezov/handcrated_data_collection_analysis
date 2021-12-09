# 25 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/seidel_2d/seidel_2d.c"
static
void init_array (int n,
                 double A[ 2000 + 0][2000 + 0][2000 + 0])
{
        int i, j, k;

        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        for (k = 0; k < n; k++)
                                A[i][j][k] = (double) (i + j + (n-k))* 10 / (n);
}
