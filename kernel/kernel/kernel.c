#include <stdio.h>
#include <stdint.h>
#include <kernel/tty.h>
#include <kernel/debug.h>
#include <kernel/timing.h>

void kernel_main(void) {
	terminal_initialize();
	Debug_LogI("Initalize Terminal");

	Debug_LogW("Initalize PIT");
	kernel_init_pit(100);

	Debug_LogE("Start App Loop");
	uint8_t u8Num = 0;
	while (1) {
		printf("%d\n", u8Num);
		u8Num++;
		kernel_delay(1);
	}
}