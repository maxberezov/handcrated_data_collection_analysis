static void print_array(int m, int n, double s[1800+0], double q[2200+0])
{
   int i;

   fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
   fprintf(stderr, "begin dump: %s", "s");
   for(i = 0; i <= m-1; i += 1) {
      if (i%20==0)
         fprintf(stderr, "\n");
      fprintf(stderr, "%0.2lf ", s[i]);
   }
   fprintf(stderr, "\nend   dump: %s\n", "s");
   fprintf(stderr, "begin dump: %s", "q");
   for(i = 0; i <= n-1; i += 1) {
      if (i%20==0)
         fprintf(stderr, "\n");
      fprintf(stderr, "%0.2lf ", q[i]);
   }
   fprintf(stderr, "\nend   dump: %s\n", "q");
   fprintf(stderr, "==END   DUMP_ARRAYS==\n");
}
