# 组成原理速查

## 层次

应用 → OS → ISA → 硬件

## 数据

| 概念 | 要点 |
|------|------|
| 补码 | 负=取反+1；n 位范围 [-2^(n-1), 2^(n-1)-1] |
| 浮点 | IEEE 754；0.1+0.2≠0.3 |
| UTF-8 | 变长；勿按字节截中文 |

## 存储层次

寄存器 < L1 < L2 < L3 < RAM < SSD < HDD

局部性：时间 + 空间

## CPU

取指→译码→执行；流水线；分支预测

性能 ≈ 指令数 × CPI × 时钟周期

## 教程

- [01 系统层次](../guides/01-computer-system-layers.md)
- [02 数据表示](../guides/02-data-representation.md)
- [03 存储层次](../guides/03-memory-hierarchy.md)
- [04 指令与 CPU](../guides/04-instruction-set-and-cpu.md)
