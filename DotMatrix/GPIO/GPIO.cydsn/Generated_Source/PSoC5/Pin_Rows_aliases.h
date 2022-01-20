/*******************************************************************************
* File Name: Pin_Rows.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_Rows_ALIASES_H) /* Pins Pin_Rows_ALIASES_H */
#define CY_PINS_Pin_Rows_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_Rows_0			(Pin_Rows__0__PC)
#define Pin_Rows_0_INTR	((uint16)((uint16)0x0001u << Pin_Rows__0__SHIFT))

#define Pin_Rows_1			(Pin_Rows__1__PC)
#define Pin_Rows_1_INTR	((uint16)((uint16)0x0001u << Pin_Rows__1__SHIFT))

#define Pin_Rows_2			(Pin_Rows__2__PC)
#define Pin_Rows_2_INTR	((uint16)((uint16)0x0001u << Pin_Rows__2__SHIFT))

#define Pin_Rows_3			(Pin_Rows__3__PC)
#define Pin_Rows_3_INTR	((uint16)((uint16)0x0001u << Pin_Rows__3__SHIFT))

#define Pin_Rows_4			(Pin_Rows__4__PC)
#define Pin_Rows_4_INTR	((uint16)((uint16)0x0001u << Pin_Rows__4__SHIFT))

#define Pin_Rows_5			(Pin_Rows__5__PC)
#define Pin_Rows_5_INTR	((uint16)((uint16)0x0001u << Pin_Rows__5__SHIFT))

#define Pin_Rows_6			(Pin_Rows__6__PC)
#define Pin_Rows_6_INTR	((uint16)((uint16)0x0001u << Pin_Rows__6__SHIFT))

#define Pin_Rows_7			(Pin_Rows__7__PC)
#define Pin_Rows_7_INTR	((uint16)((uint16)0x0001u << Pin_Rows__7__SHIFT))

#define Pin_Rows_INTR_ALL	 ((uint16)(Pin_Rows_0_INTR| Pin_Rows_1_INTR| Pin_Rows_2_INTR| Pin_Rows_3_INTR| Pin_Rows_4_INTR| Pin_Rows_5_INTR| Pin_Rows_6_INTR| Pin_Rows_7_INTR))

#endif /* End Pins Pin_Rows_ALIASES_H */


/* [] END OF FILE */
