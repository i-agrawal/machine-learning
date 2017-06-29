#include "mm.h"
#include <stdio.h>
#include <time.h>

int main() {
  unsigned long start, end;
  int N = 1024;
  matrix * a = create_matrix(N, N);
  matrix * b = create_matrix(N, N);
  matrix * c = create_matrix(N, N);
  matrix * d = create_matrix(N, N);

  start = clock();
  multiply(a, b, c);
  end = clock();
  printf("running time: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);

  int i, j, k;
  int idex, kdex;
  double aval;
  double *ma, *mb, *mc, *md;

  ma = a->data;
  mb = b->data;
  mc = c->data;
  md = d->data;
  start = clock();
  for (i = 0; i != N*N; i++) {
    md[i] = 0;
  }
  for (i = 0; i != N; i++) {
    for (k = 0; k != N; k++) {
      idex = i*N;
      kdex = k*N;
      aval = ma[idex + k];
      for (j = 0; j != N; j++) {
        md[idex+j] += aval * mb[kdex+j];
      }
    }
  }
  end = clock();
  printf("running time: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
  
  double error = 0;
  for (i = 0; i != N*N; i++) {
    aval = md[i] - mc[i];
    error += aval * aval;
  }
  printf("total error: %f difference\n", error);
  destroy_matrix(a);
  destroy_matrix(b);
  destroy_matrix(c);
  destroy_matrix(d);

  matrix * e = create_matrix(3, 3);
  matrix * f = create_matrix(3, 1);
  matrix * g = create_matrix(3, 1);
  
  e->data[0] = 1;
  e->data[1] = 1;
  e->data[2] = 1;
  
  e->data[3] = 2;
  e->data[4] = 2;
  e->data[5] = 1;
  
  e->data[6] = 3;
  e->data[7] = 3;
  e->data[8] = 1;

  f->data[0] = 1.5;
  f->data[1] = 2.5;
  f->data[2] = 3.5;

  multiply(e, f, g);
  for (i = 0; i != 3; i++) {
    printf("%g * %g + %g * %g + %g * %g = %g\n", f->data[0], e->data[3*i], f->data[1], e->data[3*i+1], f->data[2], e->data[3*i+2], g->data[i]);
  }

  return 0;
}
