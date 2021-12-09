void kernel_2mm(int ni, int nj, int nk, int nl, double alpha, double beta, double tmp[1600+0][1800+0], double A[1600+0][2200+0], double B[2200+0][1800+0], double C[1800+0][2400+0], double D[1600+0][2400+0])
{
   int i, j, k;
   //PIPS generated variable
   int i_t, j_t, k_t, i_l, j_l, k_l;
   
   
   
   for(i = 0; i <= ni-1; i += 1) {
      //PIPS generated variable
      int I_0, I_1;
      I_1 = nj-1;
      I_0 = 0;

#pragma omp parallel for 
      for(j = I_0; j <= I_1; j += 1)
         tmp[i][j] = 0.0;
   }
   
   
   
   /* D := alpha*A*B*C + beta*D */
#pragma scop
   polybench_timer_start();

   for(i_t = 0; i_t <= (ni+nj+nk-3)/256; i_t += 1) {
      //PIPS generated variable
      int I_2, I_3;
      I_3 = (-256*i_t+nj+nk-2)/256;
      I_2 = (((-i_t)>(((-ni+256)/256))) ? (-i_t): (((-ni+256)/256)));

#pragma omp parallel for private(i_l,j_l,k_l,k_t)
      for(j_t = I_2; j_t <= I_3; j_t += 1)
         for(k_t = (((-i_t)>(((256*j_t-nj+256)/256))) ? (-i_t): (((256*j_t-nj+256)/256))); k_t <= ((((-256*i_t+nk-1)/256)<((j_t))) ? ((-256*i_t+nk-1)/256): ((j_t))); k_t += 1)

            for(i_l = (((0)>((-256*j_t))) ? (0): ((-256*j_t))); i_l <= (((-256*j_t+255)<((ni-1))) ? (-256*j_t+255): ((ni-1))); i_l += 1)
               for(j_l = 256*j_t-256*k_t; j_l <= (((256*j_t-256*k_t+255)<((nj-1))) ? (256*j_t-256*k_t+255): ((nj-1))); j_l += 1)
                  for(k_l = 256*i_t+256*k_t; k_l <= (((256*i_t+256*k_t+255)<((nk-1))) ? (256*i_t+256*k_t+255): ((nk-1))); k_l += 1)
                     tmp[i_l][j_l] += alpha*A[i_l][k_l]*B[k_l][j_l];
   }
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
