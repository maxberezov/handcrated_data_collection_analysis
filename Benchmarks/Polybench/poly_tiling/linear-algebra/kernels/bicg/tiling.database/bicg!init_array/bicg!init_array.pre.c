static void init_array(int m, int n, double A[2200+0][1800+0], double r[2200+0], double p[1800+0], double s[1800+0], double q[1800+0])
{
   int i, j;

   for(i = 0; i <= m-1; i += 1)
      p[i] = (double) (i%m)/m;
   for(i = 0; i <= n-1; i += 1) {
      r[i] = (double) (i%n)/n;
      for(j = 0; j <= m-1; j += 1)
         A[i][j] = (double) (i*(j+1)%n)/n;
   }

   for(i = 0; i <= n-1; i += 1)
      q[i] = 0;

   for(i = 0; i <= m-1; i += 1)
      s[i] = 0;
}
