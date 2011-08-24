/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

/**
 * @file    STM8S/serial_lld.h
 * @brief   STM8S low level serial driver header.
 *
 * @addtogroup SERIAL
 * @{
 */

#ifndef _SERIAL_LLD_H_
#define _SERIAL_LLD_H_

#if HAL_USE_SERIAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define SD_MODE_PARITY          0x07        /**< @brief Parity field mask.  */
#define SD_MODE_PARITY_NONE     0x00        /**< @brief No parity.          */
#define SD_MODE_PARITY_EVEN     0x05        /**< @brief Even parity.        */
#define SD_MODE_PARITY_ODD      0x07        /**< @brief Odd parity.         */

#define SD_MODE_STOP            0x30        /**< @brief Stop bits mask.     */
#define SD_MODE_STOP_1          0x00        /**< @brief One stop bit.       */
#define SD_MODE_STOP_2          0x20        /**< @brief Two stop bits.      */
#define SD_MODE_STOP_1P5        0x30        /**< @brief 1.5 stop bits.      */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   UART1 driver enable switch.
 * @details If set to @p TRUE the support for UART1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM8S_SERIAL_USE_UART1) || defined(__DOXYGEN__)
#define STM8S_SERIAL_USE_UART1          TRUE
#endif

/**
 * @brief   UART2 driver enable switch.
 * @details If set to @p TRUE the support for UART3 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM8S_SERIAL_USE_UART2) || defined(__DOXYGEN__)
#define STM8S_SERIAL_USE_UART2          TRUE
#endif

/**
 * @brief   UART3 driver enable switch.
 * @details If set to @p TRUE the support for UART3 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM8S_SERIAL_USE_UART3) || defined(__DOXYGEN__)
#define STM8S_SERIAL_USE_UART3          TRUE
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if STM8S_SERIAL_USE_UART2 && STM8S_SERIAL_USE_UART3
#error "STM8S UART2 and UART3 cannot be used together"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Generic Serial Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a serial driver operations.
 * @note    This structure content is architecture dependent, each driver
 *          implementation defines its own version and the custom static
 *          initializers.
 */
typedef struct {
  /**
   * @brief Bit rate register.
   */
  uint16_t                  sc_brr;
  /**
   * @brief Mode flags.
   */
  uint8_t                   sc_mode;
} SerialConfig;

/**
 * @brief   @p SerialDriver specific data.
 */
#define _serial_driver_data                                                 \
  _base_asynchronous_channel_data                                           \
  /* Driver state.*/                                                        \
  sdstate_t                 state;                                          \
  /* Input queue.*/                                                         \
  InputQueue                iqueue;                                         \
  /* Output queue.*/                                                        \
  OutputQueue               oqueue;                                         \
  /* Input circular buffer.*/                                               \
  uint8_t                   ib[SERIAL_BUFFERS_SIZE];                        \
  /* Output circular buffer.*/                                              \
  uint8_t                   ob[SERIAL_BUFFERS_SIZE];                        \
  /* End of the mandatory fields.*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Macro for baud rate computation.
 * @note    Make sure the final baud rate is within tolerance.
 */
#define BRR(b) (SYSCLK / (b))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM8S_SERIAL_USE_UART1 && !defined(__DOXYGEN__)
extern SerialDriver SD1;
#endif
#if STM8S_SERIAL_USE_UART2 && !defined(__DOXYGEN__)
extern SerialDriver SD2;
#endif
#if STM8S_SERIAL_USE_UART3 && !defined(__DOXYGEN__)
extern SerialDriver SD3;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sd_lld_init(void);
  void sd_lld_start(SerialDriver *sdp, const SerialConfig *config);
  void sd_lld_stop(SerialDriver *sdp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SERIAL */

#endif /* _SERIAL_LLD_H_ */

/** @} */
