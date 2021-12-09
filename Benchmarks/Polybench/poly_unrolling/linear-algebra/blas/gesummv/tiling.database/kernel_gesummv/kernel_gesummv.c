# 70 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly/linear-algebra/blas/gesummv/gesummv.c"
void kernel_gesummv(int n,
                    double alpha,
                    double beta,
                    double A[ 30 + 0][30 + 0],
                    double B[ 30 + 0][30 + 0],
                    double tmp[ 30 + 0],
                    double x[ 30 + 0],
                    double y[ 30 + 0])
{
        int i, j;

#pragma scop
        polybench_timer_start();;

          for (i = 0; i < n; i++)
        {

                 tmp[i] = 0.0;
                y[i] = 0.0;
        }



l1: for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                {
                        tmp[i] = A[i][j] * x[j] + tmp[i];
                        y[i] = B[i][j] * x[j] + y[i];
                }
                y[i] = alpha * tmp[i] + beta * y[i];
        }
        polybench_timer_stop();;

        polybench_timer_print();;

#pragma endscop

}
