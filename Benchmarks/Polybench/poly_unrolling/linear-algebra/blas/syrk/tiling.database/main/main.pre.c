int main(int argc, char **argv)
{
   /* Retrieve problem size. */
   int n = 30;
   int m = 20;
   
   /* Variable declaration/allocation. */
   double alpha;
   double beta;
   double (*C)[30+0][30+0];
   C = (double (*)[30+0][30+0]) polybench_alloc_data((30+0)*(30+0), sizeof(double));
   double (*A)[30+0][20+0];
   A = (double (*)[30+0][20+0]) polybench_alloc_data((30+0)*(20+0), sizeof(double));
   
   /* Initialize array(s). */
   init_array(n, m, &alpha, &beta, *C, *A);
   
   /* Start timer. */
   polybench_timer_start();
   
   /* Run kernel. */
   kernel_syrk(n, m, alpha, beta, *C, *A);
   
   /* Stop and print timer. */
   polybench_timer_stop();
   polybench_timer_print();
   
   /* Prevent dead-code elimination. All live-out data must be printed
      by the function call in argument. */
   if (argc>42&&!strcmp(argv[0], ""))
      print_array(n, *C);
   
   /* Be clean. */
   free((void *) C);
   free((void *) A);

   return 0;
}
