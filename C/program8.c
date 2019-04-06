#include <stdio.h>

int main(int argc, char **argv) {

    int i = 2;
    int j = 1;

    if(argc == i) {
        printf("%s", argv[j]);
    } else {
        printf("Please use two arguments!");
    }
    printf("\n");

    return 0;
}
