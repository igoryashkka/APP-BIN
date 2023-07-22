#include "lib.h"
#include "acutest.h"


//
void test_check_bit(void) {
    TEST_CHECK_(check_bit(5, 0) == 1, "check_bit(%d, %d) ", 5, 0);
    TEST_CHECK_(check_bit(5, 1) == 0, "check_bit(%d, %d) ", 5, 1);
    TEST_CHECK_(check_bit(5, 15) == 0, "check_bit(%d, %d) ", 5, 15);
}

void test_reset_bit(void) {
    TEST_CHECK_(reset_bit(11, 0) == 10, "reset_bit(%d, %d) ", 11, 0);
    TEST_CHECK_(reset_bit(11, 1) == 9, "reset_bit(%d, %d) ", 11, 1);
    TEST_CHECK_(reset_bit(11, 2) == 11, "reset_bit(%d, %d) ", 11, 2);
}

void test_count_seted_bit(void) {
    TEST_CHECK_(count_seted_bit(11) == 3, "count_seted_bit(%d) = %d ", 11, 3);
    TEST_CHECK_(count_seted_bit(1000) == 6, "count_seted_bit(%d) =  %d ", 1000, 6);
    TEST_CHECK_(count_seted_bit(4443) == 7, "count_seted_bit(%d) =  %d ", 4443, 7);
}

void test_reverse_bits(void){
    TEST_CHECK_(reverse_bits(44) == 19, "reverse_bits(%d, %d) ", 44, 19);
    TEST_CHECK_(reverse_bits(12) == 3, "count_seted_bit(%d, %d) ", 12, 3);
    TEST_CHECK_(reverse_bits(4443) == 3748, "count_seted_bit(%d, %d) ", 4443, 3748);
}

void test_convert_bin_to_decimal(void) {
    char * number_1 = "0b1111";
    char * number_2 = "0b1011";
    char * number_3 = "0b101011";

    TEST_CHECK_(convert_bin_to_decimal(number_1) == 15, "convert_bin_to_decimal(%s) = %d ", number_1, 15);
    TEST_CHECK_(convert_bin_to_decimal(number_2) == 11, "convert_bin_to_decimal(%s) = %d ", number_2, 11);
    TEST_CHECK_(convert_bin_to_decimal(number_3) == 43, "convert_bin_to_decimal(%s) = %d ", number_3, 43);
}

// need to fix
void test_convert_decimal_to_bin(void) {
    const int size = 8;
    int arr_number[size] = {1,1,1,1,0,0,1,1};
    int test_number[size];

    int test_size = convert_decimal_bin_origin(243,test_number);

    TEST_CHECK_(test_size == size && (memcmp(arr_number, test_number, sizeof(arr_number)) == 0), "convert_decimal_bin( _ ) =  %d", 8);


}


TEST_LIST = {
    {"check_bit - return value of bit ", test_check_bit},
    {"reset_bit - reset bit value of exact_position ", test_reset_bit},
    {"count_seted_bit - return counter of bits", test_count_seted_bit},
    {"reverse_bits -  all 0 set as 1, all 1 - as 0", test_reverse_bits},
    {"convert_bin_to_decimal - convert bin number in decimal number ", test_convert_bin_to_decimal},
    {"convert_decimal_to_bin - convert decimal number in bin number, return number of valueble bits ", test_convert_decimal_to_bin},
    {0}
};

    