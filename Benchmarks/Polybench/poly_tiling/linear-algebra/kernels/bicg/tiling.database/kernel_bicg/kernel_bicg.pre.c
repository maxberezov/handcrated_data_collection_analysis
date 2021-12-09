void kernel_bicg(int m, int n, double A[2200+0][1800+0], double s[1800+0], double q[2200+0], double p[1800+0], double r[2200+0])
{
   int i, j;
   //PIPS generated variable
   int i_t, j_t, i_l, j_l;

#pragma scop
   polybench_timer_start();

   for(i_t = 0; i_t <= (n-1)/8; i_t += 1)
      for(j_t = 0; j_t <= (m-1)/8; j_t += 1)

         for(i_l = 8*i_t; i_l <= (((8*i_t+7)<((n-1))) ? (8*i_t+7): ((n-1))); i_l += 1)
            for(j_l = 8*j_t; j_l <= (((8*j_t+7)<((m-1))) ? (8*j_t+7): ((m-1))); j_l += 1) {
               s[j_l] = s[j_l]+r[i_l]*A[i_l][j_l];
               q[i_l] = q[i_l]+A[i_l][j_l]*p[j_l];
            }
   polybench_timer_stop();

   polybench_timer_print();
#pragma endscop

}
