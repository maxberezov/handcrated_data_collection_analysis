static void init_array(int n, double C[40+0][40+0], double A[40+0][40+0])
{
   int i, j;

   for(i = 0; i <= n-1; i += 1)
      for(j = 0; j <= n-1; j += 1)
         C[i][j] = A[i][j] = 1;
}
