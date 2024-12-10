#include "../include/mathOps.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

#define ITERATIVE_FIBONACCI 1
#define RECURSIVE_FIBONACCI 2
#define ITERATIVE_FACTORIAL 3
#define RECURSIVE_FACTORIAL 4

typedef struct Algorithm{
  int id;
  const char * name;
} Algorithm;

typedef struct Options{
  int value;
  int algorithm;
} Options;

Algorithm algorithms[] = {
  {ITERATIVE_FIBONACCI,"fii"},
  {RECURSIVE_FIBONACCI,"fir"},
  {ITERATIVE_FACTORIAL,"fai"},
  {RECURSIVE_FACTORIAL,"far"},
  {0, NULL}
};

void printUsage() {
  fprintf(stderr, "Uso: programa [opções]\n");
  fprintf(stderr, "Opções:\n");
  fprintf(stderr, "\t-a <fii|fir|fai|far>\tSeleciona o algoritmo (fii para Fibonacci Iterativo, fir para Fibonacci Recursivo, fai para Fatorial Iterativo, far para Fatorial Recursivo)\n");
  fprintf(stderr, "\t-v <int>\tDefine o valor a ser calculado\n");
  fprintf(stderr, "\t-h\t\tExibe esta ajuda\n");
}

int getAlgorithmId(const char * name){
  for (int i = 0; algorithms[i].id != 0; i++) {
    if (strcmp(algorithms[i].name, name) == 0) return algorithms[i].id;
  }
  return 0;
}

const char * getAlgorithmNameById(int id) {
  for (int i = 0; algorithms[i].id != 0; i++) {
    if(algorithms[i].id == id) return algorithms[i].name;
  }
  return "";
}

void parseArguments(int argc, char ** argv, Options * opt) {
  extern char * optarg;
  int c;

  // inicializacao variaveis globais para opcoes
  opt->value = 0;
  opt->algorithm = 0;

  // Processamento de argumentos com getopt
  while ((c = getopt(argc, argv, "a:v:h")) != -1){
    switch(c) {
      case 'a':
        opt->algorithm = getAlgorithmId(optarg);
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
}

int main (int argc, char ** argv){
  Options opt;
  parseArguments(argc, argv, &opt);
  long long int response;
  struct timespec start, end;
  struct rusage usage;

  clock_gettime(CLOCK_MONOTONIC, &start);

  getrusage(RUSAGE_SELF, &usage);

  switch (opt.algorithm){
    case RECURSIVE_FIBONACCI:
      response = recursiveFibonacci(opt.value);
      break;
    case ITERATIVE_FIBONACCI:
      response = iterativeFibonacci(opt.value);
      break;
    case RECURSIVE_FACTORIAL:
      response = recursiveFactorial(opt.value);
      break;
    case ITERATIVE_FACTORIAL:
      response = iterativeFactorial(opt.value);
      break;
    default:
      fprintf(stderr, "Erro: Algoritmo desconhecido.\n");
      printUsage();
      exit(EXIT_FAILURE);
  }

  getrusage(RUSAGE_SELF, &usage);

  clock_gettime(CLOCK_MONOTONIC, &end);

  double elapsed = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_nsec - start.tv_nsec) / 1000000.0);

  double userTime = usage.ru_utime.tv_sec * 1000.0 + usage.ru_utime.tv_usec / 1000.0;
  double systemTime = usage.ru_stime.tv_sec * 1000.0 + usage.ru_stime.tv_usec / 1000.0;

  FILE *fp = fopen("csv/tempos.csv", "a");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%s, %d, %f, %f, %f\n", getAlgorithmNameById(opt.algorithm), opt.value, userTime, systemTime, elapsed);
  fclose(fp);

  printf("Valor retornado: %lld\n", response);
  printf("Tempo de sistema: %f ms\n", systemTime);
  printf("Tempo de usuario: %f ms\n", userTime);

  return EXIT_SUCCESS;
}
