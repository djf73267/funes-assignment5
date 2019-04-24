#include <algorithm>
#include "heapSort.h"
void heapSort::heapify(int arr[], int bottom, int root,int &count)
{
    // Pre:  root is the index of a node that may violate the heap order property
    // Post:  Heap order property is restored between root and bottom
    int maxChild = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;
    if (leftChild  <=  bottom) {
        if(leftChild  ==  bottom){
            maxChild  = leftChild;
            count++;
        }
        else{
            if(arr[leftChild] <=  arr [rightChild]){
                maxChild  =  rightChild ;
                count++;
            }
            else{
                maxChild  = leftChild ;
                count++;
            }
            
        }
        if(arr[root] < arr[maxChild])
        {
            std::swap(arr[root], arr[maxChild]);
            heapify(arr, bottom,maxChild,count);
        }
    }
    
    
    
    

//    if (leftChild < bottom && arr[leftChild] > arr[maxChild]){
//        maxChild = leftChild;
//        count ++;
//    }
//
//    if (rightChild < bottom && arr[rightChild] > arr[maxChild]) {
//        maxChild = rightChild;
//        count ++;
//    }
//
//    if (maxChild != root) {
//        std::swap(arr[root], arr[maxChild]);
//
//        heapify(arr, bottom, maxChild, count);
//    }
}

//  heap sort function
int heapSort::heapSorting(int arr[], int bottom)
{
    int count = 0;
   // convert array arr into a heap
    for (int root = bottom / 2 - 1; root >= 0; root--)
        heapify(arr, bottom, root, count);

    //sort array
    for (int root = bottom - 1; root >= 0; root--) {
        std::swap(arr[0], arr[root]);
        heapify(arr, root, 0, count);
    }
    return count;
}



