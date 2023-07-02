#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define ASCII_ZERO 48
//do we need here put volatile ? 
uint32_t status = 0;
//TODO : Tests

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

//void test(int const tr){}

//optimize
void convert_decimal_bin(int decimal_number) {
    int counter_position = sizeof(decimal_number) * 8 - 1;
    int bit = 0;
    printf("0b");

    while(counter_position>-1){
        bit = check_bit(decimal_number,counter_position);
        printf("%d",bit);
        counter_position--;
    }
    printf("\n");
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

    
    char bin_num[34];
    // take user input
    printf("Enter Bin number ");
    scanf("%s", bin_num);
    
    // printing the input value
    printf("your number is %s\n", bin_num);

    printf("dec num : %d",convert_bin_to_decimal(bin_num));
    

   

    return 0;
}
