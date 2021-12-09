void kernel_syrk(int n, int m, double alpha, double beta, double C[30+0][30+0], double A[30+0][20+0])
{
   int i, j, k;
   //PIPS generated variable
   int k_t, j_t, k_l, j_l;
   
   //BLAS PARAMS
   //TRANS = 'N'
   //UPLO  = 'L'
   // =>  Form  C := alpha*A*A**T + beta*C.
   //A is NxM
   //C is NxN
#pragma scop
   polybench_timer_start();
   {
      //PIPS generated variable
      int I_4, I_5;
      I_5 = n-1;
      I_4 = 0;


#pragma omp parallel for private(j,j_l,j_t,k_l,k_t)
      for(i = I_4; i <= I_5; i += 1) {
         {
            //PIPS generated variable
            int I_0, I_1;
            I_1 = i;
            I_0 = 0;

#pragma omp ivdep 
#pragma omp vector always 
            for(j = I_0; j <= I_1; j += 1)
               C[i][j] *= beta;
         }
         for(k_t = 0; k_t <= (m-1)/4; k_t += 1)
            for(j_t = 0; j_t <= i/4; j_t += 1)
               for(k_l = 4*k_t; k_l <= (((4*k_t+3)<((m-1))) ? (4*k_t+3): ((m-1))); k_l += 1) {
                  {
                     //PIPS generated variable
                     int I_2, I_3;
                     I_3 = (((i)<((4*j_t+3))) ? (i): ((4*j_t+3)));
                     I_2 = 4*j_t;

#pragma omp ivdep 
#pragma omp vector always 
                     for(j_l = I_2; j_l <= I_3; j_l += 1)
                        C[i][j_l] += alpha*A[i][k_l]*A[j_l][k_l];
                  }
               }
      }
   }
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
