# 关系模型与 SQL 基础

> **难度**：入门 | **阅读时间**：约 25 分钟 | **前置**：无 | **标签**：`sql` `relational`

## 学习目标

- [ ] 理解表、主键、外键
- [ ] 会写 SELECT / JOIN / GROUP BY 基础语句
- [ ] 知道三范式的设计意图

## 关系模型

数据组织为 **二维表**（关系）：

| 列 | 说明 |
|----|------|
| 行 | 一条记录 |
| 主键 PK | 唯一标识一行 |
| 外键 FK | 引用另一表主键 |

**示例**：

```sql
-- 学生表
CREATE TABLE students (
  id INT PRIMARY KEY,
  name VARCHAR(64) NOT NULL
);

-- 成绩表
CREATE TABLE scores (
  student_id INT,
  course   VARCHAR(32),
  score    INT,
  PRIMARY KEY (student_id, course),
  FOREIGN KEY (student_id) REFERENCES students(id)
);
```

## 三范式（口述）

1. **1NF**：字段原子，无重复列组
2. **2NF**：非主键字段完全依赖主键（消除部分依赖）
3. **3NF**：非主键字段不传递依赖其他非主键字段

**反例**：学生表存 `dept_name`，院系改名需改多行 → 应拆院系表。

## SQL 基础

```sql
-- 查询
SELECT name, score FROM scores WHERE score >= 60;

-- 排序
SELECT * FROM scores ORDER BY score DESC;

-- 聚合
SELECT course, AVG(score) FROM scores GROUP BY course;

-- 过滤聚合
SELECT student_id FROM scores GROUP BY student_id HAVING MIN(score) > 80;
```

## JOIN

```sql
-- 内连接：两表都匹配才出现
SELECT s.name, sc.score
FROM students s
INNER JOIN scores sc ON s.id = sc.student_id;

-- 左连接：保留左表全部
SELECT s.name, sc.score
FROM students s
LEFT JOIN scores sc ON s.id = sc.student_id;
```

**场景**（经典面试）：工资高于本部门平均工资的员工 — 自连接 + 子查询，见 [career/interview](../../../career/interview/guides/02-cs-fundamentals.md)。

## CRUD

```sql
INSERT INTO students (id, name) VALUES (1, 'Alice');
UPDATE students SET name = 'Bob' WHERE id = 1;
DELETE FROM students WHERE id = 1;
```

## 本节小结

- 表 + 主外键建模实体关系
- SELECT / JOIN / GROUP BY / HAVING 为查询核心
- 范式减少冗余与更新异常

## 练习

1. 设计「博客文章 + 评论」三范式表结构
2. 写出每门课都大于 80 分的学生 id（GROUP BY + HAVING）

## 延伸阅读

- [索引与查询优化](02-index-and-query-optimization.md)
- [sql-cheatsheet.md](../references/sql-cheatsheet.md)
