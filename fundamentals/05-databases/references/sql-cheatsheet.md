# SQL 与数据库速查

## 建模

主键 PK；外键 FK；1NF 2NF 3NF 减冗余

## 查询

```sql
SELECT ... FROM ... WHERE ...
JOIN ... ON ...
GROUP BY ... HAVING ...
ORDER BY ... LIMIT ...
```

INNER / LEFT JOIN

## 索引

B+ 树；联合索引最左前缀；覆盖索引免回表

EXPLAIN 看执行计划

## 事务

ACID；隔离级别 RC / RR / Serializable

脏读 / 不可重复读 / 幻读

MVCC + 行锁 / 间隙锁

## 扩展

主从读写分离；分库分表；Redis 缓存

穿透 / 击穿 / 雪崩

## 教程

- [01 关系模型与 SQL](../guides/01-relational-model-and-sql.md)
- [02 索引优化](../guides/02-index-and-query-optimization.md)
- [03 事务并发](../guides/03-transaction-and-concurrency.md)
- [04 存储扩展](../guides/04-storage-and-scaling.md)
