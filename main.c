#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "lib.h"




//do we need here put volatile ? 
uint32_t status = 0;
//TODO : 
//Tests
// Toggling 
// bin in dec fp
// cli 
//error handling 
//secure 
//
// perfomance
// refact
//additinal tasks


void foo(int *b){

//
}

int so = 10;


int main() {
  
    int eleven = 11;
    int array_eleven[32];
    int array[32];
    
  
    float number = 243.3;

    printf("\n\n");

    printf("dec_bin no ptr \n\n");
    printf(" main test - -2 ");
    convert_decimal_bin(eleven);
    printf(" main test - -1 ");
    printf("dec_bin origin ptr \n\n");
   
    int counter = convert_decimal_bin_origin(eleven,array_eleven);
  
    show_arr(array_eleven,counter);
   
    convert_decimal_to_fp_bin(number,array);




    

    

   

    return 0;
}
