/**
* @file         main.c
* @brief        Sorted strings of ../sources/source.txt
* @author       Dvortsova Varvara BSE182 HSE
* @include      stdio.h, stdlib.h, locale.h, sort_lib.h, help_lib.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "sort_lib.h"
#include "help_lib.h"


int main() {

    setlocale(LC_ALL, "ru_RU.cp1251");

    int length = 0;
    char* nameOfFile = "../src/source.txt";

    char* bufferOrigin      =  getBuffersFromSourceFile(&length, nameOfFile);
    char* bufferLeftToRight = calloc(length + 1, sizeof(bufferOrigin));
    char* bufferRightToLeft = calloc(length + 1, sizeof(bufferOrigin));
    memcpy(bufferLeftToRight, bufferOrigin,length);
    memcpy(bufferRightToLeft, bufferOrigin,length);

    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    printf("Len of file = %d\n", linesCount);
    //arrange pointers to the buffer
    struct LineOfFile* sourceList        = arrangePointersFromBuffer(bufferOrigin, linesCount, length);
    struct LineOfFile* sourceLeftToRight = arrangePointersFromBuffer(bufferLeftToRight, linesCount, length);
    struct LineOfFile* sourceRightToLeft = arrangePointersFromBuffer(bufferRightToLeft, linesCount, length);

    startQuickSortLib(sourceLeftToRight, 0,linesCount - 1, LEFT_TO_RIGHT);
    startQuickSortLib(sourceRightToLeft, 0,linesCount - 1,RIGHT_TO_LEFT);

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

