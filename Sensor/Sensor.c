#include "Sensor.h"

#define Black_CNT1          30                               //mode = 1 黑线持续次数
#define Black_CNT2          30                               //mode = 2 黑线持续次数
#define Black_CNT3          50                               //mode = 3、4 黑线持续次数

#define White_CNT           1000                              //白线持续次数  
#define White_CNT2          5000                              //mode = 2 白线持续次数
#define White_CNT3          7000                              //mode = 3、4 白线持续次数


extern volatile int flag;                                  //flag状态位：0-暂停；1-AB；2-BC；3-CD；4-DA；
extern volatile bool flag_LED;
extern volatile int mode;                                  //mode状态位：0-暂停；



/*
    函数功能：路径控制总函数
    参数：无
*/
int Follow_Route(void)
{
    static int cnt = 0;
    /* 模式一 */
    if(mode == 1)
    {
        if(flag == 1)                                                    //AB段末尾
        {
            if(P1 || P2 || P3 || P4 || P5 || P6 || P7 || P8)        //任一点检测到黑线
            {
                cnt++;
                // printf("%d\r\n", cnt);
                if(cnt > Black_CNT1)                                     //检测到黑线持续5次
                {
                    flag_LED = 1;
                    flag = 0;
                    cnt = 0;
                    return 0;
                }
            }
            else   cnt = 0;                                         //连续检测黑线判定
        }   
    }

    /* 模式二 */
    else if(mode == 2)
    {
        /* B点判定 */
        if(flag == 1)
        {
            if(P1 || P2 || P3 || P4 || P5 || P6 || P7 || P8)        //任一点检测到黑线
            {
                cnt++;
                if(cnt > Black_CNT2)             //检测到黑线持续5次
                {
                    flag_LED = 1;
                    flag = 2;               //进入状态二
                    cnt = 0;
                    return 2;
                }
            }
            else   cnt = 0;
        }
        /* C点判定 */
        else if(flag == 2)
        {
            if(!(P1 || P2 || P3 || P4 || P5 || P6 || P7 || P8))                  //所有点检测到白线
            {
                cnt++;
                if(cnt > White_CNT2)               //检测到白线持续White_CNT2次
                {
                    flag_LED = 1;
                    flag = 3;
                    cnt = 0;
                    return 3;
                }
            }
            else   cnt = 0;
        }
        /* D点判定 */
        else if(flag == 3)
        {
            if(P1 || P2 || P3 || P4)        //任一点检测到黑线
            {
                cnt++;
                if(cnt > Black_CNT2)                //检测到黑线持续Black_CNT2次
                {
                    flag_LED = 1;
                    flag = 4;
                    cnt = 0;
                    return 4;
                }
            }
            else   cnt = 0;
        }
        /* A点（终点）判定 */
        else if(flag == 4)
        {
            if(!(P1 || P2 || P3 || P4 || P5 || P6 || P7 || P8))                  //所有点检测到白线
            {
                cnt++;
                if(cnt > White_CNT3 )                  //检测到白线持续White_CNT4次
                {
                    flag_LED = 1;
                    flag = 0;           //一圈结束
                    cnt = 0;
                    return 0;
                }
            }
            else   cnt = 0;
        }
    }

    /* 模式三 */
    else if(mode == 3)
    {
        Follow_Route_Mode3(0);      //仅进行一次绕圈
        return 3;
    }

    /* 模式四 */
    else if(mode == 4)
    {
        Follow_Route_Mode4();      //循环绕四圈
        return 4;
    }
    return 0;
}




/*
    函数功能：模式三路径控制
    参数：  stop：循环停止标志位
    stop - 1：循环继续
    stop - 0：循环一次
*/
int Follow_Route_Mode3(int stop)
{
    static int cnt3 = 0;
    /* C点判定 */
    if(flag == 1)
    {
        if(P5 || P6 || P7 || P8)        //车体左侧任一点检测到黑线
        {
            cnt3++;
            if(cnt3 > Black_CNT3)               //检测到黑线持续Black_CNT3次
            {
                flag_LED = 1;
                flag = 2;               //进入下一状态
                cnt3 = 0;
                return 2;
            }
        }
        else   cnt3 = 0;
    }

    /* B点判定 */
    else if(flag == 2)
    {
        if(!(P1 || P2 || P3 || P4 || P5 || P6 || P7 || P8))              //所有点检测到白线
        {
            cnt3++;
            if(cnt3 > White_CNT3)                             //检测到白线持续White_CNT3次
            {
                flag_LED = 1;
                flag = 3;
                cnt3 = 0;
                return 3;
            }
        }
    }

    /* D点判定 */
    else if(flag == 3)
    {
        if(P1 || P2 || P3 || P4)        //车体右侧任一点检测到黑线
        {
            cnt3++;
            if(cnt3 > Black_CNT3)                      //检测到黑线持续Black_CNT3次
            {
                flag_LED = 1;
                flag = 4;
                cnt3 = 0;
                return 4;
            }
        }
    }

    /* A点判定 */
    else if(flag == 4)
    {
        if(!(P1 || P2 || P3 || P4 || P5 || P6 || P7 || P8))             //所有点检测到白线
        {
            cnt3++;
            if(cnt3 > White_CNT3)                      //检测到白线持续White_CNT3次
            {
                flag_LED = 1;
                flag = stop;                     //停止
                cnt3 = 0;
                return 0;
            }
        }
    }
    return 0;
}





/*
    函数功能：模式四路径控制
*/
int Follow_Route_Mode4(void)
{
    Follow_Route_Mode3(1);  //循环三圈不停止
    Follow_Route_Mode3(1);
    Follow_Route_Mode3(1);
    Follow_Route_Mode3(0);      //停止
    return 0;
}








/*
    函数：Incremental_Quantity
    功能：普通直行巡线模式
    参数：无
*/
int Incremental_Quantity(void)
{
    int value = 0;
    if(!P1) //检测到最右端
        value += 12;
    if(!P2) 
        value += 9;
    if(!P3)
        value += 7;
    if(!P4)
        value += 3;
    if(!P5)
        value -= 3;
    if(!P6)
        value -= 7;
    if(!P7)
        value -= 9;
    if(!P8)
        value -= 12;
    return value;
}




/*
    函数：Incremental_Quantity3
    功能：mode == 3、4, flag == 3时
    说明：C -> B：逆时针巡线
*/
int Incremental_Quantity3(void)
{
    int value = 0;
    if(!P8)
        value += 9;
    if(!P7)
        value += 6;
    if(!P6)
        value += 4;
    if(!P5)
        value += 2;
    if(!P4)
        value -= 2;
    if(!P3)
        value -= 4;
    if(!P2)
        value -= 6;
    if(!P1) 
        value -= 9;
    return value;
}






/*
    函数：Incremental_Quantity4
    功能：mode == 3、4, flag == 4时
    说明：D -> A：顺时针巡线
*/
int Incremental_Quantity4(void)
{
    int value = 0;
    if(!P1) //检测到最右端
        value += 20;
    if(!P2) 
        value += 10;
    if(!P3)
        value += 8;
    if(!P4)
        value += 5;
    if(!P5)
        value -= 5;
    if(!P6)
        value -= 8;
    if(!P7)
        value -= 10;
    if(!P8)
        value -= 20;
    return value;
}
