# 操作系统速查

## 进程 / 线程

| 概念 | 要点 |
|------|------|
| 进程 | 资源单位；独立地址空间 |
| 线程 | 调度单位；共享进程内存 |
| 状态 | 就绪 / 运行 / 阻塞 |

## 内存

虚拟地址 → 页表 → 物理地址；缺页换页

堆 / 栈 / 代码段

## 文件

inode + 目录项；fd；rwx 权限

## 同步

竞态 → 互斥锁；死锁四条件

固定加锁顺序

## Linux

`ps` `top` `kill` `chmod` `ls -l`

## 教程

- [01 进程与线程](../guides/01-process-and-thread.md)
- [02 内存管理](../guides/02-memory-management.md)
- [03 文件系统](../guides/03-filesystem.md)
- [04 同步与死锁](../guides/04-synchronization-and-deadlock.md)
