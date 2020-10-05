/**
* @file         sort_lib.h
* @brief        Headers of methods for qsort and comparator
* @author       Dvortsova Varvara BSE182 HSE
*/

#ifndef SORT_STRINGS_SORT_LIB_H
#define SORT_STRINGS_SORT_LIB_H

/**
 * Macros define custom SWAP function for swaping two pointers
 * @param[in] item1 first elem to swap
 * @param[in] item2 second elem to swap
 * */
#define SWAP(item1, item2){\
        struct LineOfFile temp = (item1);\
        item1 = item2;\
        item2 = temp;\
}

/**
* @brief  Struct is keeping pointers to char*
*/
struct LineOfFile{
    char* start;/**< keeps point on the beginning of the line*/
    char* end;/**< keeps point on the end of the line*/
};

/*! This is an enum for defining the type of direction of sorting  */
enum HOW_TO_COMPARE_STRING{
    LEFT_TO_RIGHT,/*!< this is left to right sorting */
    RIGHT_TO_LEFT,/*!< this is right to left sorting */
    NONE_SORT/*!< this is no sorting type */
};

/**
* @brief       Sorts array
* @details     Implements the quicksort algorithm
* @param[in]   arr               array of struct LineOfFile*
* @param[in]   start             index of the beginning of the arr to sort
* @param[in]   end               index of the end of the arr to sort
* @param[in]   howToCompareStr   type of comparator
* @return                        pIndex
 */
int partitionSortLib(struct LineOfFile* arr, int start, int end,enum HOW_TO_COMPARE_STRING howToCompareStr);

/**
* @brief       Run qsort
* @param[in]   arr               array of struct LineOfFile*
* @param[in]   start             index of the beginning of the arr to sort
* @param[in]   end               index of the end of the arr to sort
* @param[in]   howToCompareStr   type of comparator
 */
void startQuickSortLib(struct LineOfFile* arr, int start, int end, enum HOW_TO_COMPARE_STRING howToCompareStr);


/**
* @brief       Methods overrides strcmp for struct LineOfFile*
* @param[in]   s1              first line
* @param[in]   len1            length of first line
* @param[in]   s2              second line
* @param[in]   len2            length of second line
* @param[in]   howToCompareStr type of comparator
* @return                      positive number if s1 > s2, negative number if s1 < s2 else 0
 */
int strcmpSortLib( struct LineOfFile* item1, struct LineOfFile* item2, enum HOW_TO_COMPARE_STRING howToCompareStr);

/**
* @brief       Checks if array with char* is in order
* @param[in]   numbers         array of struct LineOfFile*
* @param[in]   arraySize      number of items in numbers
* @param[in]   howToCompareStr type of comparator
* @return                      1 if numbers is in order, else -1
 */
int isSorted(struct LineOfFile* numbers, int arraySize, enum HOW_TO_COMPARE_STRING howToCompareStr);

#endif //SORT_STRINGS_SORT_LIB_H
