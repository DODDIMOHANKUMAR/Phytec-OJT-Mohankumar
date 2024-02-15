#include <stdio.h> 
int main() 
{ 
    int n = 5; 
  
    // first outer loop to iterate through each row 
    for (int i = 0; i < 2 * n - 1; i++) { 
  
        // assigning values to the comparator according to 
        // the row number 
        int comp; 
        if (i < n) { 
            comp = 2 * (n - i) - 1; 
        } 
        else { 
            comp = 2 * (i - n + 1) + 1; 
        }
      for (int j =0;j<comp;j++) {
	      printf(" ");
      }
      for(int k =0;k<2*n - comp;k++){
	      printf("%C ",k + 'A');
      }

    
    printf("\n");
    }
    return 0;
}

