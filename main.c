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
//secure (MISRA)
//
// perfomance
// refact
//additinal tasks


int main() {
  
    int eleven = 11;
    printf("Before -- \n");
    printf("numebr : %d\n",eleven);
    convert_decimal_bin(eleven);
    printf("After -- \n");
    eleven = set_bit(eleven,10);
    printf("numebr : %d\n",eleven);
    convert_decimal_bin(eleven);
    printf("After Reset -- \n");
    eleven = reset_bit(eleven, 10);
    eleven = reset_bit(eleven, 1);
    printf("numebr : %d\n",eleven);
    convert_decimal_bin(eleven);

    
    //char bin_num[34];
    // take user input
    //printf("Enter Bin number ");
    //scanf("%s", bin_num);
    
    // printing the input value
   // printf("your number is %s\n", bin_num);
    // not working
    //printf("dec num : %d",convert_bin_to_decimal(bin_num));

    //printf("\n\n\n");
    //
    

    int* arr_integer_part = NULL;
    int arr_integer_part_n [32];
    float fp_number = 500.78;
    printf("Test fp \n");
   // convert_decimal_to_fp_bin(fp_number,arr_integer_part);

    printf("\n \n\n");


    

    

   

    return 0;
}
