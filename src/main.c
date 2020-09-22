#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <spandsp.h>
#include "sort_lib.h"


int main() {

    enum HOW_TO_COMPARE_STRING howToCompareStr = LEFT_TO_RIGHT;
    struct LineOfFile* sourceList = NULL;
    setlocale(LC_ALL, "ru_RU.cp1251");
    //read source file
    FILE* file = NULL;
    char* buffer = NULL;
    long length = 0;
    long currentLine = 0;
    long i = 0;

    file = fopen("../source.txt", "r");

    if (!file) {
        printf("failed to open file");
        exit(EXIT_FAILURE);
    }

    // define size of file
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = calloc(length, sizeof(buffer));
    if (buffer) {
        //read all file in buffer
        fread(buffer, 1, length, file);
    }
    fclose(file);

    if (!buffer) {
        printf("read nothing");
        exit(EXIT_FAILURE);
    }

    long linesCount = 1;

    // count amount of lines
    for (i = 0; i < length; i++) {
        if((i + 1) == (length - 1 )|| i == (length - 1 ))
            if(buffer[i + 1] == '\n'||buffer[i] == '\n')
                break;
        if(buffer[i] == '\n')
            linesCount++;
        while(buffer[i] == '\n' && i < (length - 1))
            i++;
    }

    if(linesCount >= length){
        linesCount = 0;
    }

    printf("Lines count: %d\n", (int)linesCount);
    sourceList =  calloc(linesCount,linesCount * sizeof(struct LineOfFile*));
    currentLine = 0;
    int startOfLine = 0;
    int lenOfCurrentLine = 0;
    for (i = 0; i < length; i++) {
        startOfLine = i;// remember point of the beginning of current line
        lenOfCurrentLine = 0;
        for (int j = i + 1; j < length; ++j) {
            if(buffer[j] == '\n'|| (i + 1) == length - 1)
            {
                buffer[j] = '\0';
                lenOfCurrentLine++;
                break;
            }
            lenOfCurrentLine++;
        }

        sourceList[currentLine].lenOfLine = lenOfCurrentLine;
        sourceList[currentLine].line = calloc(lenOfCurrentLine, sizeof(char*));

        memcpy(sourceList[currentLine].line, &buffer[startOfLine], lenOfCurrentLine);

        currentLine++;
        i += lenOfCurrentLine;

    }
    free(buffer);

    //copy array with pointers

    struct LineOfFile* listWithWordsForSort = NULL;
    listWithWordsForSort = calloc(linesCount, linesCount * sizeof(char*));
    for (int k = 0; k < linesCount ; ++k) {
        listWithWordsForSort[k] = sourceList[k];
    }


    // Имеем массив lines в котором linesCount строк
    for (i = 0; i < linesCount; i++){
        printf("len = %d %s\n", sourceList[i].lenOfLine, sourceList[i].line);
    }

    quickSortSortLib(sourceList, currentLine, howToCompareStr );

    FILE* fileToWriteResult = NULL;
    fileToWriteResult = fopen("../result.txt", "w");

    if (!fileToWriteResult){
        printf("failed to open file");
        exit(42);
    }

    for (int l = 0; l < linesCount; ++l){
        fprintf(fileToWriteResult,"%s \n",sourceList[l].line);
    }
    fclose(fileToWriteResult);
    for (i = 0; i < linesCount; i++) {
        free(listWithWordsForSort[i].line);
    }
    for (i = 0; i < linesCount; i++) {
        free(sourceList[i].line);
    }
    free(sourceList);
    free(listWithWordsForSort);


    exit(EXIT_SUCCESS);
}






