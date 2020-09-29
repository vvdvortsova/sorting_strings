//
// Created by vara on 29.09.2020.
//

#ifndef SORT_STRINGS_HELP_LIB_H
#define SORT_STRINGS_HELP_LIB_H

#include "sort_lib.h"

char* getBuffersFromSourceFile(int* length, char* nameOfFile);
struct LineOfFile* arrangePointersFromBuffer(char* origin, int numberOfLines, int lengthOfBuffer);
int getNumberOfLinesInBuffer(char* buffer, int length);
void putResultToFiles(struct LineOfFile* sourceOrigin, int linesCount, char* nameOfFile,
        enum HOW_TO_COMPARE_STRING howToCompare);


#endif //SORT_STRINGS_HELP_LIB_H
