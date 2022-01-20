/*******************************************************************************
* File Name: Pin_Cols.h  
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

#if !defined(CY_PINS_Pin_Cols_H) /* Pins Pin_Cols_H */
#define CY_PINS_Pin_Cols_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_Cols_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_Cols__PORT == 15 && ((Pin_Cols__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pin_Cols_Write(uint8 value);
void    Pin_Cols_SetDriveMode(uint8 mode);
uint8   Pin_Cols_ReadDataReg(void);
uint8   Pin_Cols_Read(void);
void    Pin_Cols_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pin_Cols_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pin_Cols_SetDriveMode() function.
     *  @{
     */
        #define Pin_Cols_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pin_Cols_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pin_Cols_DM_RES_UP          PIN_DM_RES_UP
        #define Pin_Cols_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pin_Cols_DM_OD_LO           PIN_DM_OD_LO
        #define Pin_Cols_DM_OD_HI           PIN_DM_OD_HI
        #define Pin_Cols_DM_STRONG          PIN_DM_STRONG
        #define Pin_Cols_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pin_Cols_MASK               Pin_Cols__MASK
#define Pin_Cols_SHIFT              Pin_Cols__SHIFT
#define Pin_Cols_WIDTH              8u

/* Interrupt constants */
#if defined(Pin_Cols__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pin_Cols_SetInterruptMode() function.
     *  @{
     */
        #define Pin_Cols_INTR_NONE      (uint16)(0x0000u)
        #define Pin_Cols_INTR_RISING    (uint16)(0x0001u)
        #define Pin_Cols_INTR_FALLING   (uint16)(0x0002u)
        #define Pin_Cols_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pin_Cols_INTR_MASK      (0x01u) 
#endif /* (Pin_Cols__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_Cols_PS                     (* (reg8 *) Pin_Cols__PS)
/* Data Register */
#define Pin_Cols_DR                     (* (reg8 *) Pin_Cols__DR)
/* Port Number */
#define Pin_Cols_PRT_NUM                (* (reg8 *) Pin_Cols__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_Cols_AG                     (* (reg8 *) Pin_Cols__AG)                       
/* Analog MUX bux enable */
#define Pin_Cols_AMUX                   (* (reg8 *) Pin_Cols__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_Cols_BIE                    (* (reg8 *) Pin_Cols__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_Cols_BIT_MASK               (* (reg8 *) Pin_Cols__BIT_MASK)
/* Bypass Enable */
#define Pin_Cols_BYP                    (* (reg8 *) Pin_Cols__BYP)
/* Port wide control signals */                                                   
#define Pin_Cols_CTL                    (* (reg8 *) Pin_Cols__CTL)
/* Drive Modes */
#define Pin_Cols_DM0                    (* (reg8 *) Pin_Cols__DM0) 
#define Pin_Cols_DM1                    (* (reg8 *) Pin_Cols__DM1)
#define Pin_Cols_DM2                    (* (reg8 *) Pin_Cols__DM2) 
/* Input Buffer Disable Override */
#define Pin_Cols_INP_DIS                (* (reg8 *) Pin_Cols__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_Cols_LCD_COM_SEG            (* (reg8 *) Pin_Cols__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_Cols_LCD_EN                 (* (reg8 *) Pin_Cols__LCD_EN)
/* Slew Rate Control */
#define Pin_Cols_SLW                    (* (reg8 *) Pin_Cols__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_Cols_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_Cols__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_Cols_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_Cols__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_Cols_PRTDSI__OE_SEL0        (* (reg8 *) Pin_Cols__PRTDSI__OE_SEL0) 
#define Pin_Cols_PRTDSI__OE_SEL1        (* (reg8 *) Pin_Cols__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_Cols_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_Cols__PRTDSI__OUT_SEL0) 
#define Pin_Cols_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_Cols__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_Cols_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_Cols__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pin_Cols__SIO_CFG)
    #define Pin_Cols_SIO_HYST_EN        (* (reg8 *) Pin_Cols__SIO_HYST_EN)
    #define Pin_Cols_SIO_REG_HIFREQ     (* (reg8 *) Pin_Cols__SIO_REG_HIFREQ)
    #define Pin_Cols_SIO_CFG            (* (reg8 *) Pin_Cols__SIO_CFG)
    #define Pin_Cols_SIO_DIFF           (* (reg8 *) Pin_Cols__SIO_DIFF)
#endif /* (Pin_Cols__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pin_Cols__INTSTAT)
    #define Pin_Cols_INTSTAT            (* (reg8 *) Pin_Cols__INTSTAT)
    #define Pin_Cols_SNAP               (* (reg8 *) Pin_Cols__SNAP)
    
	#define Pin_Cols_0_INTTYPE_REG 		(* (reg8 *) Pin_Cols__0__INTTYPE)
	#define Pin_Cols_1_INTTYPE_REG 		(* (reg8 *) Pin_Cols__1__INTTYPE)
	#define Pin_Cols_2_INTTYPE_REG 		(* (reg8 *) Pin_Cols__2__INTTYPE)
	#define Pin_Cols_3_INTTYPE_REG 		(* (reg8 *) Pin_Cols__3__INTTYPE)
	#define Pin_Cols_4_INTTYPE_REG 		(* (reg8 *) Pin_Cols__4__INTTYPE)
	#define Pin_Cols_5_INTTYPE_REG 		(* (reg8 *) Pin_Cols__5__INTTYPE)
	#define Pin_Cols_6_INTTYPE_REG 		(* (reg8 *) Pin_Cols__6__INTTYPE)
	#define Pin_Cols_7_INTTYPE_REG 		(* (reg8 *) Pin_Cols__7__INTTYPE)
#endif /* (Pin_Cols__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_Cols_H */


/* [] END OF FILE */
