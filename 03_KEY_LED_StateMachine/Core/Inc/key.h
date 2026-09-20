#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

typedef enum
{
    KEY_EVENT_NONE = 0, // 当前没有按键事件
    KEY_EVENT_SHORT_PRESS, // 检测到一次短按
    KEY_EVENT_LONG_PRESS  // 检测到一次长按
} KEY_EVENT;

KEY_EVENT Key_Scan(void);

//uint16_t Scan_key(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

#endif
