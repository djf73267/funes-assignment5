#include <cstdlib>
#include <time.h>
#include <iostream>
#include "randomizedQuickSort.h"
int rcount =0;
/*
 Parameter: int arr[], int low, int high
 Objective: Function rPartition and rPivot takes random element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot
 **/

int randomizedQuickSort::rPartition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            rcount++;
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int randomizedQuickSort::rPivot(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    std::swap(arr[random], arr[high]);

    return rPartition(arr, low, high);
}

/*
 Parameter: int arr[], int low, int high
 Objective: This function takes the return value of the partition method calls itself recursively
 and seperates the values based on the partition
 **/
int randomizedQuickSort::rquickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = rPivot(arr, low, high);

        rquickSort(arr, low, pi - 1);
        rquickSort(arr, pi + 1, high);

    }
return rcount;
}
