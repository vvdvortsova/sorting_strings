/**
* @file         main.c
* @brief        Sorts strings of ../sources/source.txt and outputs in results/
* @author       Dvortsova Varvara BSE182 HSE
* @include      stdio.h, stdlib.h, string.h, assert.h, sort_lib.h, help_lib.h
*/
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sort_lib.h"
#include "help_lib.h"


int main() {


    int length = 0;
    char* nameOfFile = "src/source.txt";
    char* bufferOrigin      =  getBuffersFromSourceFile(&length, nameOfFile);

    assert(bufferOrigin != NULL);
    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    //arrange pointers to the buffer
    struct LineOfFile* sourceList        = arrangePointersFromBuffer(bufferOrigin, linesCount, length);
    struct LineOfFile* sourceLeftToRight = sourceList;

    assert(sourceList != NULL);
    assert(sourceLeftToRight != NULL);

    startQuickSortLib(sourceLeftToRight, 0,linesCount - 1, LEFT_TO_RIGHT);
    putResultToFiles(sourceLeftToRight, linesCount, "results/sortedLeftToRight.txt", LEFT_TO_RIGHT);
    startQuickSortLib(sourceLeftToRight, 0,linesCount - 1, RIGHT_TO_LEFT);
    putResultToFiles(sourceLeftToRight, linesCount, "results/sortedRightToLeft.txt", RIGHT_TO_LEFT);
    putResultToFiles(sourceList, linesCount, "results/original.txt", NONE_SORT);

    free(bufferOrigin);
    free(sourceList);

    exit(EXIT_SUCCESS);
}

