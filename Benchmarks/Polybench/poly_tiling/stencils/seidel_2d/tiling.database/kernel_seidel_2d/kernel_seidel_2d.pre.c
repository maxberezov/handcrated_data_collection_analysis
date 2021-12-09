void kernel_seidel_2d(int tsteps, int n, double A[2000+0][2000+0][2000+0])
{
   int t, i, j;
   //PIPS generated variable
   int i_t, j_t, i_l, j_l;

#pragma scop
   polybench_timer_start();

   for(t = 1; t <= n-1; t += 1)
      for(i_t = ((((-3*n-5)/16)>(((((-n-5)/16)>(((-n-6)/8))) ? ((-n-5)/16): (((-n-6)/8))))) ? ((-3*n-5)/16): (((((-n-5)/16)>(((-n-6)/8))) ? ((-n-5)/16): (((-n-6)/8))))); i_t <= ((((3*n-1)/8)<(((((n-3)/4)<(((((5*n-9)/16)<(((3*n-9)/16))) ? ((5*n-9)/16): (((3*n-9)/16))))) ? ((n-3)/4): (((((5*n-9)/16)<(((3*n-9)/16))) ? ((5*n-9)/16): (((3*n-9)/16))))))) ? ((3*n-1)/8): (((((n-3)/4)<(((((5*n-9)/16)<(((3*n-9)/16))) ? ((5*n-9)/16): (((3*n-9)/16))))) ? ((n-3)/4): (((((5*n-9)/16)<(((3*n-9)/16))) ? ((5*n-9)/16): (((3*n-9)/16))))))); i_t += 1)
         for(j_t = ((((-4*i_t-n+11)/12)>(((((-8*i_t-n+3)/8)>(((((4*i_t-n+6)/4)>(((-n+10)/8))) ? ((4*i_t-n+6)/4): (((-n+10)/8))))) ? ((-8*i_t-n+3)/8): (((((4*i_t-n+6)/4)>(((-n+10)/8))) ? ((4*i_t-n+6)/4): (((-n+10)/8))))))) ? ((-4*i_t-n+11)/12): (((((-8*i_t-n+3)/8)>(((((4*i_t-n+6)/4)>(((-n+10)/8))) ? ((4*i_t-n+6)/4): (((-n+10)/8))))) ? ((-8*i_t-n+3)/8): (((((4*i_t-n+6)/4)>(((-n+10)/8))) ? ((4*i_t-n+6)/4): (((-n+10)/8))))))); j_t <= (((i_t+2)<(((((-i_t+1)/3)<(((-8*i_t+n-3)/8))) ? ((-i_t+1)/3): (((-8*i_t+n-3)/8))))) ? (i_t+2): (((((-i_t+1)/3)<(((-8*i_t+n-3)/8))) ? ((-i_t+1)/3): (((-8*i_t+n-3)/8))))); j_t += 1)
            for(i_l = (((1)>((((4*i_t-4*j_t+1)>((((8*i_t+8*j_t+1)>((-16*j_t-n+4))) ? (8*i_t+8*j_t+1): ((-16*j_t-n+4))))) ? (4*i_t-4*j_t+1): ((((8*i_t+8*j_t+1)>((-16*j_t-n+4))) ? (8*i_t+8*j_t+1): ((-16*j_t-n+4))))))) ? (1): ((((4*i_t-4*j_t+1)>((((8*i_t+8*j_t+1)>((-16*j_t-n+4))) ? (8*i_t+8*j_t+1): ((-16*j_t-n+4))))) ? (4*i_t-4*j_t+1): ((((8*i_t+8*j_t+1)>((-16*j_t-n+4))) ? (8*i_t+8*j_t+1): ((-16*j_t-n+4))))))); i_l <= (((4*i_t-4*j_t+12)<((((8*i_t+8*j_t+n+5)<((n-2))) ? (8*i_t+8*j_t+n+5): ((n-2))))) ? (4*i_t-4*j_t+12): ((((8*i_t+8*j_t+n+5)<((n-2))) ? (8*i_t+8*j_t+n+5): ((n-2))))); i_l += 1)
               for(j_l = (((i_l-8*i_t-8*j_t-7)>((((-i_l-16*j_t+2)>((1))) ? (-i_l-16*j_t+2): ((1))))) ? (i_l-8*i_t-8*j_t-7): ((((-i_l-16*j_t+2)>((1))) ? (-i_l-16*j_t+2): ((1))))); j_l <= (((i_l-8*i_t-8*j_t)<((((-i_l-16*j_t+17)<((n-2))) ? (-i_l-16*j_t+17): ((n-2))))) ? (i_l-8*i_t-8*j_t): ((((-i_l-16*j_t+17)<((n-2))) ? (-i_l-16*j_t+17): ((n-2))))); j_l += 1)
                  A[t][i_l][j_l] = (A[t-1][i_l-1][j_l-1]+A[t-1][i_l-1][j_l])/9.0;
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
