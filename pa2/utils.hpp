#ifndef UTILS_HPP
#define UTILS_HPP

#include "performance.hpp"

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT     3
#define ALGQSORT3    4
#define ALGQSORTINS  5
#define ALGQSORT3INS 6
#define ALGSHELLSORT 7
#define ALGRECSEL    8

typedef struct alg{
  int num;
  char * name;
} alg_t;

alg_t algvet[]={
  {ALGINSERTION,"i"},
  {ALGSELECTION,"s"},
  {ALGQSORT,"q"},
  {ALGQSORT3,"q3"},
  {ALGQSORTINS,"qi"},
  {ALGQSORT3INS,"q3i"},
  {ALGSHELLSORT,"h"},
  {ALGRECSEL,"rs"},
  {0,0}
};

void swap(int *xp, int *yp, sortperf_t *s);
void initVector(int * vet, int size);
void printVector(int * vet, int size);
int median (int a, int b, int c);
int name2num(char * name);
char * num2name(int num);
void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);

#endif
