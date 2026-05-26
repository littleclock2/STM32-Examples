#include "stm32f10x.h"
#include "TIM_PWM.h"
#include <stdbool.h>

/*TIM3 OC2 作为PWM输出通道*/
void TIM_PWM_Init(void){
	
	
	/*设置为1kHZ 向上计数的时基*/
	TIM_TimeBaseInitTypeDef TIM_PWM_Init = {
		.TIM_Prescaler = 10000 - 1,
		.TIM_ClockDivision = TIM_CKD_DIV1,
		.TIM_Period = 456 - 1,
		.TIM_CounterMode = TIM_CounterMode_Down
	};
	
	/*比较捕获寄存器设置*/
	TIM_OCInitTypeDef TIM_PWM_OC_Init = {
		.TIM_OCMode = TIM_OCMode_PWM1,//PWM1模式
		.TIM_Pulse = 0,//PWM定时器的比较值 本程序使用PWM作呼吸灯，需要更改，初始值为0
		.TIM_OCPolarity = TIM_OCPolarity_High,//大于比较值时输出高电平
		.TIM_OutputState = ENABLE
	};
	//NVIC配置
	NVIC_InitTypeDef TIM_NVIC = {
		.NVIC_IRQChannel = TIM3_IRQn,
		.NVIC_IRQChannelPreemptionPriority = 1,
		.NVIC_IRQChannelSubPriority = 3,
		.NVIC_IRQChannelCmd = ENABLE
	};
	
	//LED灯GPIO配置
		GPIO_InitTypeDef LED_Init = {
		.GPIO_Pin = GPIO_Pin_5,
		.GPIO_Mode = GPIO_Mode_AF_PP,
		.GPIO_Speed = GPIO_Speed_50MHz
	};
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//NVIC_Init(&TIM_NVIC);
	
	GPIO_Init(GPIOB,&LED_Init);
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3部分重映射  TIM3_CH2->PB5    
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//重映射TIM_PWM，到了PB5的LED上
	
	TIM_TimeBaseInit(TIM3,&TIM_PWM_Init);//定时器时基初始化
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//更新中断
	TIM_ClearFlag(TIM3,TIM_IT_Update);
	
	TIM_OC2Init(TIM3,&TIM_PWM_OC_Init);//OC2初始化
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//使能预装载寄存器
	TIM_Cmd(TIM3,ENABLE);

	TIM_SetCompare2(TIM3,11);

	return;
	
	
}

void TIM3_IRQHandler(void){
	static bool flag = 0;//呼吸灯正反标志位
	static uint16_t cnt = 0;
	/*if(TIM_GetFlagStatus(TIM_PWM,TIM_IT_Update)){
		if(flag)
			flag = (--cnt == 0)? false : true; 
		else
			flag = (++cnt == 720)? true : false; 
		TIM_SetCompare2(TIM_PWM,cnt);
		TIM_ClearFlag(TIM_PWM,TIM_IT_Update);
	}
	*/
	return;
}