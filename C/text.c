#include <stdio.h>

int main(void) {
    FILE *fp;

    printf("console message\n");

    if((fp = freopen("random.txt", "w", stdout)) == NULL) {
        printf("ERROR!!!");
    }

    printf("test message");

    fclose(fp);

    return 0;
}
