/*******************************************************************************
* File Name: AnalogIN.h  
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

#if !defined(CY_PINS_AnalogIN_H) /* Pins AnalogIN_H */
#define CY_PINS_AnalogIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AnalogIN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AnalogIN__PORT == 15 && ((AnalogIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AnalogIN_Write(uint8 value);
void    AnalogIN_SetDriveMode(uint8 mode);
uint8   AnalogIN_ReadDataReg(void);
uint8   AnalogIN_Read(void);
void    AnalogIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   AnalogIN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AnalogIN_SetDriveMode() function.
     *  @{
     */
        #define AnalogIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AnalogIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AnalogIN_DM_RES_UP          PIN_DM_RES_UP
        #define AnalogIN_DM_RES_DWN         PIN_DM_RES_DWN
        #define AnalogIN_DM_OD_LO           PIN_DM_OD_LO
        #define AnalogIN_DM_OD_HI           PIN_DM_OD_HI
        #define AnalogIN_DM_STRONG          PIN_DM_STRONG
        #define AnalogIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AnalogIN_MASK               AnalogIN__MASK
#define AnalogIN_SHIFT              AnalogIN__SHIFT
#define AnalogIN_WIDTH              1u

/* Interrupt constants */
#if defined(AnalogIN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AnalogIN_SetInterruptMode() function.
     *  @{
     */
        #define AnalogIN_INTR_NONE      (uint16)(0x0000u)
        #define AnalogIN_INTR_RISING    (uint16)(0x0001u)
        #define AnalogIN_INTR_FALLING   (uint16)(0x0002u)
        #define AnalogIN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AnalogIN_INTR_MASK      (0x01u) 
#endif /* (AnalogIN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AnalogIN_PS                     (* (reg8 *) AnalogIN__PS)
/* Data Register */
#define AnalogIN_DR                     (* (reg8 *) AnalogIN__DR)
/* Port Number */
#define AnalogIN_PRT_NUM                (* (reg8 *) AnalogIN__PRT) 
/* Connect to Analog Globals */                                                  
#define AnalogIN_AG                     (* (reg8 *) AnalogIN__AG)                       
/* Analog MUX bux enable */
#define AnalogIN_AMUX                   (* (reg8 *) AnalogIN__AMUX) 
/* Bidirectional Enable */                                                        
#define AnalogIN_BIE                    (* (reg8 *) AnalogIN__BIE)
/* Bit-mask for Aliased Register Access */
#define AnalogIN_BIT_MASK               (* (reg8 *) AnalogIN__BIT_MASK)
/* Bypass Enable */
#define AnalogIN_BYP                    (* (reg8 *) AnalogIN__BYP)
/* Port wide control signals */                                                   
#define AnalogIN_CTL                    (* (reg8 *) AnalogIN__CTL)
/* Drive Modes */
#define AnalogIN_DM0                    (* (reg8 *) AnalogIN__DM0) 
#define AnalogIN_DM1                    (* (reg8 *) AnalogIN__DM1)
#define AnalogIN_DM2                    (* (reg8 *) AnalogIN__DM2) 
/* Input Buffer Disable Override */
#define AnalogIN_INP_DIS                (* (reg8 *) AnalogIN__INP_DIS)
/* LCD Common or Segment Drive */
#define AnalogIN_LCD_COM_SEG            (* (reg8 *) AnalogIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define AnalogIN_LCD_EN                 (* (reg8 *) AnalogIN__LCD_EN)
/* Slew Rate Control */
#define AnalogIN_SLW                    (* (reg8 *) AnalogIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AnalogIN_PRTDSI__CAPS_SEL       (* (reg8 *) AnalogIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AnalogIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AnalogIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AnalogIN_PRTDSI__OE_SEL0        (* (reg8 *) AnalogIN__PRTDSI__OE_SEL0) 
#define AnalogIN_PRTDSI__OE_SEL1        (* (reg8 *) AnalogIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AnalogIN_PRTDSI__OUT_SEL0       (* (reg8 *) AnalogIN__PRTDSI__OUT_SEL0) 
#define AnalogIN_PRTDSI__OUT_SEL1       (* (reg8 *) AnalogIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AnalogIN_PRTDSI__SYNC_OUT       (* (reg8 *) AnalogIN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AnalogIN__SIO_CFG)
    #define AnalogIN_SIO_HYST_EN        (* (reg8 *) AnalogIN__SIO_HYST_EN)
    #define AnalogIN_SIO_REG_HIFREQ     (* (reg8 *) AnalogIN__SIO_REG_HIFREQ)
    #define AnalogIN_SIO_CFG            (* (reg8 *) AnalogIN__SIO_CFG)
    #define AnalogIN_SIO_DIFF           (* (reg8 *) AnalogIN__SIO_DIFF)
#endif /* (AnalogIN__SIO_CFG) */

/* Interrupt Registers */
#if defined(AnalogIN__INTSTAT)
    #define AnalogIN_INTSTAT            (* (reg8 *) AnalogIN__INTSTAT)
    #define AnalogIN_SNAP               (* (reg8 *) AnalogIN__SNAP)
    
	#define AnalogIN_0_INTTYPE_REG 		(* (reg8 *) AnalogIN__0__INTTYPE)
#endif /* (AnalogIN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AnalogIN_H */


/* [] END OF FILE */
