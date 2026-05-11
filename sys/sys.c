#include "sys.h"


/* 
    函数功能：Set_Duty()设定指定定时器指定通道的占空比
    参数：   
        PWMA:       指定定时器名称  PWM_0_INST
        Channel:    指定定时器通道  DL_TIMER_CC_0_INDEX / DL_TIMER_CC_1_INDEX
        ARR:        定时器重装载值
        duty：      设定占空比      归一化的占空比（0 ~ 1）
 */
void Set_Duty(GPTIMER_Regs * PWMA, DL_TIMER_CC_INDEX Channel, int ARR, float duty)
{
    uint32_t CompareValue;
    // CompareValue = ARR - ARR * duty;
    CompareValue = ARR * duty;
    DL_Timer_setCaptureCompareValue(PWMA, CompareValue, Channel);
}
 
 
/* 
    函数功能：Set_Freq()设定指定定时器频率
    参数：   
        PWMA:       指定定时器名称  PWM_0_INST
        CLK_FREQ:   定时器总线频率  PWM_0_INST_CLK_FREQ
        freq：      设定频率值      
 */
void Set_Freq(GPTIMER_Regs *PWMA , uint32_t CLK_FREQ, uint32_t freq)
{
    uint32_t period;
    period = CLK_FREQ / freq;
    DL_Timer_setLoadValue(PWMA, period);
}



void delay_ms(uint32_t ms)
{
    while(ms--)
        delay_cycles(CPUCLK_FREQ/1000);
}


void delay_us(uint32_t us)
{
    while(us--)
        delay_cycles(CPUCLK_FREQ/1000000);
}


int fputc(int c, FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART_0_INST, c);
    return c;
}
 
int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
        DL_UART_Main_transmitDataBlocking(UART_0_INST, s[i]);
    return len;
}
 
int puts(const char *_ptr)
{
    int count = fputs(_ptr, stdout);
    count += fputs("\n", stdout);
    return count;
}


/* 绝对值函数 */
int myabs(int x)
{
	int y;
	y = (x < 0) ? -x :x;
	return y;
}
