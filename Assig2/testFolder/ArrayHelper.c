/**
 * @author Ben Hylak
 *
 * Array Helper class. Contains functions to sort an array using Quick Sort algorithm.
 */

#include "ArrayHelper.h"
#include <stdio.h>

/**Partitions a segment of an array around a pivot number and then returns a pivot index that the array is partitioned around
 * @param left Lower bound of segment
 * @param high Upper bound of segment
 * @param Pivot value used to split segment
 * @return Index of new pivot*/
int partition(int arr[], int left, int right, int pivot)
{
    while(left<right)
    {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;

        if(left<=right)
        {
            swap(&arr[left], &arr[right]);  
            if(arr[left] == arr[right]) left++;
        }
    }

    return right;
}

/**Swaps the values of two pointers
 * @param element1 The first pointer
 * @param element2 The second pointer
 */
void swap(int* element1, int* element2)
{
    int tempVar = *element1;
    
    *element1 = *element2;
    *element2 = tempVar;
}

/**Quick sort function that takes low and high bounds for sort. (Used for sorting segments of an array) Sorts in place.
 * @param arr Array that segment belongs to
 * @param low Lower bound of segment
 * @param high Upper bound of segment
 */
void quickSortHelper(int arr[], int low, int high)
{
    if(low>=high) return;

    int pivLoc = (high+low)/2;
    int pivot = arr[pivLoc];

    int newPivLoc = partition(arr, low, high, pivot);

    quickSortHelper(arr, low, newPivLoc-1);
    quickSortHelper(arr, newPivLoc+1, high);
}

/**Sorts an array in ascending order using quick sort algorithm, in place.
 * @param arr Array to be sorted
 * @param size Size of array
 */
void quickSort(int arr[], int size)
{
    quickSortHelper(arr, 0, size-1);
}

