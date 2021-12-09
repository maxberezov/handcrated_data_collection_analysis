# 515 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
static
void*
xmalloc(size_t alloc_sz)
{
  void* ret = 
# 519 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c" 3 4
             ((void *)0)
# 519 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
                 ;
  /* By default, post-pad the arrays. Safe behavior, but likely useless. */
  polybench_inter_array_padding_sz += 0;
  size_t padded_sz = alloc_sz + polybench_inter_array_padding_sz;
  int err = posix_memalign (&ret, 4096, padded_sz);
  if (! ret || err)
    {
      fprintf (
# 526 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c" 3 4
              stderr
# 526 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/utilities/polybench.c"
                    , "[PolyBench] posix_memalign: cannot allocate memory");
      exit (1);
    }
  /* Safeguard: this is invoked only if polybench.c has been compiled
     with inter-array padding support from polybench.h. If so, move
     the starting address of the allocation and return it to the
     user. The original pointer is registered in an allocation table
     internal to polybench.c. Data must then be freed using
     polybench_free_data, which will inspect the allocation table to
     free the original pointer.*/







  return ret;
}
