#ifndef LIB_BIN_
#define  LIB_BIN_

#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include <stdio.h>

int check_bit(int number,int bit_position);
int reset_bit(int number,int bit_position);
int set_bit(int number,int bit_position);
int toggle_bit(int number,int bit_position);


int convert_bin_to_decimal(char*bin_num);
void convert_decimal_to_fp_bin(double fp_decimal,int* arr_integer_part);


int convert_decimal_bin_origin(int int_bin,int *arr_bin);


void show_arr(int *arr,int counter);


int count_seted_bit(int number);
int reverse_bits(int number);


#define ASCII_ZERO 48

#endif