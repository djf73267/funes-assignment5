#include "mergeSort.h"
int count = 0;

/*
 Parameter: int arr[], int low, int mid, int high)
 Objective: This function creates two sub arrays
 and merges back from low to high
 **/
void mergeSort::merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    int* Left = new int[n1];
    int* Right = new int[n2];


    for (i = 0; i < n1; i++)
        Left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[mid + 1+ j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            count++;
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}


int mergeSort::mergeSorter(int arr [], int i, int j) {
    int mid;

    if (i < j) {
        mid = i+(j-i)/2;
        mergeSorter(arr,i, mid);
        mergeSorter(arr, mid+1, j);
        merge(arr, i, mid, j);
    }
    return count;
}
