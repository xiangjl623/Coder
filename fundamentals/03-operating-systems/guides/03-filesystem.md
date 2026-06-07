# 文件系统

> **难度**：入门 | **阅读时间**：约 18 分钟 | **前置**：[内存管理](02-memory-management.md) | **标签**：`filesystem` `inode`

## 学习目标

- [ ] 理解文件、目录与路径
- [ ] 知道 inode 存元数据、目录存文件名映射
- [ ] 会使用 Linux 基本文件权限

## 文件抽象

OS 把磁盘数据组织为 **文件**（字节流）和 **目录**（名字 → 文件/子目录）。

**路径**：

- 绝对：`/home/user/doc.txt`
- 相对：相对当前工作目录

## inode（概念）

Unix 系文件系统中，**inode** 存文件元数据：大小、权限、时间戳、数据块指针等；**目录项** 把文件名链接到 inode。

```
文件名 "report.txt" → inode #12345 → 数据块
```

硬链接：多个目录项指向同一 inode；软链接（符号链接）：存另一路径字符串。

## 权限（Linux）

```bash
ls -l
# -rw-r--r-- 1 user group 1024 Jan  1 12:00 file.txt
#  owner group others: rwx
```

| 权限 | 文件 | 目录 |
|------|------|------|
| r | 读内容 | 列目录 |
| w | 写内容 | 增删改目录项 |
| x | 执行 | 进入（cd） |

`chmod`、`chown` 修改权限与属主。

## 打开文件的过程

```
open("a.txt") → 进程获得文件描述符 fd
read(fd, buf, n) → 内核读数据到 buf
close(fd)
```

标准输入/输出/错误：fd 0、1、2。

## 与 C 语言

```c
FILE *fp = fopen("data.txt", "r");
/* 或更低层 read/write，见 languages/c/ */
```

## 本节小结

- 文件 = 命名 + inode + 数据块
- Linux 权限 rwx 对文件/目录含义不同
- fd 是进程访问文件的句柄

## 练习

1. 用 `ls -li` 观察 inode 号；创建硬链接对比
2. 解释为何删除正在写入的日志文件有时仍占磁盘空间（进程仍持有 fd）

## 延伸阅读

- [engineering/02-linux-and-shell/](../../../engineering/02-linux-and-shell/)
- [同步与死锁](04-synchronization-and-deadlock.md)
