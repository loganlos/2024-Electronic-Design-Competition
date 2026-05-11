#include "GYRO.h"

// 定义接收变量
uint8_t RollL, RollH, PitchL, PitchH, YawL, YawH, VL, VH, SUM;
float Pitch,Roll,Yaw;

// 串口接收状态标识
#define WAIT_HEADER1 0
#define WAIT_HEADER2 1
#define RECEIVE_DATA 2

uint8_t RxState = WAIT_HEADER1;
uint8_t receivedData[9];
uint8_t dataIndex = 0;



//发送置偏航角置零命令
void Serial_JY61P_Zero_Yaw(void)
{
    DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X69);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X88);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XB5);
	delay_ms(100);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X76);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X00);
	delay_ms(100);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0X00);
    delay_ms(500);
}




// 串口中断处理函数
/*
    * 串口接收数据，并解析出角度
    * 接收到的数据格式为：0x55 0x53 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX
    * 其中0xXX为角度数据，单位为0.1度
    * 角度数据为16位，高8位在前，低8位在后
    * 角度数据为正数表示顺时针旋转，负数表示逆时针旋转
    * 角度数据为0表示水平
    * 角度数据为180表示垂直
    * 角度数据为90表示垂直向上
    * 角度数据为-90表示垂直向下
    * 角度数据为360表示水平向右
    * 角度数据为-360表示水平向左
*/
void UART_JY61P_INST_IRQHandler(void) 
{
    uint8_t uartdata = DL_UART_Main_receiveData(UART_JY61P_INST);   // 接收一个uint8_t数据

    switch (RxState) {
    case WAIT_HEADER1:
        if (uartdata == 0x55) {
            RxState = WAIT_HEADER2;
        }
        break;
    case WAIT_HEADER2:
        if (uartdata == 0x53) {
            RxState = RECEIVE_DATA;
            dataIndex = 0;
        } else {
            RxState = WAIT_HEADER1;                                 // 如果不是期望的第二个头，重置状态
        }
        break;
    case RECEIVE_DATA:
        receivedData[dataIndex++] = uartdata;
        if (dataIndex == 9) {
            // 数据接收完毕，分配给具体的变量
            RollL = receivedData[0];
            RollH = receivedData[1];
            PitchL = receivedData[2];
            PitchH = receivedData[3];
            YawL = receivedData[4];
            YawH = receivedData[5];
            VL = receivedData[6];
            VH = receivedData[7];
            SUM = receivedData[8];

            // 校验SUM是否正确
            uint8_t calculatedSum = 0x55 + 0x53 + RollH + RollL + PitchH + PitchL + YawH + YawL + VH + VL;
            if (calculatedSum == SUM) {
                // 校验成功，可以进行后续处理
                if((float)(((uint16_t)RollH << 8) | RollL)/32768*180>180){
                    Roll = (float)(((uint16_t)RollH << 8) | RollL)/32768*180 - 360;
                }else{
                    Roll = (float)(((uint16_t)RollH << 8) | RollL)/32768*180;
                }

                if((float)(((uint16_t)PitchH << 8) | PitchL)/32768*180>180){
                    Pitch = (float)(((uint16_t)PitchH << 8) | PitchL)/32768*180 - 360;
                }else{
                    Pitch = (float)(((uint16_t)PitchH << 8) | PitchL)/32768*180;
                }

                if((float)(((uint16_t)YawH << 8) | YawL)/32768*180 >180){
                    Yaw = (float)(((uint16_t)YawH << 8) | YawL)/32768*180 - 360;
                }else{
                    Yaw = (float)(((uint16_t)YawH << 8) | YawL)/32768*180;
                }
                
            } else {
                // 校验失败，处理错误
            }
            RxState = WAIT_HEADER1;                                 // 重置状态以等待下一个数据包
        }
        break;
    }
}
