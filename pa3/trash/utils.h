#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int name2num(char *name);
char *num2name(int num);
void parse_args(int argc, char **argv, opt_t *opt);
void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);
void uso();
void initVector(int * vet, int size);
void printVector(int * vet, int size);


#endif