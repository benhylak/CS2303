#include "ArrayHelper.h"
#include <stdio.h>

/**
 * @brief Prints average, min and max of array.
 *
 * Prints average, min and max of array "arr". If size is <=0, an error is printed and -1 is returned. Otherwise, 0 is returned.
 *
 * @param arr The array to run the function on
 * @param size The size of the array
 * @return int 
 */

int printAvgMaxMin(int* arr, int size)
{
    if(size<=0)
    {
        printf("Array of size %d is not a valid input for this function", size);
        return -1; //error
    }
    else
    {
        int minSet = 0; //variable to store if min has been set yet
        int maxSet = 0; //variable to store if max has been set yet

        int min; //min value in arr
        int max; //max value in arr
        int sum = 0; //sum of all vals in arr

        for(int i=0; i<size; i++)
        {
            int tempNum = arr[i];
            
            if(tempNum<min || !minSet) //if current val is less than min or min hasn't been set yet 
            {
                min = tempNum;
                minSet = 1; //record that min has been set
            }

            if(tempNum>max || !maxSet) //if current val is greater than max or max hasn't been set yet
            {
                max = tempNum;
                maxSet = 1; //record that max has been set
            }
            
            sum += tempNum; //sum tempNum with the rest
        }

        int avgNum = sum/size;

        printf("Minimum: %d Maximum: %d Average: %d\n", min, max, avgNum);

        return 0; //success
    }       
}
