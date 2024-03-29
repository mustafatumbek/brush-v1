/**
  ********************************************************************************
  * @file stm8s_uart1.h
  * @brief This file contains all functions prototypes and macros for the UART1 peripheral.
  * @author STMicroelectronics - MCD Application Team
  * @version V1.0.1
  * @date 09/22/2008
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2008 STMicroelectronics</center></h2>
  * @image html logo.bmp
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_UART1_H
#define __STM8S_UART1_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s_map.h"
/* Exported types ------------------------------------------------------------*/

/** @addtogroup UART1_Exported_Types
  * @{
  */


/**
  * @brief UART1 Irda Modes
  */

typedef enum { UART1_IRDAMODE_NORMAL         = (u8)0x00, /**< 0x00 Irda Normal Mode   */
               UART1_IRDAMODE_LOWPOWER       = (u8)0x01  /**< 0x01 Irda Low Power Mode */

             } UART1_IrDAMode_TypeDef;

/**
  * @brief UART1 WakeUP Modes
  */

typedef enum { UART1_WAKEUP_IDLELINE       = (u8)0x00, /**< 0x01 Idle Line wake up                */
               UART1_WAKEUP_ADDRESSMARK    = (u8)0x08  /**< 0x02 Address Mark wake up          */
             } UART1_WakeUp_TypeDef;


/**
  * @brief UART1 LIN Break detection length possible values
  */
typedef enum { UART1_LINBREAKDETECTIONLENGTH_10BITS = (u8)0x00, /**< 0x01 10 bits Lin Break detection            */
               UART1_LINBREAKDETECTIONLENGTH_11BITS = (u8)0x01  /**< 0x02 11 bits Lin Break detection          */
             } UART1_LINBreakDetectionLength_TypeDef;

/**
  * @brief UART1 stop bits possible values
  */

typedef enum { UART1_STOPBITS_1   = (u8)0x00,    /**< One stop bit is  transmitted at the end of frame*/
               UART1_STOPBITS_0_5 = (u8)0x10,    /**< Half stop bits is transmitted at the end of frame*/
               UART1_STOPBITS_2  = (u8)0x20,    /**< Two stop bits are  transmitted at the end of frame*/
               UART1_STOPBITS_1_5 = (u8)0x30     /**< One and half stop bits*/
             } UART1_StopBits_TypeDef;


/**
  * @brief UART1 parity possible values
  */
typedef enum { UART1_PARITY_NO     = (u8)0x00,      /**< No Parity*/
               UART1_PARITY_EVEN   = (u8)0x04,      /**< Even Parity*/
               UART1_PARITY_ODD    = (u8)0x06       /**< Odd Parity*/
             } UART1_Parity_TypeDef;

/**
  * @brief UART1 Synchrone modes
  */
typedef enum { UART1_SYNCMODE_CLOCK_DISABLE    = (u8)0x80, /**< 0x80 Sync mode Disable, SLK pin Disable */
               UART1_SYNCMODE_CLOCK_ENABLE     = (u8)0x08, /**< 0x08 Sync mode Enable, SLK pin Enable     */
               UART1_SYNCMODE_CPOL_LOW         = (u8)0x40, /**< 0x40 Steady low value on SCLK pin outside transmission window */
               UART1_SYNCMODE_CPOL_HIGH        = (u8)0x04, /**< 0x04 Steady high value on SCLK pin outside transmission window */
               UART1_SYNCMODE_CPHA_MIDDLE      = (u8)0x20, /**< 0x20 SCLK clock line activated in middle of data bit     */
               UART1_SYNCMODE_CPHA_BEGINING    = (u8)0x02, /**< 0x02 SCLK clock line activated at beginning of data bit  */
               UART1_SYNCMODE_LASTBIT_DISABLE  = (u8)0x10, /**< 0x10 The clock pulse of the last data bit is not output to the SCLK pin */
               UART1_SYNCMODE_LASTBIT_ENABLE   = (u8)0x01  /**< 0x01 The clock pulse of the last data bit is output to the SCLK pin */
             } UART1_SyncMode_TypeDef;

/**
  * @brief UART1 Word length possible values
  */
typedef enum { UART1_WORDLENGTH_8D = (u8)0x00,/**< 0x00 8 bits Data  */
               UART1_WORDLENGTH_9D = (u8)0x10 /**< 0x10 9 bits Data  */
             } UART1_WordLength_TypeDef;

/**
  * @brief UART1 Mode possible values
  */
typedef enum { UART1_MODE_RX_ENABLE     = (u8)0x08,  /**< 0x08 Receive Enable                     */
               UART1_MODE_TX_ENABLE     = (u8)0x04,  /**< 0x04 Transmit Enable                    */
               UART1_MODE_TX_DISABLE    = (u8)0x80,  /**< 0x80 Transmit Disable                   */
               UART1_MODE_RX_DISABLE    = (u8)0x40,  /**< 0x40 Single-wire Half-duplex mode       */
               UART1_MODE_TXRX_ENABLE   = (u8)0x0C  /**< 0x0C Transmit Enable and Receive Enable */
             } UART1_Mode_TypeDef;
/**
  * @brief UART1 Flag possible values
  */
typedef enum { UART1_FLAG_TXE   = (u16)0x0080, /*!< Transmit Data Register Empty flag */
               UART1_FLAG_TC  = (u16)0x0040, /*!< Transmission Complete flag */
               UART1_FLAG_RXNE = (u16)0x0020, /*!< Read Data Register Not Empty flag */
               UART1_FLAG_IDLE = (u16)0x0010, /*!< Idle line detected flag */
               UART1_FLAG_OR   = (u16)0x0008, /*!< OverRun error flag */
               UART1_FLAG_NF  = (u16)0x0004, /*!< Noise error flag */
               UART1_FLAG_FE  = (u16)0x0002, /*!< Framing Error flag */
               UART1_FLAG_PE  = (u16)0x0001, /*!< Parity Error flag */
               UART1_FLAG_LBDF   = (u16)0x0210, /*!< Line Break Detection Flag */
               UART1_FLAG_SBK   = (u16)0x0101  /*!< Send Break characters Flag */
             } UART1_Flag_TypeDef;

/**
  * @brief UART1 Interrupt definition
  * UART1_IT possible values
  * Elements values convention: 0xZYX
  * X: Position of the corresponding Interrupt
  * Y: Flag position
  * Z: Register index
  */
typedef enum { UART1_IT_TXE        = (u16)0x0277, /*!< Transmit interrupt */
               UART1_IT_TC         = (u16)0x0266, /*!< Transmission Complete interrupt */
               UART1_IT_RXNE       = (u16)0x0255, /*!< Receive interrupt */
               UART1_IT_IDLE       = (u16)0x0244, /*!< IDLE line interrupt */
               UART1_IT_OR        = (u16)0x0235, /*!< Overrun Error interrupt */
               UART1_IT_PE         = (u16)0x0100, /*!< Parity Error interrupt */
               UART1_IT_LBDF        = (u16)0x0346, /**< LIN break detection interrupt */
               UART1_IT_RXNE_OR   = (u16)0x0205  /*!< Receive/Overrun interrupt */
             } UART1_IT_TypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/** @addtogroup UART1_Private_Macros
  * @{
  */

/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */

/**
 * @brief Macro used by the assert_param function in order to check the different sensitivity values for the MODEs
 * possible combination should be one of the following
 */
#define IS_UART1_MODE_OK(Mode) \
  (((Mode) == (u8)UART1_MODE_RX_ENABLE) || \
   ((Mode) == (u8)UART1_MODE_RX_DISABLE) || \
   ((Mode) == (u8)UART1_MODE_TX_ENABLE) || \
   ((Mode) == (u8)UART1_MODE_TX_DISABLE) || \
   ((Mode) == (u8)UART1_MODE_TXRX_ENABLE) || \
   ((Mode) == (u8)((u8)UART1_MODE_TX_ENABLE|(u8)UART1_MODE_RX_ENABLE)) || \
   ((Mode) == (u8)((u8)UART1_MODE_TX_ENABLE|(u8)UART1_MODE_RX_DISABLE)) || \
   ((Mode) == (u8)((u8)UART1_MODE_TX_DISABLE|(u8)UART1_MODE_RX_DISABLE)) || \
   ((Mode) == (u8)((u8)UART1_MODE_TX_DISABLE|(u8)UART1_MODE_RX_ENABLE)))

/**
 * @brief Macro used by the assert_param function in order to check the different sensitivity values for the WordLengths
 */
#define IS_UART1_WORDLENGTH_OK(WordLength) \
  (((WordLength) == UART1_WORDLENGTH_8D) || \
   ((WordLength) == UART1_WORDLENGTH_9D))

/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the SyncModes; it should exclude values such as  UART1_CLOCK_ENABLE|UART1_CLOCK_DISABLE
  * UART1_SyncMode value should exclude values such as  UART1_CLOCK_ENABLE|UART1_CLOCK_DISABLE
  */
#define IS_UART1_SYNCMODE_OK(SyncMode) \
  (!((((SyncMode)&(((u8)UART1_SYNCMODE_CLOCK_ENABLE)|((u8)UART1_SYNCMODE_CLOCK_DISABLE))) == (((u8)UART1_SYNCMODE_CLOCK_ENABLE)|((u8)UART1_SYNCMODE_CLOCK_DISABLE))) || \
     (((SyncMode)&(((u8)UART1_SYNCMODE_CPOL_LOW )|((u8)UART1_SYNCMODE_CPOL_HIGH))) == (((u8)UART1_SYNCMODE_CPOL_LOW )|((u8)UART1_SYNCMODE_CPOL_HIGH))) || \
     (((SyncMode)&(((u8)UART1_SYNCMODE_CPHA_MIDDLE)|((u8)UART1_SYNCMODE_CPHA_BEGINING))) == (((u8)UART1_SYNCMODE_CPHA_MIDDLE)|((u8)UART1_SYNCMODE_CPHA_BEGINING))) || \
     (((SyncMode)&(((u8)UART1_SYNCMODE_LASTBIT_DISABLE)|((u8)UART1_SYNCMODE_LASTBIT_ENABLE))) == (((u8)UART1_SYNCMODE_LASTBIT_DISABLE)|((u8)UART1_SYNCMODE_LASTBIT_ENABLE)))))

/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the FLAGs
  */
#define IS_UART1_FLAG_OK(Flag) \
  (((Flag) == UART1_FLAG_TXE) || \
   ((Flag) == UART1_FLAG_TC)  || \
   ((Flag) == UART1_FLAG_RXNE) || \
   ((Flag) == UART1_FLAG_IDLE) || \
   ((Flag) == UART1_FLAG_OR) || \
   ((Flag) == UART1_FLAG_NF) || \
   ((Flag) == UART1_FLAG_FE) || \
   ((Flag) == UART1_FLAG_PE) || \
   ((Flag) == UART1_FLAG_SBK) || \
   ((Flag) == UART1_FLAG_LBDF))
/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the FLAGs that can be cleared by writing 0
  */
#define IS_UART1_CLEAR_FLAG_OK(Flag) \
  (((Flag) == UART1_FLAG_RXNE) || \
   ((Flag) == UART1_FLAG_LBDF))



/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the Interrupts
  */

#define IS_UART1_CONFIG_IT_OK(Interrupt) \
  (((Interrupt) == UART1_IT_PE) || \
   ((Interrupt) == UART1_IT_TXE) || \
   ((Interrupt) == UART1_IT_TC) || \
   ((Interrupt) == UART1_IT_RXNE_OR ) || \
   ((Interrupt) == UART1_IT_IDLE) || \
   ((Interrupt) == UART1_IT_LBDF))

/**
  * @brief Macro used by the assert function in order to check the different sensitivity values for the pending bit
  */
#define IS_UART1_GET_IT_OK(ITPendingBit) \
  (((ITPendingBit) == UART1_IT_TXE)  || \
   ((ITPendingBit) == UART1_IT_TC)   || \
   ((ITPendingBit) == UART1_IT_RXNE) || \
   ((ITPendingBit) == UART1_IT_IDLE) || \
   ((ITPendingBit) == UART1_IT_OR)  || \
   ((ITPendingBit) == UART1_IT_LBDF)  || \
   ((ITPendingBit) == UART1_IT_PE))

/**
  * @brief Macro used by the assert function in order to check the different sensitivity values for the pending bit that can be cleared by writing 0
  */
#define IS_UART1_CLEAR_IT_OK(ITPendingBit) \
  (((ITPendingBit) == UART1_IT_RXNE) || \
   ((ITPendingBit) == UART1_IT_LBDF))


/**
 * @brief Macro used by the assert_param function in order to check the different sensitivity values for the IrDAModes
 */
#define IS_UART1_IRDAMODE_OK(IrDAMode) \
  (((IrDAMode) == UART1_IRDAMODE_LOWPOWER) || \
   ((IrDAMode) == UART1_IRDAMODE_NORMAL))

/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the WakeUps
  */
#define IS_UART1_WAKEUP_OK(WakeUp) \
  (((WakeUp) == UART1_WAKEUP_IDLELINE) || \
   ((WakeUp) == UART1_WAKEUP_ADDRESSMARK))

/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the LINBreakDetectionLengths
  */
#define IS_UART1_LINBREAKDETECTIONLENGTH_OK(LINBreakDetectionLength) \
  (((LINBreakDetectionLength) == UART1_LINBREAKDETECTIONLENGTH_10BITS) || \
   ((LINBreakDetectionLength) == UART1_LINBREAKDETECTIONLENGTH_11BITS))

/**
  * @brief Macro used by the assert_param function in order to check the different sensitivity values for the UART1_StopBits
  */
#define IS_UART1_STOPBITS_OK(StopBit) (((StopBit) == UART1_STOPBITS_1) || \
                                       ((StopBit) == UART1_STOPBITS_0_5) || \
                                       ((StopBit) == UART1_STOPBITS_2) || \
                                       ((StopBit) == UART1_STOPBITS_1_5 ))

/**
 * @brief Macro used by the assert_param function in order to check the different sensitivity values for the Paritys
 */
#define IS_UART1_PARITY_OK(Parity) (((Parity) == UART1_PARITY_NO) || \
                                    ((Parity) == UART1_PARITY_EVEN) || \
                                    ((Parity) == UART1_PARITY_ODD ))

/**
 * @brief Macro used by the assert_param function in order to check the maximum baudrate value
 */
#define IS_UART1_BAUDRATE_OK(NUM) ((NUM) <= (u32)625000)


/**
 * @brief Macro used by the assert_param function in order to check the address of the UART1 or UART node
 */
#define UART1_ADDRESS_MAX ((u8)16)
#define IS_UART1_ADDRESS_OK(node) ((node) < UART1_ADDRESS_MAX )

/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup UART1_Exported_Functions
  * @{
  */

void UART1_DeInit(void);
void UART1_Init(u32 BaudRate, UART1_WordLength_TypeDef WordLength, UART1_StopBits_TypeDef StopBits, UART1_Parity_TypeDef Parity, UART1_SyncMode_TypeDef SyncMode, UART1_Mode_TypeDef Mode);
void UART1_Cmd(FunctionalState NewState);
void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState);
void UART1_HalfDuplexCmd(FunctionalState NewState);
void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode);
void UART1_IrDACmd(FunctionalState NewState);
void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength);
void UART1_LINCmd(FunctionalState NewState);
void UART1_SmartCardCmd(FunctionalState NewState);
void UART1_SmartCardNACKCmd(FunctionalState NewState);
void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp);
void UART1_ReceiverWakeUpCmd(FunctionalState NewState);
u8 UART1_ReceiveData8(void);
u16 UART1_ReceiveData9(void);
void UART1_SendData8(u8 Data);
void UART1_SendData9(u16 Data);
void UART1_SendBreak(void);
void UART1_SetAddress(u8 UART1_Address);
void UART1_SetGuardTime(u8 UART1_GuardTime);
void UART1_SetPrescaler(u8 UART1_Prescaler);

FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG);
void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG);
ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT);
void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT);

/**
  * @}
  */

#endif /* __STM8S_UART1_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
