#include "lib.h"
#define DEBUG_INFO_TEST_STEPS
//do as macro
int check_bit(int number,int bit_position){
    return (number>>bit_position) & 1;
}

int reset_bit(int number,int bit_position){
    return (number & (~(1<<bit_position)));
}


int set_bit(int number,int bit_position){
    return (number | (1<<bit_position));
     
}

int toggle_bit(int number,int bit_position){
    return (number ^ (1<<bit_position));
}

void toggle_bit_ptr(int *number,int bit_position){
    (*number) ^= (1<<bit_position);
}


int convert_bin_to_decimal(char*bin_num){
   #ifdef DEBUG_INFO_DESCRIPTION
      printf("Function convert_bin_to_decimal started .\n");
      printf("args : char * bin_num : \n");
   #endif

    int number_vaueble_bit = strlen(bin_num);
    int number_dec = 0;


    for (int i = number_vaueble_bit - 1, j = 0; i > 1;j++, i--)
    {   
        
        if(bin_num[i] == ASCII_ZERO)
        {   
            continue;
        }
        else
        {
            number_dec += pow(2,j);
        } 
    }
    return number_dec;
}




int convert_decimal_bin_origin(int int_bin,int *arr_bin){
     #ifdef DEBUG_INFO_DESCRIPTION
      printf("Function convert_decimal_bin_origin started .\n");
      printf("args : int int_bin , int *arr_bin: \n");
    #endif

    int counter = 0;
    while (int_bin>0)
    {   
        if(int_bin%2==0) {
            arr_bin[counter] = 0;
        }
        else {
            arr_bin[counter] = 1;
        }
        counter++;
        int_bin = int_bin/2 ;   
    }
    return counter; 
}




// --- Fp conversation --- //
// check sign 
void convert_decimal_to_fp_bin(double fp_decimal,int* arr_integer_part){
     #ifdef DEBUG_INFO_DESCRIPTION
      printf("Function convert_decimal_to_fp_bin started .\n");
      printf("args : double fp_decimal ,int* arr_integer_part \n");
    #endif
    int current_arr_int[32];
   
    int counter = 0;
    
    int int_fp_decimal = fp_decimal;
    double fract_fp_decimal = fp_decimal - int_fp_decimal;

    counter = convert_decimal_bin_origin(int_fp_decimal,current_arr_int);
    arr_integer_part = (int*) malloc(counter * sizeof(int));

   
    for(int i = 0;i < counter; i++) {
        arr_integer_part[i] = current_arr_int[i];
    }
 
    

    for(int i = counter - 1;i >=0; i--) {
      printf("%d",  arr_integer_part[i]);
    }
    
    int counetr_i = 0;
    int current_arr_double[24];

    while (true)
    {
        fract_fp_decimal = fract_fp_decimal * (double)2.00;

        if(counetr_i == 12 ) {fract_fp_decimal += 0.1;}
       
        
        if (fract_fp_decimal >= 1.0) {
        current_arr_double[counetr_i] = 1;
        fract_fp_decimal -= 1.0;
        }else {
        current_arr_double[counetr_i] = 0;
        }

        counetr_i++;


        if (counetr_i == 24){break;}
    }

    printf(".");

    for(int i = 0;i < counetr_i; i++) {
      printf("%d",  current_arr_double[i]);
    }



    // fractorial part  //

    //Normalize AND//
    free(arr_integer_part);

}


int count_seted_bit(int number){
    #ifdef DEBUG_INFO_DESCRIPTION
      printf("Function count_seted_bit started .\n");
      printf("args : int number\n");
    #endif
    int counter = 0;
    int counter_set_bits = 0;
    int temp_numner = number;
    while (number>0)
    {   
        if (check_bit(temp_numner,counter)==1)
        {
            counter_set_bits++;
        }
        counter++;
        number = number/2 ;   
    }
    return counter_set_bits;
}

int reverse_bits(int number){
    #ifdef DEBUG_INFO_DESCRIPTION
      printf("Function count_seted_bit started .\n");
      printf("args : int number\n");
    #endif
    int counter = 0;
    int temp_numner = number;
    int *current_number = &temp_numner;

    while (number>0)
    {   
        toggle_bit_ptr(current_number,counter);
        counter++;
        number = number/2 ;   
    }   
    return *current_number;
}

void show_arr(int *arr,int counter){
    for (int i = counter - 1 ; i >=0 ; i--)
    {
        printf("%d",arr[i]);
    }
}