#include <stdio.h>

int main(void) {
    int amount;
    int tmp;
    int bills_20;
    int bills_10;
    int bills_5; 
    int bills_1;
    int i;
    int i_10;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    bills_20 = amount / 20;
    i = amount - bills_20 * 20;
    i_10 = i / 10;
    tmp = amount % 20;
    bills_10 = tmp / 10;
    tmp = amount % 10;
    bills_5 = tmp / 5;
    tmp = amount % 5;
    bills_1 = tmp / 1;

    printf("$20 bills: %d\n", bills_20);
    printf("i is %d\n", i);
    printf("i_10 is %d\n", i_10);
    printf("$10 bills: %d\n", bills_10);
    printf("$5 bills: %d\n", bills_5);
    printf("$1 bills: %d\n", bills_1);

    return 0;
}
