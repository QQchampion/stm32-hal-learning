#include "led.h"

// 目前来说，只控制了一个灯，努力进一步改成控制三个灯
// 初步想法，先switch选灯，再嵌套switch选状态
void LED_SetState(LED_STATE sate) 
	{ 
	switch (sate)
		{
		case LED_OFF: // 状态关灯，此时应为关灯
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			break;
		
		case LED_ON: // 状态开灯，此时应为开灯
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
			break;	
		}
	}
	
