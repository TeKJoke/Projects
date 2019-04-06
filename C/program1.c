#include <stdio.h>

int main(void) {
    int x;

    printf("enter the value of x: ");
    scanf("%d", &x);

    int result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 is equal to %d\n", result);

    return 0;
}
