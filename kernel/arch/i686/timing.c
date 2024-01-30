#include <kernel/timing.h>
#include <sys/io.h>

#define PIT_CRYSTAL_HZ 1193180

static uint32_t u32CPUSpeed = 0;

enum {
    PIT_IRQ = 0x20,      // IRQ line for PIT
    PIT_CHANNEL0 = 0x40, // Channel 0 data port (read/write)
    PIT_CHANNEL1 = 0x41, // Channel 1 data port (read/write)
    PIT_CHANNEL2 = 0x42, // Channel 2 data port (read/write)
    PIT_COMMAND = 0x43,  // Mode/Command register (write only, a read is ignored)
} ePITCHANNELS; 

void kernel_init_pit(uint32_t u32Frequency) {
    uint16_t u16Divisor = PIT_CRYSTAL_HZ / u32Frequency;

    outb(PIT_COMMAND, 0x36);
    outb(PIT_CHANNEL0, (u16Divisor & 0xFF));
    outb(PIT_CHANNEL0, (u16Divisor >> 8) & 0xFF);
}

uint32_t kernel_read_sys_time() {
    uint32_t time = inb(PIT_CHANNEL0);

    return time;
}

void kernel_delay(uint32_t u32Milliseconds) {
    // Assume a processor running at 1 MHz
    if (u32CPUSpeed == 0) get_cpu_speed();

    volatile uint32_t u32Cycles = (u32Milliseconds * u32CPUSpeed) >> 1; // divide by 2 since we have 2 instructions per burn.
    u32Cycles = u32Cycles / 10;
    while (u32Cycles > 0) {
        asm volatile("nop"); // (no-operation) instructions for busy-waiting
        u32Cycles--; // 1 Instruction.
    }
}

uint32_t get_cpu_speed() {
    uint32_t result;

    asm volatile(
        "cpuid\n\t"          // Execute CPUID instruction
        "movl %%edx, %0"     // Move the value in edx to the result variable
        : "=r" (result)      // Output: constraint for the result variable
        : "a" (0x80000002)   // Input: constraint for the CPUID function (0x80000002)
        : "%ebx", "%ecx", "%edx" // Clobbered registers (registers that the assembler should assume have been modified)
    );

    u32CPUSpeed = result;
    return result;
}