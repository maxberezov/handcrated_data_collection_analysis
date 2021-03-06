/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* seidel-2d.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include polybench common header. */
#include <polybench.h>

/* Include benchmark-specific header. */
#include "seidel_2d.h"


/* Array initialization. */
static
void init_array (int n,
                 DATA_TYPE POLYBENCH_3D(A,N,N,N,n,n,n))
{
        int i, j, k;

        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        for (k = 0; k < n; k++)
                                A[i][j][k] = (DATA_TYPE) (i + j + (n-k))* 10 / (n);
}



/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
                 DATA_TYPE POLYBENCH_3D(A,N,N,N,n,n,n))

{
        int i, j, k;

        POLYBENCH_DUMP_START;
        POLYBENCH_DUMP_BEGIN("A");
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        for (k = 0; k < n; k++) {
                                if ((i * n * n + j * n + k) % 20 == 0) fprintf(POLYBENCH_DUMP_TARGET, "\n");
                                fprintf(POLYBENCH_DUMP_TARGET, DATA_PRINTF_MODIFIER, A[i][j][k]);
                        }
        POLYBENCH_DUMP_END("A");
        POLYBENCH_DUMP_FINISH;
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
void kernel_seidel_2d(int tsteps,
                      int n,
                      DATA_TYPE POLYBENCH_3D(A,N,N,N,n,n,n))
{
        int t, i, j;

#pragma scop
        polybench_start_instruments;

        for (t = 1; t <= _PB_N - 1; t++) {
l0:                for (i = 1; i<= _PB_N - 2; i++) {
                        for (j = 1; j <= _PB_N - 2; j++) {
                                A[t][i][j] = (A[t-1][i-1][j-1] + A[t-1][i-1][j])/SCALAR_VAL(9.0);
                        }
                }
        }
        polybench_stop_instruments;

        polybench_print_instruments;

#pragma endscop

}


int main(int argc, char** argv)
{
/* Retrieve problem size. */
        int n = N;
        int tsteps = TSTEPS;

/* Variable declaration/allocation. */
         POLYBENCH_3D_ARRAY_DECL(A, DATA_TYPE, N, N, N, n, n, n);


/* Initialize array(s). */
        init_array (n, POLYBENCH_ARRAY(A));



/* Run kernel. */
        kernel_seidel_2d (tsteps, n, POLYBENCH_ARRAY(A));



/* Prevent dead-code elimination. All live-out data must be printed
   by the function call in argument. */
        polybench_prevent_dce(print_array(n, POLYBENCH_ARRAY(A)));

/* Be clean. */
        POLYBENCH_FREE_ARRAY(A);

        return 0;
}
