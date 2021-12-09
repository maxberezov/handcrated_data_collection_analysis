int main(int argc, char **argv)
{
   /* Retrieve problem size. */
   int n = 4000;
   
   /* Variable declaration/allocation. */
   double alpha;
   double beta;
   double (*A)[4000+0][4000+0];
   A = (double (*)[4000+0][4000+0]) polybench_alloc_data((4000+0)*(4000+0), sizeof(double));
   double (*u1)[4000+0];
   u1 = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*v1)[4000+0];
   v1 = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*u2)[4000+0];
   u2 = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*v2)[4000+0];
   v2 = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*w)[4000+0];
   w = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*x)[4000+0];
   x = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*y)[4000+0];
   y = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   double (*z)[4000+0];
   z = (double (*)[4000+0]) polybench_alloc_data(4000+0, sizeof(double));
   
   
   /* Initialize array(s). */
   init_array(n, &alpha, &beta, *A, *u1, *v1, *u2, *v2, *w, *x, *y, *z);
   
   
   /* Run kernel. */
   kernel_gemver(n, alpha, beta, *A, *u1, *v1, *u2, *v2, *w, *x, *y, *z);
   
   
   /* Prevent dead-code elimination. All live-out data must be printed
      by the function call in argument. */
   if (argc>42&&!strcmp(argv[0], ""))
      print_array(n, *w);
   
   /* Be clean. */
   free((void *) A);
   free((void *) u1);
   free((void *) v1);
   free((void *) u2);
   free((void *) v2);
   free((void *) w);
   free((void *) x);
   free((void *) y);
   free((void *) z);

   return 0;
}
