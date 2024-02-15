#include <stdio.h>

int main() {
    // Probability of getting heads in one toss
    double probabilityOfHeads = 0.5;

    // Number of tosses
    int numTosses = 3;

    // Calculate probability of getting heads in all three tosses
    double probabilityOfAllHeads = 1.0;
    for (int i = 0; i < numTosses; ++i) {
        probabilityOfAllHeads *= probabilityOfHeads;
    }

    // Display the result
    printf("Probability of getting heads in all three tosses: %lf\n", probabilityOfAllHeads);

    return 0;
}

