#include "../include/mathOps.h"
#include <stdio.h>

long int recursiveFibonacci(int position) {
    if (position == 0 || position == 1)
        return position;
    
    return recursiveFibonacci(position - 1) + recursiveFibonacci(position - 2);
};

long int iterativeFibonacci() {
    return 0;
};

long int recursiveFactorial() {
    return 0;
};

long int iterativeFactorial() {
    return 0;
};