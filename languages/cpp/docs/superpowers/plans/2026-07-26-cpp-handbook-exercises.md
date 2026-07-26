# C++ 学习手册例题作业答案增强 Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 在 `languages/cpp/学习手册/C++从入门到精通.md` 的 Guide 1～15 中补齐「知识点实战例题 → 作业练习（含挑战）→ 参考答案（含解析）」，对齐 C 语言手册练习闭环。

**Architecture:** 只改汇总手册单文件。各 Guide 将原「实战练习」整块替换为三节（例题 / 作业 / 参考答案），作业优先复用现有题干并细化；Guide 14～15 从简。前言学习建议同步更新。不改 `guides/**`、题库、PDF。

**Tech Stack:** Markdown；示例代码 C++17（`iostream` / STL / RAII）；校验用 `rg` 统计标题。

**Spec:** `languages/cpp/docs/superpowers/specs/2026-07-26-cpp-handbook-exercises-design.md`

## Global Constraints

- 仅修改：`languages/cpp/学习手册/C++从入门到精通.md`（允许新建/更新本 plan 旁的校验备注，但交付物是手册）
- 标准与风格：`-std=c++17`；优先现代 C++；答案含「思路/解析」+ 代码（纯思考题可用参考表述）
- 题量：Guide 1～13 → 2 例题 + 3 作业 + 1 挑战；Guide 14～15 → 1 例题 + 2 作业 + 1 挑战
- 章节编号：只顺延练习区及之后「总结与延伸」编号，不重排知识小节
- **不要 git commit**，除非用户明确要求
- 不要改 `guides/**`、`题库/`、PDF

---

## File Map

| 文件 | 职责 |
|------|------|
| `languages/cpp/学习手册/C++从入门到精通.md` | 唯一内容交付物 |
| `languages/cpp/docs/superpowers/specs/2026-07-26-cpp-handbook-exercises-design.md` | 已批准规格（只读） |
| `languages/cpp/docs/superpowers/plans/2026-07-26-cpp-handbook-exercises.md` | 本计划 |

## Canonical Block Template

每个 Guide 练习区必须符合下列形态（`N` 为该 Guide 练习区起始小节号）：

```markdown
### N、知识点实战例题

**例题1：标题**

**题目**：……

**解题思路**：
1. …
2. …

**完整代码**：

```cpp
#include <iostream>
// …
```

**要点/易错**：
- …

**例题2：标题**
（同上四段结构）

### N+1、作业练习

> 先独立完成，做完再到本节文末「参考答案」对照。

**练习1**：……（可含要点列表）

**练习2**：……

**练习3**：……

**挑战题**：……

### N+2、参考答案

**练习1 参考答案**

思路/解析：……

```cpp
// …
```

**练习2 参考答案**
（同上）

**练习3 参考答案**
（同上）

**挑战题参考答案**

思路/解析：……

```cpp
// 或纯文字参考表述
```
```

然后接原「总结与延伸」（标题编号 +3，例如原「六」变「九」若中间插入三节）。

---

### Task 1: 前言学习建议

**Files:**
- Modify: `languages/cpp/学习手册/C++从入门到精通.md`（文首「刚好遇见你」与学习建议，约 L1～L10）

**Interfaces:**
- Consumes: 无
- Produces: 统一学习闭环文案，供后续各 Guide 作业区引导语呼应

- [ ] **Step 1: 更新文首**

将学习建议与目标说明改为（可微调措辞，须保留闭环语义与题库链接）：

```markdown
## 刚好遇见你

- **目标读者**：已掌握 C 基础、希望系统学习现代 C++ 的学习者
- **核心价值**：在 C 基础上掌握 OOP、STL、RAII 与常用现代特性
- **建议先修**：[C 语言模块](../c/)

这份学习计划按天组织：每天包含**知识点讲解**、**知识点实战例题（含解题思路）**、**作业练习**（含挑战题）；每天文末提供**参考答案**，建议先独立完成再对照。

> **学习建议**：先看当天知识点 → 跟做「知识点实战例题」→ 独立完成作业与挑战 → 对照本节「参考答案」→ 需要更多题再做 [题库](../题库/C++题库.md)。
```

- [ ] **Step 2: 校验前言**

Run:

```bash
rg -n "知识点实战例题|参考答案|题库" "languages/cpp/学习手册/C++从入门到精通.md" | head -20
```

Expected: 文首附近出现「知识点实战例题」「参考答案」与题库链接。

- [ ] **Step 3: 不提交**

不要 `git commit`。

---

### Task 2: Guide 01～04 练习区

**Files:**
- Modify: `languages/cpp/学习手册/C++从入门到精通.md` 中 `#guide-01`～`#guide-04` 的「实战练习」至「总结与延伸」之间

**Interfaces:**
- Consumes: Task 1 闭环文案；Canonical Block Template
- Produces: Guide 01～04 完整例题/作业/答案

**定位锚点：** 各 Guide 内搜索 `### .*实战练习`，替换直到下一个 `### .*总结与延伸`（不含总结正文，但总结标题编号 +3）。

#### Guide 01 命题清单（N=五）

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 最小 Hello | 输出两行欢迎语；`g++ -std=c++17` |
| 例题2 | 编译命令对比 | 说明 `.c`/`gcc` 与 `.cpp`/`g++` 差异（可配最小代码） |
| 练习1 | 编译运行 Hello C++ | 沿用现有：创建/编译/运行 |
| 练习2 | 对比 C 与 C++ 输出 | 沿用：`hello.c` + `hello.cpp` |
| 练习3 | 简答 | `.cpp` 扩展名原因；`<<` 是流插入运算符 |
| 挑战题 | 名片输出 | 用 `cout` 打出带边框的个人信息 5 行 |

答案：练习1～2 给完整代码；练习3 给参考表述；挑战题给边框代码。

#### Guide 02 命题清单（原「七、实战练习」→ 七/八/九）

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | VS Code / 命令行编译 | 给出一条完整 `g++ -std=c++17 -Wall …` 命令并解释参数 |
| 例题2 | 两数之和 iostream | `cin` 读两 int，`cout` 输出和 |
| 练习1 | 配置编译任务 | 沿用：tasks.json / Ctrl+Shift+B |
| 练习2 | 输出个人信息 | 沿用现有样例意图，要求学习者自写 |
| 练习3 | 两数之和 | 沿用 |
| 挑战题 | 三数平均 | 读三个 double，输出平均值（保留 2 位小数可用 `fixed`/`setprecision`） |

#### Guide 03 命题清单（原「六」）

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 命名空间隔离 | 两个 namespace 同名函数，用限定名调用 |
| 例题2 | 头文件声明 | `.h` 声明 + `.cpp` 定义 + main 调用的最小多文件示意 |
| 练习1 | 多文件编译 | 沿用并写清 `g++ a.cpp b.cpp -o app` |
| 练习2 | 命名空间实验 | 沿用 |
| 练习3 | 观察预处理 | `-E` 或说明 include 展开 |
| 挑战题 | 匿名命名空间 | 演示翻译单元内隐藏符号（简短可运行例） |

#### Guide 04 命题清单（原「七」）

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 引用交换 | `void swap(int& a, int& b)` |
| 例题2 | auto 与 iostream | `auto x = 1.5;` 与四则运算小计算器骨架 |
| 练习1 | 引用交换 | 沿用 |
| 练习2 | auto 推导 | 沿用 |
| 练习3 | iostream 计算器 | 沿用 |
| 挑战题 | 引用与指针对比 | 同一交换功能写引用版与指针版并简述差异 |

- [ ] **Step 1: 写入 Guide 01 完整三节**（按 Canonical Template，含全部答案代码）
- [ ] **Step 2: 写入 Guide 02 完整三节**
- [ ] **Step 3: 写入 Guide 03 完整三节**
- [ ] **Step 4: 写入 Guide 04 完整三节**
- [ ] **Step 5: 校验**

Run:

```bash
rg -n "知识点实战例题|作业练习|参考答案" "languages/cpp/学习手册/C++从入门到精通.md"
```

Expected: Guide 01～04 区域内各至少出现一次上述三类标题；不再残留这四节的「### …实战练习」作为练习区标题。

- [ ] **Step 6: 不提交**

---

### Task 3: Guide 05～08 练习区

**Files:**
- Modify: 同上手册文件，`#guide-05`～`#guide-08`

**Interfaces:**
- Consumes: Canonical Template；各节现有练习题干
- Produces: Guide 05～08 完整练习闭环

#### Guide 05

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | new/delete 单个 int | `new int(42)` / `delete` |
| 例题2 | nullptr 判断 | 指针为空则提示，否则解引用输出 |
| 练习1 | new/delete | 沿用（建议扩到数组 `new int[n]` / `delete[]`） |
| 练习2 | nullptr 与指针 | 沿用 |
| 练习3 | 类型转换 | `static_cast` 示例 |
| 挑战题 | 泄漏对比说明 | 写一段会泄漏的代码 + RAII/`unique_ptr` 修正版（可提前引用后续章概念作简述） |

#### Guide 06

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | if-else 成绩等级 | 分数→等级 |
| 例题2 | enum class 菜单 | 枚举选项 + switch |
| 练习1～3 | 成绩等级 / enum class 菜单 / 三目 | 沿用细化 |
| 挑战题 | 综合：简易 ATM 菜单 | enum class + do-while + switch |

#### Guide 07

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 范围 for 求和 | `vector` 或数组 |
| 例题2 | 引用修改元素 | `for (auto& x : v) x *= 2;` |
| 练习1～3 | 求和 / 修改元素 / 嵌套循环 | 沿用 |
| 挑战题 | 打印乘法表 | 嵌套循环 1～9 |

#### Guide 08

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | string 拼接与查找 | `+` / `find` / `substr` |
| 例题2 | vector 动态添加 | `push_back` 后遍历 |
| 练习1～3 | string / vector / 找最大值 | 沿用 |
| 挑战题 | 统计字符串元音字母个数 | 仅 aeiouAEIOU |

- [ ] **Step 1～4:** 分别写入 Guide 05、06、07、08 完整三节
- [ ] **Step 5: 校验** — `rg -n "知识点实战例题"` 计数应 ≥ 8（含 01～08）
- [ ] **Step 6: 不提交**

---

### Task 4: Guide 09～12 练习区

**Files:**
- Modify: `#guide-09`～`#guide-12`

#### Guide 09

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 函数重载 print | `int` / `double` / `string` |
| 例题2 | 默认参数 | 带默认宽高的矩形面积 |
| 练习1～3 | 重载 / 默认参数 / 函数模板 | 沿用 |
| 挑战题 | 模板 + 重载共存说明 | 实现 `max` 模板，并说明与重载如何选择 |

#### Guide 10

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | Circle 类 | 半径、面积、周长 |
| 例题2 | 构造与封装 | private 成员 + getter/setter |
| 练习1～3 | Circle / 封装 / 链式调用 | 沿用 |
| 挑战题 | 计数器类 | 构造时归零，`inc()` 返回 `*this` 支持链式 |

#### Guide 11

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 继承 | Animal / Dog |
| 例题2 | 虚函数 | 基类指针调用 `speak` |
| 练习1～3 | 继承层次 / 虚函数多态 / 抽象类 | 沿用 |
| 挑战题 | 纯虚 Shape | `area()` 纯虚，Circle/Rectangle 实现 |

#### Guide 12

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 函数模板 swap | |
| 例题2 | map 计数 | 单词→次数（可写死输入） |
| 练习1～3 | 模板栈 / map 词频 / algorithm | 沿用 |
| 挑战题 | sort + unique 去重 | vector 排序后去重 |

- [ ] **Step 1～4:** 写入 Guide 09～12
- [ ] **Step 5: 校验** — 手册中 `### .*知识点实战例题` 应 ≥ 12
- [ ] **Step 6: 不提交**

---

### Task 5: Guide 13～15 练习区

**Files:**
- Modify: `#guide-13`～`#guide-15`

#### Guide 13（完整题量）

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | unique_ptr 管理 int | `make_unique` |
| 例题2 | shared_ptr use_count | 拷贝后计数 |
| 练习1～3 | unique_ptr 数组 / shared_ptr 共享 / RAII 文件类 | 沿用细化 |
| 挑战题 | 工厂返回 unique_ptr | 函数返回 `unique_ptr<T>` |

#### Guide 14（从简：1+2+1）

在「扩展建议」与「总结与延伸」之间**新增**练习三节（或把「五、扩展建议」后插入），编号理顺：

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 按学号查找 | 在现有 `StudentManager` 思路上写 `findById` 调用示例 |
| 练习1 | 按姓名查询 | 增加 `findByName`（精确匹配即可） |
| 练习2 | 学生人数统计 | `size()` 或自写计数并在菜单显示 |
| 挑战题 | 学号唯一性 | `addStudent` 时若学号已存在则拒绝并提示 |

总结标题顺延。

#### Guide 15（从简：1+2+1）

在「六、总结」之前插入练习区：

| 类型 | 标题 | 要求 |
|------|------|------|
| 例题1 | 现代特性小 demo | 一段同时用 `auto`、范围 for、`vector` 的短程序 |
| 练习1 | 下周学习清单 | 写出 5 条可执行的学习计划（文字答案） |
| 练习2 | 对照 cppreference | 查阅 `std::vector::push_back` 并写 3 条笔记（文字） |
| 挑战题 | 避免 C 风格 | 把一段 C 风格数组求和改写成 `vector`+范围 for |

- [ ] **Step 1:** 写入 Guide 13
- [ ] **Step 2:** 写入 Guide 14（从简）
- [ ] **Step 3:** 写入 Guide 15（从简）
- [ ] **Step 4: 全量结构校验**

Run:

```bash
rg -c "知识点实战例题" "languages/cpp/学习手册/C++从入门到精通.md"
rg -c "作业练习" "languages/cpp/学习手册/C++从入门到精通.md"
rg -c "参考答案" "languages/cpp/学习手册/C++从入门到精通.md"
rg -n "### .*实战练习" "languages/cpp/学习手册/C++从入门到精通.md"
```

Expected:
- `知识点实战例题` ≥ 15
- `作业练习` ≥ 15
- `参考答案` ≥ 15（文首提及可不计在 `###` 级；`###` 级参考答案应为 15）
- `### .*实战练习` 应为 **0**（旧标题已全部替换）

- [ ] **Step 5: 代码围栏抽查**

Run（PowerShell 示例）：

```powershell
$c = Get-Content -Raw "languages/cpp/学习手册/C++从入门到精通.md"
$opens = ([regex]::Matches($c, '(?m)^```')).Count
Write-Output "fence_lines=$opens"
if ($opens % 2 -ne 0) { Write-Error "Unbalanced fences" }
```

Expected: `fence_lines` 为偶数。

- [ ] **Step 6: 不提交**

---

### Task 6: 验收对照规格

**Files:**
- Read-only: spec + 手册

- [ ] **Step 1: 对照规格验收清单**

逐项确认 `2026-07-26-cpp-handbook-exercises-design.md` 中「验收标准」全部满足。

- [ ] **Step 2: 抽查 Guide 01、08、14 各一节**

人工确认：例题含解题思路与要点；作业有引导语；答案含解析；Guide 14 为从简题量。

- [ ] **Step 3: 向用户汇报**

报告：已改文件路径、各 Guide 已完成、`rg` 计数结果、未改动的文件列表。

---

## Self-Review (Plan vs Spec)

| Spec 要求 | 对应 Task |
|-----------|-----------|
| 前言学习建议 | Task 1 |
| Guide 1～13 完整题量 | Task 2～5（13 在 Task 5） |
| Guide 14～15 从简 | Task 5 |
| 仅改汇总手册 | Global Constraints |
| 不改 guides/题库/PDF | Global Constraints |
| 答案含解析 | Canonical Template + 各命题清单 |
| 验收标准 | Task 6 |

无 TBD/TODO 占位。提交步骤已按用户规则改为「不提交」。
