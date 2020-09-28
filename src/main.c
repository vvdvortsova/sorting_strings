#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>
#include "sort_lib.h"


char* getBuffersFromSourceFile(int* length, char* nameOfFile);
struct LineOfFile* arrangePointersFromBuffer(char* origin, int numberOfLines, int lengthOfBuffer);
int getNumberOfLinesInBuffer(char* buffer, int length);
void putResultToFiles(struct LineOfFile* sourceOrigin, int linesCount,
                        char* nameOfFile, enum HOW_TO_COMPARE_STRING howToCompare);

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

void putResultToFiles(struct LineOfFile *sourceOrigin, int linesCount,
            char *nameOfFile, enum HOW_TO_COMPARE_STRING howToCompare){
    assert(sourceOrigin);
    assert(nameOfFile);
    assert(linesCount != 0);

    int isSortedArray = -1;
    if(howToCompare != NONE_SORT){
        isSortedArray = isSorted(sourceOrigin, linesCount, howToCompare);
        if(isSortedArray > 0)printf(" is SORTED\n");
        else printf(" is UNSORTED\n");
    }

    FILE* fileToWriteResult = NULL;
    fileToWriteResult = fopen(nameOfFile, "w");

    if (!fileToWriteResult){
        printf("failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < linesCount; ++i)
        if(*sourceOrigin[i].line != '\0')
            fprintf(fileToWriteResult,"%s\n", sourceOrigin[i].line);

    fclose(fileToWriteResult);
}

int getNumberOfLinesInBuffer(char *buffer, int length){
    int linesCount = 0;
//     count amount of lines
    for (int i = 0; i < length; i++){
        if(buffer[i] == '\n')
            linesCount++;
    }

    if(linesCount >= length)
        linesCount = 0;

    return linesCount;
}

struct LineOfFile* arrangePointersFromBuffer(char* bufferOrigin, int numberOfLines, int lengthOfBuffer){
    assert(bufferOrigin);

    struct LineOfFile* sourceList =  calloc(numberOfLines,numberOfLines * sizeof(struct LineOfFile*));
    int currentLine = 0;
    int startOfLine = 0;
    int lenOfCurrentLine = 0;

    for (int i = 0; i < lengthOfBuffer; i++){

        lenOfCurrentLine++;
        if(bufferOrigin[i] == '\n')
        {
            bufferOrigin[i] = '\0';
            sourceList[currentLine].lenOfLine = lenOfCurrentLine;
            sourceList[currentLine].line      = &bufferOrigin[startOfLine];

            if((i + 1) < lengthOfBuffer - 2 ){
                startOfLine = i + 1;
                currentLine++;
            }
            lenOfCurrentLine = 0;
        }
    }
    return sourceList;
}

char* getBuffersFromSourceFile(int* length, char* nameOfFile){
    assert(nameOfFile);
    FILE* file = NULL;

    file = fopen(nameOfFile, "r");

    if (!file) {
        printf("failed to open file");
        exit(EXIT_FAILURE);
    }

    // define size of file
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *bufferOrigin = calloc(*length + 1, sizeof(bufferOrigin));

    if (bufferOrigin) {
        //read all file in bufferOrigin
        fread(bufferOrigin, 1, *length, file);
    }
    fclose(file);
    if(bufferOrigin != NULL)
        bufferOrigin[*length] = '\n';

    return bufferOrigin;
}





