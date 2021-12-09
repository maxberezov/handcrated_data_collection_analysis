# 116 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/generated/gemm.c"
int main(int argc, char** argv)
{
/* Retrieve problem size. */
        int ni = 2000;
        int nj = 2300;
        int nk = 2600;

/* Variable declaration/allocation. */
        double alpha;
        double beta;
        double (*C)[2000 + 0][2300 + 0]; C = (double(*)[2000 + 0][2300 + 0])polybench_alloc_data ((2000 + 0) * (2300 + 0), sizeof(double));;
        double (*A)[2000 + 0][2600 + 0]; A = (double(*)[2000 + 0][2600 + 0])polybench_alloc_data ((2000 + 0) * (2600 + 0), sizeof(double));;
        double (*B)[2600 + 0][2300 + 0]; B = (double(*)[2600 + 0][2300 + 0])polybench_alloc_data ((2600 + 0) * (2300 + 0), sizeof(double));;

/* Initialize array(s). */
        init_array (ni, nj, nk, &alpha, &beta,
                    *C,
                    *A,
                    *B);


/* Run kernel. */
        kernel_gemm (ni, nj, nk,
                     alpha, beta,
                     *C,
                     *A,
                     *B);



/* Prevent dead-code elimination. All live-out data must be printed
   by the function call in argument. */
        if (argc > 42 && ! strcmp(argv[0], "")) print_array(ni, nj, *C);

/* Be clean. */
        free((void*)C);;
        free((void*)A);;
        free((void*)B);;

        return 0;
}
