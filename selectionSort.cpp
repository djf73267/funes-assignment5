#include <iostream>
#include "selectionSort.h"
/*
 Parameter: int arr[] , int n
 Objective: This function takes attempts to find the minimum value and will compare to the value at the front
 and will decide if the value goes to the front
 **/

int selectionSort::selectionSorting(int arr[] , int n)
{
    //variable declared , comparsion to count number of comparsion done
    int comparsion = 0;
   
    int i, j, pos, temp;
    for (i = 0; i < n-1; i++)
    {
        pos = i;
        for (j = i+1; j < n; j++)
        {
            //increment comparsion
            comparsion++;
            if (arr[j] < arr[pos]){
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos]= temp;
    }
    return comparsion;
}
