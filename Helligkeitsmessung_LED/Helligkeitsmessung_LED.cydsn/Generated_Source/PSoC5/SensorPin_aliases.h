/*******************************************************************************
* File Name: SensorPin.h  
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

#if !defined(CY_PINS_SensorPin_ALIASES_H) /* Pins SensorPin_ALIASES_H */
#define CY_PINS_SensorPin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define SensorPin_0			(SensorPin__0__PC)
#define SensorPin_0_INTR	((uint16)((uint16)0x0001u << SensorPin__0__SHIFT))

#define SensorPin_INTR_ALL	 ((uint16)(SensorPin_0_INTR))

#endif /* End Pins SensorPin_ALIASES_H */


/* [] END OF FILE */
