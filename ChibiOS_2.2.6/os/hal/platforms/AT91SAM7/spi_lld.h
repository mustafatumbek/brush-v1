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
 * @file    AT91SAM7/spi_lld.h
 * @brief   AT91SAM7 low level SPI driver header.
 *
 * @addtogroup SPI
 * @{
 */

#ifndef _SPI_LLD_H_
#define _SPI_LLD_H_

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Device compatibility..                                                    */
/*===========================================================================*/

#if defined (AT91C_BASE_SPI)
#define AT91C_BASE_SPI0                 AT91C_BASE_SPI
#define AT91C_ID_SPI0                   AT91C_ID_SPI

#define SPI0_MISO                       (1 << 12)
#define SPI0_MOSI                       (1 << 13)
#define SPI0_SCK                        (1 << 14)
#else
#define SPI0_MISO                       (1 << 16)
#define SPI0_MOSI                       (1 << 17)
#define SPI0_SCK                        (1 << 18)

#define SPI1_MISO                       (1 << 24)
#define SPI1_MOSI                       (1 << 23)
#define SPI1_SCK                        (1 << 22)
#endif

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   SPID1 enable switch (SPI0 device).
 * @details If set to @p TRUE the support for SPI0 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(AT91SAM7_SPI_USE_SPI0) || defined(__DOXYGEN__)
#define AT91SAM7_SPI_USE_SPI0           TRUE
#endif

/**
 * @brief   SPID2 enable switch (SPI1 device).
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(AT91SAM7_SPI_USE_SPI1) || defined(__DOXYGEN__)
#define AT91SAM7_SPI_USE_SPI1           TRUE
#endif

/**
 * @brief   SPI0 device interrupt priority level setting.
 */
#if !defined(AT91SAM7_SPI0_PRIORITY) || defined(__DOXYGEN__)
#define AT91SAM7_SPI0_PRIORITY          (AT91C_AIC_PRIOR_HIGHEST - 1)
#endif

/**
 * @brief   SPI1 device interrupt priority level setting.
 */
#if !defined(AT91SAM7_SPI1_PRIORITY) || defined(__DOXYGEN__)
#define AT91SAM7_SPI1_PRIORITY          (AT91C_AIC_PRIOR_HIGHEST - 1)
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if defined (AT91C_BASE_SPI) && AT91SAM7_SPI_USE_SPI1
#error "SPI1 not present"
#endif

#if !AT91SAM7_SPI_USE_SPI0 && !AT91SAM7_SPI_USE_SPI1
#error "SPI driver activated but no SPI peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing an SPI driver.
 */
typedef struct SPIDriver SPIDriver;

/**
 * @brief   SPI notification callback type.
 *
 * @param[in] spip      pointer to the @p SPIDriver object triggering the
 *                      callback
 */
typedef void (*spicallback_t)(SPIDriver *spip);

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
   * @brief Operation complete callback or @p NULL.
   */
  spicallback_t         spc_endcb;
  /* End of the mandatory fields.*/
  /**
   * @brief The chip select line port.
   */
  ioportid_t            spc_ssport;
  /**
   * @brief The chip select line pad number.
   */
  uint16_t              spc_sspad;
  /**
   * @brief SPI Chip Select Register initialization data.
   */
  uint32_t              spc_csr;
} SPIConfig;

/**
 * @brief Structure representing a SPI driver.
 */
struct SPIDriver {
  /**
   * @brief Driver state.
   */
  spistate_t            spd_state;
  /**
   * @brief Current configuration data.
   */
  const SPIConfig       *spd_config;
#if SPI_USE_WAIT || defined(__DOXYGEN__)
  /**
   * @brief Waiting thread.
   */
  Thread                *spd_thread;
#endif /* SPI_USE_WAIT */
#if SPI_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
#if CH_USE_MUTEXES || defined(__DOXYGEN__)
  /**
   * @brief Mutex protecting the bus.
   */
  Mutex                 spd_mutex;
#elif CH_USE_SEMAPHORES
  Semaphore             spd_semaphore;
#endif
#endif /* SPI_USE_MUTUAL_EXCLUSION */
#if defined(SPI_DRIVER_EXT_FIELDS)
  SPI_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the SPIx registers block.
   */
  AT91PS_SPI            spd_spi;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT91SAM7_SPI_USE_SPI0 && !defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif

#if AT91SAM7_SPI_USE_SPI1 && !defined(__DOXYGEN__)
extern SPIDriver SPID2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void spi_lld_init(void);
  void spi_lld_start(SPIDriver *spip);
  void spi_lld_stop(SPIDriver *spip);
  void spi_lld_select(SPIDriver *spip);
  void spi_lld_unselect(SPIDriver *spip);
  void spi_lld_ignore(SPIDriver *spip, size_t n);
  void spi_lld_exchange(SPIDriver *spip, size_t n,
                        const void *txbuf, void *rxbuf);
  void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf);
  void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf);
  uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SPI */

#endif /* _SPI_LLD_H_ */

/** @} */
