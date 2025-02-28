/*
 * MIT License 
 * 
 * Copyright (c) 2020 Kirill Kotyagin
 */

#ifndef USB_CORE_H
#define USB_CORE_H

#include <stdint.h>
#include <stddef.h>
#include "stm32f10x.h"
#include "usb_std.h"
#include "usb_io.h"
typedef struct
{
  __IO uint16_t EP0R;                 /*!< USB Endpoint 0 register,                   Address offset: 0x00 */ 
  __IO uint16_t RESERVED0;            /*!< Reserved */     
  __IO uint16_t EP1R;                 /*!< USB Endpoint 1 register,                   Address offset: 0x04 */
  __IO uint16_t RESERVED1;            /*!< Reserved */       
  __IO uint16_t EP2R;                 /*!< USB Endpoint 2 register,                   Address offset: 0x08 */
  __IO uint16_t RESERVED2;            /*!< Reserved */       
  __IO uint16_t EP3R;                 /*!< USB Endpoint 3 register,                   Address offset: 0x0C */ 
  __IO uint16_t RESERVED3;            /*!< Reserved */       
  __IO uint16_t EP4R;                 /*!< USB Endpoint 4 register,                   Address offset: 0x10 */
  __IO uint16_t RESERVED4;            /*!< Reserved */       
  __IO uint16_t EP5R;                 /*!< USB Endpoint 5 register,                   Address offset: 0x14 */
  __IO uint16_t RESERVED5;            /*!< Reserved */       
  __IO uint16_t EP6R;                 /*!< USB Endpoint 6 register,                   Address offset: 0x18 */
  __IO uint16_t RESERVED6;            /*!< Reserved */       
  __IO uint16_t EP7R;                 /*!< USB Endpoint 7 register,                   Address offset: 0x1C */
  __IO uint16_t RESERVED7[17];        /*!< Reserved */     
  __IO uint16_t CNTR;                 /*!< Control register,                          Address offset: 0x40 */
  __IO uint16_t RESERVED8;            /*!< Reserved */       
  __IO uint16_t ISTR;                 /*!< Interrupt status register,                 Address offset: 0x44 */
  __IO uint16_t RESERVED9;            /*!< Reserved */       
  __IO uint16_t FNR;                  /*!< Frame number register,                     Address offset: 0x48 */
  __IO uint16_t RESERVEDA;            /*!< Reserved */       
  __IO uint16_t DADDR;                /*!< Device address register,                   Address offset: 0x4C */
  __IO uint16_t RESERVEDB;            /*!< Reserved */       
  __IO uint16_t BTABLE;               /*!< Buffer Table address register,             Address offset: 0x50 */
  __IO uint16_t RESERVEDC;            /*!< Reserved */       
} USB_TypeDef;
#define USB_BASE              (APB1PERIPH_BASE + 0x00005C00) /*!< USB_IP Peripheral Registers base address */
#define UID_BASE              ((uint32_t)0x1FFFF7E8)    /*!< Unique device ID register base address */
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x00006000) /*!< USB_IP Packet Memory Area base address */
#define USB                 ((USB_TypeDef *) USB_BASE)
/******************************************************************************/
/*                                                                            */
/*                                   USB Device FS                            */
/*                                                                            */
/******************************************************************************/
#define USB_SETUP_MAX_PAYLOAD_SIZE   32
#define USB_SETUP_MAX_SIZE (sizeof(usb_setup_t) + USB_SETUP_MAX_PAYLOAD_SIZE)

/*!< Endpoint-specific registers */
#define  USB_EP0R                            USB_BASE                      /*!< Endpoint 0 register address */
#define  USB_EP1R                            (USB_BASE + 0x00000004)       /*!< Endpoint 1 register address */
#define  USB_EP2R                            (USB_BASE + 0x00000008)       /*!< Endpoint 2 register address */
#define  USB_EP3R                            (USB_BASE + 0x0000000C)       /*!< Endpoint 3 register address */
#define  USB_EP4R                            (USB_BASE + 0x00000010)       /*!< Endpoint 4 register address */
#define  USB_EP5R                            (USB_BASE + 0x00000014)       /*!< Endpoint 5 register address */
#define  USB_EP6R                            (USB_BASE + 0x00000018)       /*!< Endpoint 6 register address */
#define  USB_EP7R                            (USB_BASE + 0x0000001C)       /*!< Endpoint 7 register address */

/* bit positions */ 
#define USB_EP_CTR_RX_Pos                       (15U)                          
#define USB_EP_CTR_RX_Msk                       (0x1U << USB_EP_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP_CTR_RX                           USB_EP_CTR_RX_Msk              /*!< EndPoint Correct TRansfer RX */
#define USB_EP_DTOG_RX_Pos                      (14U)                          
#define USB_EP_DTOG_RX_Msk                      (0x1U << USB_EP_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP_DTOG_RX                          USB_EP_DTOG_RX_Msk             /*!< EndPoint Data TOGGLE RX */
#define USB_EPRX_STAT_Pos                       (12U)                          
#define USB_EPRX_STAT_Msk                       (0x3U << USB_EPRX_STAT_Pos)    /*!< 0x00003000 */
#define USB_EPRX_STAT                           USB_EPRX_STAT_Msk              /*!< EndPoint RX STATus bit field */
#define USB_EP_SETUP_Pos                        (11U)                          
#define USB_EP_SETUP_Msk                        (0x1U << USB_EP_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP_SETUP                            USB_EP_SETUP_Msk               /*!< EndPoint SETUP */
#define USB_EP_T_FIELD_Pos                      (9U)                           
#define USB_EP_T_FIELD_Msk                      (0x3U << USB_EP_T_FIELD_Pos)   /*!< 0x00000600 */
#define USB_EP_T_FIELD                          USB_EP_T_FIELD_Msk             /*!< EndPoint TYPE */
#define USB_EP_KIND_Pos                         (8U)                           
#define USB_EP_KIND_Msk                         (0x1U << USB_EP_KIND_Pos)      /*!< 0x00000100 */
#define USB_EP_KIND                             USB_EP_KIND_Msk                /*!< EndPoint KIND */
#define USB_EP_CTR_TX_Pos                       (7U)                           
#define USB_EP_CTR_TX_Msk                       (0x1U << USB_EP_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP_CTR_TX                           USB_EP_CTR_TX_Msk              /*!< EndPoint Correct TRansfer TX */
#define USB_EP_DTOG_TX_Pos                      (6U)                           
#define USB_EP_DTOG_TX_Msk                      (0x1U << USB_EP_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP_DTOG_TX                          USB_EP_DTOG_TX_Msk             /*!< EndPoint Data TOGGLE TX */
#define USB_EPTX_STAT_Pos                       (4U)                           
#define USB_EPTX_STAT_Msk                       (0x3U << USB_EPTX_STAT_Pos)    /*!< 0x00000030 */
#define USB_EPTX_STAT                           USB_EPTX_STAT_Msk              /*!< EndPoint TX STATus bit field */
#define USB_EPADDR_FIELD_Pos                    (0U)                           
#define USB_EPADDR_FIELD_Msk                    (0xFU << USB_EPADDR_FIELD_Pos) /*!< 0x0000000F */
#define USB_EPADDR_FIELD                        USB_EPADDR_FIELD_Msk           /*!< EndPoint ADDRess FIELD */

/* EndPoint REGister MASK (no toggle fields) */
#define  USB_EPREG_MASK                      (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)
                                                                           /*!< EP_TYPE[1:0] EndPoint TYPE */
#define USB_EP_TYPE_MASK_Pos                    (9U)                           
#define USB_EP_TYPE_MASK_Msk                    (0x3U << USB_EP_TYPE_MASK_Pos) /*!< 0x00000600 */
#define USB_EP_TYPE_MASK                        USB_EP_TYPE_MASK_Msk           /*!< EndPoint TYPE Mask */
#define USB_EP_BULK                             ((uint32_t)0x00000000)         /*!< EndPoint BULK */
#define USB_EP_CONTROL                          ((uint32_t)0x00000200)         /*!< EndPoint CONTROL */
#define USB_EP_ISOCHRONOUS                      ((uint32_t)0x00000400)         /*!< EndPoint ISOCHRONOUS */
#define USB_EP_INTERRUPT                        ((uint32_t)0x00000600)         /*!< EndPoint INTERRUPT */
#define  USB_EP_T_MASK                       (~USB_EP_T_FIELD & USB_EPREG_MASK)
                                                                 
#define  USB_EPKIND_MASK                     (~USB_EP_KIND & USB_EPREG_MASK)  /*!< EP_KIND EndPoint KIND */
                                                                           /*!< STAT_TX[1:0] STATus for TX transfer */
#define USB_EP_TX_DIS                           ((uint32_t)0x00000000)         /*!< EndPoint TX DISabled */
#define USB_EP_TX_STALL                         ((uint32_t)0x00000010)         /*!< EndPoint TX STALLed */
#define USB_EP_TX_NAK                           ((uint32_t)0x00000020)         /*!< EndPoint TX NAKed */
#define USB_EP_TX_VALID                         ((uint32_t)0x00000030)         /*!< EndPoint TX VALID */
#define USB_EPTX_DTOG1                          ((uint32_t)0x00000010)         /*!< EndPoint TX Data TOGgle bit1 */
#define USB_EPTX_DTOG2                          ((uint32_t)0x00000020)         /*!< EndPoint TX Data TOGgle bit2 */
#define  USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)
                                                                           /*!< STAT_RX[1:0] STATus for RX transfer */
#define USB_EP_RX_DIS                           ((uint32_t)0x00000000)         /*!< EndPoint RX DISabled */
#define USB_EP_RX_STALL                         ((uint32_t)0x00001000)         /*!< EndPoint RX STALLed */
#define USB_EP_RX_NAK                           ((uint32_t)0x00002000)         /*!< EndPoint RX NAKed */
#define USB_EP_RX_VALID                         ((uint32_t)0x00003000)         /*!< EndPoint RX VALID */
#define USB_EPRX_DTOG1                          ((uint32_t)0x00001000)         /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOG2                          ((uint32_t)0x00002000)         /*!< EndPoint RX Data TOGgle bit1 */
#define  USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)

/*******************  Bit definition for USB_EP0R register  *******************/
#define USB_EP0R_EA_Pos                         (0U)                           
#define USB_EP0R_EA_Msk                         (0xFU << USB_EP0R_EA_Pos)      /*!< 0x0000000F */
//#define USB_EP0R_EA                             USB_EP0R_EA_Msk                /*!< Endpoint Address */

#define USB_EP0R_STAT_TX_Pos                    (4U)                           
#define USB_EP0R_STAT_TX_Msk                    (0x3U << USB_EP0R_STAT_TX_Pos) /*!< 0x00000030 */
//#define USB_EP0R_STAT_TX                        USB_EP0R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
//#define USB_EP0R_STAT_TX_0                      (0x1U << USB_EP0R_STAT_TX_Pos) /*!< 0x00000010 */
//#define USB_EP0R_STAT_TX_1                      (0x2U << USB_EP0R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP0R_DTOG_TX_Pos                    (6U)                           
#define USB_EP0R_DTOG_TX_Msk                    (0x1U << USB_EP0R_DTOG_TX_Pos) /*!< 0x00000040 */
//#define USB_EP0R_DTOG_TX                        USB_EP0R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP0R_CTR_TX_Pos                     (7U)                           
#define USB_EP0R_CTR_TX_Msk                     (0x1U << USB_EP0R_CTR_TX_Pos)  /*!< 0x00000080 */
//#define USB_EP0R_CTR_TX                         USB_EP0R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP0R_EP_KIND_Pos                    (8U)                           
#define USB_EP0R_EP_KIND_Msk                    (0x1U << USB_EP0R_EP_KIND_Pos) /*!< 0x00000100 */
//#define USB_EP0R_EP_KIND                        USB_EP0R_EP_KIND_Msk           /*!< Endpoint Kind */
                                                                           
#define USB_EP0R_EP_TYPE_Pos                    (9U)                           
#define USB_EP0R_EP_TYPE_Msk                    (0x3U << USB_EP0R_EP_TYPE_Pos) /*!< 0x00000600 */
//#define USB_EP0R_EP_TYPE                        USB_EP0R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
//#define USB_EP0R_EP_TYPE_0                      (0x1U << USB_EP0R_EP_TYPE_Pos) /*!< 0x00000200 */
//#define USB_EP0R_EP_TYPE_1                      (0x2U << USB_EP0R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP0R_SETUP_Pos                      (11U)                          
#define USB_EP0R_SETUP_Msk                      (0x1U << USB_EP0R_SETUP_Pos)   /*!< 0x00000800 */
//#define USB_EP0R_SETUP                          USB_EP0R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP0R_STAT_RX_Pos                    (12U)                          
#define USB_EP0R_STAT_RX_Msk                    (0x3U << USB_EP0R_STAT_RX_Pos) /*!< 0x00003000 */
//#define USB_EP0R_STAT_RX                        USB_EP0R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
//#define USB_EP0R_STAT_RX_0                      (0x1U << USB_EP0R_STAT_RX_Pos) /*!< 0x00001000 */
//#define USB_EP0R_STAT_RX_1                      (0x2U << USB_EP0R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP0R_DTOG_RX_Pos                    (14U)                          
#define USB_EP0R_DTOG_RX_Msk                    (0x1U << USB_EP0R_DTOG_RX_Pos) /*!< 0x00004000 */
//#define USB_EP0R_DTOG_RX                        USB_EP0R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP0R_CTR_RX_Pos                     (15U)                          
#define USB_EP0R_CTR_RX_Msk                     (0x1U << USB_EP0R_CTR_RX_Pos)  /*!< 0x00008000 */
//#define USB_EP0R_CTR_RX                         USB_EP0R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP1R register  *******************/
#define USB_EP1R_EA_Pos                         (0U)                           
#define USB_EP1R_EA_Msk                         (0xFU << USB_EP1R_EA_Pos)      /*!< 0x0000000F */
//#define USB_EP1R_EA                             USB_EP1R_EA_Msk                /*!< Endpoint Address */
                                                                          
#define USB_EP1R_STAT_TX_Pos                    (4U)                           
#define USB_EP1R_STAT_TX_Msk                    (0x3U << USB_EP1R_STAT_TX_Pos) /*!< 0x00000030 */
//#define USB_EP1R_STAT_TX                        USB_EP1R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
//#define USB_EP1R_STAT_TX_0                      (0x1U << USB_EP1R_STAT_TX_Pos) /*!< 0x00000010 */
//#define USB_EP1R_STAT_TX_1                      (0x2U << USB_EP1R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP1R_DTOG_TX_Pos                    (6U)                           
#define USB_EP1R_DTOG_TX_Msk                    (0x1U << USB_EP1R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP1R_CTR_TX_Pos                     (7U)                           
#define USB_EP1R_CTR_TX_Msk                     (0x1U << USB_EP1R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP1R_EP_KIND_Pos                    (8U)                           
#define USB_EP1R_EP_KIND_Msk                    (0x1U << USB_EP1R_EP_KIND_Pos) /*!< 0x00000100 */

#define USB_EP1R_EP_TYPE_Pos                    (9U)                           
#define USB_EP1R_EP_TYPE_Msk                    (0x3U << USB_EP1R_EP_TYPE_Pos) /*!< 0x00000600 */

#define USB_EP1R_SETUP_Pos                      (11U)                          
#define USB_EP1R_SETUP_Msk                      (0x1U << USB_EP1R_SETUP_Pos)   /*!< 0x00000800 */
                                                                           
#define USB_EP1R_STAT_RX_Pos                    (12U)                          
#define USB_EP1R_STAT_RX_Msk                    (0x3U << USB_EP1R_STAT_RX_Pos) /*!< 0x00003000 */

#define USB_EP1R_DTOG_RX_Pos                    (14U)                          
#define USB_EP1R_DTOG_RX_Msk                    (0x1U << USB_EP1R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP1R_CTR_RX_Pos                     (15U)                          
#define USB_EP1R_CTR_RX_Msk                     (0x1U << USB_EP1R_CTR_RX_Pos)  /*!< 0x00008000 */

/*******************  Bit definition for USB_EP2R register  *******************/
#define USB_EP2R_EA_Pos                         (0U)                           
#define USB_EP2R_EA_Msk                         (0xFU << USB_EP2R_EA_Pos)      /*!< 0x0000000F */

#define USB_EP2R_STAT_TX_Pos                    (4U)                           
#define USB_EP2R_STAT_TX_Msk                    (0x3U << USB_EP2R_STAT_TX_Pos) /*!< 0x00000030 */

#define USB_EP2R_DTOG_TX_Pos                    (6U)                           
#define USB_EP2R_DTOG_TX_Msk                    (0x1U << USB_EP2R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP2R_CTR_TX_Pos                     (7U)                           
#define USB_EP2R_CTR_TX_Msk                     (0x1U << USB_EP2R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP2R_EP_KIND_Pos                    (8U)                           
#define USB_EP2R_EP_KIND_Msk                    (0x1U << USB_EP2R_EP_KIND_Pos) /*!< 0x00000100 */

#define USB_EP2R_EP_TYPE_Pos                    (9U)                           
#define USB_EP2R_EP_TYPE_Msk                    (0x3U << USB_EP2R_EP_TYPE_Pos) /*!< 0x00000600 */

#define USB_EP2R_SETUP_Pos                      (11U)                          
#define USB_EP2R_SETUP_Msk                      (0x1U << USB_EP2R_SETUP_Pos)   /*!< 0x00000800 */

#define USB_EP2R_STAT_RX_Pos                    (12U)                          
#define USB_EP2R_STAT_RX_Msk                    (0x3U << USB_EP2R_STAT_RX_Pos) /*!< 0x00003000 */

#define USB_EP2R_DTOG_RX_Pos                    (14U)                          
#define USB_EP2R_DTOG_RX_Msk                    (0x1U << USB_EP2R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP2R_CTR_RX_Pos                     (15U)                          
#define USB_EP2R_CTR_RX_Msk                     (0x1U << USB_EP2R_CTR_RX_Pos)  /*!< 0x00008000 */

/*******************  Bit definition for USB_EP3R register  *******************/
#define USB_EP3R_EA_Pos                         (0U)                           
#define USB_EP3R_EA_Msk                         (0xFU << USB_EP3R_EA_Pos)      /*!< 0x0000000F */

#define USB_EP3R_STAT_TX_Pos                    (4U)                           
#define USB_EP3R_STAT_TX_Msk                    (0x3U << USB_EP3R_STAT_TX_Pos) /*!< 0x00000030 */

#define USB_EP3R_DTOG_TX_Pos                    (6U)                           
#define USB_EP3R_DTOG_TX_Msk                    (0x1U << USB_EP3R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP3R_CTR_TX_Pos                     (7U)                           
#define USB_EP3R_CTR_TX_Msk                     (0x1U << USB_EP3R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP3R_EP_KIND_Pos                    (8U)                           
#define USB_EP3R_EP_KIND_Msk                    (0x1U << USB_EP3R_EP_KIND_Pos) /*!< 0x00000100 */

#define USB_EP3R_EP_TYPE_Pos                    (9U)                           
#define USB_EP3R_EP_TYPE_Msk                    (0x3U << USB_EP3R_EP_TYPE_Pos) /*!< 0x00000600 */

#define USB_EP3R_SETUP_Pos                      (11U)                          
#define USB_EP3R_SETUP_Msk                      (0x1U << USB_EP3R_SETUP_Pos)   /*!< 0x00000800 */

#define USB_EP3R_STAT_RX_Pos                    (12U)                          
#define USB_EP3R_STAT_RX_Msk                    (0x3U << USB_EP3R_STAT_RX_Pos) /*!< 0x00003000 */

#define USB_EP3R_DTOG_RX_Pos                    (14U)                          
#define USB_EP3R_DTOG_RX_Msk                    (0x1U << USB_EP3R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP3R_CTR_RX_Pos                     (15U)                          
#define USB_EP3R_CTR_RX_Msk                     (0x1U << USB_EP3R_CTR_RX_Pos)  /*!< 0x00008000 */

/*******************  Bit definition for USB_EP4R register  *******************/
#define USB_EP4R_EA_Pos                         (0U)                           
#define USB_EP4R_EA_Msk                         (0xFU << USB_EP4R_EA_Pos)      /*!< 0x0000000F */

#define USB_EP4R_STAT_TX_Pos                    (4U)                           
#define USB_EP4R_STAT_TX_Msk                    (0x3U << USB_EP4R_STAT_TX_Pos) /*!< 0x00000030 */

#define USB_EP4R_DTOG_TX_Pos                    (6U)                           
#define USB_EP4R_DTOG_TX_Msk                    (0x1U << USB_EP4R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP4R_CTR_TX_Pos                     (7U)                           
#define USB_EP4R_CTR_TX_Msk                     (0x1U << USB_EP4R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP4R_EP_KIND_Pos                    (8U)                           
#define USB_EP4R_EP_KIND_Msk                    (0x1U << USB_EP4R_EP_KIND_Pos) /*!< 0x00000100 */

#define USB_EP4R_EP_TYPE_Pos                    (9U)                           
#define USB_EP4R_EP_TYPE_Msk                    (0x3U << USB_EP4R_EP_TYPE_Pos) /*!< 0x00000600 */

#define USB_EP4R_SETUP_Pos                      (11U)                          
#define USB_EP4R_SETUP_Msk                      (0x1U << USB_EP4R_SETUP_Pos)   /*!< 0x00000800 */

#define USB_EP4R_STAT_RX_Pos                    (12U)                          
#define USB_EP4R_STAT_RX_Msk                    (0x3U << USB_EP4R_STAT_RX_Pos) /*!< 0x00003000 */

#define USB_EP4R_DTOG_RX_Pos                    (14U)                          
#define USB_EP4R_DTOG_RX_Msk                    (0x1U << USB_EP4R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP4R_CTR_RX_Pos                     (15U)                          
#define USB_EP4R_CTR_RX_Msk                     (0x1U << USB_EP4R_CTR_RX_Pos)  /*!< 0x00008000 */

/*******************  Bit definition for USB_EP5R register  *******************/
#define USB_EP5R_EA_Pos                         (0U)                           
#define USB_EP5R_EA_Msk                         (0xFU << USB_EP5R_EA_Pos)      /*!< 0x0000000F */

#define USB_EP5R_STAT_TX_Pos                    (4U)                           
#define USB_EP5R_STAT_TX_Msk                    (0x3U << USB_EP5R_STAT_TX_Pos) /*!< 0x00000030 */

#define USB_EP5R_DTOG_TX_Pos                    (6U)                           
#define USB_EP5R_DTOG_TX_Msk                    (0x1U << USB_EP5R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP5R_CTR_TX_Pos                     (7U)                           
#define USB_EP5R_CTR_TX_Msk                     (0x1U << USB_EP5R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP5R_EP_KIND_Pos                    (8U)                           
#define USB_EP5R_EP_KIND_Msk                    (0x1U << USB_EP5R_EP_KIND_Pos) /*!< 0x00000100 */

#define USB_EP5R_EP_TYPE_Pos                    (9U)                           
#define USB_EP5R_EP_TYPE_Msk                    (0x3U << USB_EP5R_EP_TYPE_Pos) /*!< 0x00000600 */

#define USB_EP5R_SETUP_Pos                      (11U)                          
#define USB_EP5R_SETUP_Msk                      (0x1U << USB_EP5R_SETUP_Pos)   /*!< 0x00000800 */

#define USB_EP5R_STAT_RX_Pos                    (12U)                          
#define USB_EP5R_STAT_RX_Msk                    (0x3U << USB_EP5R_STAT_RX_Pos) /*!< 0x00003000 */

#define USB_EP5R_DTOG_RX_Pos                    (14U)                          
#define USB_EP5R_DTOG_RX_Msk                    (0x1U << USB_EP5R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP5R_CTR_RX_Pos                     (15U)                          
#define USB_EP5R_CTR_RX_Msk                     (0x1U << USB_EP5R_CTR_RX_Pos)  /*!< 0x00008000 */

/*******************  Bit definition for USB_EP6R register  *******************/
#define USB_EP6R_EA_Pos                         (0U)                           
#define USB_EP6R_EA_Msk                         (0xFU << USB_EP6R_EA_Pos)      /*!< 0x0000000F */

#define USB_EP6R_STAT_TX_Pos                    (4U)                           
#define USB_EP6R_STAT_TX_Msk                    (0x3U << USB_EP6R_STAT_TX_Pos) /*!< 0x00000030 */

#define USB_EP6R_DTOG_TX_Pos                    (6U)                           
#define USB_EP6R_DTOG_TX_Msk                    (0x1U << USB_EP6R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP6R_CTR_TX_Pos                     (7U)                           
#define USB_EP6R_CTR_TX_Msk                     (0x1U << USB_EP6R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP6R_EP_KIND_Pos                    (8U)                           
#define USB_EP6R_EP_KIND_Msk                    (0x1U << USB_EP6R_EP_KIND_Pos) /*!< 0x00000100 */


#define USB_EP6R_EP_TYPE_Pos                    (9U)                           
#define USB_EP6R_EP_TYPE_Msk                    (0x3U << USB_EP6R_EP_TYPE_Pos) /*!< 0x00000600 */
                    

#define USB_EP6R_SETUP_Pos                      (11U)                          
#define USB_EP6R_SETUP_Msk                      (0x1U << USB_EP6R_SETUP_Pos)   /*!< 0x00000800 */
//#define USB_EP6R_SETUP                          USB_EP6R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP6R_STAT_RX_Pos                    (12U)                          
#define USB_EP6R_STAT_RX_Msk                    (0x3U << USB_EP6R_STAT_RX_Pos) /*!< 0x00003000 */
//#define USB_EP6R_STAT_RX                        USB_EP6R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
//#define USB_EP6R_STAT_RX_0                      (0x1U << USB_EP6R_STAT_RX_Pos) /*!< 0x00001000 */
//#define USB_EP6R_STAT_RX_1                      (0x2U << USB_EP6R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP6R_DTOG_RX_Pos                    (14U)                          
#define USB_EP6R_DTOG_RX_Msk                    (0x1U << USB_EP6R_DTOG_RX_Pos) /*!< 0x00004000 */
//#define USB_EP6R_DTOG_RX                        USB_EP6R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP6R_CTR_RX_Pos                     (15U)                          
#define USB_EP6R_CTR_RX_Msk                     (0x1U << USB_EP6R_CTR_RX_Pos)  /*!< 0x00008000 */
//#define USB_EP6R_CTR_RX                         USB_EP6R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP7R register  *******************/
#define USB_EP7R_EA_Pos                         (0U)                           
#define USB_EP7R_EA_Msk                         (0xFU << USB_EP7R_EA_Pos)      /*!< 0x0000000F */
//#define USB_EP7R_EA                             USB_EP7R_EA_Msk                /*!< Endpoint Address */

#define USB_EP7R_STAT_TX_Pos                    (4U)                           
#define USB_EP7R_STAT_TX_Msk                    (0x3U << USB_EP7R_STAT_TX_Pos) /*!< 0x00000030 */
//#define USB_EP7R_STAT_TX                        USB_EP7R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
//#define USB_EP7R_STAT_TX_0                      (0x1U << USB_EP7R_STAT_TX_Pos) /*!< 0x00000010 */
//#define USB_EP7R_STAT_TX_1                      (0x2U << USB_EP7R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP7R_DTOG_TX_Pos                    (6U)                           
#define USB_EP7R_DTOG_TX_Msk                    (0x1U << USB_EP7R_DTOG_TX_Pos) /*!< 0x00000040 */
//#define USB_EP7R_DTOG_TX                        USB_EP7R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP7R_CTR_TX_Pos                     (7U)                           
#define USB_EP7R_CTR_TX_Msk                     (0x1U << USB_EP7R_CTR_TX_Pos)  /*!< 0x00000080 */
//#define USB_EP7R_CTR_TX                         USB_EP7R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP7R_EP_KIND_Pos                    (8U)                           
#define USB_EP7R_EP_KIND_Msk                    (0x1U << USB_EP7R_EP_KIND_Pos) /*!< 0x00000100 */
//#define USB_EP7R_EP_KIND                        USB_EP7R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP7R_EP_TYPE_Pos                    (9U)                           
#define USB_EP7R_EP_TYPE_Msk                    (0x3U << USB_EP7R_EP_TYPE_Pos) /*!< 0x00000600 */
//#define USB_EP7R_EP_TYPE                        USB_EP7R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
//#define USB_EP7R_EP_TYPE_0                      (0x1U << USB_EP7R_EP_TYPE_Pos) /*!< 0x00000200 */
//#define USB_EP7R_EP_TYPE_1                      (0x2U << USB_EP7R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP7R_SETUP_Pos                      (11U)                          
#define USB_EP7R_SETUP_Msk                      (0x1U << USB_EP7R_SETUP_Pos)   /*!< 0x00000800 */
//#define USB_EP7R_SETUP                          USB_EP7R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP7R_STAT_RX_Pos                    (12U)                          
#define USB_EP7R_STAT_RX_Msk                    (0x3U << USB_EP7R_STAT_RX_Pos) /*!< 0x00003000 */

#define USB_EP7R_DTOG_RX_Pos                    (14U)                          
#define USB_EP7R_DTOG_RX_Msk                    (0x1U << USB_EP7R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP7R_CTR_RX_Pos                     (15U)                          
#define USB_EP7R_CTR_RX_Msk                     (0x1U << USB_EP7R_CTR_RX_Pos)  /*!< 0x00008000 */

/*!< Common registers */
/*******************  Bit definition for USB_CNTR register  *******************/
#define USB_CNTR_FRES_Pos                       (0U)                           
#define USB_CNTR_FRES_Msk                       (0x1U << USB_CNTR_FRES_Pos)    /*!< 0x00000001 */
#define USB_CNTR_PDWN_Pos                       (1U)                           
#define USB_CNTR_PDWN_Msk                       (0x1U << USB_CNTR_PDWN_Pos)    /*!< 0x00000002 */
#define USB_CNTR_LP_MODE_Pos                    (2U)                           
#define USB_CNTR_LP_MODE_Msk                    (0x1U << USB_CNTR_LP_MODE_Pos) /*!< 0x00000004 */
#define USB_CNTR_FSUSP_Pos                      (3U)                           
#define USB_CNTR_FSUSP_Msk                      (0x1U << USB_CNTR_FSUSP_Pos)   /*!< 0x00000008 */
#define USB_CNTR_RESUME_Pos                     (4U)                           
#define USB_CNTR_RESUME_Msk                     (0x1U << USB_CNTR_RESUME_Pos)  /*!< 0x00000010 */
#define USB_CNTR_ESOFM_Pos                      (8U)                           
#define USB_CNTR_ESOFM_Msk                      (0x1U << USB_CNTR_ESOFM_Pos)   /*!< 0x00000100 */
#define USB_CNTR_SOFM_Pos                       (9U)                           
#define USB_CNTR_SOFM_Msk                       (0x1U << USB_CNTR_SOFM_Pos)    /*!< 0x00000200 */
#define USB_CNTR_RESETM_Pos                     (10U)                          
#define USB_CNTR_RESETM_Msk                     (0x1U << USB_CNTR_RESETM_Pos)  /*!< 0x00000400 */
#define USB_CNTR_SUSPM_Pos                      (11U)                          
#define USB_CNTR_SUSPM_Msk                      (0x1U << USB_CNTR_SUSPM_Pos)   /*!< 0x00000800 */
#define USB_CNTR_WKUPM_Pos                      (12U)                          
#define USB_CNTR_WKUPM_Msk                      (0x1U << USB_CNTR_WKUPM_Pos)   /*!< 0x00001000 */
#define USB_CNTR_ERRM_Pos                       (13U)                          
#define USB_CNTR_ERRM_Msk                       (0x1U << USB_CNTR_ERRM_Pos)    /*!< 0x00002000 */
#define USB_CNTR_PMAOVRM_Pos                    (14U)                          
#define USB_CNTR_PMAOVRM_Msk                    (0x1U << USB_CNTR_PMAOVRM_Pos) /*!< 0x00004000 */
#define USB_CNTR_CTRM_Pos                       (15U)                          
#define USB_CNTR_CTRM_Msk                       (0x1U << USB_CNTR_CTRM_Pos)    /*!< 0x00008000 */

/*******************  Bit definition for USB_ISTR register  *******************/
#define USB_ISTR_EP_ID_Pos                      (0U)                           
#define USB_ISTR_EP_ID_Msk                      (0xFU << USB_ISTR_EP_ID_Pos)   /*!< 0x0000000F */
#define USB_ISTR_DIR_Pos                        (4U)                           
#define USB_ISTR_DIR_Msk                        (0x1U << USB_ISTR_DIR_Pos)     /*!< 0x00000010 */
#define USB_ISTR_ESOF_Pos                       (8U)                           
#define USB_ISTR_ESOF_Msk                       (0x1U << USB_ISTR_ESOF_Pos)    /*!< 0x00000100 */
#define USB_ISTR_SOF_Pos                        (9U)                           
#define USB_ISTR_SOF_Msk                        (0x1U << USB_ISTR_SOF_Pos)     /*!< 0x00000200 */
#define USB_ISTR_RESET_Pos                      (10U)                          
#define USB_ISTR_RESET_Msk                      (0x1U << USB_ISTR_RESET_Pos)   /*!< 0x00000400 */
#define USB_ISTR_SUSP_Pos                       (11U)                          
#define USB_ISTR_SUSP_Msk                       (0x1U << USB_ISTR_SUSP_Pos)    /*!< 0x00000800 */
#define USB_ISTR_WKUP_Pos                       (12U)                          
#define USB_ISTR_WKUP_Msk                       (0x1U << USB_ISTR_WKUP_Pos)    /*!< 0x00001000 */
#define USB_ISTR_ERR_Pos                        (13U)                          
#define USB_ISTR_ERR_Msk                        (0x1U << USB_ISTR_ERR_Pos)     /*!< 0x00002000 */
#define USB_ISTR_PMAOVR_Pos                     (14U)                          
#define USB_ISTR_PMAOVR_Msk                     (0x1U << USB_ISTR_PMAOVR_Pos)  /*!< 0x00004000 */
#define USB_ISTR_CTR_Pos                        (15U)                          
#define USB_ISTR_CTR_Msk                        (0x1U << USB_ISTR_CTR_Pos)     /*!< 0x00008000 */

/*******************  Bit definition for USB_FNR register  ********************/
#define USB_FNR_FN_Pos                          (0U)                           
#define USB_FNR_FN_Msk                          (0x7FFU << USB_FNR_FN_Pos)     /*!< 0x000007FF */
#define USB_FNR_LSOF_Pos                        (11U)                          
#define USB_FNR_LSOF_Msk                        (0x3U << USB_FNR_LSOF_Pos)     /*!< 0x00001800 */
#define USB_FNR_LCK_Pos                         (13U)                          
#define USB_FNR_LCK_Msk                         (0x1U << USB_FNR_LCK_Pos)      /*!< 0x00002000 */
#define USB_FNR_RXDM_Pos                        (14U)                          
#define USB_FNR_RXDM_Msk                        (0x1U << USB_FNR_RXDM_Pos)     /*!< 0x00004000 */
#define USB_FNR_RXDP_Pos                        (15U)                          
#define USB_FNR_RXDP_Msk                        (0x1U << USB_FNR_RXDP_Pos)     /*!< 0x00008000 */

/******************  Bit definition for USB_DADDR register  *******************/
#define USB_DADDR_ADD_Pos                       (0U)                           
#define USB_DADDR_ADD_Msk                       (0x7FU << USB_DADDR_ADD_Pos)   /*!< 0x0000007F */
#define USB_DADDR_ADD0_Pos                      (0U)                           
#define USB_DADDR_ADD0_Msk                      (0x1U << USB_DADDR_ADD0_Pos)   /*!< 0x00000001 */
#define USB_DADDR_ADD1_Pos                      (1U)                           
#define USB_DADDR_ADD1_Msk                      (0x1U << USB_DADDR_ADD1_Pos)   /*!< 0x00000002 */
#define USB_DADDR_ADD2_Pos                      (2U)                           
#define USB_DADDR_ADD2_Msk                      (0x1U << USB_DADDR_ADD2_Pos)   /*!< 0x00000004 */
#define USB_DADDR_ADD3_Pos                      (3U)                           
#define USB_DADDR_ADD3_Msk                      (0x1U << USB_DADDR_ADD3_Pos)   /*!< 0x00000008 */
#define USB_DADDR_ADD4_Pos                      (4U)                           
#define USB_DADDR_ADD4_Msk                      (0x1U << USB_DADDR_ADD4_Pos)   /*!< 0x00000010 */
#define USB_DADDR_ADD5_Pos                      (5U)                           
#define USB_DADDR_ADD5_Msk                      (0x1U << USB_DADDR_ADD5_Pos)   /*!< 0x00000020 */
#define USB_DADDR_ADD6_Pos                      (6U)                           
#define USB_DADDR_ADD6_Msk                      (0x1U << USB_DADDR_ADD6_Pos)   /*!< 0x00000040 */

#define USB_DADDR_EF_Pos                        (7U)                           
#define USB_DADDR_EF_Msk                        (0x1U << USB_DADDR_EF_Pos)     /*!< 0x00000080 */

/******************  Bit definition for USB_BTABLE register  ******************/    
#define USB_BTABLE_BTABLE_Pos                   (3U)                           
#define USB_BTABLE_BTABLE_Msk                   (0x1FFFU << USB_BTABLE_BTABLE_Pos) /*!< 0x0000FFF8 */

/*!< Buffer descriptor table */
/*****************  Bit definition for USB_ADDR0_TX register  *****************/
#define USB_ADDR0_TX_ADDR0_TX_Pos               (1U)                           
#define USB_ADDR0_TX_ADDR0_TX_Msk               (0x7FFFU << USB_ADDR0_TX_ADDR0_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR1_TX register  *****************/
#define USB_ADDR1_TX_ADDR1_TX_Pos               (1U)                           
#define USB_ADDR1_TX_ADDR1_TX_Msk               (0x7FFFU << USB_ADDR1_TX_ADDR1_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR2_TX register  *****************/
#define USB_ADDR2_TX_ADDR2_TX_Pos               (1U)                           
#define USB_ADDR2_TX_ADDR2_TX_Msk               (0x7FFFU << USB_ADDR2_TX_ADDR2_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR3_TX register  *****************/
#define USB_ADDR3_TX_ADDR3_TX_Pos               (1U)                           
#define USB_ADDR3_TX_ADDR3_TX_Msk               (0x7FFFU << USB_ADDR3_TX_ADDR3_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR4_TX register  *****************/
#define USB_ADDR4_TX_ADDR4_TX_Pos               (1U)                           
#define USB_ADDR4_TX_ADDR4_TX_Msk               (0x7FFFU << USB_ADDR4_TX_ADDR4_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR5_TX register  *****************/
#define USB_ADDR5_TX_ADDR5_TX_Pos               (1U)                           
#define USB_ADDR5_TX_ADDR5_TX_Msk               (0x7FFFU << USB_ADDR5_TX_ADDR5_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR6_TX register  *****************/
#define USB_ADDR6_TX_ADDR6_TX_Pos               (1U)                           
#define USB_ADDR6_TX_ADDR6_TX_Msk               (0x7FFFU << USB_ADDR6_TX_ADDR6_TX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR7_TX register  *****************/
#define USB_ADDR7_TX_ADDR7_TX_Pos               (1U)                           
#define USB_ADDR7_TX_ADDR7_TX_Msk               (0x7FFFU << USB_ADDR7_TX_ADDR7_TX_Pos) /*!< 0x0000FFFE */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_COUNT0_TX register  ****************/
#define USB_COUNT0_TX_COUNT0_TX_Pos             (0U)                           
#define USB_COUNT0_TX_COUNT0_TX_Msk             (0x3FFU << USB_COUNT0_TX_COUNT0_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT1_TX register  ****************/
#define USB_COUNT1_TX_COUNT1_TX_Pos             (0U)                           
#define USB_COUNT1_TX_COUNT1_TX_Msk             (0x3FFU << USB_COUNT1_TX_COUNT1_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT2_TX register  ****************/
#define USB_COUNT2_TX_COUNT2_TX_Pos             (0U)                           
#define USB_COUNT2_TX_COUNT2_TX_Msk             (0x3FFU << USB_COUNT2_TX_COUNT2_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT3_TX register  ****************/
#define USB_COUNT3_TX_COUNT3_TX_Pos             (0U)                           
#define USB_COUNT3_TX_COUNT3_TX_Msk             (0x3FFU << USB_COUNT3_TX_COUNT3_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT4_TX register  ****************/
#define USB_COUNT4_TX_COUNT4_TX_Pos             (0U)                           
#define USB_COUNT4_TX_COUNT4_TX_Msk             (0x3FFU << USB_COUNT4_TX_COUNT4_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT5_TX register  ****************/
#define USB_COUNT5_TX_COUNT5_TX_Pos             (0U)                           
#define USB_COUNT5_TX_COUNT5_TX_Msk             (0x3FFU << USB_COUNT5_TX_COUNT5_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT6_TX register  ****************/
#define USB_COUNT6_TX_COUNT6_TX_Pos             (0U)                           
#define USB_COUNT6_TX_COUNT6_TX_Msk             (0x3FFU << USB_COUNT6_TX_COUNT6_TX_Pos) /*!< 0x000003FF */

/*****************  Bit definition for USB_COUNT7_TX register  ****************/
#define USB_COUNT7_TX_COUNT7_TX_Pos             (0U)                           
#define USB_COUNT7_TX_COUNT7_TX_Msk             (0x3FFU << USB_COUNT7_TX_COUNT7_TX_Pos) /*!< 0x000003FF */

/*----------------------------------------------------------------------------*/

/****************  Bit definition for USB_COUNT0_TX_0 register  ***************/
#define USB_COUNT0_TX_0_COUNT0_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 0 (low) */

/****************  Bit definition for USB_COUNT0_TX_1 register  ***************/
#define USB_COUNT0_TX_1_COUNT0_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 0 (high) */

/****************  Bit definition for USB_COUNT1_TX_0 register  ***************/
#define USB_COUNT1_TX_0_COUNT1_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 1 (low) */

/****************  Bit definition for USB_COUNT1_TX_1 register  ***************/
#define USB_COUNT1_TX_1_COUNT1_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 1 (high) */

/****************  Bit definition for USB_COUNT2_TX_0 register  ***************/
#define USB_COUNT2_TX_0_COUNT2_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 2 (low) */

/****************  Bit definition for USB_COUNT2_TX_1 register  ***************/
#define USB_COUNT2_TX_1_COUNT2_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 2 (high) */

/****************  Bit definition for USB_COUNT3_TX_0 register  ***************/

/****************  Bit definition for USB_COUNT3_TX_1 register  ***************/

/****************  Bit definition for USB_COUNT4_TX_0 register  ***************/
#define USB_COUNT4_TX_0_COUNT4_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 4 (low) */

/****************  Bit definition for USB_COUNT4_TX_1 register  ***************/
#define USB_COUNT4_TX_1_COUNT4_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 4 (high) */

/****************  Bit definition for USB_COUNT5_TX_0 register  ***************/
#define USB_COUNT5_TX_0_COUNT5_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 5 (low) */

/****************  Bit definition for USB_COUNT5_TX_1 register  ***************/
#define USB_COUNT5_TX_1_COUNT5_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 5 (high) */

/****************  Bit definition for USB_COUNT6_TX_0 register  ***************/
#define USB_COUNT6_TX_0_COUNT6_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 6 (low) */

/****************  Bit definition for USB_COUNT6_TX_1 register  ***************/
#define USB_COUNT6_TX_1_COUNT6_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 6 (high) */

/****************  Bit definition for USB_COUNT7_TX_0 register  ***************/
#define USB_COUNT7_TX_0_COUNT7_TX_0             ((uint32_t)0x000003FF)         /*!< Transmission Byte Count 7 (low) */

/****************  Bit definition for USB_COUNT7_TX_1 register  ***************/
#define USB_COUNT7_TX_1_COUNT7_TX_1             ((uint32_t)0x03FF0000)         /*!< Transmission Byte Count 7 (high) */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_ADDR0_RX register  *****************/
#define USB_ADDR0_RX_ADDR0_RX_Pos               (1U)                           
#define USB_ADDR0_RX_ADDR0_RX_Msk               (0x7FFFU << USB_ADDR0_RX_ADDR0_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR1_RX register  *****************/
#define USB_ADDR1_RX_ADDR1_RX_Pos               (1U)                           
#define USB_ADDR1_RX_ADDR1_RX_Msk               (0x7FFFU << USB_ADDR1_RX_ADDR1_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR2_RX register  *****************/
#define USB_ADDR2_RX_ADDR2_RX_Pos               (1U)                           
#define USB_ADDR2_RX_ADDR2_RX_Msk               (0x7FFFU << USB_ADDR2_RX_ADDR2_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR3_RX register  *****************/
#define USB_ADDR3_RX_ADDR3_RX_Pos               (1U)                           
#define USB_ADDR3_RX_ADDR3_RX_Msk               (0x7FFFU << USB_ADDR3_RX_ADDR3_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR4_RX register  *****************/
#define USB_ADDR4_RX_ADDR4_RX_Pos               (1U)                           
#define USB_ADDR4_RX_ADDR4_RX_Msk               (0x7FFFU << USB_ADDR4_RX_ADDR4_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR5_RX register  *****************/
#define USB_ADDR5_RX_ADDR5_RX_Pos               (1U)                           
#define USB_ADDR5_RX_ADDR5_RX_Msk               (0x7FFFU << USB_ADDR5_RX_ADDR5_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR6_RX register  *****************/
#define USB_ADDR6_RX_ADDR6_RX_Pos               (1U)                           
#define USB_ADDR6_RX_ADDR6_RX_Msk               (0x7FFFU << USB_ADDR6_RX_ADDR6_RX_Pos) /*!< 0x0000FFFE */

/*****************  Bit definition for USB_ADDR7_RX register  *****************/
#define USB_ADDR7_RX_ADDR7_RX_Pos               (1U)                           
#define USB_ADDR7_RX_ADDR7_RX_Msk               (0x7FFFU << USB_ADDR7_RX_ADDR7_RX_Pos) /*!< 0x0000FFFE */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_COUNT0_RX register  ****************/
#define USB_COUNT0_RX_COUNT0_RX_Pos             (0U)                           
#define USB_COUNT0_RX_COUNT0_RX_Msk             (0x3FFU << USB_COUNT0_RX_COUNT0_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT0_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT0_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT0_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT0_RX_BLSIZE_Msk                (0x1U << USB_COUNT0_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT1_RX register  ****************/
#define USB_COUNT1_RX_COUNT1_RX_Pos             (0U)                           
#define USB_COUNT1_RX_COUNT1_RX_Msk             (0x3FFU << USB_COUNT1_RX_COUNT1_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT1_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT1_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT1_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT1_RX_BLSIZE_Msk                (0x1U << USB_COUNT1_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT2_RX register  ****************/
#define USB_COUNT2_RX_COUNT2_RX_Pos             (0U)                           
#define USB_COUNT2_RX_COUNT2_RX_Msk             (0x3FFU << USB_COUNT2_RX_COUNT2_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT2_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT2_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT2_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT2_RX_BLSIZE_Msk                (0x1U << USB_COUNT2_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT3_RX register  ****************/
#define USB_COUNT3_RX_COUNT3_RX_Pos             (0U)                           
#define USB_COUNT3_RX_COUNT3_RX_Msk             (0x3FFU << USB_COUNT3_RX_COUNT3_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT3_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT3_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT3_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT3_RX_BLSIZE_Msk                (0x1U << USB_COUNT3_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT4_RX register  ****************/
#define USB_COUNT4_RX_COUNT4_RX_Pos             (0U)                           
#define USB_COUNT4_RX_COUNT4_RX_Msk             (0x3FFU << USB_COUNT4_RX_COUNT4_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT4_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT4_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT4_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT4_RX_BLSIZE_Msk                (0x1U << USB_COUNT4_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT5_RX register  ****************/
#define USB_COUNT5_RX_COUNT5_RX_Pos             (0U)                           
#define USB_COUNT5_RX_COUNT5_RX_Msk             (0x3FFU << USB_COUNT5_RX_COUNT5_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT5_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT5_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT5_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT5_RX_BLSIZE_Msk                (0x1U << USB_COUNT5_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT6_RX register  ****************/
#define USB_COUNT6_RX_COUNT6_RX_Pos             (0U)                           
#define USB_COUNT6_RX_COUNT6_RX_Msk             (0x3FFU << USB_COUNT6_RX_COUNT6_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT6_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT6_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT6_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT6_RX_BLSIZE_Msk                (0x1U << USB_COUNT6_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*****************  Bit definition for USB_COUNT7_RX register  ****************/
#define USB_COUNT7_RX_COUNT7_RX_Pos             (0U)                           
#define USB_COUNT7_RX_COUNT7_RX_Msk             (0x3FFU << USB_COUNT7_RX_COUNT7_RX_Pos) /*!< 0x000003FF */

#define USB_COUNT7_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT7_RX_NUM_BLOCK_Msk             (0x1FU << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */

#define USB_COUNT7_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT7_RX_BLSIZE_Msk                (0x1U << USB_COUNT7_RX_BLSIZE_Pos) /*!< 0x00008000 */

/*----------------------------------------------------------------------------*/

/****************  Bit definition for USB_COUNT0_RX_0 register  ***************/
#define USB_COUNT0_RX_0_COUNT0_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT0_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT0_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT0_RX_1 register  ***************/
#define USB_COUNT0_RX_1_COUNT0_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT0_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 1 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT0_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT1_RX_0 register  ***************/
#define USB_COUNT1_RX_0_COUNT1_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT1_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT1_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT1_RX_1 register  ***************/
#define USB_COUNT1_RX_1_COUNT1_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT1_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT1_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT2_RX_0 register  ***************/
#define USB_COUNT2_RX_0_COUNT2_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT2_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT2_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT2_RX_1 register  ***************/
#define USB_COUNT2_RX_1_COUNT2_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT2_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT2_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT3_RX_0 register  ***************/
#define USB_COUNT3_RX_0_COUNT3_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT3_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT3_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT3_RX_1 register  ***************/
#define USB_COUNT3_RX_1_COUNT3_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT3_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT3_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT4_RX_0 register  ***************/
#define USB_COUNT4_RX_0_COUNT4_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT4_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT4_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT4_RX_1 register  ***************/
#define USB_COUNT4_RX_1_COUNT4_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT4_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT4_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT5_RX_0 register  ***************/
#define USB_COUNT5_RX_0_COUNT5_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT5_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT5_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT5_RX_1 register  ***************/
#define USB_COUNT5_RX_1_COUNT5_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT5_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT5_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/***************  Bit definition for USB_COUNT6_RX_0  register  ***************/
#define USB_COUNT6_RX_0_COUNT6_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT6_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT6_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT6_RX_1 register  ***************/
#define USB_COUNT6_RX_1_COUNT6_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT6_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT6_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/***************  Bit definition for USB_COUNT7_RX_0 register  ****************/
#define USB_COUNT7_RX_0_COUNT7_RX_0             ((uint32_t)0x000003FF)         /*!< Reception Byte Count (low) */

#define USB_COUNT7_RX_0_NUM_BLOCK_0             ((uint32_t)0x00007C00)         /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_0           ((uint32_t)0x00000400)         /*!< Bit 0 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_1           ((uint32_t)0x00000800)         /*!< Bit 1 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_2           ((uint32_t)0x00001000)         /*!< Bit 2 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_3           ((uint32_t)0x00002000)         /*!< Bit 3 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_4           ((uint32_t)0x00004000)         /*!< Bit 4 */

#define USB_COUNT7_RX_0_BLSIZE_0                ((uint32_t)0x00008000)         /*!< BLock SIZE (low) */

/***************  Bit definition for USB_COUNT7_RX_1 register  ****************/
#define USB_COUNT7_RX_1_COUNT7_RX_1             ((uint32_t)0x03FF0000)         /*!< Reception Byte Count (high) */

#define USB_COUNT7_RX_1_NUM_BLOCK_1             ((uint32_t)0x7C000000)         /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_0           ((uint32_t)0x04000000)         /*!< Bit 0 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_1           ((uint32_t)0x08000000)         /*!< Bit 1 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_2           ((uint32_t)0x10000000)         /*!< Bit 2 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_3           ((uint32_t)0x20000000)         /*!< Bit 3 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_4           ((uint32_t)0x40000000)         /*!< Bit 4 */

#define USB_COUNT7_RX_1_BLSIZE_1                ((uint32_t)0x80000000)         /*!< BLock SIZE (high) */

/* USB Control Endpoint Operation Status */

typedef enum {
    usb_status_ack     = 0x00,
    usb_status_nak     = 0x01,
    usb_status_fail    = 0x02,
} usb_status_t;

/* USB Control Endpoint Exchange Complete Callback */

typedef void (*usb_tx_complete_cb_t)();

/* USB Control Endpoint Event Handler */

void usb_control_endpoint_event_handler(uint8_t ep_num, usb_endpoint_event_t ep_event);

/* USB Device State */

typedef enum {
    usb_device_state_reset          = 0x00,
    usb_device_state_address_set    = 0x01,
    usb_device_state_configured     = 0x02,    
} usb_device_state_t;

/* Device Level Events */

void usb_device_handle_reset(void);
void usb_device_handle_configured(void);
void usb_device_handle_suspend(void);
void usb_device_handle_wakeup(void);
void usb_device_handle_frame(void);
void usb_device_poll(void);

#endif /* USB_CORE_H */
