/*******************************************************************************
*                           C O P Y R I G H T (c)
*							  D A R M O R ™
*						    All Rights Reserved
*******************************************************************************
* @file       debug.h
* @copyright  COPYRIGHT (c) 2024 Darmor™. All rights reserved.
* @author     Darren Morrison
* @brief      Header file for debug functionality
***************************************************************************** */
#ifndef KERNEL_DEBUG_H
#define KERNEL_DEBUG_H


#ifdef __cplusplus
extern "C" {
#endif


/** INCLUDES ******************************************************************/


/** COMMON CONSTANT DEFINITIONS ***********************************************/


/** COMMON MACRO DEFINITIONS **************************************************/


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void Debug_LogI(const char* data);
void Debug_LogW(const char* data);
void Debug_LogD(const char* data);
void Debug_LogE(const char* data);


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** GLOBAL VARIABLES (SHARED ACROSS CODE MODULES) *****************************/


/** DEBUG *********************************************************************/


#ifdef __cplusplus
}
#endif


#endif // KERNEL_DEBUG_H