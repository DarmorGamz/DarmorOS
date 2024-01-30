/*******************************************************************************
*                           C O P Y R I G H T (c)
*							  D A R M O R ™
*						    All Rights Reserved
*******************************************************************************
* @file       tty.c
* @copyright  COPYRIGHT (c) 2024 Darmor™. All rights reserved.
* @author     Darren Morrison
* @brief      Used to interact with the terminal
* @details    
***************************************************************************** */
/** INCLUDES ******************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <kernel/tty.h>
#include "vga.h"


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/
#define TERMINAL_COLOR_DEFAULT vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK)
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** VARIABLES *****************************************************************/
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/
void _terminal_scroll();


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
/**************************************************************************//**
 *  Used to initalize the terminal driver.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

/**************************************************************************//**
 *  Outputs
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
	unsigned char uc = c;
	// Check for newline \n
	if (uc == '\n') {
		terminal_row++; // Next row.
		terminal_column = 0; // Reset column.

		// Scroll the terminal if it exceeds viewable area.
		if (terminal_row == VGA_HEIGHT) {
			_terminal_scroll();
			terminal_row--;
		}
		return;
	}
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;

		// Scroll the terminal if it exceeds viewable area.
		if (++terminal_row == VGA_HEIGHT) {
			_terminal_scroll();
			terminal_row--;
		}
	}
}

void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++) {
		terminal_putchar(data[i]);
	}
}

void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}

void terminal_newline(void) {
	terminal_putchar('\n');
}


/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
void _terminal_scroll() {
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			const size_t index2 = (y+1) * VGA_WIDTH + x;
			if (y == VGA_HEIGHT-1) {
				terminal_buffer[index] = vga_entry(' ', terminal_color);
			} else {
				terminal_buffer[index] = vga_entry(terminal_buffer[index2], terminal_color);
			}
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_setcolordefault(void) {
	terminal_color = TERMINAL_COLOR_DEFAULT;
}

