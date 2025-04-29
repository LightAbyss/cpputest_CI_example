#ifndef IO_H_
#define IO_H_

#include <stdint.h>

typedef uint32_t IOaddrs_t;
typedef uint32_t IOdata_t;

IOdata_t IOread(IOaddrs_t addr);
void IOwrite(IOaddrs_t addr, IOdata_t data);

#endif /* IO_H_ */