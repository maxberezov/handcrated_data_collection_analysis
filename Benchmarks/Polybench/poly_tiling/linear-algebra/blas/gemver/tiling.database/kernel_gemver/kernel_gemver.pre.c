void kernel_gemver(int n, double alpha, double beta, double A[4000+0][4000+0], double u1[4000+0], double v1[4000+0], double u2[4000+0], double v2[4000+0], double w[4000+0], double x[4000+0], double y[4000+0], double z[4000+0])
{
   int i, j;
   //PIPS generated variable
   int i_t, j_t, i_l, j_l;

#pragma scop
   polybench_timer_start();
   {
      //PIPS generated variable
      int I_2, I_3;
      I_3 = ((((3*n+4)/8)<(((((3*n+4)/16)<(((((n-1)/4)<(((n-1)/8))) ? ((n-1)/4): (((n-1)/8))))) ? ((3*n+4)/16): (((((n-1)/4)<(((n-1)/8))) ? ((n-1)/4): (((n-1)/8))))))) ? ((3*n+4)/8): (((((3*n+4)/16)<(((((n-1)/4)<(((n-1)/8))) ? ((n-1)/4): (((n-1)/8))))) ? ((3*n+4)/16): (((((n-1)/4)<(((n-1)/8))) ? ((n-1)/4): (((n-1)/8)))))));
      I_2 = 0;


#pragma omp parallel for private(i_l,j_l,j_t)
      for(i_t = I_2; i_t <= I_3; i_t += 1)
         for(j_t = (8*i_t-n+1)/8; j_t <= (n-1)/8; j_t += 1)

            for(i_l = (((8*i_t)>((8*i_t+8*j_t))) ? (8*i_t): ((8*i_t+8*j_t))); i_l <= (((8*i_t+8*j_t+14)<((((8*i_t+n+6)<((((8*j_t+n+6)<((2*n-2))) ? (8*j_t+n+6): ((2*n-2))))) ? (8*i_t+n+6): ((((8*j_t+n+6)<((2*n-2))) ? (8*j_t+n+6): ((2*n-2))))))) ? (8*i_t+8*j_t+14): ((((8*i_t+n+6)<((((8*j_t+n+6)<((2*n-2))) ? (8*j_t+n+6): ((2*n-2))))) ? (8*i_t+n+6): ((((8*j_t+n+6)<((2*n-2))) ? (8*j_t+n+6): ((2*n-2))))))); i_l += 1) {
               {
                  //PIPS generated variable
                  int I_0, I_1;
                  I_1 = (((-i_l+8*j_t+7)<((((-i_l+n-1)<((-8*i_t))) ? (-i_l+n-1): ((-8*i_t))))) ? (-i_l+8*j_t+7): ((((-i_l+n-1)<((-8*i_t))) ? (-i_l+n-1): ((-8*i_t)))));
                  I_0 = (((-i_l)>((((-i_l+8*j_t)>((((-8*i_t-7)>((-n+1))) ? (-8*i_t-7): ((-n+1))))) ? (-i_l+8*j_t): ((((-8*i_t-7)>((-n+1))) ? (-8*i_t-7): ((-n+1))))))) ? (-i_l): ((((-i_l+8*j_t)>((((-8*i_t-7)>((-n+1))) ? (-8*i_t-7): ((-n+1))))) ? (-i_l+8*j_t): ((((-8*i_t-7)>((-n+1))) ? (-8*i_t-7): ((-n+1)))))));

#pragma omp ivdep 
#pragma omp vector always 
                  for(j_l = I_0; j_l <= I_1; j_l += 1)
                     A[-j_l][i_l+j_l] = A[-j_l][i_l+j_l]+u1[-j_l]*v1[i_l+j_l]+u2[-j_l]*v2[i_l+j_l];
               }
            }
   }

   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
