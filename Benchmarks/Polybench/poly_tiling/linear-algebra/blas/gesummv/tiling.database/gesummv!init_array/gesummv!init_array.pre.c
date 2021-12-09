static void init_array(int n, double *alpha, double *beta, double A[30+0][30+0], double B[30+0][30+0], double x[30+0])
{
   int i, j;

   *alpha = 1.5;
   *beta = 1.2;
   for(i = 0; i <= n-1; i += 1) {
      x[i] = (double) (i%n)/n;
      for(j = 0; j <= n-1; j += 1) {
         A[i][j] = (double) ((i*j+1)%n)/n;
         B[i][j] = (double) ((i*j+2)%n)/n;
      }
   }
}
