#include "include/io.h"

static IOdata_t fakeReg = 0;

IOdata_t IOread(IOaddrs_t addrs){
  IOaddrs_t x = addrs;
  x++;
  return (IOdata_t) fakeReg;
}

void IOwrite(IOaddrs_t addr, IOdata_t data){
  IOaddrs_t x = addr;
  x++;
  fakeReg = data;
}