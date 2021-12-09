void polybench_flush_cache()
{
   int cs = 32770*1024/sizeof(double);
   double *flush = (double *) calloc(cs, sizeof(double));
   int i;
   double tmp = 0.0;
   
   
   
   for(i = 0; i <= cs-1; i += 1)
      tmp += flush[i];
   tmp<=10.0?(void) 0:__assert_fail("tmp <= 10.0", "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c", 123, __func__);
   free(flush);
}
