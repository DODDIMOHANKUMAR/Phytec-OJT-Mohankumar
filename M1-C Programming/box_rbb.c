#include <stdio.h>

int main() {
    // Number of boxes with red balls, black balls, and blue balls
    int numRedBoxes = 3;
    int numBlackBoxes = 5;
    int numBlueBoxes = 6;

    // Total number of boxes
    int totalBoxes = numRedBoxes + numBlackBoxes + numBlueBoxes;

    // Calculate probability of selecting a box with a red ball
    double probabilityOfRedBox = (double)numRedBoxes / totalBoxes;

    // Display the result
    printf("Probability of selecting a box with a red ball: %lf\n", probabilityOfRedBox);

    return 0;
}

