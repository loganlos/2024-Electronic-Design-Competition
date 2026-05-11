/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA0
#define PWM_0_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                             80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_8
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM25)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM25_PF_TIMA0_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOB
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_12
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM29)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM29_PF_TIMA0_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (3332U)
/* Defines for TIMER_Encoder_Read */
#define TIMER_Encoder_Read_INST                                          (TIMG6)
#define TIMER_Encoder_Read_INST_IRQHandler                        TIMG6_IRQHandler
#define TIMER_Encoder_Read_INST_INT_IRQN                        (TIMG6_INT_IRQn)
#define TIMER_Encoder_Read_INST_LOAD_VALUE                                 (7999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_0_FBRD_40_MHZ_115200_BAUD                                      (45)
/* Defines for UART_JY61P */
#define UART_JY61P_INST                                                    UART2
#define UART_JY61P_INST_IRQHandler                              UART2_IRQHandler
#define UART_JY61P_INST_INT_IRQN                                  UART2_INT_IRQn
#define GPIO_UART_JY61P_RX_PORT                                            GPIOB
#define GPIO_UART_JY61P_TX_PORT                                            GPIOB
#define GPIO_UART_JY61P_RX_PIN                                    DL_GPIO_PIN_16
#define GPIO_UART_JY61P_TX_PIN                                    DL_GPIO_PIN_17
#define GPIO_UART_JY61P_IOMUX_RX                                 (IOMUX_PINCM33)
#define GPIO_UART_JY61P_IOMUX_TX                                 (IOMUX_PINCM43)
#define GPIO_UART_JY61P_IOMUX_RX_FUNC                  IOMUX_PINCM33_PF_UART2_RX
#define GPIO_UART_JY61P_IOMUX_TX_FUNC                  IOMUX_PINCM43_PF_UART2_TX
#define UART_JY61P_BAUD_RATE                                            (115200)
#define UART_JY61P_IBRD_40_MHZ_115200_BAUD                                  (21)
#define UART_JY61P_FBRD_40_MHZ_115200_BAUD                                  (45)





/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOA)

/* Defines for PIN_LED: GPIOA.13 with pinCMx 35 on package pin 6 */
#define LED_PIN_LED_PIN                                         (DL_GPIO_PIN_13)
#define LED_PIN_LED_IOMUX                                        (IOMUX_PINCM35)
/* Port definition for Pin Group GPIO_EncoderA */
#define GPIO_EncoderA_PORT                                               (GPIOA)

/* Defines for PIN_0: GPIOA.31 with pinCMx 6 on package pin 39 */
// pins affected by this interrupt request:["PIN_0","PIN_1"]
#define GPIO_EncoderA_INT_IRQN                                  (GPIOA_INT_IRQn)
#define GPIO_EncoderA_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_EncoderA_PIN_0_IIDX                            (DL_GPIO_IIDX_DIO31)
#define GPIO_EncoderA_PIN_0_PIN                                 (DL_GPIO_PIN_31)
#define GPIO_EncoderA_PIN_0_IOMUX                                 (IOMUX_PINCM6)
/* Defines for PIN_1: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_EncoderA_PIN_1_IIDX                            (DL_GPIO_IIDX_DIO12)
#define GPIO_EncoderA_PIN_1_PIN                                 (DL_GPIO_PIN_12)
#define GPIO_EncoderA_PIN_1_IOMUX                                (IOMUX_PINCM34)
/* Port definition for Pin Group GPIO_EncoderB */
#define GPIO_EncoderB_PORT                                               (GPIOB)

/* Defines for PIN_2: GPIOB.24 with pinCMx 52 on package pin 23 */
// pins affected by this interrupt request:["PIN_2","PIN_3"]
#define GPIO_EncoderB_INT_IRQN                                  (GPIOB_INT_IRQn)
#define GPIO_EncoderB_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_EncoderB_PIN_2_IIDX                            (DL_GPIO_IIDX_DIO24)
#define GPIO_EncoderB_PIN_2_PIN                                 (DL_GPIO_PIN_24)
#define GPIO_EncoderB_PIN_2_IOMUX                                (IOMUX_PINCM52)
/* Defines for PIN_3: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_EncoderB_PIN_3_IIDX                             (DL_GPIO_IIDX_DIO9)
#define GPIO_EncoderB_PIN_3_PIN                                  (DL_GPIO_PIN_9)
#define GPIO_EncoderB_PIN_3_IOMUX                                (IOMUX_PINCM26)
/* Port definition for Pin Group DIR */
#define DIR_PORT                                                         (GPIOB)

/* Defines for AIN1: GPIOB.10 with pinCMx 27 on package pin 62 */
#define DIR_AIN1_PIN                                            (DL_GPIO_PIN_10)
#define DIR_AIN1_IOMUX                                           (IOMUX_PINCM27)
/* Defines for AIN2: GPIOB.23 with pinCMx 51 on package pin 22 */
#define DIR_AIN2_PIN                                            (DL_GPIO_PIN_23)
#define DIR_AIN2_IOMUX                                           (IOMUX_PINCM51)
/* Defines for BIN1: GPIOB.26 with pinCMx 57 on package pin 28 */
#define DIR_BIN1_PIN                                            (DL_GPIO_PIN_26)
#define DIR_BIN1_IOMUX                                           (IOMUX_PINCM57)
/* Defines for BIN2: GPIOB.27 with pinCMx 58 on package pin 29 */
#define DIR_BIN2_PIN                                            (DL_GPIO_PIN_27)
#define DIR_BIN2_IOMUX                                           (IOMUX_PINCM58)
/* Defines for P1: GPIOA.1 with pinCMx 2 on package pin 34 */
#define Sensor_P1_PORT                                                   (GPIOA)
#define Sensor_P1_PIN                                            (DL_GPIO_PIN_1)
#define Sensor_P1_IOMUX                                           (IOMUX_PINCM2)
/* Defines for P2: GPIOA.7 with pinCMx 14 on package pin 49 */
#define Sensor_P2_PORT                                                   (GPIOA)
#define Sensor_P2_PIN                                            (DL_GPIO_PIN_7)
#define Sensor_P2_IOMUX                                          (IOMUX_PINCM14)
/* Defines for P3: GPIOA.14 with pinCMx 36 on package pin 7 */
#define Sensor_P3_PORT                                                   (GPIOA)
#define Sensor_P3_PIN                                           (DL_GPIO_PIN_14)
#define Sensor_P3_IOMUX                                          (IOMUX_PINCM36)
/* Defines for P4: GPIOB.5 with pinCMx 18 on package pin 53 */
#define Sensor_P4_PORT                                                   (GPIOB)
#define Sensor_P4_PIN                                            (DL_GPIO_PIN_5)
#define Sensor_P4_IOMUX                                          (IOMUX_PINCM18)
/* Defines for P5: GPIOB.11 with pinCMx 28 on package pin 63 */
#define Sensor_P5_PORT                                                   (GPIOB)
#define Sensor_P5_PIN                                           (DL_GPIO_PIN_11)
#define Sensor_P5_IOMUX                                          (IOMUX_PINCM28)
/* Defines for P6: GPIOB.0 with pinCMx 12 on package pin 47 */
#define Sensor_P6_PORT                                                   (GPIOB)
#define Sensor_P6_PIN                                            (DL_GPIO_PIN_0)
#define Sensor_P6_IOMUX                                          (IOMUX_PINCM12)
/* Defines for P7: GPIOB.6 with pinCMx 23 on package pin 58 */
#define Sensor_P7_PORT                                                   (GPIOB)
#define Sensor_P7_PIN                                            (DL_GPIO_PIN_6)
#define Sensor_P7_IOMUX                                          (IOMUX_PINCM23)
/* Defines for P8: GPIOB.7 with pinCMx 24 on package pin 59 */
#define Sensor_P8_PORT                                                   (GPIOB)
#define Sensor_P8_PIN                                            (DL_GPIO_PIN_7)
#define Sensor_P8_IOMUX                                          (IOMUX_PINCM24)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for S2: GPIOB.1 with pinCMx 13 on package pin 48 */
#define KEY_S2_PIN                                               (DL_GPIO_PIN_1)
#define KEY_S2_IOMUX                                             (IOMUX_PINCM13)
/* Defines for EN: GPIOB.4 with pinCMx 17 on package pin 52 */
#define KEY_EN_PIN                                               (DL_GPIO_PIN_4)
#define KEY_EN_IOMUX                                             (IOMUX_PINCM17)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_Encoder_Read_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_JY61P_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
