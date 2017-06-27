#include "mm.h"
#include <stdlib.h>
#if defined __APPLE__ && __MACH__
#include <Accelerate/Accelerate.h>
#endif
#ifdef __MM_DEBUG__
#include <stdio.h>
#endif

// allocate memory
matrix * create_matrix(int rows, int cols) {
  matrix m = { (double*)malloc(sizeof(double) * rows * cols), rows, cols  };
  matrix * ptr = (matrix *)malloc(sizeof(matrix));
  *ptr = m;
  return ptr;
}

// free memory
void destroy_matrix(matrix * ptr) {
  free(ptr->data);
  free(ptr);
}

// access memory
double * matrix_access(matrix * ptr, int row, int col) {
  return ptr->data + row * ptr->cols + col;
}

// multiply matrices
void multiply(matrix * left, matrix * right, matrix * dest) {
  #if defined __APPLE__ && __MACH__ && __USE_BLAS__
  double *a, *b, *c;
  int M, N, K;
  matrix mat;

  mat = *left;
  a = mat.data;
  M = mat.rows;
  K = mat.cols;
  mat = *right;
  b = mat.data;
  N = mat.rows;
  c = dest->data;

  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, 1, a, M, b, K, 0, c, M);
  #else
  int i, j, k, bv, cv, I, J, K;
  double *a, *b, *c;
  double ac;

  I = left->rows;
  K = left->cols;
  a = left->data;
  J = right->cols;
  b = right->data;
  c = dest->data;

  // cache independent ikj method
  for (i = 0; i != I*J; i++) {
    c[i] = 0;
  }
  for (i = 0; i != I; i++) {
    for (k = 0; k != K; k++) {
      cv = i*J;
      ac = a[i*K + k];
      bv = k*J;
      for (j = 0; j != J; j++) {
        c[cv + j] += ac * b[bv + j];
        #ifdef __MM_DEBUG__
        printf("%f * %f\n", ac, b[bv+j]);
        #endif
      }
    }
  }
  #endif
}
