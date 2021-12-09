# 25 "/home/maksim/PycharmProjects/data_collection_unrolling/Benchmarks/Polybench/poly_tiling/linear-algebra/kernels/bicg/bicg.c"
static
void init_array (int m, int n,
double A[ 2200 + 0][1800 + 0],
double r[ 2200 + 0],
double p[ 1800 + 0],
double s[ 1800 + 0],
double q[ 1800 + 0]

)
{
int i, j;

for (i = 0; i < m; i++)
p[i] = (double)(i % m) / m;
for (i = 0; i < n; i++) {
r[i] = (double)(i % n) / n;
for (j = 0; j < m; j++)
A[i][j] = (double) (i*(j+1) % n)/n;
}

for (i = 0; i < n; i++){
q[i] = 0;}

for (i = 0; i < m; i++){
s[i] = 0;}


}
