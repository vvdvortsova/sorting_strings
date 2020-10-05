/**
* @file         help_lib.c
* @brief        Realization of methods for helping functions in main and test
* @author       Dvortsova Varvara BSE182 HSE
* @include      help_lib.h, stdio.h, stdlib.h, locale.h, assert.h, help_lib.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>
#include "help_lib.h"

void putResultToFiles(struct LineOfFile *sourceOrigin, int linesCount, char* nameOfFile,
        enum HOW_TO_COMPARE_STRING howToCompare){
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
        if(*sourceOrigin[i].start != '\0')
            fprintf(fileToWriteResult,"%s\n", sourceOrigin[i].start);
    fclose(fileToWriteResult);
}

int getNumberOfLinesInBuffer(char *buffer, int length){
    assert(buffer);
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
            sourceList[currentLine].start      = &bufferOrigin[startOfLine];
            sourceList[currentLine].end = &bufferOrigin[i];

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
        printf("failed to open file %s", nameOfFile);
        exit(EXIT_FAILURE);
    }

    // define size of file
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *bufferOrigin = calloc(*length + 1, sizeof(bufferOrigin));

    if (bufferOrigin) {
        //read all file in bufferOrigin
        int res = fread(bufferOrigin, 1, *length, file);
        if(res != *length)
            exit(EXIT_FAILURE);
    }
    fclose(file);
    if(bufferOrigin != NULL)
        bufferOrigin[*length] = '\n';
    return bufferOrigin;
}





