#define DOUBLE_PRECISION

#include "mm.h"
#include "grapher.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // ------------------------------------------------- //
  // We are going to learn a y = mx + b for some data  //
  // To see the data look at res/linear.dat            //
  // ------------------------------------------------- //

  // First lets get our points from res/linear.dat
  FILE * data = fopen("res/linear.dat", "r");
  if (data == NULL) {
    fprintf(stderr, "failed to open the data file\n");
    return -1;
  }

  // Lets get how many data points
  int ch, points = 0;
  for (ch = getc(data); ch != EOF; ch = getc(data)) {
    // If there is a newline that means a new point
    if (ch == '\n') points++;
  }
  
  // Lets create the matrix for inputs and outputs
  matrix * inputs = create_matrix(points, 2);
  matrix * outputs = create_matrix(points, 1);

  // Move the file pointer to the beginning again
  fseek(data, 0, SEEK_SET);

  // Put the points into the matrices
  int i, j;
  for (i = 0; i != points; i++) {
    // Get x value to mulitply by m
    fscanf(data, "%lf", inputs->data + 2*i);
    // Put 1 value to multiply by b
    inputs->data[2*i + 1] = 1;
    // Get y value to for the correct value
    fscanf(data, "%lf", outputs->data + i);
  }

  // Now we make a guess for our line looking at the data
  matrix * guess = create_matrix(2, 1);
  guess->data[0] = 0.6;
  guess->data[1] = 5;
  // y = 1 * x + 0 * 1;

  // Now lets graph it
  window * graph = create_window();
  double m = guess->data[0];
  double b = guess->data[1];
  send_command(graph, "set xrange [-5:200]");
  send_command(graph, "set yrange [-1:60]");
  send_command(graph, "plot \"res/linear.dat\"");
  draw_line(graph, m, b);

  // See it for 3 seconds
  unsigned long time = clock();
  while (clock() - time < CLOCKS_PER_SEC * 3);

  // Get how many iterations of gradient descent
  int iterations;
  printf("How Many Iterations: ");
  fflush(stdout);
  scanf("%d", &iterations);

  // Lets transpose inputs for later
  matrix * inputs_t = create_matrix(2, points);
  for (i = 0; i != points; i++) {
    inputs_t->data[i] = inputs->data[2*i];
    inputs_t->data[points + i] = 1;
  }

  // Lets start gradient descent
  double error, diff;
  double alpha = 0.0001;
  matrix * gradients = create_matrix(2, 1);
  matrix * hypothesis = create_matrix(points, 1);

  for (i = 0; i != iterations; i++) {
    // Graph every iteration to show difference
    m = guess->data[0];
    b = guess->data[1];
    send_command(graph, "plot \"res/linear.dat\"");
    draw_line(graph, m, b);

    time = clock();
    multiply(inputs, guess, hypothesis); // hyp = ax + b

    for (error = 0, j = 0; j != points; j++) {
      // Get the error from our guess
      hypothesis->data[j] -= outputs->data[j];  // hyp = ax + b - y
      diff = hypothesis->data[j];
      error += diff * diff;
    }
    error = error / (2 * points);
    printf("iteration %d: %f error\n", i+1, error);

    // The function is (outputs - (guess * inputs))^2 / 2M
    // Take derivative with respect to guess
    // inputs * (guess - outputs) / M
    multiply(inputs_t, hypothesis, gradients);
    scale(gradients, -alpha / points, gradients);
    add(guess, gradients, guess);

    while (clock() - time < CLOCKS_PER_SEC / 2);
  }

  // Lets clean up
  destroy_matrix(inputs);
  destroy_matrix(outputs);
  destroy_matrix(guess);
  destroy_window(graph);

  return 0;
}
