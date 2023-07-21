#include "lib.h"
#include "acutest.h"



void test_add(void){
        //TEST_CHECK_(add)
}

void test_check_bit(void) {
    // Test case 1: bit at position 0 is 1
    TEST_CHECK_(check_bit(5, 0) == 1, "check_bit(%d, %d) ", 5, 0);
    // Test case 2: bit at position 1 is 0
    TEST_CHECK_(check_bit(5, 1) == 0, "check_bit(%d, %d) ", 5, 1);
    // Test case 2: bit at position 15 is 0
    TEST_CHECK_(check_bit(5, 15) == 0, "check_bit(%d, %d) ", 5, 15);
}



TEST_LIST = {
    {"int check_bit(int, int);", test_check_bit},
    {"int add(int,int);", test_add},
    {0}
};

    