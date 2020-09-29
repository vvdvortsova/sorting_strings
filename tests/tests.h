//
// Created by vara on 29.09.2020.
//

#ifndef SORT_STRINGS_TESTS_H
#define SORT_STRINGS_TESTS_H

#include "../src/sort_lib.c"
#include "../src/help_lib.h"
/**
 * Macros define custom assert function for unit testing
 * @param nameOfMethod Describe the name Of method where assertTestINT was called
 * @param code Actual value
 * @param expected Expected value
 * */
#define assertTestINT( nameOfMethod,code, expected )\
    if((code) == (expected)){\
        printf("[TEST] [ %s ] [PASSED] (%s:%d)\n",\
                nameOfMethod, __FILE__, __LINE__);\
    }else{\
        fprintf(stderr, "[TEST] [ %s ] [FAILED] (%s:%d) \n",\
                nameOfMethod,__FILE__, __LINE__);\
        fprintf(stderr, "[TEST] expected = %d code = %d \n",expected, code);\
    }

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();

#endif
