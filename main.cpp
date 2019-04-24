#include <iostream>
#include <fstream>

#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "randomizedQuickSort.h"
#include "heapSort.h"

using namespace std;

quickSort qS;
selectionSort sS;
mergeSort mS;
heapSort hS;
randomizedQuickSort rS;
int main(int argc, char *argv[])
{
    string filename;
    int i=0;
    int n, arr[10000];
    filename= argv[1];

    //ifstream inFile("random.txt");
    ifstream inFile(filename);

    if(!inFile)
        cout<<"can't openfile.";

    while(inFile>>n)
    {
        arr[i]=n;
        i++;
    }

    n = sizeof(arr) / sizeof(arr[0]);
    int opt;
    cout<<"1.Sort using Selection Sort.\n";
    cout<<"2.Sort using Merge Sort.\n";
    cout<<"3.Sort using Quick Sort(Last Pivot).\n";
    cout<<"4.Sort using Quick Sort(Random pivot).\n";
    cout<<"5.Sort using Heap Sort.\n";
    cout<<"Enter your Option: ";
    cin>>opt;

    int count = 0;

    switch(opt){
        case 1:
            count = sS.selectionSorting(arr, n);
            break;
        case 2:
            count = mS.mergeSorter(arr,0, n-1);
            break;
        case 3:
            count = qS.quickSorter(arr,0, n-1);
            break;
        case 4:
            count = rS.rquickSort(arr,0,n-1);
            break;
        case 5:
              count = hS.heapSorting(arr, n);
            break;
        default:
            cout<<"Invalid option";
    }

        cout << "Sorted array is \n" ;
        for (int i = 0; i < n; ++i)
              cout << arr[i] << " ";
        cout << "\n";
        cout<<"Number of comparisons: "<<count;
    return  0;
}
