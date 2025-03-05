#include <stdio.h>



int isEven(int secretNum) {
    printf("I will now decide if your number is even. \n");
    
    return !(secretNum % 2);
}
