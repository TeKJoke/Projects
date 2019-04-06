#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n0, n1, n2, n3;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &n0, &n1, &n2, &n3);

    if(n0 > n1 && n1 > n2 && n2 > n3) {
        printf("Largest : %d\n", n0);
        printf("Smallest: %d\n", n3);
    }
    else if(n1 > n2 && n2 > n3 && n3 > n0) {
        printf("Largest : %d\n", n1);
        printf("Smallest: %d\n", n0);
    }
    else if(n2 > n3 && n3 > n0 && n0 > n1) {
        printf("Largest : %d\n", n2);
        printf("Smallest: %d\n", n1);
    }
    else {
        printf("Largest : %d\n", n3);
        printf("Smallest: %d\n", n2);
    }

    return 0;
}
