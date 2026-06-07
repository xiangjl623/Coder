# 计算机基础

> **难度**：进阶 | **阅读时间**：约 40 分钟 | **前置**：[01 面试准备](01-interview-preparation.md) | **标签**：`os` `network` `database`

## 学习目标

- [ ] 能对比进程与线程、说明死锁四个必要条件
- [ ] 说清 TCP 与 HTTP、GET 与 POST 的区别
- [ ] 解释索引、事务隔离级别与常见 SQL 思路

---

## 一、操作系统与 Linux

与 [fundamentals/03-operating-systems/](../../../fundamentals/03-operating-systems/) 专题对照复习。

### 进程 vs 线程

| 维度 | 进程 | 线程 |
|------|------|------|
| 资源 | 独立地址空间 | 共享进程内存 |
| 切换开销 | 较大 | 较小 |
| 通信 | IPC（管道、消息队列等） | 共享变量（需同步） |
| 崩溃影响 | 相对隔离 | 可能影响整个进程 |

**面试常考**：`sleep()` vs `wait()` —— `sleep` 不释放锁，时间到后重新竞争；`wait` 在同步块中调用，释放锁并等待 `notify`。

### 虚拟内存

把磁盘空间当作内存扩展，通过页表映射。好处：进程隔离、内存大于物理 RAM、按需加载。

### 死锁

四个必要条件（缺一不可）：互斥、占有且等待、不可抢占、循环等待。

**避免思路**：固定加锁顺序、超时重试、银行家算法（了解即可）。

### Linux 常考点

与 [engineering/02-linux-and-shell/](../../../engineering/02-linux-and-shell/) 对照复习：

```bash
ps aux          # 查看进程
top / htop      # 资源占用
kill -9 <pid>   # 强制结束
```

**场景题**：「如何查某个端口被谁占用？」→ `netstat -tlnp` 或 `ss -tlnp`（现代发行版）。

---

## 二、计算机网络

与 [fundamentals/04-networking/](../../../fundamentals/04-networking/) 专题对照复习。

### OSI 与 TCP/IP（简化对照）

| OSI 层 | TCP/IP | 典型协议/设备 |
|--------|--------|---------------|
| 应用层 | 应用层 | HTTP、DNS、gRPC |
| 表示/会话 | （并入应用） | TLS、Cookie |
| 传输层 | 传输层 | TCP、UDP |
| 网络层 | 网络层 | IP、路由器 |
| 数据链路/物理 | 网络接口 | 以太网、交换机 |

### TCP vs UDP

| | TCP | UDP |
|---|-----|-----|
| 连接 | 面向连接 | 无连接 |
| 可靠 | 重传、有序 | 不保证 |
| 场景 | HTTP、文件传输 | 视频、DNS、游戏 |

### HTTP 要点

**GET vs POST**（经典笔试题，需结合语义与实现）：

| 维度 | GET | POST |
|------|-----|------|
| 语义 | 获取资源 | 提交/创建（常带 body） |
| 缓存 | 可缓存 | 通常不缓存 |
| 幂等 | 幂等 | 不一定 |
| Body | 一般无 | 常有 |

**补充（2020s）**：HTTP/2 多路复用；HTTPS = HTTP + TLS；REST 资源用名词 URI + 动词 HTTP 方法。

### 从 URL 到页面（简版）

```
DNS 解析域名 → TCP 三次握手 → TLS 握手（HTTPS）
→ 发送 HTTP 请求 → 服务器响应 → 浏览器解析渲染
```

可结合「浏览器输入 URL 后发生什么」类题目，按层回答，不必一次背全栈细节。

### 会话跟踪

Cookie、Session、Token（JWT）—— 现代前后端分离多用 **JWT + 无状态 API**；传统 JSP 时代常考 Session 与 Cookie 区别。

---

## 三、数据库与存储

与 [fundamentals/05-databases/](../../../fundamentals/05-databases/) 专题对照复习。

### 关系型基础

**三范式（口述版）**：

1. 字段原子性，无重复组
2. 非主键字段完全依赖主键
3. 非主键字段不传递依赖其他非主键字段

**反例**：学生表里冗余存「院系名称」且未与院系表关联 → 更新异常。

### 索引

InnoDB 常用 **B+ 树**索引：叶子节点链表便于范围扫描；与 [fundamentals/01-data-structures/](../../../fundamentals/01-data-structures/) 树结构、[fundamentals/05-databases/](../../../fundamentals/05-databases/) 对照理解。

**原则**：WHERE / JOIN / ORDER BY 常用列考虑索引；避免过多索引拖慢写入。

### 事务与隔离级别

| 级别 | 脏读 | 不可重复读 | 幻读 |
|------|------|------------|------|
| READ UNCOMMITTED | 可能 | 可能 | 可能 |
| READ COMMITTED | 否 | 可能 | 可能 |
| REPEATABLE READ | 否 | 否 | InnoDB 下幻读多为否* |
| SERIALIZABLE | 否 | 否 | 否 |

*MySQL InnoDB 默认 REPEATABLE READ，通过 MVCC + 间隙锁处理多数幻读场景。

### 经典 SQL 思路（素材化）

**场景**：查每门课都大于 80 分的学生。

```sql
SELECT student_id
FROM scores
GROUP BY student_id
HAVING MIN(score) > 80;
```

**场景**：部门工资高于本部门平均工资的员工。

```sql
SELECT e.*
FROM employees e
JOIN (
  SELECT dept_id, AVG(salary) AS avg_sal
  FROM employees GROUP BY dept_id
) d ON e.dept_id = d.dept_id
WHERE e.salary > d.avg_sal;
```

**场景**：百万用户积分每年清零 —— 考虑：分批 UPDATE、避免长事务锁表、低峰执行、归档日志、是否用定时任务 + 限流。

### 分页

小数据：`LIMIT offset, size`。深分页性能差时：用 **上次最大 id** 游标分页，或搜索引擎。

### Redis 与 NoSQL（简述）

| 用途 | 说明 |
|------|------|
| 缓存 | 热点数据、减轻 DB 压力；注意穿透/击穿/雪崩 |
| 分布式锁 | SET NX EX；需考虑超时与续期 |
| 计数 / 排行榜 | INCR、ZSET |

NoSQL（MongoDB 等）适合文档型、灵活 schema；强一致金融核心仍多选关系型 +  careful 设计。

---

## 四、答题示例：线程同步

**问**：`synchronized` 与 `Lock` 有何异同？

1. **是什么**：二者都用于互斥访问共享资源。
2. **原理**：`synchronized` JVM 内置、自动释放；`Lock`（如 `ReentrantLock`）显式 `lock/unlock`，可中断、可公平、可多条件变量。
3. **注意**：`Lock` 必须在 `finally` 中释放；高并发下还可了解 CAS、无锁结构（进阶）。

---

## 本节小结

- OS：进程/线程、死锁、Linux 常用命令
- 网络：分层、TCP/HTTP、GET/POST、URL 请求链
- 数据库：范式、索引、事务、SQL 聚合与 JOIN 思路、Redis 角色

## 练习

1. 手绘 TCP 三次握手、四次挥手时序图
2. 为「博客文章表 + 评论表」写第三范式下的表结构
3. 口述：100 万行表 `LIMIT 1000000, 10` 为何慢，如何优化

## 延伸阅读

- [engineering/02-linux-and-shell/](../../../engineering/02-linux-and-shell/)
- [03 操作系统：进程与线程](../../../fundamentals/03-operating-systems/guides/01-process-and-thread.md)
- [04 网络：TCP 与 HTTP](../../../fundamentals/04-networking/guides/03-transport-layer-tcp-udp.md)
- [05 数据库：事务与 SQL](../../../fundamentals/05-databases/guides/03-transaction-and-concurrency.md)
- [01 数据结构](../../../fundamentals/01-data-structures/)
- [03 数据结构与算法（面试）](03-data-structures-and-algorithms.md)
