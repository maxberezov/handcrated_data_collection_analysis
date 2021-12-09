# 92 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/stencils/heat_3d/heat_3d.c"
int main(int argc, char** argv)
{
/* Retrieve problem size. */
        int n = 40;
        int tsteps = 100;

/* Variable declaration/allocation. */
        double (*A)[40 + 0][40 + 0][40 + 0]; A = (double(*)[40 + 0][40 + 0][40 + 0])polybench_alloc_data ((40 + 0) * (40 + 0) * (40 + 0), sizeof(double));;
        double (*B)[40 + 0][40 + 0][40 + 0]; B = (double(*)[40 + 0][40 + 0][40 + 0])polybench_alloc_data ((40 + 0) * (40 + 0) * (40 + 0), sizeof(double));;


/* Initialize array(s). */
        init_array (n, *A, *B);

/* Start timer. */
        polybench_timer_start();;

/* Run kernel. */
        kernel_heat_3d (tsteps, n, *A, *B);

/* Stop and print timer. */
        polybench_timer_stop();;
        polybench_timer_print();;

/* Prevent dead-code elimination. All live-out data must be printed
   by the function call in argument. */
        if (argc > 42 && ! strcmp(argv[0], "")) print_array(n, *A);

/* Be clean. */
        free((void*)A);;

        return 0;
}
