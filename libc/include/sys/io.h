#ifndef IOPORT_H_
#define IOPORT_H_ 1

unsigned char inb(unsigned short port);
void outb(unsigned char value, unsigned short port);

#endif