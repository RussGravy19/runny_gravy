#include <stdio.h>



int is_even(int secretNum) {
    printf("I will now decide if your number is even. \n");
    
    return !(secretNum % 2);
}
