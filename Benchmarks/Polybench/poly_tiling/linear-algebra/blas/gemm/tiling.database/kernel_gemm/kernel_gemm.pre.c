void kernel_gemm(int ni, int nj, int nk, double alpha, double beta, double C[2000+0][2300+0], double A[2000+0][2600+0], double B[2600+0][2300+0])
{
   int i, j, k;
   //PIPS generated variable
   int i_t, k_t, j_t, i_l, k_l, j_l;
   
   //BLAS PARAMS
   //TRANSA = 'N'
   //TRANSB = 'N'
   // => Form C := alpha*A*B + beta*C,
   //A is NIxNK
   //B is NKxNJ
   //C is NIxNJ
#pragma scop
   for(i = 0; i <= ni-1; i += 1) {
      //PIPS generated variable
      int I_0, I_1;
      I_1 = nj-1;
      I_0 = 0;

#pragma omp parallel for 
      for(j = I_0; j <= I_1; j += 1)
         C[i][j] *= beta;
   }
   
   
   polybench_timer_start();
   {
      //PIPS generated variable
      int I_4, I_5;
      I_5 = (ni-1)/8;
      I_4 = 0;


#pragma omp parallel for private(i_l,j_l,j_t,k_l,k_t)
      for(i_t = I_4; i_t <= I_5; i_t += 1)
         for(k_t = 0; k_t <= (nk-1)/8; k_t += 1)
            for(j_t = 0; j_t <= (nj-1)/8; j_t += 1)

               for(i_l = 8*i_t; i_l <= (((8*i_t+7)<((ni-1))) ? (8*i_t+7): ((ni-1))); i_l += 1)
                  for(k_l = 8*k_t; k_l <= (((8*k_t+7)<((nk-1))) ? (8*k_t+7): ((nk-1))); k_l += 1) {
                     {
                        //PIPS generated variable
                        int I_2, I_3;
                        I_3 = (((8*j_t+7)<((nj-1))) ? (8*j_t+7): ((nj-1)));
                        I_2 = 8*j_t;

#pragma omp ivdep 
#pragma omp vector always 
                        for(j_l = I_2; j_l <= I_3; j_l += 1)
                           C[i_l][j_l] += alpha*A[i_l][k_l]*B[k_l][j_l];
                     }
                  }
   }
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
