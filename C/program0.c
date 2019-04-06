#include <stdio.h>
#define CALC (4.0f/3.0f)

int main(void) {
    float radius = 10.0f;
    float volume = (CALC * 3.14159265359 * (radius * radius * radius));
    printf("The volume of a sphere with a radius of %.1f is %.2f\n", radius, volume);
    return 0;
}
