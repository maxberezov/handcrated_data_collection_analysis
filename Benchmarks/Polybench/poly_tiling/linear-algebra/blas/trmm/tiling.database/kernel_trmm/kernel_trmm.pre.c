void kernel_trmm(int m, int n, double alpha, double A[20+0][20+0], double B[20+0][30+0])
{
   int i, j, k, z;
   //PIPS generated variable
   int i_t, j_t, i_l, j_l;
   
   //BLAS parameters
   //SIDE   = 'L'
   //UPLO   = 'L'
   //TRANSA = 'T'
   //DIAG   = 'U'
   // => Form  B := alpha*A**T*B.
   // A is MxM
   // B is MxN
#pragma scop
   polybench_timer_start();

   for(i_t = 0; i_t <= (m-1)/4; i_t += 1) {
      //PIPS generated variable
      int I_0, I_1;
      I_1 = (n-1)/4;
      I_0 = 0;

#pragma omp parallel for private(i_l,j_l,k,z)
      for(j_t = I_0; j_t <= I_1; j_t += 1)

         for(i_l = 4*i_t; i_l <= (((4*i_t+3)<((m-1))) ? (4*i_t+3): ((m-1))); i_l += 1)
            for(j_l = 4*j_t; j_l <= (((4*j_t+3)<((n-1))) ? (4*j_t+3): ((n-1))); j_l += 1) {
               z = 0;
               for(k = i_l+1; k <= m-1; k += 1)
                  B[i_l][j_l] += A[k][i_l]*B[k][j_l];
               B[i_l][j_l] = alpha*B[i_l][j_l]+z;
            }
   }
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
