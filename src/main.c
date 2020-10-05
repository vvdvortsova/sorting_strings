/**
* @file         main.c
* @brief        Sorts strings of ../sources/source.txt and outputs in results/
* @author       Dvortsova Varvara BSE182 HSE
* @include      stdio.h, stdlib.h, string.h, assert.h, sort_lib.h, help_lib.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sort_lib.h"
#include "help_lib.h"


int main() {


    int length = 0;
    char* nameOfFile = "src/source.txt";

    char* bufferOrigin      =  getBuffersFromSourceFile(&length, nameOfFile);
    char* bufferLeftToRight = calloc(length + 1, sizeof(bufferOrigin));
    char* bufferRightToLeft = calloc(length + 1, sizeof(bufferOrigin));
    memcpy(bufferLeftToRight, bufferOrigin,length);
    memcpy(bufferRightToLeft, bufferOrigin,length);

    assert(bufferOrigin != NULL);
    assert(bufferLeftToRight != NULL);
    assert(bufferRightToLeft != NULL);

    int linesCount = getNumberOfLinesInBuffer(bufferOrigin, length);

    printf("Len of file = %d\n", linesCount);
    //arrange pointers to the buffer
    struct LineOfFile* sourceList        = arrangePointersFromBuffer(bufferOrigin, linesCount, length);
    struct LineOfFile* sourceLeftToRight = arrangePointersFromBuffer(bufferLeftToRight, linesCount, length);
    struct LineOfFile* sourceRightToLeft = arrangePointersFromBuffer(bufferRightToLeft, linesCount, length);

    assert(sourceList != NULL);
    assert(sourceLeftToRight != NULL);
    assert(sourceRightToLeft != NULL);

    startQuickSortLib(sourceLeftToRight, 0,linesCount - 1, LEFT_TO_RIGHT);
    startQuickSortLib(sourceRightToLeft, 0,linesCount - 1,RIGHT_TO_LEFT);

    putResultToFiles(sourceLeftToRight, linesCount, "results/sortedRightToLeft.txt", LEFT_TO_RIGHT);
    putResultToFiles(sourceRightToLeft, linesCount, "results/sortedLeftToRight.txt", RIGHT_TO_LEFT);
    putResultToFiles(sourceList, linesCount, "results/original.txt", NONE_SORT);

    free(bufferOrigin);
    free(bufferLeftToRight);
    free(bufferRightToLeft);

    free(sourceList);
    free(sourceLeftToRight);
    free(sourceRightToLeft);

    exit(EXIT_SUCCESS);
}

