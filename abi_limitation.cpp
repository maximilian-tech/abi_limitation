#include <benchmark/benchmark.h>


void doNotOptimize(void* val) {
    asm volatile("" : : "m"(val) : "memory");
}

__attribute__((noinline))
static void my_func_5( 
  void* A,
  void* B,
  void* C,
  void* D,
  void* E
  //void* G
){
  doNotOptimize(A);
  doNotOptimize(B);
  doNotOptimize(C);
  doNotOptimize(D);
  doNotOptimize(E);
  
  //doNotOptimize(G);
}

static void BM_FunctionCall_arg5(benchmark::State& state)
{
  void *A, *B, *C, *D, *E;
  for (auto _ : state)
    my_func_5(A,B,C,D,E);
}

__attribute__((noinline))
static void my_func_6( 
  void* A,
  void* B,
  void* C,
  void* D,
  void* E,
  void* F
  //void* G
){
  doNotOptimize(A);
  doNotOptimize(B);
  doNotOptimize(C);
  doNotOptimize(D);
  doNotOptimize(E);
  doNotOptimize(F);
  //doNotOptimize(G);
}

static void BM_FunctionCall_arg6(benchmark::State& state)
{
  void *A, *B, *C, *D, *E, *F;
  for (auto _ : state)
    my_func_6(A,B,C,D,E,F);
}

__attribute__((noinline))
static void my_func_7( 
  void* A,
  void* B,
  void* C,
  void* D,
  void* E,
  void* F,
  void* G
){
  doNotOptimize(A);
  doNotOptimize(B);
  doNotOptimize(C);
  doNotOptimize(D);
  doNotOptimize(E);
  doNotOptimize(F);
  doNotOptimize(G);
}

static void BM_FunctionCall_arg7(benchmark::State& state)
{
  void *A, *B, *C, *D, *E, *F, *G;
  for (auto _ : state)
    my_func_7(A,B,C,D,E,F,G);
}

BENCHMARK(BM_FunctionCall_arg7);
BENCHMARK(BM_FunctionCall_arg6);
BENCHMARK(BM_FunctionCall_arg5);

BENCHMARK_MAIN();
