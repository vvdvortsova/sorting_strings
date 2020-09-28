//
// Created by vara on 17.09.2020.
//

#ifndef SORT_STRINGS_SORT_LIB_H
#define SORT_STRINGS_SORT_LIB_H

#include <spandsp.h>

#define SWAP(item1, item2){\
        struct LineOfFile temp = (item1);\
        item1 = item2;\
        item2 = temp;\
}

struct LineOfFile{
    char* line;
    unsigned int lenOfLine;
};

enum HOW_TO_COMPARE_STRING{
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT,
    NONE_SORT
};
int partitionSortLib(struct LineOfFile* arr, int start, int end,enum HOW_TO_COMPARE_STRING howToCompareStr);
void startQuickSortLib(struct LineOfFile* arr, int start, long end, enum HOW_TO_COMPARE_STRING howToCompareStr);
void quickSortSortLib(struct LineOfFile *numbers, long array_size,enum HOW_TO_COMPARE_STRING howToCompareStr);
int strcmpSortLib( const char *s1, int len1, const char *s2, int len2, enum HOW_TO_COMPARE_STRING howToCompareStr);
int isSorted(struct LineOfFile *numbers, long array_size,enum HOW_TO_COMPARE_STRING howToCompareStr);
#endif //SORT_STRINGS_SORT_LIB_H
