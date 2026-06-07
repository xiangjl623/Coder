# 事务与并发

> **难度**：进阶 | **阅读时间**：约 22 分钟 | **前置**：[索引与查询优化](02-index-and-query-optimization.md) | **标签**：`transaction` `acid` `mvcc`

## 学习目标

- [ ] 说出 ACID 含义
- [ ] 对比四种隔离级别与异常现象
- [ ] 了解 MVCC 如何解决读写冲突

## 事务

一组 SQL 作为**整体**提交或回滚：

```sql
START TRANSACTION;
UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;
COMMIT;   -- 或 ROLLBACK;
```

## ACID

| 字母 | 含义 |
|------|------|
| A 原子性 | 全成功或全失败 |
| C 一致性 | 约束始终满足（如不透支） |
| I 隔离性 | 并发事务互不不当干扰 |
| D 持久性 | 提交后崩溃不丢 |

## 并发异常

| 现象 | 说明 |
|------|------|
| 脏读 | 读到未提交的数据 |
| 不可重复读 | 同一事务两次读同行不同（他事务 UPDATE 并提交） |
| 幻读 | 同一条件两次读行数不同（他事务 INSERT/DELETE） |

## 隔离级别

| 级别 | 脏读 | 不可重复读 | 幻读 |
|------|------|------------|------|
| READ UNCOMMITTED | 可能 | 可能 | 可能 |
| READ COMMITTED | 否 | 可能 | 可能 |
| REPEATABLE READ | 否 | 否 | 多数否* |
| SERIALIZABLE | 否 | 否 | 否 |

*InnoDB 默认 RR，MVCC + 间隙锁处理多数幻读。

## MVCC（多版本并发控制）

每行多版本；读看到 **快照**，写创建新版本 — 读写少阻塞。

**undo log**：旧版本链，支持一致性读与回滚。

## 锁（简述）

- **行锁**：锁单行
- **表锁**：锁整表（MyISAM 等）
- **间隙锁**：锁索引间隙，防幻读（RR）

**原则**：事务尽量短；固定访问顺序减死锁（与 [03 OS：死锁](../../03-operating-systems/guides/04-synchronization-and-deadlock.md) 同理）。

## 经典场景

**百万用户积分清零**：分批 UPDATE、低峰、避免长事务锁表、记录任务进度、可幂等重试。

## 本节小结

- 事务保证 ACID
- 隔离级别 trade-off 性能与一致性
- InnoDB 靠 MVCC + 锁实现并发控制

## 练习

1. 举例说明「不可重复读」与「幻读」区别
2. 为什么银行转账必须包在事务里

## 延伸阅读

- [存储与扩展](04-storage-and-scaling.md)
- [career/interview/guides/02-cs-fundamentals.md](../../../career/interview/guides/02-cs-fundamentals.md)
