#include <CppUTestExt/MockSupport.h>

extern "C"{
  #include "extra_fun.h"
}

int other_fun(int a){
  mock().actualCall("other_fun")
  .withParameter("a", a);
  
  return mock().intReturnValue();
}