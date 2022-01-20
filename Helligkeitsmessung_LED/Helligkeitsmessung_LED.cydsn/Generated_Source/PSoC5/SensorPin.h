/*******************************************************************************
* File Name: SensorPin.h  
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

#if !defined(CY_PINS_SensorPin_H) /* Pins SensorPin_H */
#define CY_PINS_SensorPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SensorPin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SensorPin__PORT == 15 && ((SensorPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SensorPin_Write(uint8 value);
void    SensorPin_SetDriveMode(uint8 mode);
uint8   SensorPin_ReadDataReg(void);
uint8   SensorPin_Read(void);
void    SensorPin_SetInterruptMode(uint16 position, uint16 mode);
uint8   SensorPin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SensorPin_SetDriveMode() function.
     *  @{
     */
        #define SensorPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SensorPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SensorPin_DM_RES_UP          PIN_DM_RES_UP
        #define SensorPin_DM_RES_DWN         PIN_DM_RES_DWN
        #define SensorPin_DM_OD_LO           PIN_DM_OD_LO
        #define SensorPin_DM_OD_HI           PIN_DM_OD_HI
        #define SensorPin_DM_STRONG          PIN_DM_STRONG
        #define SensorPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SensorPin_MASK               SensorPin__MASK
#define SensorPin_SHIFT              SensorPin__SHIFT
#define SensorPin_WIDTH              1u

/* Interrupt constants */
#if defined(SensorPin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SensorPin_SetInterruptMode() function.
     *  @{
     */
        #define SensorPin_INTR_NONE      (uint16)(0x0000u)
        #define SensorPin_INTR_RISING    (uint16)(0x0001u)
        #define SensorPin_INTR_FALLING   (uint16)(0x0002u)
        #define SensorPin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SensorPin_INTR_MASK      (0x01u) 
#endif /* (SensorPin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensorPin_PS                     (* (reg8 *) SensorPin__PS)
/* Data Register */
#define SensorPin_DR                     (* (reg8 *) SensorPin__DR)
/* Port Number */
#define SensorPin_PRT_NUM                (* (reg8 *) SensorPin__PRT) 
/* Connect to Analog Globals */                                                  
#define SensorPin_AG                     (* (reg8 *) SensorPin__AG)                       
/* Analog MUX bux enable */
#define SensorPin_AMUX                   (* (reg8 *) SensorPin__AMUX) 
/* Bidirectional Enable */                                                        
#define SensorPin_BIE                    (* (reg8 *) SensorPin__BIE)
/* Bit-mask for Aliased Register Access */
#define SensorPin_BIT_MASK               (* (reg8 *) SensorPin__BIT_MASK)
/* Bypass Enable */
#define SensorPin_BYP                    (* (reg8 *) SensorPin__BYP)
/* Port wide control signals */                                                   
#define SensorPin_CTL                    (* (reg8 *) SensorPin__CTL)
/* Drive Modes */
#define SensorPin_DM0                    (* (reg8 *) SensorPin__DM0) 
#define SensorPin_DM1                    (* (reg8 *) SensorPin__DM1)
#define SensorPin_DM2                    (* (reg8 *) SensorPin__DM2) 
/* Input Buffer Disable Override */
#define SensorPin_INP_DIS                (* (reg8 *) SensorPin__INP_DIS)
/* LCD Common or Segment Drive */
#define SensorPin_LCD_COM_SEG            (* (reg8 *) SensorPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define SensorPin_LCD_EN                 (* (reg8 *) SensorPin__LCD_EN)
/* Slew Rate Control */
#define SensorPin_SLW                    (* (reg8 *) SensorPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SensorPin_PRTDSI__CAPS_SEL       (* (reg8 *) SensorPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SensorPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SensorPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SensorPin_PRTDSI__OE_SEL0        (* (reg8 *) SensorPin__PRTDSI__OE_SEL0) 
#define SensorPin_PRTDSI__OE_SEL1        (* (reg8 *) SensorPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SensorPin_PRTDSI__OUT_SEL0       (* (reg8 *) SensorPin__PRTDSI__OUT_SEL0) 
#define SensorPin_PRTDSI__OUT_SEL1       (* (reg8 *) SensorPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SensorPin_PRTDSI__SYNC_OUT       (* (reg8 *) SensorPin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SensorPin__SIO_CFG)
    #define SensorPin_SIO_HYST_EN        (* (reg8 *) SensorPin__SIO_HYST_EN)
    #define SensorPin_SIO_REG_HIFREQ     (* (reg8 *) SensorPin__SIO_REG_HIFREQ)
    #define SensorPin_SIO_CFG            (* (reg8 *) SensorPin__SIO_CFG)
    #define SensorPin_SIO_DIFF           (* (reg8 *) SensorPin__SIO_DIFF)
#endif /* (SensorPin__SIO_CFG) */

/* Interrupt Registers */
#if defined(SensorPin__INTSTAT)
    #define SensorPin_INTSTAT            (* (reg8 *) SensorPin__INTSTAT)
    #define SensorPin_SNAP               (* (reg8 *) SensorPin__SNAP)
    
	#define SensorPin_0_INTTYPE_REG 		(* (reg8 *) SensorPin__0__INTTYPE)
#endif /* (SensorPin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SensorPin_H */


/* [] END OF FILE */
