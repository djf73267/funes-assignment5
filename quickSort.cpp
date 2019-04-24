//quickSort.cpp
#include <algorithm>
#include <math.h>
#include "quickSort.h"
int compares =0;
/*
 Parameter: int arr[], int low, int high
 Objective: This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot
 **/
int quickSort::partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            compares++;
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/*
 Parameter: int arr[], int low, int high
 Objective: This function takes the return value of the partition method calls itself recursively
 and seperates the values based on the partition
 **/
int quickSort::quickSorter(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSorter(arr, low, pi - 1);
        quickSorter(arr, pi + 1, high);

    }
return compares;
}
