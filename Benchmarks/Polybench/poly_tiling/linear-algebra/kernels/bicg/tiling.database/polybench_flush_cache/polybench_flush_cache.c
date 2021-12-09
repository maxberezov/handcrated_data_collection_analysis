# 112 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
void polybench_flush_cache()
{
  int cs = 32770 * 1024 / sizeof(double);
  double* flush = (double*) calloc (cs, sizeof(double));
  int i;
  double tmp = 0.0;



  for (i = 0; i < cs; i++)
    tmp += flush[i];
  
# 123 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c" 3 4
 ((
# 123 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
 tmp <= 10.0
# 123 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c" 3 4
 ) ? (void) (0) : __assert_fail (
# 123 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
 "tmp <= 10.0"
# 123 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c" 3 4
 , "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c", 123, __func__))
# 123 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
                     ;
  free (flush);
}
