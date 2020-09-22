//
// Created by vara on 17.09.2020.
//

#include "sort_lib.h"
#include <ctype.h>


void quickSortSortLib(struct LineOfFile *numbers, long array_size,enum HOW_TO_COMPARE_STRING howToCompareStr) {
    startQuickSortLib(numbers, 0, array_size - 1, howToCompareStr);
}


int partitionSortLib(struct LineOfFile* arr, int start, int end,enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    struct LineOfFile* pivot = &arr[(start + end) / 2];
    int i = start;
    int j = end;
    for (;i <= j;)
    {
        //if i less than pivot go ahead
        if(strcmpSortLib(arr[i].line,arr[i].lenOfLine, pivot->line, pivot->lenOfLine, howToCompareStr) < 0)//<
        {
            do{i++;}
            while (strcmpSortLib(arr[i].line, arr[i].lenOfLine, pivot->line, pivot->lenOfLine, howToCompareStr) < 0);//<
            //if j more than pivot go back
        }
        else if(strcmpSortLib(arr[j].line, arr[j].lenOfLine, pivot->line, pivot->lenOfLine, howToCompareStr) > 0)//>
        {
            do{j--;}
            while (strcmpSortLib(arr[j].line, arr[j].lenOfLine, pivot->line, pivot->lenOfLine, howToCompareStr) > 0);//>
        }
            //if i<=j swap
        else if (i <= j)
        {
            SWAP(&arr[i],&arr[j]);
            i++;
            j--;
        }
    };
    return i;

}


void startQuickSortLib(struct LineOfFile* arr, int start, long end, enum HOW_TO_COMPARE_STRING howToCompareStr)
{
    int pIndex = partitionSortLib(arr, start, end, howToCompareStr);
    if (start < pIndex - 1)
        startQuickSortLib(arr, start, pIndex - 1, howToCompareStr);
    if (pIndex < end)
        startQuickSortLib(arr, pIndex, end, howToCompareStr);
}



int strcmpSortLib( const char *s1, const int len1, const char *s2, const int len2, enum HOW_TO_COMPARE_STRING howToCompareStr)
{

    int i = 0,j = 0;
    switch(howToCompareStr){
        case LEFT_TO_RIGHT:
            while((i) <= (len1 - 1) && !isalpha(s1[i])){
                ++i;
            }
            while((j) <= (len2 - 1) && !isalpha(s2[j])){
                ++j;
            }
            for( ; *s1 == *s2; ++s1, ++s2 )
            {

                if (s1[i] == '\0' && s2[j] == '\0'){
                    return 0;
                }
                if (s1[i] == '\0' || s2[j] == '\0' ){
                    return (unsigned char) s1[i] - (unsigned char) s2[j];
                }
                while((i + 1) <= (len1 - 1) && !isalpha(s1[i + 1])){
                    ++i;
                }
                while((j + 1) <= (len2 - 1) && !isalpha(s2[j + 1])){
                    ++j;
                }
            }
            break;
        case RIGHT_TO_LEFT:
            i = len1 - 1;
            j = len2 - 1;
            while((i) >= 0 && !isalpha(s1[i])){
                --i;
            }
            while((j) >= 0 && !isalpha(s2[j])){
                --j;
            }
            for( ; tolower(s1[i]) == tolower(s2[j]); --i, --j){

                if (s1[i] == '\0' && s2[j] == '\0'){
                    return 0;
                }
                if (s1[i] == '\0' || s2[j] == '\0' ){
                    return (unsigned char) s1[i] - (unsigned char) s2[j];
                }
                while((i - 1) >= 0 && !isalpha(s1[i-1])){
                    --i;
                }
                while((j-1) >= 0 && !isalpha(s2[j - 1])){
                    --j;
                }
            }
            break;
    };
    return (unsigned char) s1[i] - (unsigned char) s2[j];
}
