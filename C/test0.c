#include <stdio.h>

typedef struct {
    char *model;
    char *year;
    char *letter;
} car_t;

int main(int argc, char *argv[]) {

    if(argc != 4) {
        printf("Program error!\n");
        return 1;
    } 
    else {
        car_t myCar;
        myCar.model = argv[1];
        myCar.year = argv[2];
        myCar.letter = argv[3];

        printf("%s, %s, %s\n", myCar.model, myCar.year, myCar.letter);
    }
    
    return 0;
}
