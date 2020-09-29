#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sort_lib.h"
#include "help_lib.h"


int main() {

    setlocale(LC_ALL, "ru_RU.cp1251");

    struct LineOfFile* sourceList        = NULL;
    struct LineOfFile* sourceLeftToRight = NULL;
    struct LineOfFile* sourceRightToLeft = NULL;

    char* bufferOrigin      = NULL;
    char* bufferLeftToRight = NULL;
    char* bufferRightToLeft = NULL;

    int length = 0;
    char* nameOfFile = "../sources/source.txt";

    bufferOrigin      =  getBuffersFromSourceFile(&length, nameOfFile);
    bufferLeftToRight =  getBuffersFromSourceFile(&length, nameOfFile);
    bufferRightToLeft =  getBuffersFromSourceFile(&length, nameOfFile);

    int linesCount = 0;
    linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    printf("Len of file = %d\n", linesCount);
    //arrange pointers to the buffer
    sourceList        = arrangePointersFromBuffer(bufferOrigin, linesCount, length);
    sourceLeftToRight = arrangePointersFromBuffer(bufferLeftToRight, linesCount, length);
    sourceRightToLeft = arrangePointersFromBuffer(bufferRightToLeft, linesCount, length);

    quickSortSortLib(sourceLeftToRight, linesCount, LEFT_TO_RIGHT);
    quickSortSortLib(sourceRightToLeft, linesCount, RIGHT_TO_LEFT);

    putResultToFiles(sourceLeftToRight, linesCount, "../results/sortedRightToLeft.txt", LEFT_TO_RIGHT);
    putResultToFiles(sourceRightToLeft, linesCount, "../results/sortedLeftToRight.txt", RIGHT_TO_LEFT);
    putResultToFiles(sourceList, linesCount, "../results/original.txt", NONE_SORT);

    free(bufferOrigin);
    free(bufferLeftToRight);
    free(bufferRightToLeft);

    free(sourceList);
    free(sourceLeftToRight);
    free(sourceRightToLeft);

    exit(EXIT_SUCCESS);
}

