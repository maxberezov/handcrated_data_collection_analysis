static void print_array(int n, double y[30+0])
{
   int i;

   fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
   fprintf(stderr, "begin dump: %s", "y");
   for(i = 0; i <= n-1; i += 1) {
      if (i%20==0)
         fprintf(stderr, "\n");
      fprintf(stderr, "%0.2lf ", y[i]);
   }
   fprintf(stderr, "\nend   dump: %s\n", "y");
   fprintf(stderr, "==END   DUMP_ARRAYS==\n");
}
