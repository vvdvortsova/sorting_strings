/**
* @file         help_lib.h
* @brief        Headers of methods for helping functions in main and tests
* @author       Dvortsova Varvara BSE182 HSE
* @include      sort_lib.h
*/
#ifndef SORT_STRINGS_HELP_LIB_H
#define SORT_STRINGS_HELP_LIB_H

#include "sort_lib.h"

/**
* @brief       Method gets char* buffer from File
* @param[out]  length      size of buffer
* @param[in]   nameOfFile  name of file
* @return                  buffer with bytes
 */
char* getBuffersFromSourceFile(int* length, char* nameOfFile);

/**
* @brief       Method places pointers from the structure
*               to the beginning of the lines in the buffer
* @details     Struct LineOfFiles char* line keeps pointer of the beginning of the line in the buffer
*               and lenOfLine keeps size of this line
* @param[in]   origin           buffer with bytes
* @param[in]   numberOfLines
* @param[in]   lengthOfBuffer
* @return                      struct LineOfFile*
*/
struct LineOfFile* arrangePointersFromBuffer(char* origin, int numberOfLines, int lengthOfBuffer);

/**
* @brief       Method gets number of lines in buffer
* @param[in]   buffer
* @param[in]   length   number of bytes in buffer
* @return               number of lines in buffer
 */
int getNumberOfLinesInBuffer(char* buffer, int length);

/**
* @brief       Method puts strings from sourceOrigin to file
* @details     Methods doesnt put empty strings
* @param[in]   sourceOrigin
* @param[in]   linesCount
* @param[in]   nameOfFile
* @param[in]   howToCompare
 */
void putResultToFiles(struct LineOfFile* sourceOrigin, int linesCount, char* nameOfFile,
        enum HOW_TO_COMPARE_STRING howToCompare);


#endif //SORT_STRINGS_HELP_LIB_H
