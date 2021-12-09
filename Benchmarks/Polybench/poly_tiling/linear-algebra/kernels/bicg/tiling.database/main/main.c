# 117 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
int main(int argc, char** argv)
{
/* Retrieve problem size. */
int n = 2200;
int m = 1800;

/* Variable declaration/allocation. */
double (*A)[2200 + 0][1800 + 0]; A = (double(*)[2200 + 0][1800 + 0])polybench_alloc_data ((2200 + 0) * (1800 + 0), sizeof(double));;
double (*s)[1800 + 0]; s = (double(*)[1800 + 0])polybench_alloc_data (1800 + 0, sizeof(double));;
double (*q)[2200 + 0]; q = (double(*)[2200 + 0])polybench_alloc_data (2200 + 0, sizeof(double));;
double (*p)[1800 + 0]; p = (double(*)[1800 + 0])polybench_alloc_data (1800 + 0, sizeof(double));;
double (*r)[2200 + 0]; r = (double(*)[2200 + 0])polybench_alloc_data (2200 + 0, sizeof(double));;

/* Initialize array(s). */
init_array (m, n,
*A,
*r,
*p,
*s,
*q);

/* Run kernel. */
kernel_bicg (m, n,
*A,
*s,
*q,
*p,
*r);


/* Prevent dead-code elimination. All live-out data must be printed
by the function call in argument. */
if (argc > 42 && ! strcmp(argv[0], "")) print_array(m, n, *s, *q);

/* Be clean. */
free((void*)A);;
free((void*)s);;
free((void*)q);;
free((void*)p);;
free((void*)r);;

return 0;
}
