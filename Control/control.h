#include "sys.h"

void Control(void);
void Set_Pwm(int Left, int Right);
float PWM_Limit(float IN,float max,float min);
float PID_A(float Encoder,float Target);
float PID_B(float Encoder,float Target);
float Target_Control(float now,float target);
float GYRO_Control(float now,float target);
