#include "../include/mathOps.h"
#include <stdio.h>

long long int recursiveFibonacci(int position) {
    if (position == 0 || position == 1)
        return position;
    
    return recursiveFibonacci(position - 1) + recursiveFibonacci(position - 2);
};

long long int iterativeFibonacci(int position) {
    long long int a = 0, b = 1, next;
    for (int i = 2; i <= position; i ++) {
        next = a + b;
        a = b;
        b = next;
    }
    return position == 0 ? a : b;
};

long long int recursiveFactorial(int value) {
    if (value <= 1)
        return 1;
    return value * recursiveFactorial(value - 1);
};

long long int iterativeFactorial(int value) {
    long long int result = 1;
    for (int i = 2; i <= value; i++) {
        result *= i;
    }

    return result;
};