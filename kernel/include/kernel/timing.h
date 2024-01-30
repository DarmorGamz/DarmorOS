/*******************************************************************************
*                           C O P Y R I G H T (c)
*							  D A R M O R ™
*						    All Rights Reserved
*******************************************************************************
* @file       timing.h
* @copyright  COPYRIGHT (c) 2024 Darmor™. All rights reserved.
* @author     Darren Morrison
* @brief      Header file for time related control
***************************************************************************** */
#ifndef KERNEL_TIMING_H
#define KERNEL_TIMING_H


#ifdef __cplusplus
extern "C" {
#endif


/** INCLUDES ******************************************************************/
#include <stdint.h>


/** COMMON CONSTANT DEFINITIONS ***********************************************/


/** COMMON MACRO DEFINITIONS **************************************************/


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void kernel_init_pit(uint32_t);
void kernel_delay(uint32_t);
uint32_t get_cpu_speed();
uint32_t kernel_read_sys_time();


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** GLOBAL VARIABLES (SHARED ACROSS CODE MODULES) *****************************/


/** DEBUG *********************************************************************/


#ifdef __cplusplus
}
#endif


#endif // KERNEL_TIMING_H