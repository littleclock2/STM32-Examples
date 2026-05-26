/*
* 使用TIM3的PWM生成一个PWM波，再用捕获定时器测出来PWM的信息
* 本设计使用一个等精度法测量中低频 测频法测高频
* 档位为CAPTRUE时可以测占空比 不过本设计不需要
* 量程8HZ - 25MHZ 稳定运行 
* 精度0.1% 只能说足够使用,可以求平均值提高精度
* 欲用频率计 将PA2 PA3 PE0 一同接待测信号、
* 需要extern double UnknownSig_fre;即频率
*  
*/

#include "stm32f10x.h"
#include <stdbool.h>
#include "myfunc.h"
#include "TIM_PWM.h"
#include "TIM_capture.h"
#include "TIM_ETR.h"
#include "Basic_TIM.h"


int main(void){
 	SystemInit();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIM_PWM_Init();
	TIM_ETR_Init();
	TIM_capture_init();
	BasicTIM_Init();
	
	
	while(1){
		delay_ms(100);
		delay_ms(100);
		delay_ms(100);
	}
	return 0;
}
