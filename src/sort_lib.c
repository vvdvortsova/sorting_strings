/**
* @file         sort_lib.c
* @brief        Realization of methods for qsort and comparator
* @author       Dvortsova Varvara BSE182 HSE
* @include      assert.h, sort_lib.h,spandsp.h,ctype.h
*/

#include "sort_lib.h"
#include <ctype.h>
#include <assert.h>
#include <spandsp.h>

int isSorted(struct LineOfFile *numbers, int arraySize, enum HOW_TO_COMPARE_STRING howToCompareStr){
    assert(numbers != NULL);
    assert(arraySize > 0);
    for (int i = 0; i < arraySize - 1; ++i) {
        if(strcmpSortLib(numbers[i].line, numbers[i].lenOfLine, numbers[i + 1].line, numbers[i + 1].lenOfLine, howToCompareStr) > 0){
            return -1;
        }
    }
    return 1;
}
void quickSortSortLib(struct LineOfFile *numbers, int arraySize, enum HOW_TO_COMPARE_STRING howToCompareStr) {
    assert(numbers != NULL);
    assert(arraySize > 0);
    startQuickSortLib(numbers, 0, arraySize - 1, howToCompareStr);
}


int partitionSortLib(struct LineOfFile* arr, int start, int end,enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    struct LineOfFile pivot = arr[(start + end) / 2];
    int i = start;
    int j = end;

    for (;i <= j;)
    {
        //if i less than pivot go ahead
        if(strcmpSortLib(arr[i].line,arr[i].lenOfLine, pivot.line, pivot.lenOfLine, howToCompareStr) < 0)//<
        {
            do{i++;}
            while (strcmpSortLib(arr[i].line,arr[i].lenOfLine, pivot.line, pivot.lenOfLine, howToCompareStr) < 0);//<
            //if j more than pivot go back
        }
        if(strcmpSortLib(arr[j].line,arr[j].lenOfLine, pivot.line, pivot.lenOfLine, howToCompareStr) > 0)//>
        {
            do{j--;}
            while (strcmpSortLib(arr[j].line,arr[j].lenOfLine, pivot.line, pivot.lenOfLine, howToCompareStr) > 0);//>
        }
            //if i<=j swap
        if (i <= j)
        {
            SWAP(arr[i],arr[j]);
            i++;
            j--;
        }
    };
    return i;

}


void startQuickSortLib(struct LineOfFile* arr, int start, int end, enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    int pIndex = partitionSortLib(arr, start, end, howToCompareStr);
    if (start < pIndex - 1)
        startQuickSortLib(arr, start, pIndex - 1, howToCompareStr);
    if (pIndex < end)
        startQuickSortLib(arr, pIndex, end, howToCompareStr);
}



int strcmpSortLib( const char *s1, int len1, const char *s2,  int len2, enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    int i = 0, j = 0;

    switch(howToCompareStr){
        case LEFT_TO_RIGHT:
            while(i <= (len1 - 1) && !isalpha(s1[i]))
                ++i;

            while(j <= (len2 - 1) && !isalpha(s2[j]))
                ++j;

            for( ; s1[i] == s2[i]; ++i, ++j )
            {
                if (s1[i] == '\0' || s2[j] == '\0' )
                    break;

                while((i + 1) <= (len1 - 1) && !isalpha(s1[i + 1]))
                    ++i;

                while((j + 1) <= (len2 - 1) && !isalpha(s2[j + 1]))
                    ++j;
            }
            break;

        case RIGHT_TO_LEFT:
            i = len1;
            j = len2;
            do{
                    do i--;
                    while((i >= 0)&& !isalpha(s1[i]));
                    do j--;
                    while((j >= 0) && !isalpha(s2[j]));

            }while(((i > 0) && (j > 0)) && (s1[i] == s2[j]));
            break;

        default:
            return -1;
    }
    return (unsigned char) s1[i] - (unsigned char) s2[j];
}
