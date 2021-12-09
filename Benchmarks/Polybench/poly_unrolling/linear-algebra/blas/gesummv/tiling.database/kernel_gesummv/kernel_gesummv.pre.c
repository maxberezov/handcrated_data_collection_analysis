void kernel_gesummv(int n, double alpha, double beta, double A[30+0][30+0], double B[30+0][30+0], double tmp[30+0], double x[30+0], double y[30+0])
{
   int i, j;
   //PIPS generated variable
   int i_t, j_t, i_l, j_l;

#pragma scop
   polybench_timer_start();
   {
      //PIPS generated variable
      int I_0, I_1;
      I_1 = n-1;
      I_0 = 0;


#pragma omp parallel for 
      for(i = I_0; i <= I_1; i += 1) {
         tmp[i] = 0.0;
         y[i] = 0.0;
      }
   }
   {
      //PIPS generated variable
      int I_2, I_3;
      I_3 = (n-1)/4;
      I_2 = 0;

      
      
      
#pragma omp parallel for private(i_l,j_l,j_t)
      for(i_t = I_2; i_t <= I_3; i_t += 1)
         for(j_t = 0; j_t <= (n-1)/4; j_t += 1)
            
            
            
            for(i_l = 4*i_t; i_l <= (((4*i_t+3)<((n-1))) ? (4*i_t+3): ((n-1))); i_l += 1)
               for(j_l = 4*j_t; j_l <= (((4*j_t+3)<((n-1))) ? (4*j_t+3): ((n-1))); j_l += 1) {
                  tmp[i_l] = A[i_l][j_l]*x[j_l]+tmp[i_l];
                  y[i_l] = B[i_l][j_l]*x[j_l]+y[i_l];
               }
   }
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
