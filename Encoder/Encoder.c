#include "Encoder.h"


extern volatile uint32_t EncoderA_Port, EncoderB_Port;      //编码器端口
extern volatile int32_t EncoderA_CNT, EncoderB_CNT;         //编码器计数值
extern volatile int32_t EncoderA_VEL, EncoderB_VEL;         //马达速度 


/*
    * 编码器初始化
*/
void Encoder_Init(void)
{
    /* 关闭所有输出 */
    AIN1_Low;
    AIN2_Low;
    BIN1_Low;
    BIN2_Low;

    /* 使能编码器定时器、GPIO中断 */
    NVIC_EnableIRQ(GPIO_EncoderA_INT_IRQN);
    NVIC_EnableIRQ(GPIO_EncoderB_INT_IRQN);
    NVIC_EnableIRQ(TIMER_Encoder_Read_INST_INT_IRQN);
    DL_Timer_startCounter(TIMER_Encoder_Read_INST);

    /* 使能PWM波输出 */
    DL_Timer_startCounter(PWM_0_INST);
}




/*
    * 编码器读取中断服务函数
    * 读取编码器数值
*/
void TIMER_Encoder_Read_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_Encoder_Read_INST)){
        case DL_TIMER_IIDX_ZERO:
            Read_Encoder();            //赋值编码器数值
            // printf("%d,%d\r\n",EncoderA_VEL,EncoderB_VEL);
            break;
        default:
            break;
    }
}




/*
    * 编码器读取函数
    * 编码器A、B分别对应编码器A、B的引脚
    * EncoderA_CNT、EncoderB_CNT    分别对应编码器A、B的计数值
    * EncoderA_Port、EncoderB_Port  分别对应编码器A、B的端口
*/
void Encodering(void)
{
    EncoderA_Port = DL_GPIO_getEnabledInterruptStatus(GPIO_EncoderA_PORT, GPIO_EncoderA_PIN_0_PIN | GPIO_EncoderA_PIN_1_PIN);
    EncoderB_Port = DL_GPIO_getEnabledInterruptStatus(GPIO_EncoderB_PORT, GPIO_EncoderB_PIN_2_PIN | GPIO_EncoderB_PIN_3_PIN);
    
    /* 编码器A */
    if((EncoderA_Port & GPIO_EncoderA_PIN_0_PIN) == GPIO_EncoderA_PIN_0_PIN)        //编码器A-Pin0
    {
        if(!DL_GPIO_readPins(GPIO_EncoderA_PORT,GPIO_EncoderA_PIN_1_PIN))   EncoderA_CNT--;
        else                                                                EncoderA_CNT++;
    }
    else if((EncoderA_Port & GPIO_EncoderA_PIN_1_PIN) == GPIO_EncoderA_PIN_1_PIN)   //编码器A-Pin1
    {
        if(!DL_GPIO_readPins(GPIO_EncoderA_PORT,GPIO_EncoderA_PIN_0_PIN))   EncoderA_CNT++;
        else                                                                EncoderA_CNT--;
    }
    DL_GPIO_clearInterruptStatus(GPIO_EncoderA_PORT, GPIO_EncoderA_PIN_0_PIN|GPIO_EncoderA_PIN_1_PIN);


    /* 编码器B */
    if((EncoderB_Port & GPIO_EncoderB_PIN_2_PIN) == GPIO_EncoderB_PIN_2_PIN)
    {
        if(!DL_GPIO_readPins(GPIO_EncoderB_PORT,GPIO_EncoderB_PIN_3_PIN))   EncoderB_CNT--;
        else                                                                EncoderB_CNT++;
    }
    else if((EncoderB_Port & GPIO_EncoderB_PIN_3_PIN) == GPIO_EncoderB_PIN_3_PIN)
    {
        if(!DL_GPIO_readPins(GPIO_EncoderB_PORT,GPIO_EncoderB_PIN_2_PIN))   EncoderB_CNT++;
        else                                                                EncoderB_CNT--;
    }
    DL_GPIO_clearInterruptStatus(GPIO_EncoderB_PORT, GPIO_EncoderB_PIN_2_PIN|GPIO_EncoderB_PIN_3_PIN);
}





/**************************************************************************
Function: Read encoder count per unit time
Input   : TIMX：Timer
Output  : none
函数功能：单位时间读取编码器计数
入口参数：TIMX：定时器
返回  值：速度值
**************************************************************************/
void Read_Encoder(void)
{
    EncoderA_VEL = EncoderA_CNT;
    EncoderA_CNT = 0;
    EncoderB_VEL = EncoderB_CNT;
    EncoderB_CNT = 0;
}
