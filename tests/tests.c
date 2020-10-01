/**
* @file         tests.c
* @brief        Run all tests from tests.h
* @author       Dvortsova Varvara BSE182 HSE
* @include      locale.h, tests.h, ../src/help_lib.h
*/
#include <locale.h>
#include "tests.h"
#include "../src/help_lib.h"






void test3(){
    int length = 0;
    char* nameOfFile = "../tests/test_01.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0, linesCount - 1, LEFT_TO_RIGHT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, LEFT_TO_RIGHT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test4(){
    int length = 0;
    char* nameOfFile = "../tests/test_01.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0, linesCount - 1, RIGHT_TO_LEFT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, RIGHT_TO_LEFT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test5(){
    int length = 0;
    char* nameOfFile = "../tests/test3_1251.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0, linesCount - 1, RIGHT_TO_LEFT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, RIGHT_TO_LEFT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test6(){
    int length = 0;
    char* nameOfFile = "../tests/test3_1251.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0, linesCount - 1, LEFT_TO_RIGHT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, LEFT_TO_RIGHT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test7(){
    int length = 0;
    char* nameOfFile = "../tests/test4_1251.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0, linesCount - 1, LEFT_TO_RIGHT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, LEFT_TO_RIGHT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test8(){
    int length = 0;
    char* nameOfFile = "../tests/test4_1251.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0, linesCount - 1, RIGHT_TO_LEFT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, RIGHT_TO_LEFT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test9(){
    int length = 0;
    char* nameOfFile = "../tests/test_02.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList,0, linesCount - 1, RIGHT_TO_LEFT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, RIGHT_TO_LEFT),1);

    free(bufferOrigin);
    free(sourceList);
}

void test10(){
    int length = 0;
    char* nameOfFile = "../tests/test_02.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    startQuickSortLib(sourceList, 0,linesCount - 1, LEFT_TO_RIGHT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, LEFT_TO_RIGHT),1);

    free(bufferOrigin);
    free(sourceList);
}
int main(void){
    setlocale(LC_ALL, "ru_RU.cp1251");

    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}
