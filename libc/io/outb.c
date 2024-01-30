#include <sys/io.h>

void outb(unsigned char value, unsigned short port) {
    asm volatile("out %%al, %%dx" : : "a"(value), "d"(port) : "memory");
}