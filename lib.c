#include "lib.h"

//do as macro
int check_bit(int number,int bit_position){
    int bit = 0;
    bit = (number>>bit_position) & 1 ;

    return bit;
}

int reset_bit(int number,int bit_position){
    number = number & (~(1<<bit_position));
    return number;
}


int set_bit(int number,int bit_position){
    number = number | (1<<bit_position);
    return number;
}
int toggle_bit(int number,int bit_position){
    return (number ^ (1<<bit_position));
}
/// 

/*
int* reverse_bits(int decimal_number){
    int counter_position = sizeof(decimal_number) * 8 - 1;
    int bit = 0;
    printf("0b");
    int arr_temp[counter_position];
    int counter_i = 0;
    while(counter_position>-1){
        bit = check_bit(decimal_number,counter_position);
        arr_temp[counter_i] = bit;
        counter_position--;
        counter_i++;
    }

    for (int  i = 0; i < counter_i; i++)
    {
        toggle_bit(arr_temp[i],i);
    }
    

    printf("\n");

    return arr_temp;
}
*/
//void test(int const tr){}


//optimize
int convert_decimal_bin(int decimal_number) {
    int temp = decimal_number;
    int counter_position = sizeof(decimal_number) * 8 - 1;
 
    int bit = 0;
    printf("0b");

    while(counter_position>-1){
        bit = check_bit(decimal_number,counter_position);
        printf("%d",bit);
        counter_position--;
       
    }
    printf("\n");



    return temp;
}

int convert_bin_to_decimal(char*bin_num){
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

void convert_decimal_to_fp_bin(double fp_decimal,int* arr_integer_part){
    int current_arr_int[32];
   
    int counter = 0;
    
    int int_fp_decimal = fp_decimal;
    double fract_fp_decimal = fp_decimal - int_fp_decimal;

    printf("= %f\n",fract_fp_decimal);
   

    while (int_fp_decimal>0)
    {

    
        
        if(int_fp_decimal%2==0) {
            current_arr_int[counter] = 0;
        }
        else {
            current_arr_int[counter] = 1;
        }
        counter++;
        int_fp_decimal = int_fp_decimal/2 ;

    }



    arr_integer_part = (int*) malloc(counter * sizeof(int));

   
    for(int i = 0;i < counter; i++) {
        arr_integer_part[i] = current_arr_int[i];
    }
 
 
    printf("\n\n");

     for(int i = counter - 1;i >=0; i--) {
      printf("%d",  arr_integer_part[i]);
    }
    
    int counetr_i = 0;
    int current_arr_double[24];

    while (true)
    {
      


        fract_fp_decimal = fract_fp_decimal * (double)2.00;

    if (counetr_i == 12 ) {fract_fp_decimal += 0.1;}
       
        
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
    

}
