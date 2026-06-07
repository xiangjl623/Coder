# 存储与扩展

> **难度**：进阶 | **阅读时间**：约 20 分钟 | **前置**：[事务与并发](03-transaction-and-concurrency.md) | **标签**：`replication` `redis` `sharding`

## 学习目标

- [ ] 了解主从复制与读写分离
- [ ] 知道分库分表的基本动机
- [ ] 理解 Redis 在架构中的常见角色

## 垂直与水平扩展

| 方式 | 说明 |
|------|------|
| 垂直 | 更强 CPU/内存/磁盘 |
| 水平 | 更多机器分担数据与流量 |

数据库单机到极限 → **读写分离**、**分库分表**、**缓存**。

## 主从复制

```
主库 (写) --binlog 同步--> 从库 (读)
```

- 写走主，读走从（延迟需容忍）
- 故障切换：提升从库为主（运维复杂）

## 分库分表

**分库**：按业务或 hash 拆到不同 DB 实例。  
**分表**：单库内按 user_id 等 hash 多表。

**挑战**：跨分片 JOIN、全局 ID、扩容 rebalance。

**原则**：能不分就不分；先优化索引与 SQL；再缓存；最后分片。

## Redis 常见用途

| 场景 | 命令/结构 |
|------|-----------|
| 缓存 | String + TTL |
| 计数 | INCR |
| 排行榜 | ZSET |
| 分布式锁 | SET key NX EX |
| 会话 | Hash |

### 缓存问题

| 问题 | 思路 |
|------|------|
| 穿透 | 布隆过滤器 / 缓存空值 |
| 击穿 | 热点 key 互斥重建 |
| 雪崩 | 过期时间加随机 |

## NoSQL（概览）

| 类型 | 示例 | 适用 |
|------|------|------|
| KV | Redis | 缓存、计数 |
| 文档 | MongoDB | 灵活 schema |
| 列族 | HBase | 大数据（了解） |

强一致核心业务仍多选 **关系型 +  careful 设计**。

## 连接池

应用维护连接池复用 TCP 连接，避免频繁建连 — 经典 JDBC/ORM 面试点。

## 本节小结

- 扩展路径：优化 → 缓存 → 读写分离 → 分片
- Redis 作缓存与辅助结构，非主存（除非设计如此）
- 分库分表带来分布式复杂度

## 练习

1. 画「读多写少」系统的缓存 + 主从架构图
2. 说明为何「双写缓存与 DB」可能不一致

## 延伸阅读

- [career/interview/guides/04-system-design-and-engineering.md](../../../career/interview/guides/04-system-design-and-engineering.md)
- [sql-cheatsheet.md](../references/sql-cheatsheet.md)
