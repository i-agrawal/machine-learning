#define DOUBLE_PRECISION

#include "mm.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void * act;    // Activation Function
  void * error;  // Error Function
  void * derror; // Error Function Derivative

  matrix * theta; // The Regression's Weights
} regression;

regression * create_linear(int);
void linear_activation(matrix *, matrix *, matrix *);
void linear_error(matrix *, matrix *);
void

regression * create_linear(int vars) {
  act =
}

void linear_activation(matrix * X, matrix * theta, matrix * Y) {
  multiply(X, theta, Y);
}

int main() {
  int i;

  // ------------------------------------------------- //
  // We are going to learn f(a, b) = 1.5a + 2.5b + 3.5 //
  // NOTE: 3.5 is multiplying c but c is always 1      //
  // ------------------------------------------------- //

  int vars = 2;                               // There are 2 variables
  matrix * actual = create_matrix(vars+1, 1); // Actual weights multiplying a, b, and c
  actual->data[0] = 1.5;                      // Weight for a is 1.5
  actual->data[1] = 2.5;                      // Weight for b is 2.5
  actual->data[2] = 3.5;                      // Weight for c is 3.5

  // We need data to learn from
  int samples = 1000;                                   // We will have 1000 samples
  matrix * inputs = create_matrix(samples, vars+1);     // Matrix of inputs, each row is a sample's input
  matrix * correct_outputs = create_matrix(samples, 1); // Matrix of outputs, each row is a sample's correct output

  // Let us create the data since we know the correct output
  printf("Creating Random Data\n");
  for (i = 0; i < samples; i++) {
    inputs->data[3*i]   = (double)(rand() % 500) / 5;   // Randomly select a for this sample
    inputs->data[3*i+1] = (double)(rand() % 500) / 5;   // Randomly select b for this sample
    inputs->data[3*i+2] = 1;                            // c is always 1
  }

  // Let us calculate the correct outputs
  multiply(inputs, actual, correct_outputs);

  // We are going to display some samples
  printf("Displaying First Few Samples\n");
  int display = 5; // We will display the first 5 samples
  for (i = 0; i < display; i++) {
    printf("%g * %g + %g * %g + %g * %g = %g\n", actual->data[0], inputs->data[3*i], actual->data[1], inputs->data[3*i+1], actual->data[2], inputs->data[3*i+2], correct_outputs->data[i]);
  }

  // Now we get into the actual linear regression

  regression * linreg = create_linear(vars);

  // Linear Regression wants to do the following
  //      given inputs a, b, c, ...
  //      and f(a, b, c, ...) = w1*a + w2*b + w3*c + ...
  //      we want to find w1, w2, w3, ...
  // So why the hell do we have matrices
  //    |
  //    | a  b  c
  //    |
  //    |
  //    |
  // As a matrix multiplication it is simply f(θ, X) (hyp) equals the inputs (X) times the weights (θ)
  // so the activation function is hyp = Xθ

  // The Error is a simply the square of the difference (to make it positive)
  // The difference is simply hyp - Y


  return 0;
}
