#include "key.h"

#define KEY_LONG_PRESS_TIME  1000
#define KEY_DEBOUNCE_TIME    20 // 消抖时间

KEY_EVENT Key_Scan(void)
{
    static uint8_t key_pressed = 0; // 记录程序是否已经确认了“这次按下”
    static uint8_t long_pressed = 0; //记录本次按键是否已经触发过长按
    static uint32_t press_time = 0; // 记录按键是什么时候按下的
 
    GPIO_PinState key_level; // 枚举出 按键的 GPIO 引脚的电平状态

    key_level = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

    /* 当前按键处于按下状态 */
    if (key_level == GPIO_PIN_SET)
    {
        /* 第一次检测到按下 */
        if (key_pressed == 0)
        {
            HAL_Delay(KEY_DEBOUNCE_TIME);

            if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
            {
                key_pressed = 1;
                long_pressed = 0;
                press_time = HAL_GetTick();
            }
        }

        /* 按住时间达到1秒，产生一次长按事件 */
        if ((key_pressed == 1) &&
            (long_pressed == 0) &&
            (HAL_GetTick() - press_time >= KEY_LONG_PRESS_TIME))
        {
            long_pressed = 1;

            return KEY_EVENT_LONG_PRESS;
        }
    }else
    {
        /* 之前按下，现在释放 */
        if (key_pressed == 1)
        {
            HAL_Delay(KEY_DEBOUNCE_TIME);

            if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
            {
                key_pressed = 0;

                /*
                 * 如果本次没有产生长按事件，
                 * 那么释放时产生一次短按事件。
                 */
                if (long_pressed == 0)
                {
                    return KEY_EVENT_SHORT_PRESS;
                }

                long_pressed = 0;
            }
        }
    }

    return KEY_EVENT_NONE;
}