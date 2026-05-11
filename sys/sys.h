#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

typedef unsigned          char uint8_t;

#define AIN1_High       DL_GPIO_setPins(DIR_PORT, DIR_AIN1_PIN)
#define AIN1_Low        DL_GPIO_clearPins(DIR_PORT, DIR_AIN1_PIN)
#define AIN2_High       DL_GPIO_setPins(DIR_PORT, DIR_AIN2_PIN)
#define AIN2_Low        DL_GPIO_clearPins(DIR_PORT, DIR_AIN2_PIN)
#define BIN1_High       DL_GPIO_setPins(DIR_PORT, DIR_BIN1_PIN)
#define BIN1_Low        DL_GPIO_clearPins(DIR_PORT, DIR_BIN1_PIN)
#define BIN2_High       DL_GPIO_setPins(DIR_PORT, DIR_BIN2_PIN)
#define BIN2_Low        DL_GPIO_clearPins(DIR_PORT, DIR_BIN2_PIN)


#define LED_High        DL_GPIO_setPins(LED_PORT, LED_PIN_LED_PIN)
#define LED_Low         DL_GPIO_clearPins(LED_PORT, LED_PIN_LED_PIN)



void delay_ms(uint32_t ms);
void delay_us(uint32_t us);
int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int puts(const char *_ptr);
void Set_Duty(GPTIMER_Regs * PWMA, DL_TIMER_CC_INDEX Channel, int ARR, float duty);
void Set_Freq(GPTIMER_Regs *PWMA , uint32_t CLK_FREQ, uint32_t freq);
int myabs(int x);