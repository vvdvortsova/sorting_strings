/**
* @file         test.c
* @brief        Run all test
* @author       Dvortsova Varvara BSE182 HSE
* @include      locale.h, ../src/sort_lib.h, ../src/help_lib.h
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "../src/sort_lib.c"
#include "../src/help_lib.h"

/**
 * Macros define custom assert function for unit testing
 * @param nameOfMethod   Describe the name Of method where assertTestINT was called
 * @param code           Actual value
 * @param expected       Expected value
 * */
#define assertTestINT( nameOfMethod,code, expected )\
    if((code) == (expected)){\
        printf("[TEST] [ %s ] [PASSED]\n",\
                nameOfMethod);\
    }else{\
        fprintf(stderr, "[TEST] [ %s ] [FAILED]\n",\
                nameOfMethod);\
        fprintf(stderr, "[TEST] expected = %d code = %d \n",expected, code);\
    }


void doTest(char* nameOfFile, enum HOW_TO_COMPARE_STRING howToCompareStr){
    int length = 0;
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);
    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);
    startQuickSortLib(sourceList, 0, linesCount - 1, howToCompareStr);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, howToCompareStr),1);

    free(bufferOrigin);
    free(sourceList);
}

int main(void){
    doTest("test/test_02.txt", LEFT_TO_RIGHT);
    doTest("test/test_02.txt", RIGHT_TO_LEFT);
    doTest("test/test_01.txt", LEFT_TO_RIGHT);
    doTest("test/test_01.txt", RIGHT_TO_LEFT);
    doTest("test/test_03.txt", LEFT_TO_RIGHT);
    doTest("test/test_03.txt", RIGHT_TO_LEFT);
    return 0;
}
