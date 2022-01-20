/*******************************************************************************
* File Name: VIN.h  
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

#if !defined(CY_PINS_VIN_H) /* Pins VIN_H */
#define CY_PINS_VIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VIN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VIN__PORT == 15 && ((VIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VIN_Write(uint8 value);
void    VIN_SetDriveMode(uint8 mode);
uint8   VIN_ReadDataReg(void);
uint8   VIN_Read(void);
void    VIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   VIN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VIN_SetDriveMode() function.
     *  @{
     */
        #define VIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VIN_DM_RES_UP          PIN_DM_RES_UP
        #define VIN_DM_RES_DWN         PIN_DM_RES_DWN
        #define VIN_DM_OD_LO           PIN_DM_OD_LO
        #define VIN_DM_OD_HI           PIN_DM_OD_HI
        #define VIN_DM_STRONG          PIN_DM_STRONG
        #define VIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VIN_MASK               VIN__MASK
#define VIN_SHIFT              VIN__SHIFT
#define VIN_WIDTH              1u

/* Interrupt constants */
#if defined(VIN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VIN_SetInterruptMode() function.
     *  @{
     */
        #define VIN_INTR_NONE      (uint16)(0x0000u)
        #define VIN_INTR_RISING    (uint16)(0x0001u)
        #define VIN_INTR_FALLING   (uint16)(0x0002u)
        #define VIN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VIN_INTR_MASK      (0x01u) 
#endif /* (VIN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VIN_PS                     (* (reg8 *) VIN__PS)
/* Data Register */
#define VIN_DR                     (* (reg8 *) VIN__DR)
/* Port Number */
#define VIN_PRT_NUM                (* (reg8 *) VIN__PRT) 
/* Connect to Analog Globals */                                                  
#define VIN_AG                     (* (reg8 *) VIN__AG)                       
/* Analog MUX bux enable */
#define VIN_AMUX                   (* (reg8 *) VIN__AMUX) 
/* Bidirectional Enable */                                                        
#define VIN_BIE                    (* (reg8 *) VIN__BIE)
/* Bit-mask for Aliased Register Access */
#define VIN_BIT_MASK               (* (reg8 *) VIN__BIT_MASK)
/* Bypass Enable */
#define VIN_BYP                    (* (reg8 *) VIN__BYP)
/* Port wide control signals */                                                   
#define VIN_CTL                    (* (reg8 *) VIN__CTL)
/* Drive Modes */
#define VIN_DM0                    (* (reg8 *) VIN__DM0) 
#define VIN_DM1                    (* (reg8 *) VIN__DM1)
#define VIN_DM2                    (* (reg8 *) VIN__DM2) 
/* Input Buffer Disable Override */
#define VIN_INP_DIS                (* (reg8 *) VIN__INP_DIS)
/* LCD Common or Segment Drive */
#define VIN_LCD_COM_SEG            (* (reg8 *) VIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define VIN_LCD_EN                 (* (reg8 *) VIN__LCD_EN)
/* Slew Rate Control */
#define VIN_SLW                    (* (reg8 *) VIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VIN_PRTDSI__CAPS_SEL       (* (reg8 *) VIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VIN_PRTDSI__OE_SEL0        (* (reg8 *) VIN__PRTDSI__OE_SEL0) 
#define VIN_PRTDSI__OE_SEL1        (* (reg8 *) VIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VIN_PRTDSI__OUT_SEL0       (* (reg8 *) VIN__PRTDSI__OUT_SEL0) 
#define VIN_PRTDSI__OUT_SEL1       (* (reg8 *) VIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VIN_PRTDSI__SYNC_OUT       (* (reg8 *) VIN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VIN__SIO_CFG)
    #define VIN_SIO_HYST_EN        (* (reg8 *) VIN__SIO_HYST_EN)
    #define VIN_SIO_REG_HIFREQ     (* (reg8 *) VIN__SIO_REG_HIFREQ)
    #define VIN_SIO_CFG            (* (reg8 *) VIN__SIO_CFG)
    #define VIN_SIO_DIFF           (* (reg8 *) VIN__SIO_DIFF)
#endif /* (VIN__SIO_CFG) */

/* Interrupt Registers */
#if defined(VIN__INTSTAT)
    #define VIN_INTSTAT            (* (reg8 *) VIN__INTSTAT)
    #define VIN_SNAP               (* (reg8 *) VIN__SNAP)
    
	#define VIN_0_INTTYPE_REG 		(* (reg8 *) VIN__0__INTTYPE)
#endif /* (VIN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VIN_H */


/* [] END OF FILE */
