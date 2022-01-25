/*******************************************************************************
* File Name: P_charge.h  
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

#if !defined(CY_PINS_P_charge_H) /* Pins P_charge_H */
#define CY_PINS_P_charge_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "P_charge_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 P_charge__PORT == 15 && ((P_charge__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    P_charge_Write(uint8 value);
void    P_charge_SetDriveMode(uint8 mode);
uint8   P_charge_ReadDataReg(void);
uint8   P_charge_Read(void);
void    P_charge_SetInterruptMode(uint16 position, uint16 mode);
uint8   P_charge_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the P_charge_SetDriveMode() function.
     *  @{
     */
        #define P_charge_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define P_charge_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define P_charge_DM_RES_UP          PIN_DM_RES_UP
        #define P_charge_DM_RES_DWN         PIN_DM_RES_DWN
        #define P_charge_DM_OD_LO           PIN_DM_OD_LO
        #define P_charge_DM_OD_HI           PIN_DM_OD_HI
        #define P_charge_DM_STRONG          PIN_DM_STRONG
        #define P_charge_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define P_charge_MASK               P_charge__MASK
#define P_charge_SHIFT              P_charge__SHIFT
#define P_charge_WIDTH              1u

/* Interrupt constants */
#if defined(P_charge__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in P_charge_SetInterruptMode() function.
     *  @{
     */
        #define P_charge_INTR_NONE      (uint16)(0x0000u)
        #define P_charge_INTR_RISING    (uint16)(0x0001u)
        #define P_charge_INTR_FALLING   (uint16)(0x0002u)
        #define P_charge_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define P_charge_INTR_MASK      (0x01u) 
#endif /* (P_charge__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P_charge_PS                     (* (reg8 *) P_charge__PS)
/* Data Register */
#define P_charge_DR                     (* (reg8 *) P_charge__DR)
/* Port Number */
#define P_charge_PRT_NUM                (* (reg8 *) P_charge__PRT) 
/* Connect to Analog Globals */                                                  
#define P_charge_AG                     (* (reg8 *) P_charge__AG)                       
/* Analog MUX bux enable */
#define P_charge_AMUX                   (* (reg8 *) P_charge__AMUX) 
/* Bidirectional Enable */                                                        
#define P_charge_BIE                    (* (reg8 *) P_charge__BIE)
/* Bit-mask for Aliased Register Access */
#define P_charge_BIT_MASK               (* (reg8 *) P_charge__BIT_MASK)
/* Bypass Enable */
#define P_charge_BYP                    (* (reg8 *) P_charge__BYP)
/* Port wide control signals */                                                   
#define P_charge_CTL                    (* (reg8 *) P_charge__CTL)
/* Drive Modes */
#define P_charge_DM0                    (* (reg8 *) P_charge__DM0) 
#define P_charge_DM1                    (* (reg8 *) P_charge__DM1)
#define P_charge_DM2                    (* (reg8 *) P_charge__DM2) 
/* Input Buffer Disable Override */
#define P_charge_INP_DIS                (* (reg8 *) P_charge__INP_DIS)
/* LCD Common or Segment Drive */
#define P_charge_LCD_COM_SEG            (* (reg8 *) P_charge__LCD_COM_SEG)
/* Enable Segment LCD */
#define P_charge_LCD_EN                 (* (reg8 *) P_charge__LCD_EN)
/* Slew Rate Control */
#define P_charge_SLW                    (* (reg8 *) P_charge__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define P_charge_PRTDSI__CAPS_SEL       (* (reg8 *) P_charge__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define P_charge_PRTDSI__DBL_SYNC_IN    (* (reg8 *) P_charge__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define P_charge_PRTDSI__OE_SEL0        (* (reg8 *) P_charge__PRTDSI__OE_SEL0) 
#define P_charge_PRTDSI__OE_SEL1        (* (reg8 *) P_charge__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define P_charge_PRTDSI__OUT_SEL0       (* (reg8 *) P_charge__PRTDSI__OUT_SEL0) 
#define P_charge_PRTDSI__OUT_SEL1       (* (reg8 *) P_charge__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define P_charge_PRTDSI__SYNC_OUT       (* (reg8 *) P_charge__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(P_charge__SIO_CFG)
    #define P_charge_SIO_HYST_EN        (* (reg8 *) P_charge__SIO_HYST_EN)
    #define P_charge_SIO_REG_HIFREQ     (* (reg8 *) P_charge__SIO_REG_HIFREQ)
    #define P_charge_SIO_CFG            (* (reg8 *) P_charge__SIO_CFG)
    #define P_charge_SIO_DIFF           (* (reg8 *) P_charge__SIO_DIFF)
#endif /* (P_charge__SIO_CFG) */

/* Interrupt Registers */
#if defined(P_charge__INTSTAT)
    #define P_charge_INTSTAT            (* (reg8 *) P_charge__INTSTAT)
    #define P_charge_SNAP               (* (reg8 *) P_charge__SNAP)
    
	#define P_charge_0_INTTYPE_REG 		(* (reg8 *) P_charge__0__INTTYPE)
#endif /* (P_charge__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_P_charge_H */


/* [] END OF FILE */
