# C 语言题库 Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 基于 `languages/c/references/` 生成单文件按章编排的 C 语言题库（先题后答 + 知识点总结）。

**Architecture:** 一个 Markdown 文件 `languages/c/题库/C语言题库.md`，按 references 14 主题分章；每章内「知识点速览 → 题目 → 参考答案与解析 → 知识点总结」。题目改编自语法汇总、真题与常考编程题，不整卷照搬 `exams/`。

**Tech Stack:** Markdown；素材来自 `references/C语言常用语法汇总.md`、期末真题、`编程题目-常考10题.md`；可选更新 `languages/c/README.md` 索引。

## Global Constraints

- 输出路径固定：`languages/c/题库/C语言题库.md`（单文件）
- 章节顺序与命名对齐 references 14 主题（见规格）
- 每章 15～20 题；全书约 210～280 题
- 章内结构必须为：速览 → 一、题目 → 二、参考答案与解析 → 三、本章知识点总结
- 答案需含简短解析；总结提炼口诀/对照表，不整段复制速查
- 不删除、不替换现有 `exams/`
- 代码题结果可验证；涉及 `sizeof` 等平台相关处注明「常见 64 位」

---

## File Map

| 文件 | 职责 |
|------|------|
| `languages/c/题库/C语言题库.md` | 题库正文（唯一交付物） |
| `languages/c/README.md` | 内容索引增加「题库」入口 |
| `languages/c/docs/superpowers/specs/2026-07-26-c-question-bank-design.md` | 规格（只读） |

**取材优先阅读：**

1. `languages/c/references/C语言常用语法汇总.md`
2. `languages/c/references/编程题目-常考10题.md`
3. `languages/c/references/期末考试题目1.md` / `题目2.md` / `题目3.md` / `考试真题/`
4. `languages/c/exams/` 各题型文件（改写去重）

---

### Task 1: 创建题库骨架与 README 入口

**Files:**
- Create: `languages/c/题库/C语言题库.md`
- Modify: `languages/c/README.md`（内容索引表增加一行）

**Interfaces:**
- Produces: 带目录锚点的 14 章空壳，后续 Task 只填充对应 `## 第 N 章` 区块

- [ ] **Step 1: 创建目录与题库文件骨架**

写入 `languages/c/题库/C语言题库.md`，内容须包含：

```markdown
# C 语言题库

> 按 `references/` 14 个主题分章；每章先题目、后参考答案与知识点总结。  
> 取材自语法汇总、期末真题与常考编程题，适合系统复习。

## 使用说明

1. 建议按章顺序练习；也可按薄弱主题跳章。
2. 先独立完成「一、题目」，再对照「二、参考答案与解析」。
3. 「三、本章知识点总结」用于考前速记，勿跳过。
4. 读程序题默认在常见 64 位 GCC/MSVC 环境下验证；`sizeof` 等若有差异已在答案中注明。

## 目录

1. [程序基础](#第-1-章--程序基础)
2. [数据类型与常量](#第-2-章--数据类型与常量)
3. [运算符](#第-3-章--运算符)
4. [流程控制](#第-4-章--流程控制)
5. [函数](#第-5-章--函数)
6. [指针](#第-6-章--指针)
7. [数组](#第-7-章--数组)
8. [字符串](#第-8-章--字符串)
9. [结构体与枚举](#第-9-章--结构体与枚举)
10. [预处理](#第-10-章--预处理)
11. [输入输出](#第-11-章--输入输出)
12. [文件操作](#第-12-章--文件操作)
13. [动态内存](#第-13-章--动态内存)
14. [常用库函数](#第-14-章--常用库函数)

## 第 1 章 · 程序基础
### 本章知识点速览
（待填充）
### 一、题目
（待填充）
### 二、参考答案与解析
（待填充）
### 三、本章知识点总结
（待填充）
```

其余第 2～14 章使用相同四级标题模板，章名如下：

2 数据类型与常量 · 3 运算符 · 4 流程控制 · 5 函数 · 6 指针 · 7 数组 · 8 字符串 · 9 结构体与枚举 · 10 预处理 · 11 输入输出 · 12 文件操作 · 13 动态内存 · 14 常用库函数

- [ ] **Step 2: 更新 README 索引**

在 `languages/c/README.md` 的「内容索引」表格中，在「期末考试」一行附近增加：

| 按章题库 | [题库/C语言题库.md](题库/C语言题库.md) | 14 主题：先题后答 + 知识点总结 |

- [ ] **Step 3: 自检骨架**

确认文件存在、14 个 `## 第 N 章` 标题齐全、目录链接锚点与标题一致。

- [ ] **Step 4: Commit**

```bash
git add "languages/c/题库/C语言题库.md" "languages/c/README.md"
git commit -m "Add C question bank skeleton and README link"
```

---

### Task 2: 填充第 1～4 章（程序基础～流程控制）

**Files:**
- Modify: `languages/c/题库/C语言题库.md`（第 1～4 章）

**Interfaces:**
- Consumes: Task 1 章模板
- Produces: 完整第 1～4 章内容

**每章题型配额（合计 16～18 题）：**

| 题型 | 题数 | 编号建议 |
|------|------|----------|
| 选择题 | 7 | 1～7 |
| 填空题 | 4 | 8～11 |
| 读程序写结果 | 3 | 12～14 |
| 简答/小编程 | 2 | 15～16 |

**考点侧重：**

- 第 1 章：编译流程、`main`、标识符、关键字、注释、源文件/头文件
- 第 2 章：基本类型、`sizeof`、常量进制、`signed/unsigned`、初始化
- 第 3 章：算术/关系/逻辑/位运算、自增、优先级、类型转换
- 第 4 章：`if/switch`、`for/while/do-while`、`break/continue`、三目

- [ ] **Step 1: 阅读素材对应章节**

阅读 `C语言常用语法汇总.md` 中「# 1 程序基础」「# 2 数据类型」「运算符」「流程控制」相关节，摘录易错点列表（不必提交）。

- [ ] **Step 2: 写入第 1～4 章完整内容**

替换各章「（待填充）」为正式内容。题目区用：

```markdown
#### 选择题
1. ...
#### 填空题
8. ...
#### 读程序写结果
12. ...
#### 简答或编程
15. ...
```

答案区题号一一对应，格式：

```markdown
1. **答案：B**  
   解析：……
```

知识点总结用简洁表格或条目（5～10 条），例如编译四阶段、类型与格式符对照。

- [ ] **Step 3: 自检**

- 每章题数 ∈ [15, 20]
- 答案题号与题目一一对应
- 无残留「（待填充）」于第 1～4 章

- [ ] **Step 4: Commit**

```bash
git add "languages/c/题库/C语言题库.md"
git commit -m "Fill question bank chapters 1-4"
```

---

### Task 3: 填充第 5～8 章（函数～字符串）

**Files:**
- Modify: `languages/c/题库/C语言题库.md`（第 5～8 章）

**Interfaces:**
- Consumes: 同 Task 2 题型结构
- Produces: 完整第 5～8 章

**配额微调（每章 17～20 题）：** 选择题 6～7、填空 3～4、读程序 4、简答/编程 3（指针/数组/字符串加重读程序与编程）。

**考点侧重：**

- 第 5 章：定义与声明、值传递、递归、`static`、返回值；可改编常考题中的素数/斐波那契为函数题
- 第 6 章：`*`/`&`、指针运算、指针与数组、空指针、常见错误
- 第 7 章：一维/二维、初始化、越界、排序查找；可改编「数组最大值」
- 第 8 章：字符数组与 `'\0'`、`strlen/strcpy/strcmp/strcat`、常见陷阱

- [ ] **Step 1: 阅读素材**

阅读汇总中函数/指针/数组/字符串节，以及 `编程题目-常考10题.md` 中可归入本批的题目（改编后写入，注明思路即可）。

- [ ] **Step 2: 写入第 5～8 章完整内容**

格式约束同 Task 2 Step 2。

- [ ] **Step 3: 自检**

同 Task 2 Step 3，范围改为第 5～8 章；抽查 2 道读程序题手算结果。

- [ ] **Step 4: Commit**

```bash
git add "languages/c/题库/C语言题库.md"
git commit -m "Fill question bank chapters 5-8"
```

---

### Task 4: 填充第 9～11 章（结构体～输入输出）

**Files:**
- Modify: `languages/c/题库/C语言题库.md`（第 9～11 章）

**Interfaces:**
- Produces: 完整第 9～11 章

**配额：** 每章 15～18 题（选择 7、填空 4、读程序 3、简答/编程 2～3）。

**考点侧重：**

- 第 9 章：`struct` 定义与访问、`.`/`->`、`typedef`、`union`、`enum`、链表节点示意
- 第 10 章：`#include`、`#define` 宏与副作用、条件编译、头文件守卫
- 第 11 章：`printf/scanf` 格式符、返回值、缓冲区、`getchar/putchar`

- [ ] **Step 1: 阅读素材并写入第 9～11 章**

- [ ] **Step 2: 自检题号、答案对应、无「待填充」**

- [ ] **Step 3: Commit**

```bash
git add "languages/c/题库/C语言题库.md"
git commit -m "Fill question bank chapters 9-11"
```

---

### Task 5: 填充第 12～14 章（文件～库函数）

**Files:**
- Modify: `languages/c/题库/C语言题库.md`（第 12～14 章）

**Interfaces:**
- Produces: 完整第 12～14 章；全书内容完成

**配额：** 每章 15～18 题；第 12、13 章编程题可各 3 题。

**考点侧重：**

- 第 12 章：`fopen` 模式、`fgetc/fgets/fprintf/fwrite`、`fclose`、文本 vs 二进制
- 第 13 章：`malloc/calloc/realloc/free`、空指针检查、内存泄漏、野指针
- 第 14 章：`string.h`/`stdlib.h`/`math.h`/`ctype.h` 常用函数签名与返回值

- [ ] **Step 1: 阅读素材并写入第 12～14 章**

- [ ] **Step 2: 全书搜索确认无「（待填充）」残留**

- [ ] **Step 3: Commit**

```bash
git add "languages/c/题库/C语言题库.md"
git commit -m "Fill question bank chapters 12-14"
```

---

### Task 6: 全书质量核对

**Files:**
- Modify: `languages/c/题库/C语言题库.md`（仅修错，不扩 scope）

**Interfaces:**
- Consumes: 完整 14 章
- Produces: 通过核对清单的定稿

- [ ] **Step 1: 数量与结构核对**

在仓库根目录执行（PowerShell）：

```powershell
Select-String -Path "languages/c/题库/C语言题库.md" -Pattern "^## 第 \d+ 章" | Measure-Object
Select-String -Path "languages/c/题库/C语言题库.md" -Pattern "待填充" 
```

期望：章标题计数为 14；「待填充」无匹配。

- [ ] **Step 2: 人工抽查清单**

对下列项逐条确认并修正：

1. 每章均有速览 / 一、题目 / 二、参考答案与解析 / 三、本章知识点总结
2. 抽样 6 道读程序题（第 3、4、6、7、8、13 章各一）手算与答案一致
3. 目录 14 个链接能对上标题
4. 编程题要求明确（输入/输出或函数原型）

- [ ] **Step 3: 统计题量写入使用说明（可选一行）**

若方便，在「使用说明」末尾加一句：`全书约 N 题，分 14 章。`（N 为实际统计值）

- [ ] **Step 4: Commit（若有修改）**

```bash
git add "languages/c/题库/C语言题库.md"
git commit -m "Polish C question bank after full review"
```

---

## Spec Coverage Check

| 规格要求 | 对应 Task |
|----------|-----------|
| 单文件 `题库/C语言题库.md` | Task 1 |
| 14 主题分章 | Task 1～5 |
| 章内先题后答 + 总结 | Task 2～5 |
| 每章 15～20 题 | Task 2～5 配额 + Task 6 |
| 取材 references / 真题 / exams 改编 | Task 2～5 Step 1 |
| README 入口 | Task 1 |
| 不改动 exams 删除 | 全任务不触碰删除 |

## Placeholder Scan

计划中无 TBD/TODO；验证步骤为可执行命令与明确期望。
