static void print_array(int n, double A[40+0][40+0][40+0])
{
   int i, j, k;

   fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
   fprintf(stderr, "begin dump: %s", "A");
   for(i = 0; i <= n-1; i += 1)
      for(j = 0; j <= n-1; j += 1)
         for(k = 0; k <= n-1; k += 1) {
            if ((i*n*n+j*n+k)%20==0)
               fprintf(stderr, "\n");
            fprintf(stderr, "%0.2lf ", A[i][j][k]);
         }
   fprintf(stderr, "\nend   dump: %s\n", "A");
   fprintf(stderr, "==END   DUMP_ARRAYS==\n");
}
