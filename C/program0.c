#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    for(long long int i = 1; ; i *= 2) {
        if(i == 0) {
            break;
        }
        printf("%lli\n", i);
    }
}
