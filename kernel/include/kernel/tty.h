/*******************************************************************************
*                           C O P Y R I G H T (c)
*							  D A R M O R ™
*						    All Rights Reserved
*******************************************************************************
* @file       tty.h
* @copyright  COPYRIGHT (c) 2024 Darmor™. All rights reserved.
* @author     Darren Morrison
* @brief      Header file for terminal control
***************************************************************************** */
#ifndef KERNEL_TTY_H
#define KERNEL_TTY_H

#ifdef __cplusplus
extern "C" {
#endif


/** INCLUDES ******************************************************************/
#include <stddef.h>
#include <stdint.h>


/** COMMON CONSTANT DEFINITIONS ***********************************************/


/** COMMON MACRO DEFINITIONS **************************************************/


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_newline(void);

void terminal_setcolor(uint8_t color);
void terminal_setcolordefault(void);


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** GLOBAL VARIABLES (SHARED ACROSS CODE MODULES) *****************************/


/** DEBUG *********************************************************************/


#ifdef __cplusplus
}
#endif

#endif // KERNEL_TTY_H
