#ifndef ARGS_HPP
#define ARGS_HPP

typedef struct opt{
  int size;
  int seed;
  int alg;
} opt_t;


void uso();
void parse_args(int argc, char ** argv, opt_t * opt);

#endif


