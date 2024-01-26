#ifndef KERNEL_TIMING_H
#define KERNEL_TIMING_H

#include <stdint.h>

void kernel_delay(uint32_t milliseconds);
uint32_t get_cpu_speed();

#endif // KERNEL_TIMING_H