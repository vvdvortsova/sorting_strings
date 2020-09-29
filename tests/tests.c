/**
* @file         tests.c
* @brief        Run all tests from tests.h
* @author       Dvortsova Varvara BSE182 HSE
* @include      locale.h, tests.h, ../src/help_lib.h
*/
#include <locale.h>
#include "tests.h"
#include "../src/help_lib.h"



static struct LineOfFile* getEnglishLines(int n) {
    struct LineOfFile* arr = calloc(n, n * sizeof(struct LineOfFile*));
    arr[0].line = "As stars with trains of fire and dews of blood,";
    arr[0].lenOfLine = 47;
    arr[1].line = "Disasters in the sun; and the moist star";
    arr[1].lenOfLine = 41;
    arr[2].line = "Was sick almost to doomsday with eclipse:";
    arr[2].lenOfLine = 41;
    arr[3].line = "But soft, behold! lo, where it comes again!";
    arr[3].lenOfLine = 43;
    arr[4].line = "The graves stood tenantless and the sheeted dead";
    arr[4].lenOfLine = 48;
    return arr;
}

void test1(){
    int n = 5;
    struct LineOfFile* arr = getEnglishLines(n);
    quickSortSortLib(arr, n, LEFT_TO_RIGHT);
    assertTestINT("test1", isSorted(arr, n, LEFT_TO_RIGHT),1);

}

void test2(){
    int n = 5;
    struct LineOfFile* arr = getEnglishLines(n);
    quickSortSortLib(arr, n, RIGHT_TO_LEFT);
    assertTestINT("test2", isSorted(arr, n, RIGHT_TO_LEFT),1);
}

void test3(){
    int length = 0;
    char* nameOfFile = "../tests/test_01.txt";
    struct LineOfFile* sourceList = NULL;
    char* bufferOrigin =  getBuffersFromSourceFile(&length, nameOfFile);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    sourceList = arrangePointersFromBuffer(bufferOrigin, linesCount, length);

    quickSortSortLib(sourceList, linesCount, LEFT_TO_RIGHT);
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

    quickSortSortLib(sourceList, linesCount, RIGHT_TO_LEFT);
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

    quickSortSortLib(sourceList, linesCount, RIGHT_TO_LEFT);
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

    quickSortSortLib(sourceList, linesCount, LEFT_TO_RIGHT);
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

    quickSortSortLib(sourceList, linesCount, LEFT_TO_RIGHT);
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

    quickSortSortLib(sourceList, linesCount, RIGHT_TO_LEFT);
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

    quickSortSortLib(sourceList, linesCount, RIGHT_TO_LEFT);
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

    quickSortSortLib(sourceList, linesCount, LEFT_TO_RIGHT);
    assertTestINT(nameOfFile, isSorted(sourceList, linesCount, LEFT_TO_RIGHT),1);

    free(bufferOrigin);
    free(sourceList);
}
int main(void){
    setlocale(LC_ALL, "ru_RU.cp1251");

    test1();
    test2();
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
