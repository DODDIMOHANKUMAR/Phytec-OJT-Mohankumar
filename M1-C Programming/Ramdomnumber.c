#include <stdio.h>
#include <stdlib.h>


int  main() {
    int num1, num2;
    
    printf("Enter the User input Range num1:num2 ");
    scanf("%d %d", &num1, &num2);

   
    if (num1 >= num2) {
        printf("First number is less than to second number\n");
	return 0;
       
    }

    

        rand(time(NULL));

    
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            int range = rand() % (num2 - num1 + 1) + num1; 
            printf("%d ", range);
        }
        printf("\n");
    }

	return 0;
}



