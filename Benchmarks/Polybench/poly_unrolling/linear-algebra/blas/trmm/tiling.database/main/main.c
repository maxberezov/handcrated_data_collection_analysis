# 106 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/trmm/trmm.c"
int main(int argc, char** argv)
{
/* Retrieve problem size. */
        int m = 20;
        int n = 30;

/* Variable declaration/allocation. */
        double alpha;
        double (*A)[20 + 0][20 + 0]; A = (double(*)[20 + 0][20 + 0])polybench_alloc_data ((20 + 0) * (20 + 0), sizeof(double));;
        double (*B)[20 + 0][30 + 0]; B = (double(*)[20 + 0][30 + 0])polybench_alloc_data ((20 + 0) * (30 + 0), sizeof(double));;

/* Initialize array(s). */
        init_array (m, n, &alpha, *A, *B);

/* Start timer. */
        polybench_timer_start();;

/* Run kernel. */
        kernel_trmm (m, n, alpha, *A, *B);

/* Stop and print timer. */
        polybench_timer_stop();;
        polybench_timer_print();;

/* Prevent dead-code elimination. All live-out data must be printed
   by the function call in argument. */
        if (argc > 42 && ! strcmp(argv[0], "")) print_array(m, n, *B);

/* Be clean. */
        free((void*)A);;
        free((void*)B);;

        return 0;
}
