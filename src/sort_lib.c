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

//bool isalphaSortLib(char* alpha){
//    if(isalpha(alpha))
//        return true;
//    else{
//        if((int)alpha == 0x04)
//        {
//            if((int)(alpha + 1) <= 0x4F)
//            {
//                //russian alpha!
//            }
//        } else  return false;
//
//    }
//    return  true;
//}

int isSorted(struct LineOfFile *numbers, int arraySize, enum HOW_TO_COMPARE_STRING howToCompareStr){
    assert(numbers != NULL);
    assert(arraySize > 0);
    for (int i = 0; i < arraySize - 1; ++i) {
        if(strcmpSortLib(&numbers[i],&numbers[i + 1], howToCompareStr) > 0){
            return -1;
        }
    }
    return 1;
}
//void quickSortSortLib(struct LineOfFile *numbers, int arraySize, enum HOW_TO_COMPARE_STRING howToCompareStr) {
//    assert(numbers != NULL);
//    assert(arraySize > 0);
//    startQuickSortLib(numbers, 0, arraySize - 1, howToCompareStr);
//}


int partitionSortLib(struct LineOfFile* arr, int start, int end,enum HOW_TO_COMPARE_STRING howToCompareStr)
{
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



int strcmpSortLib( struct LineOfFile* item1, struct LineOfFile* item2, enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    assert(item1 != NULL);
    assert(item2 != NULL);


    int i = 0, j = 0;


    switch(howToCompareStr){
        case LEFT_TO_RIGHT:
            while(item1->start[i] != '\0' && !isalpha(item1->start[i]))
                ++i;

            while(item2->start[j] != '\0'&& !isalpha(item2->start[j]))
                ++j;

            for( ; item1->start[i] == item2->start[i]; ++i, ++j )
            {
                if (item1->start[i] == '\0' || item2->start[j] == '\0' )
                    break;

                while(item1->start[i + 1] != '\0' && !isalpha(item1->start[i + 1]))
                    ++i;

                while(item2->start[j + 1] != '\0' && !isalpha(item2->start[j + 1]))
                    ++j;
            }
            return (unsigned char) item1->start[i] - (unsigned char) item2->start[j];

            case RIGHT_TO_LEFT:
                i--;
                j--;
            do{
                    do i--;
                    while(item1->end[i] != '\0' && !isalpha(item1->end[i]));
                    do j--;
                    while(item2->end[j] != '\0' && !isalpha(item2->end[j]));

            }while(((item1->end[i] != '\0') && (item2->end[j] != '\0')) && (item1->end[i] == item2->end[j]));

            return (unsigned char) item1->end[i] - (unsigned char) item2->end[j];


        default:
            return -1;
    }
}

