static void init_array(int ni, int nj, int nk, int nl, double *alpha, double *beta, double A[1600+0][2200+0], double B[2200+0][1800+0], double C[1800+0][2400+0], double D[1600+0][2400+0])
{
   int i, j;

   *alpha = 1.5;
   *beta = 1.2;
   for(i = 0; i <= ni-1; i += 1)
      for(j = 0; j <= nk-1; j += 1)
         A[i][j] = (double) ((i*j+1)%ni)/ni;
   for(i = 0; i <= nk-1; i += 1)
      for(j = 0; j <= nj-1; j += 1)
         B[i][j] = (double) (i*(j+1)%nj)/nj;
   for(i = 0; i <= nj-1; i += 1)
      for(j = 0; j <= nl-1; j += 1)
         C[i][j] = (double) ((i*(j+3)+1)%nl)/nl;
   for(i = 0; i <= ni-1; i += 1)
      for(j = 0; j <= nl-1; j += 1)
         D[i][j] = (double) (i*(j+2)%nk)/nk;
}
