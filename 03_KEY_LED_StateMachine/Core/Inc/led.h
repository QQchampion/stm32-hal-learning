#ifndef __LED_H__
#define __LED_H__

#include "main.h"


// ×´Ì¬»úË¼Ïë
typedef enum{
	LED_ON,
	LED_OFF
}LED_STATE;

void LED_SetState(LED_STATE sate);

#endif

