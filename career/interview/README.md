# 程序员面试准备

> 面向 2020s 中后期技术栈的通用面试指南：云原生、分布式、现代后端，以及 AI 辅助编程与 LLM 应用。采用「场景 + 原则 + 反例」结构；不包含敏感公司信息。

## 学习顺序

| 序号 | 教程 | 状态 | 涵盖内容 |
|------|------|------|----------|
| 01 | [面试准备](guides/01-interview-preparation.md) | 已发布 | 简历与作品集、流程与时间规划、行为面试 |
| 02 | [计算机基础](guides/02-cs-fundamentals.md) | 已发布 | 操作系统与 Linux、计算机网络、数据库与存储 |
| 03 | [数据结构与算法](guides/03-data-structures-and-algorithms.md) | 已发布 | 常见数据结构、复杂度、排序查找、刷题策略与现场编程 |
| 04 | [系统设计与工程实践](guides/04-system-design-and-engineering.md) | 已发布 | 系统设计方法与典型场景、现代后端栈、分布式、云原生 |
| 05 | [AI 辅助编程与应用](guides/05-ai-assisted-development.md) | 已发布 | IDE Agent 工作流、LLM 应用基础、AI 时代面试策略 |
| 06 | [经典 100 题面试宝典](guides/06-classic-100-questions.md) | 已发布 | 100 道经典技术面 Q&A（Java/算法/SQL/网络/框架 + 历史→现代） |

---

## 章节说明

### 01 面试准备

| 小节 | 要点 |
|------|------|
| 简历与作品集 | STAR、量化成果、GitHub / 开源 / Demo |
| 流程与时间规划 | 笔试 → 技术面 → HR 面；投递节奏、复盘模板 |
| 行为面试 | 协作冲突、失败经历、职业规划 |
| 答题结构 | 是什么 → 原理 → 注意点 → 思路 |

### 02 计算机基础

| 小节 | 2020s 常考重点 | 仓库双链 |
|------|----------------|----------|
| 操作系统 | 进程 vs 线程、虚拟内存、死锁 | [fundamentals/03-operating-systems/](../../fundamentals/03-operating-systems/) · [engineering/02-linux-and-shell/](../../engineering/02-linux-and-shell/) |
| 计算机网络 | TCP/HTTP、TLS、DNS、CDN | [fundamentals/04-networking/](../../fundamentals/04-networking/) |
| 数据库与存储 | 索引、事务、SQL 思路、Redis | [fundamentals/05-databases/](../../fundamentals/05-databases/) |

### 03 数据结构与算法

| 小节 | 面试要点 | 仓库双链 |
|------|----------|----------|
| 数据结构选型 | 数组、链表、栈/队列、树、哈希 | [fundamentals/01-data-structures/](../../fundamentals/01-data-structures/) |
| 排序与复杂度 | 快排、归并、大 O | [fundamentals/01-data-structures/guides/05-sorting-algorithms.md](../../fundamentals/01-data-structures/guides/05-sorting-algorithms.md) |
| 经典案例 | 栈序列、TopK、Singleton、UTF-8 截取 | — |
| 现场编程 | 刷题节奏、沟通、边界测试 | — |

### 04 系统设计与工程实践

| 小节 | 要点 |
|------|------|
| 系统设计 | 需求澄清、容量估算、trade-off |
| 典型场景 | 短链、Feed、秒杀、文件存储 |
| 现代后端 | REST、gRPC、JWT、幂等、限流 |
| 分布式与云原生 | MQ、缓存、Docker/K8s、CI/CD |

### 05 AI 辅助编程与应用

| 小节 | 要点 |
|------|------|
| AI 辅助编程 | Cursor/Copilot 工作流、Review 清单 |
| LLM 应用 | RAG、Agent、评测 |
| 面试策略 | 诚实描述 AI 使用；AI 岗 vs 工程岗 |

> 原则：AI 是杠杆，不是替身。

### 06 经典 100 题面试宝典

| 小节 | 要点 |
|------|------|
| Java / OOP | Q01–Q22：语法、String、多态、抽象类与接口 |
| 并发 / JVM | Q23–Q34：线程、锁、堆栈、GC、类加载 |
| 集合 / 算法 | Q35–Q57：Collection、IO、Singleton、排序、TopK |
| 数据库 / 网络 | Q58–Q84：SQL、索引、事务、HTTP/TCP、JWT |
| 框架 / 历史 | Q85–Q100：设计模式、Spring、Struts/EJB 现代对照 |

---

## 按岗位裁剪

| 岗位方向 | 重点章节 | 可弱化 |
|----------|----------|--------|
| 后端 / 全栈 | 01～05 全读 | — |
| 基础架构 / SRE | 02、04 加重 | 03 DP 深度 |
| 算法 / ML 工程 | 03 加重，05 必读 | 04 REST 细节 |
| AI 应用 / LLM 工程 | 03、04、05 加重 | 04 K8s 深度（视 JD） |
| 嵌入式 / C++ | 02、03 + [languages/](../../languages/) | 04 按 JD |
| 校招 / 实习 | 01～03 为主，04 了解概念 | 04 系统设计场景 |
| 八股速查 | **06 经典 100 题** + 02～03 | 06 第八章历史题按需 |

---

## 速查

| 文档 | 说明 |
|------|------|
| [06-classic-100-questions.md](guides/06-classic-100-questions.md) | **经典 100 题**完整 Q&A（速查主入口） |
| [interview-checklist.md](references/interview-checklist.md) | 面试前 / 中 / 后检查清单 |
| [common-questions-index.md](references/common-questions-index.md) | 高频问题索引 |
| [modern-stack-glossary.md](references/modern-stack-glossary.md) | 现代栈术语速查 |
| [ai-interview-talking-points.md](references/ai-interview-talking-points.md) | AI 相关面试话术 |

---

## 关联模块

| 方向 | 入口 |
|------|------|
| 数据结构 | [fundamentals/01-data-structures/](../../fundamentals/01-data-structures/) |
| 操作系统 | [fundamentals/03-operating-systems/](../../fundamentals/03-operating-systems/) |
| 计算机网络 | [fundamentals/04-networking/](../../fundamentals/04-networking/) |
| 数据库 | [fundamentals/05-databases/](../../fundamentals/05-databases/) |
| 工程实践 | [engineering/](../../engineering/) |
| 语言教程 | [languages/](../../languages/) |

## 资源

- [推荐书单](../resources/books.md)
- [社区与资讯](../resources/communities.md)

## 素材说明

案例与题型结构参考公开面试题集（如经典八股、算法 100 题、SQL/网络/design 类题目），经重写为「场景 + 原则 + 反例」教程体例，并映射到现代技术栈；不包含特定公司内部题面。
