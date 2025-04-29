#include "include/functions.h"
#include "include/extra_fun.h"

int my_fun(int a, int b){
  return (a+b);
}

int complex_fun(int a){
  int b  = other_fun(a);
  
  return b;
}