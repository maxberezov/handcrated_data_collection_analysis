int main(int argc, char **argv)
{
   /* Retrieve problem size. */
   int ni = 1600;
   int nj = 1800;
   int nk = 2200;
   int nl = 2400;
   
   /* Variable declaration/allocation. */
   double alpha;
   double beta;
   double (*tmp)[1600+0][1800+0];
   tmp = (double (*)[1600+0][1800+0]) polybench_alloc_data((1600+0)*(1800+0), sizeof(double));
   double (*A)[1600+0][2200+0];
   A = (double (*)[1600+0][2200+0]) polybench_alloc_data((1600+0)*(2200+0), sizeof(double));
   double (*B)[2200+0][1800+0];
   B = (double (*)[2200+0][1800+0]) polybench_alloc_data((2200+0)*(1800+0), sizeof(double));
   double (*C)[1800+0][2400+0];
   C = (double (*)[1800+0][2400+0]) polybench_alloc_data((1800+0)*(2400+0), sizeof(double));
   double (*D)[1600+0][2400+0];
   D = (double (*)[1600+0][2400+0]) polybench_alloc_data((1600+0)*(2400+0), sizeof(double));
   
   /* Initialize array(s). */
   init_array(ni, nj, nk, nl, &alpha, &beta, *A, *B, *C, *D);
   
   /* Start timer. */
   polybench_timer_start();
   
   /* Run kernel. */
   kernel_2mm(ni, nj, nk, nl, alpha, beta, *tmp, *A, *B, *C, *D);
   
   /* Stop and print timer. */
   polybench_timer_stop();
   polybench_timer_print();
   
   /* Prevent dead-code elimination. All live-out data must be printed
   by the function call in argument. */
   if (argc>42&&!strcmp(argv[0], ""))
      print_array(ni, nl, *D);
   
   /* Be clean. */
   free((void *) tmp);
   free((void *) A);
   free((void *) B);
   free((void *) C);
   free((void *) D);

   return 0;
}
