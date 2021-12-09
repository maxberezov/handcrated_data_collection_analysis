int main(int argc, char **argv)
{
   /* Retrieve problem size. */
   int n = 2000;
   int tsteps = 500;
   
   /* Variable declaration/allocation. */
   double (*A)[2000+0][2000+0][2000+0];
   A = (double (*)[2000+0][2000+0][2000+0]) polybench_alloc_data((2000+0)*(2000+0)*(2000+0), sizeof(double));
   
   
   /* Initialize array(s). */
   init_array(n, *A);
   
   /* Start timer. */
   polybench_timer_start();
   
   /* Run kernel. */
   kernel_seidel_2d(tsteps, n, *A);
   
   /* Stop and print timer. */
   polybench_timer_stop();
   polybench_timer_print();
   
   /* Prevent dead-code elimination. All live-out data must be printed
      by the function call in argument. */
   if (argc>42&&!strcmp(argv[0], ""))
      print_array(n, *A);
   
   /* Be clean. */
   free((void *) A);

   return 0;
}
