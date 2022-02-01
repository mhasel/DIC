/*******************************************************************************
* File Name: gps_rx.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_gps_rx_H) /* Pins gps_rx_H */
#define CY_PINS_gps_rx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "gps_rx_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 gps_rx__PORT == 15 && ((gps_rx__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    gps_rx_Write(uint8 value);
void    gps_rx_SetDriveMode(uint8 mode);
uint8   gps_rx_ReadDataReg(void);
uint8   gps_rx_Read(void);
void    gps_rx_SetInterruptMode(uint16 position, uint16 mode);
uint8   gps_rx_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the gps_rx_SetDriveMode() function.
     *  @{
     */
        #define gps_rx_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define gps_rx_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define gps_rx_DM_RES_UP          PIN_DM_RES_UP
        #define gps_rx_DM_RES_DWN         PIN_DM_RES_DWN
        #define gps_rx_DM_OD_LO           PIN_DM_OD_LO
        #define gps_rx_DM_OD_HI           PIN_DM_OD_HI
        #define gps_rx_DM_STRONG          PIN_DM_STRONG
        #define gps_rx_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define gps_rx_MASK               gps_rx__MASK
#define gps_rx_SHIFT              gps_rx__SHIFT
#define gps_rx_WIDTH              1u

/* Interrupt constants */
#if defined(gps_rx__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in gps_rx_SetInterruptMode() function.
     *  @{
     */
        #define gps_rx_INTR_NONE      (uint16)(0x0000u)
        #define gps_rx_INTR_RISING    (uint16)(0x0001u)
        #define gps_rx_INTR_FALLING   (uint16)(0x0002u)
        #define gps_rx_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define gps_rx_INTR_MASK      (0x01u) 
#endif /* (gps_rx__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define gps_rx_PS                     (* (reg8 *) gps_rx__PS)
/* Data Register */
#define gps_rx_DR                     (* (reg8 *) gps_rx__DR)
/* Port Number */
#define gps_rx_PRT_NUM                (* (reg8 *) gps_rx__PRT) 
/* Connect to Analog Globals */                                                  
#define gps_rx_AG                     (* (reg8 *) gps_rx__AG)                       
/* Analog MUX bux enable */
#define gps_rx_AMUX                   (* (reg8 *) gps_rx__AMUX) 
/* Bidirectional Enable */                                                        
#define gps_rx_BIE                    (* (reg8 *) gps_rx__BIE)
/* Bit-mask for Aliased Register Access */
#define gps_rx_BIT_MASK               (* (reg8 *) gps_rx__BIT_MASK)
/* Bypass Enable */
#define gps_rx_BYP                    (* (reg8 *) gps_rx__BYP)
/* Port wide control signals */                                                   
#define gps_rx_CTL                    (* (reg8 *) gps_rx__CTL)
/* Drive Modes */
#define gps_rx_DM0                    (* (reg8 *) gps_rx__DM0) 
#define gps_rx_DM1                    (* (reg8 *) gps_rx__DM1)
#define gps_rx_DM2                    (* (reg8 *) gps_rx__DM2) 
/* Input Buffer Disable Override */
#define gps_rx_INP_DIS                (* (reg8 *) gps_rx__INP_DIS)
/* LCD Common or Segment Drive */
#define gps_rx_LCD_COM_SEG            (* (reg8 *) gps_rx__LCD_COM_SEG)
/* Enable Segment LCD */
#define gps_rx_LCD_EN                 (* (reg8 *) gps_rx__LCD_EN)
/* Slew Rate Control */
#define gps_rx_SLW                    (* (reg8 *) gps_rx__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define gps_rx_PRTDSI__CAPS_SEL       (* (reg8 *) gps_rx__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define gps_rx_PRTDSI__DBL_SYNC_IN    (* (reg8 *) gps_rx__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define gps_rx_PRTDSI__OE_SEL0        (* (reg8 *) gps_rx__PRTDSI__OE_SEL0) 
#define gps_rx_PRTDSI__OE_SEL1        (* (reg8 *) gps_rx__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define gps_rx_PRTDSI__OUT_SEL0       (* (reg8 *) gps_rx__PRTDSI__OUT_SEL0) 
#define gps_rx_PRTDSI__OUT_SEL1       (* (reg8 *) gps_rx__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define gps_rx_PRTDSI__SYNC_OUT       (* (reg8 *) gps_rx__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(gps_rx__SIO_CFG)
    #define gps_rx_SIO_HYST_EN        (* (reg8 *) gps_rx__SIO_HYST_EN)
    #define gps_rx_SIO_REG_HIFREQ     (* (reg8 *) gps_rx__SIO_REG_HIFREQ)
    #define gps_rx_SIO_CFG            (* (reg8 *) gps_rx__SIO_CFG)
    #define gps_rx_SIO_DIFF           (* (reg8 *) gps_rx__SIO_DIFF)
#endif /* (gps_rx__SIO_CFG) */

/* Interrupt Registers */
#if defined(gps_rx__INTSTAT)
    #define gps_rx_INTSTAT            (* (reg8 *) gps_rx__INTSTAT)
    #define gps_rx_SNAP               (* (reg8 *) gps_rx__SNAP)
    
	#define gps_rx_0_INTTYPE_REG 		(* (reg8 *) gps_rx__0__INTTYPE)
#endif /* (gps_rx__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_gps_rx_H */


/* [] END OF FILE */
