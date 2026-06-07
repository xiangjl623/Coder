# 索引与查询优化

> **难度**：进阶 | **阅读时间**：约 20 分钟 | **前置**：[关系模型与 SQL](01-relational-model-and-sql.md) | **标签**：`index` `b-tree`

## 学习目标

- [ ] 解释 B+ 树索引为何适合范围查询
- [ ] 知道何时索引失效或帮倒忙
- [ ] 了解 EXPLAIN 与慢查询思路

## 为什么需要索引

全表扫描 O(n)；索引将查找降到 O(log n) 或更好（哈希等值）。

**代价**：占空间；INSERT/UPDATE/DELETE 需维护索引。

## B+ 树（InnoDB 默认）

与 [01 数据结构：树](../../01-data-structures/guides/03-trees-and-graphs-intro.md) 对照：

- 多路平衡树，磁盘友好
- **叶子节点** 存数据或主键 + 链表 → 范围扫描 `WHERE id BETWEEN` 高效
- 非叶子只存键，减少 IO

## 索引类型（MySQL 语境）

| 类型 | 说明 |
|------|------|
| 主键索引 | 聚簇，行数据在叶子（InnoDB） |
| 二级索引 | 叶子存主键，回表查行 |
| 唯一索引 | 值唯一 |
| 联合索引 | 多列；最左前缀原则 |

**最左前缀**：索引 `(a,b,c)` 可加速 `a`、`a,b`，不一定加速单独 `b`。

## 常见失效场景

- 对索引列函数：`WHERE YEAR(created_at)=2024`
- 隐式类型转换
- `%like` 前缀通配
- OR 连接不同列且未全覆盖索引
- 优化器判断全表更快（小表）

## 查询优化思路

1. **EXPLAIN** 看 type、key、rows
2. 避免 `SELECT *`，减少回表
3. 深分页：`LIMIT 1000000,10` 慢 → 游标 `WHERE id > last_id LIMIT 10`
4. 读写分离、缓存热点（见 [04 存储与扩展](04-storage-and-scaling.md)）

## 覆盖索引

查询列全在索引中 → 无需回表，性能更好。

## 本节小结

- 索引 = 空间换时间；B+ 树支持排序与范围
- 联合索引注意最左前缀
- 优化先看 EXPLAIN，再谈加索引

## 练习

1. 为 `WHERE user_id=? AND status=? ORDER BY created_at` 设计联合索引
2. 解释二级索引为何有时需要「回表」

## 延伸阅读

- [事务与并发](03-transaction-and-concurrency.md)
- [05-databases README](../README.md)
