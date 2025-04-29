#include <stdio.h>
#include "include/functions.h"
#include "io.c"

int main (void){
  int a = 5;
  int b = 10;
  int result = my_fun(a, b);
  
  printf("The result of adding %d and %d is: %d\n", a, b, result);

  IOwrite(0x0001, (IOdata_t)result);
  IOdata_t read_result = IOread(0x0001);
  
  printf("The result read from IO is: %d\n", read_result);
  
  return 0;
}