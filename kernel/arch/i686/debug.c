/*******************************************************************************
*                           C O P Y R I G H T (c)
*							  D A R M O R ™
*						    All Rights Reserved
*******************************************************************************
* @file       debug.c
* @copyright  COPYRIGHT (c) 2024 Darmor™. All rights reserved.
* @author     Darren Morrison
* @brief      Source file for debug functionality
***************************************************************************** */
/** INCLUDES ******************************************************************/
#include <kernel/debug.h>
#include <kernel/tty.h>
#include "vga.h"


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/
#define DEBUG_LOGI_COLOR VGA_COLOR_WHITE
#define DEBUG_LOGW_COLOR VGA_COLOR_LIGHT_BROWN
#define DEBUG_LOGD_COLOR VGA_COLOR_LIGHT_GREEN
#define DEBUG_LOGE_COLOR VGA_COLOR_LIGHT_RED


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
void Debug_LogI(const char * data) {
    terminal_setcolor(DEBUG_LOGI_COLOR);
    terminal_writestring(data);
    terminal_newline();
    terminal_setcolordefault();
}
void Debug_LogW(const char * data) {
    terminal_setcolor(DEBUG_LOGW_COLOR);
    terminal_writestring(data);
    terminal_newline();
    terminal_setcolordefault();
}
void Debug_LogD(const char * data) {
    terminal_setcolor(DEBUG_LOGD_COLOR);
    terminal_writestring(data);
    terminal_newline();
    terminal_setcolordefault();
}
void Debug_LogE(const char * data) {
    terminal_setcolor(DEBUG_LOGE_COLOR);
    terminal_writestring(data);
    terminal_newline();
    terminal_setcolordefault();
}


/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/