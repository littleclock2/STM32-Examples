# STM32 Examples

STM32 基础例程合集，包含频率测量等常用外设实验。

## 硬件需求

- 主控芯片：STM32F103ZET6
- 外设：TIM 输入捕获、TIM PWM、TIM ETR

## 软件环境

- IDE：Keil MDK-ARM
- 标准外设库：STM32F10x Standard Peripheral Library

## 例程列表

| 例程 | 说明 |
|------|------|
| FrequencyMeasure | 频率测量（TIM 输入捕获，8Hz-25MHz，精度 0.1%） |

## 目录结构

```
STM32-Examples/
├── FrequencyMeasure/    # 频率测量例程
│   ├── APP/             # 外设驱动
│   ├── Libraries/       # 标准外设库
│   ├── StaruUp/         # 启动文件
│   └── User/            # 主程序
├── LICENSE
└── README.md
```

## 许可证

[CC BY-NC 4.0](https://creativecommons.org/licenses/by-nc/4.0/deed.zh-hans)


---

Maintained by contributors.


