# STM32 HAL学习记录

## 学习目标

> 使用STM32 HAL库掌握常用外设、FreeRTOS和嵌入式项目开发。

## 硬件信息

- 开发板：
- MCU型号：
- 调试器：
- IDE：STM32CubeIDE
- 主教材：野火《STM32 HAL库开发实战指南》
  教材链接：https://doc.embedfire.com/mcu/stm32/f103/hal_general/zh/latest/doc/chapter1/chapter1.html#id2

## 工程目录

```text
仓库根目录/
├── 01_LED_light/       # STM32F103VET6 点灯工程（CubeMX + HAL + Keil）
├── 02_key/             # STM32F103VET6 按键控制 LED 工程
├── build_project/      # 芯片配置步骤或构建辅助文档
├── .gitignore          # 忽略编译产物和本地配置
└── README.md           # 项目说明和学习记录
```

`01_LED_light` 和 `02_key` 是两个相互独立的 STM32CubeMX/Keil 工程，各自包含 `.ioc`、源代码、HAL 驱动和 Keil 工程文件，可以分别打开、编译和烧录。

| 工程 | 内容 | 主要引脚 |
| --- | --- | --- |
| `01_LED_light` | GPIO 输出与 LED 点灯 | LED_G：PB0；LED_R：PB5 |
| `02_key` | GPIO 输入、按键消抖与按键控制 LED | KEY1：PA0；KEY2：PC13；LED_G：PB0；LED_R：PB5 |

> 仓库不保存 Keil 编译输出以及本机用户配置。克隆后请使用工程目录中的 `.ioc` 或 `.uvprojx` 打开对应工程，并在本地重新编译。

## 学习进度

- [ ] GPIO输出
- [ ] GPIO输入
- [ ] EXTI外部中断
- [ ] 定时器
- [ ] PWM
- [ ] UART
- [ ] ADC
- [ ] I2C
- [ ] SPI
- [ ] DMA
- [ ] FreeRTOS
