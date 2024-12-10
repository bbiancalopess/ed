#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

extern alg_t algvet[];

typedef struct opt{
  int size;
  int seed;
  int alg;
} opt_t;

typedef struct sortperf{
  int cmp;
  int move;
  int calls;
} sortperf_t;

void resetcounter(sortperf_t * s);
void inccmp(sortperf_t * s, int num);
void incmove(sortperf_t * s, int num);
void inccalls(sortperf_t * s, int num);
char * printsortperf(sortperf_t * s, char * str, char * pref);

int name2num(char *name);
char *num2name(int num);
void parse_args(int argc, char **argv, opt_t *opt);
void swap(int *xp, int *yp, sortperf_t *s);
void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);
void uso();
void initVector(int * vet, int size);
void printVector(int * vet, int size);


#endif