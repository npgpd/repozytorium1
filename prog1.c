 001.  #include <cblas.h>
 002.  #include <stdio.h>
 003.  #include <stdlib.h>
 004.
 005.  #define LDA 7
 006.  #define M 5
 007.  #define N 3
 008.
 009.  void print_matrix(int m, int n, int lda, double *a) {
 010.     int i, j;
 011.
 012.     for (j = 0; j < m; j++) {
 013.        for (i = 0; i < n; i++)
 014.           printf(" %5.1f", a[i+j*lda]);
 015.        printf("\n");
 016.     }
 017.  }
 018.
 019.  /* to samo co: print_matrix(m, 1, 1, x) */
 020.  void print_vector(int m, double *x) {
 021.     int j;
 022.
 023.     for (j = 0; j < m; j++)
 024.        printf(" %5.1f\n", x[j]);
 025.  }
 026.
 027.  int main() {
 028.     double a[M][LDA], x[N], y[M];
 029.     double alpha = 0.5;
 030.     double beta = 0.0;
 031.
 032.     int i, j;
 033.
 034.     /* zerowanie tablicy a */
 035.     for (j = 0; j < M; j++)
 036.        for (i = 0; i < N; i++)
 037.           a[j][i] = 0.0;
 038.
 039.     /* inicjalizacja tablicy a */
 040.     a[0][0] = 1.0;
 041.     a[0][1] = -2.0;
 042.     a[1][1] = 3.0;
 043.     a[2][2] = -0.5;
 044.     a[3][1] = 0.5;
 045.     a[4][0] = 1.0;
 046.     a[4][1] = -1.0;
 047.
 048.     /* inicjalizacja wektora x */
 049.     x[0] = 10.0;
 050.     x[1] = 20.0;
 051.     x[2] = 30.0;
 052.
 053.     printf("Macierz A:\n");
 054.     print_matrix(M, N, LDA, (double *)a);
 055.
 056.     printf("\n");
 057.     printf("Wektor X:\n");
 058.     print_vector(N, x);
 059.
 060.     /* y := alpha*a*x + beta*y */
 061.     cblas_dgemv(CblasRowMajor, CblasNoTrans, M, N, alpha, (double *)a, LDA, x, 1, beta, y, 1);
 062.
 063.     printf("\n");
 064.     printf("Wektor Y (=A*X):\n");
 065.     print_vector(M, y);
 066.
 067.     return 0;
 068.  }