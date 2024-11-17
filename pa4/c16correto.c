#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b){
  int c;
  if (b == 0) {
    fprintf(stderr, "Error: Divisao por zero nao e permitida.\n");
    return -1; 
  }
  c=a/b;
  return 0;
}

int calc(){
  int a;
  int b;
  a=13;
  b=0;
  if (actual_calc(a, b) != 0) {
    fprintf(stderr, "Calculo falhou devido a valor invalido.\n");
  }
  return 0;
}

int main(){
  calc();
  return 0;
}
