#include <kernel/timing.h>

void kernel_delay(uint32_t u32Milliseconds) {
    // Assume a processor running at 1 MHz
    volatile uint32_t u32Cycles = u32Milliseconds * 1000;

    while (u32Cycles > 0) {
        asm volatile("nop"); // (no-operation) instructions for busy-waiting
        u32Cycles--;
    }
}

uint32_t get_cpu_speed() {
    uint32_t result;
    asm volatile(
        "cpuid\n\t"
        "movl %%edx, %0"
        : "=r" (result)
        : "a" (0x80000002)
        : "%ebx", "%ecx", "%edx"
    );
    return result;
}