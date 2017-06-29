#include "mm.h"
#include <stdlib.h>

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
      }
    }
  }
}

// add matrices
void add(matrix * left, matrix * right, matrix * dest) {
  double *a, *b, *c;
  int size, i;

  a = left->data;
  size = left->rows * left->cols;
  b = right->data;
  c = dest->data;

  for (i = 0; i != size; i++) {
    c[i] = a[i] + b[i];
  }
}

// subtract matrices
void subtract(matrix * left, matrix * right, matrix * dest) {
  double *a, *b, *c;
  int size, i;

  a = left->data;
  size = left->rows * left->cols;
  b = right->data;
  c = dest->data;

  for (i = 0; i != size; i++) {
    c[i] = a[i] - b[i];
  }
}

// transpose matrices
void transpose(matrix * src, matrix * dest) {
  if (src == dest) {
    // Inplace transpose
    int i, r, c, size;
    int t, next, begin;
    double * a, temp;
    char * bitmap;

    a = src->data;
    r = src->rows;
    c = src->cols;
    size = r * c;
    bitmap = (char *)malloc(sizeof(char) * (size / sizeof(char) + 1));
    for (i = 0; i != size / sizeof(char) + 1; i++) {
      bitmap[i] = 0x00;
    }

    size -= 1;
    bitmap[0] |= 0x01;
    bitmap[size / sizeof(char)] |= (0x01 << (size & 0x07));
    i = 1;
    while (i < size) {
      begin = i;
      t = a[i];
      do {
        next = (i*r) % size;
        temp = a[next];
        a[next] = t;
        t = temp;
        bitmap[i / sizeof(char)] |= (0x01 << (i & 0x07));
        i = next;
      } while (i != begin);

      for (i = 1; (i != size) &&
          (bitmap[i / sizeof(char)] & (0x01 << (i & 0x07)));
          i++);
    }
  }
  else {
    // Out of place transpose
    int i, r, c, size;
    double *a, *b;

    a = src->data;
    r = src->rows;
    c = src->cols;
    size = r * c;
    b = dest->data;

    for (i = 0; i != size; i++) {
      b[i] = a[c * (i % r) + (i / r)];
    }
  }
}

// scale matrices
void scale(matrix * left, double factor, matrix * dest) {
  double *a, *c;
  int size, i;

  a = left->data;
  size = left->rows * left->cols;
  c = dest->data;

  for (i = 0; i != size; i++) {
    c[i] = a[i] * factor;
  }
}

// sum matrix
double sum(matrix * src) {
  double *a;
  double sum;
  int i, size;

  a = src->data;
  size = src->rows * src->cols;

  sum = 0;
  for (i = 0; i != size; i++) {
    sum += a[i];
  }
  return sum;
}
