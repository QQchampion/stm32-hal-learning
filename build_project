# 1. 选择CPU型号

> STM32F103VET6芯片开发的一款开发板，Cortex-M3内核，主频为**72MHz**,512KB的代码闪存，以及64KB的SRAM

- F103-MINI，选STM32F103RCTx型号
- F103-指南者，选STM32F103VETx型号
- F103-霸道，选STM32F103ZETx型号
- F103-拂晓电机开发板，选STM32F103VETx型号

# 2. 确认时钟源

> MCU需要时钟才能按照节拍执行指令，就像系统的“心跳”

- HSI：芯片内部提供，方便，但精度相对一般
- HSE：外部提供，通常更准确，但必须确认开发板确实有对应晶振

CCR(`Crystal/Ceramic Resonator`) : 外部晶体/陶瓷谐振器 , 作为高速外部时钟（HSE）的来源
	相比于stm32内部自带时钟源（HSI，内部高速时钟）具有**精度差**（易受温度和电压影响）、**不稳定**（随着芯片发热、频率会飘）；CCR具有较好精度和稳定性

# 3. 配置系统时钟

> 本质：把原始晶振频率转换成芯片各个模块实际需要的工作频率
> 配置系统时钟：决定这个8 MHz怎样经过倍频、分频，最终分别送给CPU、GPIO、串口、定时器等模块。

STM32F103VET6芯片主频为**72MHz**，故须PLL(×9 倍频)得到
```text
HSE (8MHz 晶振)
   │
   ▼
PLL (×9 倍频)
   │
   ▼
PLLCLK (72MHz)
   │
   ▼
SYSCLK (72MHz)  ← 系统时钟，选 PLLCLK
   │
   ▼
HCLK (72MHz)    ← AHB ÷1，喂给 CPU/内存/DMA
   │
   ├──► PCLK2 (72MHz)  ← APB2 ÷1，喂给 GPIO/USART1/SPI1
   │
   └──► PCLK1 (36MHz)  ← APB1 ÷2，喂给 USART2/I2C/TIM2
```

> STM32F103VET6芯片主频为**72MHz**，故须PLL(×9 倍频)得到
> APB1因为最高只能36 MHz，所以除以2 
> APB2可以运行在72 MHz，所以不分频

# 4. 配置IO口

若需要点亮LED必须查看PCB开发板的**原理图**，以保证是哪一个引脚控制LED灯

> IO口需要参考：数据手册

![[Pasted image 20260916094446.png|382]]

>STM32引脚数量有限，所以一个引脚通常不只具备一种功能。例如`PD5`既可以作为普通GPIO，也可以连接FSMC外设，还可以通过“重映射”作为`USART2_TX`。

## 1. 主功能

复位后的基本身份

> 芯片刚上电或复位后，该引脚默认承担的功能。

|引脚|主功能|
|---|---|
|PD0|`OSC_IN`|
|PD1|`OSC_OUT`|
|PD2|`PD2`|
|PD3|`PD3`|
|PD5|`PD5`|
>`PD2`、`PD3`、`PD5`这种写法表示它们的基本身份是普通GPIO引脚。

## 2. 默认复用功能

外设默认连接的位置

> "复用"：同一个引脚除了作为普通GPIO，还能交给片内外设控制。

当启用FSMC并使用其默认引脚映射时，PD5可以变成：FSMC_NWE，这时PD5不再由普通GPIO代码控制，而是由FSMC外设硬件控制。

## 3. 重定义功能：

把外设换到另一组固定引脚

>某个外设原本有一组默认引脚，但为了避免引脚冲突，STM32允许把它整体或部分移动到另一组预先规定好的引脚。

启用USART2重映射后，USART2的发送信号从默认的PA2转移到PD5。
# 5. 进一步配置IO的具体属性

进一步设置IO的属性
# 6. 配置工程属性

配置文件的名称、地址....
注意：要选择正确的编译工具，即 **Toolchain / IDE：MDK-ARM**

# 7. 生成代码

```text
Project: LED_light
└── LED_light
    ├── Application/MDK-ARM          ← 启动文件
    ├── Application/User/Core        ← 你的代码（main.c 等）
    ├── Drivers/STM32F1xx_HAL_Driver ← HAL 库
    ├── Drivers/CMSIS                ← 内核接口
    └── CMSIS                        ← Keil RTE 组件

```
