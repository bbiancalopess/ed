#include "algorithms.hpp"
#include "performance.hpp"
#include "utils.hpp"

// standard quicksort
void quickSort(int * A, int l, int r, sortperf_t *s) { 
}

// quicksort with median of 3
void quickSort3(int * A, int l, int r, sortperf_t *s) { 
}

// quicksort with insertion for small partitions
void quickSortIns(int * A, int l, int r, sortperf_t *s) { 
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int * A, int l, int r, sortperf_t *s) { 
}


// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s)
{
    // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    int min = l;
    inccalls(s,1);
    for (int j = l + 1; j <= r; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
	inccmp(s,1);
        if (arr[j] < arr[min]) {
            min = j;    // update the index of minimum element
        }
    }

    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    if (min!=l)
      swap(&arr[min], &arr[l], s);

    if (l + 1 < r) {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t * s) { 
  return;
}

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  return;
}

// shellsort
void shellSort(int *A, int n, sortperf_t * s) {
}

// quicksort partition using median of 3
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
}

// standard quicksort partition
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
}