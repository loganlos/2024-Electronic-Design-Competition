#include "ti_msp_dl_config.h"

/* USER CODE BEGIN Includes */
#include "GYRO.h"
#include "sys.h"
#include "Encoder.h"
#include "Sensor.h"
#include "control.h"
/* USER CODE END Includes */


/* USER CODE BEGIN PV */
volatile int flag = 1;                                  //flag状态位：0-暂停；1-AB段；2-BC段；3-CD段；4-DA段；
volatile int mode = 0;                                  //mode状态位：0-暂停；1-模式一... ...；
volatile int flag_en = 0;                               //flag_en状态位：0-不使能；1-使能

volatile uint32_t EncoderA_Port, EncoderB_Port;         //编码器端口
volatile int32_t EncoderA_CNT = 0, EncoderB_CNT = 0;    //编码器计数值
volatile int32_t EncoderA_VEL = 0, EncoderB_VEL = 0;    //马达速度

extern float Pitch, Roll, Yaw;                          //姿态角

volatile float LED_CNT = 0.0;
volatile bool flag_LED = 0;
/* USER CODE END PV */


/* USER CODE BEGIN PFP */
void Key_Scan(void);
void LED_Sound(void);
/* USER CODE END PFP */
 

int main(void)
{
    SYSCFG_DL_init();
  /* USER CODE BEGIN 2 */
    printf("Hello World\r\n");

    /* GYRO初始化 */
    Serial_JY61P_Zero_Yaw();
    NVIC_EnableIRQ(UART_JY61P_INST_INT_IRQN);
    delay_ms(500);

    /* 编码器及PWM初始化 */
    Encoder_Init();

    /* 使能控制定时器 */
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    DL_Timer_startCounter(TIMER_0_INST);

  /* USER CODE END 2 */

    while (1) {

    /* 按键扫描 */
    Key_Scan();

    if(flag_en)         //使能控制开启
    {
        Follow_Route(); //路径控制总函数函数
        /* LED闪烁 */
        LED_Sound();
    }
    }

}




/* USER CODE BEGIN 4 */

/*
    * 定时器0中断服务函数
*/
void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerA_getPendingInterrupt(TIMER_0_INST)) {
    case DL_TIMERA_IIDX_ZERO:
        //flag位判断
        if(flag == 0 || flag_en == 0 || mode == 0)      Set_Pwm(0,0);
        else if(flag_en)                                Control();
    break;
    default:
    break;
    }
}




/*
    * 按键扫描函数
    * 按键按下时，切换mode
    * 按键按下时，切换flag_en确认使能
*/
void Key_Scan(void)
{
    /* 模式切换按键 */
    if(DL_GPIO_readPins(KEY_PORT, KEY_S2_PIN) == 0)
    {
        delay_ms(10);
        if(DL_GPIO_readPins(KEY_PORT, KEY_S2_PIN) == 0)
        {
            while(!DL_GPIO_readPins(KEY_PORT, KEY_S2_PIN));
            mode = (mode + 1) % 5;
        }
    }

    /* 使能按键 */
    if(DL_GPIO_readPins(KEY_PORT, KEY_EN_PIN) == 0)
    {
        delay_ms(10);
        if(DL_GPIO_readPins(KEY_PORT, KEY_EN_PIN) == 0)
        {
            while(!DL_GPIO_readPins(KEY_PORT, KEY_EN_PIN));
            flag_en = 1 - flag_en;
        }
    }
}





/*
    * 编码器中断服务函数
*/
void GROUP1_IRQHandler(void)
{
    /* 运行编码器 */
    Encodering();
}




/*
    * LED闪烁函数
*/
void LED_Sound(void)
{
    if(flag_LED)
    {
        LED_High;
        LED_CNT  = LED_CNT + 0.1;
        if(LED_CNT >= 800) 
        {
            LED_Low;
            LED_CNT = 0;
            flag_LED = 0;
        }
    }
}
/* USER CODE END 4 */