/*******************************************************************************
* File Name: UART_pc_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_pc.h"


/***************************************
* Local data allocation
***************************************/

static UART_pc_BACKUP_STRUCT  UART_pc_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: UART_pc_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component nonretention control register.
*  Does not save the FIFO which is a set of nonretention registers.
*  This function is called by the UART_pc_Sleep() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_pc_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_pc_SaveConfig(void)
{
    #if(UART_pc_CONTROL_REG_REMOVED == 0u)
        UART_pc_backup.cr = UART_pc_CONTROL_REG;
    #endif /* End UART_pc_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: UART_pc_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the nonretention control register except FIFO.
*  Does not restore the FIFO which is a set of nonretention registers.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_pc_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
* Notes:
*  If this function is called without calling UART_pc_SaveConfig() 
*  first, the data loaded may be incorrect.
*
*******************************************************************************/
void UART_pc_RestoreConfig(void)
{
    #if(UART_pc_CONTROL_REG_REMOVED == 0u)
        UART_pc_CONTROL_REG = UART_pc_backup.cr;
    #endif /* End UART_pc_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: UART_pc_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. 
*  The UART_pc_Sleep() API saves the current component state. Then it
*  calls the UART_pc_Stop() function and calls 
*  UART_pc_SaveConfig() to save the hardware configuration.
*  Call the UART_pc_Sleep() function before calling the CyPmSleep() 
*  or the CyPmHibernate() function. 
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_pc_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_pc_Sleep(void)
{
    #if(UART_pc_RX_ENABLED || UART_pc_HD_ENABLED)
        if((UART_pc_RXSTATUS_ACTL_REG  & UART_pc_INT_ENABLE) != 0u)
        {
            UART_pc_backup.enableState = 1u;
        }
        else
        {
            UART_pc_backup.enableState = 0u;
        }
    #else
        if((UART_pc_TXSTATUS_ACTL_REG  & UART_pc_INT_ENABLE) !=0u)
        {
            UART_pc_backup.enableState = 1u;
        }
        else
        {
            UART_pc_backup.enableState = 0u;
        }
    #endif /* End UART_pc_RX_ENABLED || UART_pc_HD_ENABLED*/

    UART_pc_Stop();
    UART_pc_SaveConfig();
}


/*******************************************************************************
* Function Name: UART_pc_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when 
*  UART_pc_Sleep() was called. The UART_pc_Wakeup() function
*  calls the UART_pc_RestoreConfig() function to restore the 
*  configuration. If the component was enabled before the 
*  UART_pc_Sleep() function was called, the UART_pc_Wakeup()
*  function will also re-enable the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_pc_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_pc_Wakeup(void)
{
    UART_pc_RestoreConfig();
    #if( (UART_pc_RX_ENABLED) || (UART_pc_HD_ENABLED) )
        UART_pc_ClearRxBuffer();
    #endif /* End (UART_pc_RX_ENABLED) || (UART_pc_HD_ENABLED) */
    #if(UART_pc_TX_ENABLED || UART_pc_HD_ENABLED)
        UART_pc_ClearTxBuffer();
    #endif /* End UART_pc_TX_ENABLED || UART_pc_HD_ENABLED */

    if(UART_pc_backup.enableState != 0u)
    {
        UART_pc_Enable();
    }
}


/* [] END OF FILE */
