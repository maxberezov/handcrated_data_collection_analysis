# 54 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/generated/test.c"
void kernel_test(int n, double A[ 40 + 0][40 + 0], double C[ 40 + 0][40 + 0])
{
  int i,j,k;

#pragma scop
 for (i = 0; i < n-1; i++)
loop_1: for (j = 1; j < n-1; j++)
     for (k = 1; k < n-1; k++)
            A[j][k] = A[j-1][k-1]+32*C[i][j];
#pragma endscop

}
