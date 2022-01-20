/*******************************************************************************
* File Name: Pin_Cols.h  
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

#if !defined(CY_PINS_Pin_Cols_ALIASES_H) /* Pins Pin_Cols_ALIASES_H */
#define CY_PINS_Pin_Cols_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_Cols_0			(Pin_Cols__0__PC)
#define Pin_Cols_0_INTR	((uint16)((uint16)0x0001u << Pin_Cols__0__SHIFT))

#define Pin_Cols_1			(Pin_Cols__1__PC)
#define Pin_Cols_1_INTR	((uint16)((uint16)0x0001u << Pin_Cols__1__SHIFT))

#define Pin_Cols_2			(Pin_Cols__2__PC)
#define Pin_Cols_2_INTR	((uint16)((uint16)0x0001u << Pin_Cols__2__SHIFT))

#define Pin_Cols_3			(Pin_Cols__3__PC)
#define Pin_Cols_3_INTR	((uint16)((uint16)0x0001u << Pin_Cols__3__SHIFT))

#define Pin_Cols_4			(Pin_Cols__4__PC)
#define Pin_Cols_4_INTR	((uint16)((uint16)0x0001u << Pin_Cols__4__SHIFT))

#define Pin_Cols_5			(Pin_Cols__5__PC)
#define Pin_Cols_5_INTR	((uint16)((uint16)0x0001u << Pin_Cols__5__SHIFT))

#define Pin_Cols_6			(Pin_Cols__6__PC)
#define Pin_Cols_6_INTR	((uint16)((uint16)0x0001u << Pin_Cols__6__SHIFT))

#define Pin_Cols_7			(Pin_Cols__7__PC)
#define Pin_Cols_7_INTR	((uint16)((uint16)0x0001u << Pin_Cols__7__SHIFT))

#define Pin_Cols_INTR_ALL	 ((uint16)(Pin_Cols_0_INTR| Pin_Cols_1_INTR| Pin_Cols_2_INTR| Pin_Cols_3_INTR| Pin_Cols_4_INTR| Pin_Cols_5_INTR| Pin_Cols_6_INTR| Pin_Cols_7_INTR))
#define Pin_Cols_COL1			(Pin_Cols__COL1__PC)
#define Pin_Cols_COL1_INTR	((uint16)((uint16)0x0001u << Pin_Cols__0__SHIFT))

#define Pin_Cols_COL2			(Pin_Cols__COL2__PC)
#define Pin_Cols_COL2_INTR	((uint16)((uint16)0x0001u << Pin_Cols__1__SHIFT))

#define Pin_Cols_COL3			(Pin_Cols__COL3__PC)
#define Pin_Cols_COL3_INTR	((uint16)((uint16)0x0001u << Pin_Cols__2__SHIFT))

#define Pin_Cols_COL4			(Pin_Cols__COL4__PC)
#define Pin_Cols_COL4_INTR	((uint16)((uint16)0x0001u << Pin_Cols__3__SHIFT))

#define Pin_Cols_COL5			(Pin_Cols__COL5__PC)
#define Pin_Cols_COL5_INTR	((uint16)((uint16)0x0001u << Pin_Cols__4__SHIFT))

#define Pin_Cols_COL6			(Pin_Cols__COL6__PC)
#define Pin_Cols_COL6_INTR	((uint16)((uint16)0x0001u << Pin_Cols__5__SHIFT))

#define Pin_Cols_COL7			(Pin_Cols__COL7__PC)
#define Pin_Cols_COL7_INTR	((uint16)((uint16)0x0001u << Pin_Cols__6__SHIFT))

#define Pin_Cols_COL8			(Pin_Cols__COL8__PC)
#define Pin_Cols_COL8_INTR	((uint16)((uint16)0x0001u << Pin_Cols__7__SHIFT))

#endif /* End Pins Pin_Cols_ALIASES_H */


/* [] END OF FILE */
