#include <sys/io.h>

unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile("in %%dx, %%al" : "=a"(ret) : "d"(port) : "memory");
    return ret;
}
