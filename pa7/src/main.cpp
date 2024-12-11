#include <iostream>
/*
void parseArguments(int argc, char ** argv) {
  extern char * optarg;
  int c;

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
*/
int main (int argc, char ** argv) {

    std::cout << argc << " " << argv[0] << " " << argv[1] << " " << argv[2];


    return 0;
}