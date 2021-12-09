static void init_array(int n, int m, double *alpha, double *beta, double C[30+0][30+0], double A[30+0][20+0])
{
   int i, j;

   *alpha = 1.5;
   *beta = 1.2;
   for(i = 0; i <= n-1; i += 1)
      for(j = 0; j <= m-1; j += 1)
         A[i][j] = (double) ((i*j+1)%n)/n;
   for(i = 0; i <= n-1; i += 1)
      for(j = 0; j <= n-1; j += 1)
         C[i][j] = (double) ((i*j+2)%m)/m;
}
