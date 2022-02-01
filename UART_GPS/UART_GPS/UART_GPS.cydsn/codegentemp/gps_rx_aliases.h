/*******************************************************************************
* File Name: gps_rx.h  
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

#if !defined(CY_PINS_gps_rx_ALIASES_H) /* Pins gps_rx_ALIASES_H */
#define CY_PINS_gps_rx_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define gps_rx_0			(gps_rx__0__PC)
#define gps_rx_0_INTR	((uint16)((uint16)0x0001u << gps_rx__0__SHIFT))

#define gps_rx_INTR_ALL	 ((uint16)(gps_rx_0_INTR))

#endif /* End Pins gps_rx_ALIASES_H */


/* [] END OF FILE */
