#include "../include/mathOps.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define FIBONACCI 1
#define FACTORIAL 2

typedef struct Algorithm{
  int id;
  const char * name;
} Algorithm;

typedef struct Options{
  int value;
  int algorithm;
  int isRecursive;
  int isIterative;
} Options;

Algorithm algorithms[] = {
  {FIBONACCI,"fi"},
  {FACTORIAL,"fa"},
  {0, NULL}
};

void printUsage() {
  fprintf(stderr, "Uso: programa [opções]\n");
  fprintf(stderr, "Opções:\n");
  fprintf(stderr, "\t-a <fi|fa>\tSeleciona o algoritmo (fi para Fibonacci, fa para Fatorial)\n");
  fprintf(stderr, "\t<-r|-i>\t\tExecuta de forma recursiva ou iterativa\n");
  fprintf(stderr, "\t-v <int>\tDefine o valor a ser calculado\n");
  fprintf(stderr, "\t-h\t\tExibe esta ajuda\n");
}

int getAlgorithmId(const char * name){
  for (int i = 0; algorithms[i].id != 0; i++) {
    if (strcmp(algorithms[i].name, name) == 0) return algorithms[i].id;
  }
  return 0;
}

void parseArguments(int argc, char ** argv, Options * opt) {
  extern char * optarg;
  int c;

  // inicializacao variaveis globais para opcoes
  opt->value = 0;
  opt->algorithm = 0;
  opt->isIterative = 0;
  opt->isRecursive = 0;

  // Processamento de argumentos com getopt
  while ((c = getopt(argc, argv, "a:riv:h")) != -1){
    switch(c) {
      case 'a':
        opt->algorithm = getAlgorithmId(optarg);
        break;
      case 'r':
        opt->isRecursive = 1;
        opt->isIterative = 0;
        break;
      case 'i':
        opt->isRecursive = 0;
        opt->isIterative = 1;
        break;
      case 'v':
        opt->value = atoi(optarg);
        if (opt->value < 0) {
          fprintf(stderr, "Erro: O valor deve ser maior ou igual a 0.\n");
          printUsage();
          exit(EXIT_FAILURE);
        }
        break;
      case 'h':
      default:
        printUsage();
        exit(EXIT_FAILURE);
    }
  }
  // Verifica se o algoritmo foi especificado
  if (opt->algorithm == 0) {
    fprintf(stderr, "Erro: Algoritmo nao especificado.\n");
    printUsage();
    exit(EXIT_FAILURE);
  }

  if (!(opt->isRecursive || opt->isIterative)) {
    fprintf(stderr, "Erro: Escolha entre execução recursiva (-r) ou iterativa (-i).\n");
    printUsage();
    exit(EXIT_FAILURE);
  }
}

int main (int argc, char ** argv){
  Options opt;
  parseArguments(argc, argv, &opt);
  long int response;
  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  switch (opt.algorithm){
    case FIBONACCI:
      if (opt.isRecursive == 1) response = recursiveFibonacci(opt.value);
      else response = iterativeFibonacci(opt.value);
      break;
    case FACTORIAL:
      if (opt.isRecursive == 1) response = recursiveFactorial(opt.value);
      else response = iterativeFactorial(opt.value);
      break;
    default:
      fprintf(stderr, "Erro: Algoritmo desconhecido.\n");
      printUsage();
      exit(EXIT_FAILURE);
  }

  clock_gettime(CLOCK_MONOTONIC, &end);

  double elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1e6;
  printf("Valor retornado: %ld\n", response);
  printf("Tempo de execução: %f ms\n", elapsed);

  return EXIT_SUCCESS;
}
