#ifndef __MM_H__
#define __MM_H__

//#define __MM_DEBUG__

typedef struct {
  double * data;
  int rows;
  int cols;
} matrix;

matrix * create_matrix(int, int);
void     destroy_matrix(matrix *);
void     multiply(matrix *, matrix *, matrix *);
double * matrix_access(matrix *, int, int);

#endif
