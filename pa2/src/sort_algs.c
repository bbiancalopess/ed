#include "../include/utils.h"
#include "../include/sort_algs.h"

// shellsort
void shellSort(int *A, int n, sortperf_t * s) {
  inccalls(s, 1);
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      incmove(s, 1);
      int temp = A[i];
      int j;
      inccmp(s, 1);
      for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
        A[j] = A[j - gap];
        inccmp(s, 1);
        incmove(s, 1);
      }
      A[j] = temp;
      incmove(s, 1);
    }
  }
}

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s)
{
    int min = l;
    inccalls(s,1);
    for (int i = l + 1; i <= r; i++) {
	    inccmp(s,1);
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    if (min!=l)
      swap(&arr[min], &arr[l], s);

    if (l + 1 < r) {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t * s) { 
  inccalls(s, 1);
  for (int i = 0; i < r; i++) {
    int min = i;
    for (int j = i + 1; j <= r; j++) {
      inccmp(s, 1);
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i)
      swap(&arr[i], &arr[min], s);
  }
}

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  inccalls(s, 1);
  for (int i = l + 1; i <= r; i++) {
    int aux = v[i];
    int j = i - 1;
    inccmp(s, 1);
    incmove(s, 1);
    while (j >= 0 && aux < v[j]) {
      v[j + 1] = v[j];
      inccmp(s, 1);
      incmove(s, 1);
      j--;
    }
    v[j + 1] = aux;
    incmove(s, 1);
  }
}

// standard quicksort partition
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
  *i = l;
  *j = r;
  int pivo = A[(*i + *j) / 2];
  inccalls(s, 1);
  do {
    inccmp(s, 1);
    while (pivo > A[*i]) {
      (*i)++;
      inccmp(s, 1);
    }
    inccmp(s, 1);
    while (pivo < A[*j]) {
      (*j)--;
      inccmp(s, 1);
    }
    if (*i <= *j) {
      swap(&A[*i], &A[*j], s);
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

// standard quicksort
void quickSort(int * A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  int i, j;
  partition(A, l, r, &i, &j, s);
  if(l < j) {
    quickSort(A, l, j, s);
  }
  if (i < r) {
    quickSort(A, i, r, s);
  }
}

// median of 3 integers
int median (int a, int b, int c) {
    if ((a <= b) && (b <= c)) return b;  // a b c
    if ((a <= c) && (c <= b)) return c;  // a c b
    if ((b <= a) && (a <= c)) return a;  // b a c
    if ((b <= c) && (c <= a)) return c;  // b c a
    if ((c <= a) && (a <= b)) return a;  // c a b
    return b;                            // c b a
}

// quicksort partition using median of 3
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
  int mid = (r + l) / 2;
  int pivo = median(A[l], A[mid], A[r]);

  *i = l;
  *j = r;

  inccalls(s, 1);
  do {
    inccmp(s, 1);
    while (pivo > A[*i]) {
      (*i)++;
      inccmp(s, 1);
    }
    inccmp(s, 1);
    while (pivo < A[*j]) {
      (*j)--;
      inccmp(s, 1);
    }
    if (*i <= *j) {
      swap(&A[*i], &A[*j], s);
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

// quicksort with median of 3
void quickSort3(int * A, int l, int r, sortperf_t *s) { 
  inccalls(s, 1);
  int i, j;
  partition3(A, l, r, &i, &j, s);
  if(l < j) {
    quickSort3(A, l, j, s);
  }
  if (i < r) {
    quickSort3(A, i, r, s);
  }
}

// quicksort with insertion for small partitions
void quickSortIns(int * A, int l, int r, sortperf_t *s) { 
  int i, j;
  inccalls(s,1);
  partition(A, l, r, &i, &j, s);
  if(l<j){
    if (j-l <=50) insertionSort(A,l,j,s);
    else quickSortIns(A,l,j,s); 
  }
  
  if(i<r){
    if (r-i <=50) insertionSort(A,i,r,s);
    else quickSortIns(A,i,r,s);  
  }
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int * A, int l, int r, sortperf_t *s) { 
  int i, j;
  inccalls(s,1);
  partition3(A, l, r, &i, &j, s);
  if(l<j){
    if (j-l <=50) insertionSort(A,l,j,s);
    else quickSort3Ins(A,l,j,s); 
  }
  
  if(i<r){
    if (r-i <=50) insertionSort(A,i,r,s);
    else quickSort3Ins(A,i,r,s);  
  }
}