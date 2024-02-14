#include <stdio.h>

// Define a structure
struct Point 
{
    int x;
    int y;
};

int main() {
    // Declare a structure variable
    struct Point myPoint;

    // Initialize structure members
    myPoint.x = 100;
    myPoint.y = 200;

    // Declare a pointer to a structure
    struct Point *ptr;

    // Assign the address of myPoint to the pointer
    ptr = &myPoint;

    // Access structure members using the pointer
    printf("X coordinate: %d\n", ptr->x);
    printf("Y coordinate: %d\n", ptr->y);

    return 0;
}

