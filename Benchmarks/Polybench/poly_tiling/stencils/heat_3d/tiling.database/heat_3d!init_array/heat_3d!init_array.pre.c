static void init_array(int n, double A[40+0][40+0][40+0], double B[40+0][40+0][40+0])
{
   int i, j, k;

   for(i = 0; i <= n-1; i += 1)
      for(j = 0; j <= n-1; j += 1)
         for(k = 0; k <= n-1; k += 1)
            A[i][j][k] = B[i][j][k] = (double) (i+j+(n-k))*10/n;
}
