i#include <stdio.h>

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


int lcm(int a, int b) {
    return (a * b) / gcd(a , b);
}

int main() {
    int a =2, b = 3, c = 7, d = 9;
    int lcm_ab = lcm(a, b);
    int lcm_cd = lcm(c, d);
    int result = lcm(lcm_ab, lcm_cd);
    printf("LCM of %d, %d, %d, and %d is: %d\n", a, b, c, d, result);

    return 0;
}

