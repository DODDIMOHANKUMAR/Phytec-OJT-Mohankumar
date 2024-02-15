#include <stdio.h>

int  main() {
  // Variable declarations
  double x1, x2, y1, y2;
  int i, n;

  // Getting user input for coordinates
  printf("Input P(x1,y1):\n");
  scanf("%lf %lf", &x1, &y1);
  printf("\nInput P(x2,y2):\n");
  scanf("%lf %lf",&x2,&y2);

  // Checking if lines PQ and RS are parallel
  if ((x1 == x2) && (y1 == y2))
    printf("\nPQ and RS are parallel!\n");
  else if ((x1 == x2) || (y1 == y2))
    printf("\nPQ and RS are not parallel!\n");
  else if (((y1 - y2) / (x1 - x2) == 0.0))
    printf("\nPQ and RS are parallel!\n");
  else
    printf("\nPQ and RS are not parallel!\n");

  return (0); // End of the program
}

