#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

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

#endif 