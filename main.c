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


int main() {
  
    
    int array[32];
    int array_number[32];
  
    int number = 5789;

    printf("\n\n");

   
    int counter = convert_decimal_bin_origin(number,array);
  
    show_arr(array,counter);
   


    printf("\n --- \n");


    int new_number = reverse_bits(number);

    printf("\n -- %d \n", new_number);

    int new_counter = convert_decimal_bin_origin(new_number,array_number);
  
    show_arr(array_number,new_counter);



    

    

   

    return 0;
}
