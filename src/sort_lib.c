/**
* @file         sort_lib.c
* @brief        Realization of methods for qsort and comparator
* @author       Dvortsova Varvara BSE182 HSE
* @include      assert.h, sort_lib.h, stdio.h, ctype.h, sort_lib.h
*/

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include "sort_lib.h"

int isSorted(struct LineOfFile *numbers, int arraySize, enum HOW_TO_COMPARE_STRING howToCompareStr){
    assert(numbers != NULL);
    assert(arraySize > 0);
    for (int i = 0; i < arraySize - 1; ++i){
        if(strcmpSortLib(&numbers[i],&numbers[i + 1], howToCompareStr) > 0){
            return -1;
        }
    }
    return 1;
}

int partitionSortLib(struct LineOfFile* arr, int start, int end,enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    assert(arr != NULL);
    struct LineOfFile pivot = arr[(start + end) / 2];
    int i = start;
    int j = end;
    for (;i <= j;)
    {
        //if i less than pivot go ahead
        if(strcmpSortLib(&arr[i], &pivot, howToCompareStr) < 0)//<
        {
            do{i++;}
            while (strcmpSortLib(&arr[i], &pivot, howToCompareStr) < 0);//<
            //if j more than pivot go back
        }
        if(strcmpSortLib(&arr[j], &pivot, howToCompareStr) > 0)//>
        {
            do{j--;}
            while (strcmpSortLib(&arr[j], &pivot, howToCompareStr) > 0);//>
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
    assert(arr != NULL);
    int pIndex = partitionSortLib(arr, start, end, howToCompareStr);
    if (start < pIndex - 1)
        startQuickSortLib(arr, start, pIndex - 1, howToCompareStr);
    if (pIndex < end)
        startQuickSortLib(arr, pIndex, end, howToCompareStr);
}



int strcmpSortLib( struct LineOfFile* item1, struct LineOfFile* item2, enum HOW_TO_COMPARE_STRING howToCompareStr){
    assert(item1 != NULL);
    assert(item2 != NULL);
    assert(item1 != item2);
    switch(howToCompareStr){
        case LEFT_TO_RIGHT:
            return compareLeftToRight(item1, item2);
            case RIGHT_TO_LEFT:
            return compareRightToLeft(item1, item2);
        default:
            return -1;
    }
}

int compareRightToLeft(struct LineOfFile* item1, struct LineOfFile* item2){
    assert(item1 != NULL);
    assert(item2 != NULL);
    assert(item1 != item2);
    while(1){
        while((item1->end > item1->start) && isalpha(*item1->end ) == 0)
            item1->end--;
        while((item2->end > item2->start) && isalpha(*item2->end ) == 0)
            item2->end--;
        if(*item2->end == '\0'&&*item1->end == '\0')
            return  0;
        else if(*item1->end == '\0')
            return -1;
        else if(*item2->end == '\0')
            return 1;
        else
            return tolower((*item1->end) ) - tolower((*item2->end));
    }
}
int compareLeftToRight(struct LineOfFile *item1, struct LineOfFile *item2){
    assert(item1 != NULL);
    assert(item2 != NULL);
    assert(item1 != item2);
    int i = 0, j =0;
    while(item1->start[i] != '\0' && isalpha(item1->start[i]) == 0)
        ++i;
    while(item2->start[j] != '\0'&& isalpha(item2->start[j]) == 0)
        ++j;
    for( ; tolower(item1->start[i]) == tolower(item2->start[j]); ++i, ++j )
    {
        if (item1->start[i] == '\0' || item2->start[j] == '\0' )
            break;

        while(item1->start[i + 1] != '\0' && isalpha(item1->start[i + 1]) == 0)
            ++i;

        while(item2->start[j + 1] != '\0' && isalpha(item2->start[j + 1]) == 0)
            ++j;
    }
    return tolower(item1->start[i]) - tolower(item2->start[j]);
}

