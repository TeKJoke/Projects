#include <stdio.h>

int main(void) {
    long long m = 0X9204AFFFll;

    printf("m is %llx\n%llo\n%lld\n", m, m, m);

    printf("This is printing the following characters\x0A");

    return 0;
}
