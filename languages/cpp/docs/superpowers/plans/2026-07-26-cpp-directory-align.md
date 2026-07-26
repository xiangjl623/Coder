# C++ Directory Alignment Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Align `languages/cpp` with `languages/c` single-entry layout: consolidate 15 guides into `学习指导/`, add pointer-only `学习手册/`, generate `题库/C++题库.md`, leave `guides/` as redirect only, and fix repo links.

**Architecture:** Assemble existing guide Markdown into one mastery file with a 14-day plan and `#guide-01`…`#guide-15` anchors; replace deep links; generate a 14-theme question bank mirroring the C bank format; keep `examples/`, `exams/`, `references/` unchanged in role.

**Tech Stack:** Markdown; PowerShell for assemble/verify; content from `guides/**`, `references/C++常用语法汇总.md`, `exams/`.

## Global Constraints

- Spec: `languages/cpp/docs/superpowers/specs/2026-07-26-cpp-directory-align-design.md`
- Approach 2: delete guide article files after assembly; `guides/README.md` redirect only
- Handbook: pointer only — no full-text duplicate
- Question bank: 14 themes from `references/README.md`; ~20–25 questions/chapter; 题目 → 答案 → 总结
- Do not delete `exams/` type-based bank
- Do not rewrite C module except fixing broken cross-links if any

---

## File Map

| File | Role |
|------|------|
| `languages/cpp/学习指导/C++从入门到精通.md` | Main tutorial + 14-day plan |
| `languages/cpp/学习手册/README.md` | Pointer to 学习指导 |
| `languages/cpp/题库/C++题库.md` | Chapter question bank |
| `languages/cpp/guides/README.md` | Redirect only |
| `languages/cpp/README.md` | Index like C |
| `languages/cpp/syllabus.md` | Point to 学习指导 |
| `languages/README.md` | C++ column links |
| `certifications/university/cpp-language/README.md` | Tutorial links |
| `engineering/02-linux-and-shell/guides/01-linux-basics.md` | Env setup link |

**Guide sources (assemble in order):**

1. `guides/01-getting-started/01-C++入门：从C到现代C++.md`
2. `guides/01-getting-started/02-C++开发环境搭建：从安装到Hello World.md`
3. `guides/01-getting-started/03-程序结构：头文件、命名空间与编译链接.md`
4. `guides/01-getting-started/04-数据类型、引用与auto.md`
5. `guides/02-core-syntax/05-运算符与表达式：C++扩展特性.md`
6. `guides/02-core-syntax/06-流程控制：让程序学会做选择.md`
7. `guides/02-core-syntax/07-循环结构：重复执行的艺术.md`
8. `guides/02-core-syntax/08-数组、string与容器初探.md`
9. `guides/02-core-syntax/09-函数：重载、默认参数与内联.md`
10. `guides/03-advanced/10-类与对象：面向对象基础.md`
11. `guides/03-advanced/11-继承、多态与虚函数.md`
12. `guides/03-advanced/12-模板与STL基础.md`
13. `guides/04-projects/13-智能指针与RAII.md`
14. `guides/04-projects/14-综合实战：面向对象学生管理系统.md`
15. `guides/04-projects/15-C++学习路线与资源推荐.md`

---

### Task 1: Assemble 学习指导

**Files:**
- Create: `languages/cpp/学习指导/C++从入门到精通.md`
- Read: 15 guide files listed above

**Interfaces:**
- Produces: single file with front matter, 14-day table linking `#guide-01`…`#guide-15`, then appendix sections each starting with HTML anchor

- [ ] **Step 1: Create directory and header + 14-day plan**

Write the beginning of `学习指导/C++从入门到精通.md` with:

```markdown
# C++从入门到精通

## 刚好遇见你

- **目标读者**：已掌握 C 基础、希望系统学习现代 C++ 的学习者
- **核心价值**：在 C 基础上掌握 OOP、STL、RAII 与常用现代特性
- **建议先修**：[C 语言模块](../c/)

> **学习建议**：先看当天知识点 → 跟做示例 → 独立练习 → 再对照答案/题库。

## 整体学习计划

### 第一周：从 C 到 C++ 核心语法

| 天数 | 主题 | 主要内容 | 参考教程 |
|------|------|----------|----------|
| Day 1 | 入门与环境 | C++ 定位、Hello World、工具链 | [01](#guide-01)、[02](#guide-02) |
| Day 2 | 程序结构 | 头文件、namespace、编译链接 | [03](#guide-03) |
| Day 3 | 类型与引用 | 引用、auto、iostream | [04](#guide-04) |
| Day 4 | 运算符 | C++ 扩展、new/delete 初识 | [05](#guide-05) |
| Day 5 | 流程控制 | if/switch 与 C++ 差异 | [06](#guide-06) |
| Day 6 | 循环 | 传统循环 + 范围 for | [07](#guide-07) |
| Day 7 | 数组/string/vector | string、vector 初探 | [08](#guide-08) |

### 第二周：函数、OOP、STL 与实战

| 天数 | 主题 | 主要内容 | 参考教程 |
|------|------|----------|----------|
| Day 8 | 函数 | 重载、默认参数、inline | [09](#guide-09) |
| Day 9 | 类与对象 | class、构造析构、封装 | [10](#guide-10) |
| Day 10 | 继承与多态 | virtual、override | [11](#guide-11) |
| Day 11 | 模板与 STL | 模板、vector/map/algorithm | [12](#guide-12) |
| Day 12 | 智能指针 | unique_ptr/shared_ptr、RAII | [13](#guide-13) |
| Day 13 | 综合实战 | 学生管理系统 | [14](#guide-14) |
| Day 14 | 路线回顾 | 进阶方向与资源 | [15](#guide-15) |

---

## 附录：专栏全文
```

- [ ] **Step 2: Append 15 guides with anchors**

For each guide `i` in 1..15, append:

```markdown
<a id="guide-0i"></a>
## Guide 0i · {title from H1 of source}

{body of source with leading H1 removed or demoted to avoid duplicate top-level title}
```

Use PowerShell to concatenate UTF-8 files in order; strip BOM; fix relative image links if any (prefix `../guides/...` only if assets remain — prefer copying assets into `学习指导/assets/` if referenced).

- [ ] **Step 3: Verify anchors**

```powershell
$c = [IO.File]::ReadAllText("languages/cpp/学习指导/C++从入门到精通.md")
1..15 | ForEach-Object { $id = "guide-{0:D2}" -f $_; if ($c -notmatch [regex]::Escape("id=`"$id`"") -and $c -notmatch "#$id") { "MISSING $id" } }
```

Expected: no MISSING lines (accept either `<a id="guide-NN">` or explicit heading anchors).

- [ ] **Step 4: Commit**

```bash
git add "languages/cpp/学习指导/C++从入门到精通.md"
git commit -m "Add consolidated C++ learning guide from 15 articles"
```

---

### Task 2: Handbook pointer + guides redirect + delete articles

**Files:**
- Create: `languages/cpp/学习手册/README.md`
- Create/Overwrite: `languages/cpp/guides/README.md`
- Delete: all 15 guide `.md` files under `guides/01-…`–`04-…` (and empty topic dirs if empty)

**Interfaces:**
- Consumes: Task 1 mastery file path
- Produces: pointer handbook; redirect-only guides

- [ ] **Step 1: Write 学习手册/README.md**

```markdown
# C++ 学习手册

正文已收敛到单一入口，请使用：

**[学习指导 · C++从入门到精通](../学习指导/C++从入门到精通.md)**

该文件包含 14 天学习计划与 15 篇专栏全文。日常语法速查见 [references/](../references/)。按章刷题见 [题库/C++题库.md](../题库/C++题库.md)。
```

- [ ] **Step 2: Write guides/README.md redirect**

```markdown
# Guides（已迁移）

原 15 篇专栏已整合到：

→ [学习指导/C++从入门到精通.md](../学习指导/C++从入门到精通.md)

请使用文内锚点 `#guide-01` … `#guide-15`。本目录不再保留分篇原文。
```

- [ ] **Step 3: Delete the 15 article files and empty subdirs**

```powershell
Remove-Item -Recurse -Force languages/cpp/guides/01-getting-started, languages/cpp/guides/02-core-syntax, languages/cpp/guides/03-advanced, languages/cpp/guides/04-projects
```

Confirm only `guides/README.md` remains.

- [ ] **Step 4: Commit**

```bash
git add -A languages/cpp/学习手册 languages/cpp/guides
git commit -m "Replace cpp guides with redirect; add handbook pointer"
```

---

### Task 3: Update README, syllabus, and repo links

**Files:**
- Modify: `languages/cpp/README.md`
- Modify: `languages/cpp/syllabus.md`
- Modify: `languages/README.md`
- Modify: `certifications/university/cpp-language/README.md`
- Modify: `engineering/02-linux-and-shell/guides/01-linux-basics.md`

**Interfaces:**
- Consumes: new paths from Tasks 1–2

- [ ] **Step 1: Rewrite cpp README content index**

Mirror C-style tables:

- 学习路径 → `学习指导/C++从入门到精通.md`
- 内容索引 rows: 学习指导、学习手册、references、examples、exercises、题库、exams、certifications
- 教程目录 links: `学习指导/C++从入门到精通.md#guide-01` … `#guide-15`

- [ ] **Step 2: Update syllabus.md**

Replace `guides/` locations with 学习指导 anchors; note guides redirected.

- [ ] **Step 3: Fix external links**

| File | Change |
|------|--------|
| `languages/README.md` | C++ guides cell → `cpp/学习指导/C++从入门到精通.md` |
| `certifications/.../cpp-language/README.md` | guides → 学习指导 |
| `engineering/.../01-linux-basics.md` | deep guide link → `languages/cpp/学习指导/C++从入门到精通.md#guide-02` |

- [ ] **Step 4: Repo-wide search**

```powershell
rg -n "cpp/guides/|languages/cpp/guides/" --glob "*.md"
```

Expected: only redirects/specs/history mentions, no live article paths.

- [ ] **Step 5: Commit**

```bash
git add languages/cpp/README.md languages/cpp/syllabus.md languages/README.md certifications/university/cpp-language/README.md engineering/02-linux-and-shell/guides/01-linux-basics.md
git commit -m "Point docs and indexes to cpp learning guide"
```

---

### Task 4: Generate C++ 题库 skeleton + chapters 1–7

**Files:**
- Create: `languages/cpp/题库/C++题库.md`

**Interfaces:**
- Themes 1–7 from references README
- Produces: header + chapters 1–7 fully filled (~20–25 Q each)

- [ ] **Step 1: Write file header, 使用说明, 目录**

Same pattern as `languages/c/题库/C语言题库.md`.

- [ ] **Step 2: Fill chapters 1–7**

Titles: 程序基础；数据类型与常量；运算符；流程控制；函数与重载；引用与指针；数组与 string.

Per chapter: 速览；题目（选择/填空/读程序/简答编程）；答案解析；总结.

- [ ] **Step 3: Verify**

```powershell
# chapters 1-7 present; no 待填充 in those sections; answers ~20-25 each
```

- [ ] **Step 4: Commit**

```bash
git add "languages/cpp/题库/C++题库.md"
git commit -m "Add C++ question bank chapters 1-7"
```

---

### Task 5: Generate 题库 chapters 8–14 + README 题库 entry

**Files:**
- Modify: `languages/cpp/题库/C++题库.md`
- Modify: `languages/cpp/README.md` (ensure 题库 row exists if not in Task 3)

**Interfaces:**
- Chapters 8–14: 类与对象；继承与多态；模板；STL 容器；STL 算法；文件流；智能指针与常用头文件

- [ ] **Step 1: Append/fill chapters 8–14 (~20–25 Q each)**

- [ ] **Step 2: Full-file verify**

```powershell
$c = [IO.File]::ReadAllText("languages/cpp/题库/C++题库.md")
"chapters=$(([regex]::Matches($c,'(?m)^## 第 \d+ 章')).Count)"
"pending=$(([regex]::Matches($c,'待填充')).Count)"
```

Expected: chapters=14, pending=0; total answers roughly 280–350.

- [ ] **Step 3: Commit**

```bash
git add "languages/cpp/题库/C++题库.md" "languages/cpp/README.md"
git commit -m "Complete C++ question bank chapters 8-14"
```

---

### Task 6: Acceptance checklist

**Files:**
- Modify only if fixes needed

- [ ] **Step 1: Run acceptance checks from spec**

1. `guides/` only `README.md`  
2. 学习指导 has 14-day plan + guide-01…15  
3. 学习手册 is pointer only  
4. 题库 14 chapters, Q then A  
5. README indexes 学习指导/手册/题库  
6. `rg "cpp/guides/0"` finds no article paths  

- [ ] **Step 2: Commit polish if any**

```bash
git commit -m "Polish cpp directory alignment after acceptance checks"
```

---

## Spec Coverage

| Spec item | Task |
|-----------|------|
| 学习指导汇编 | Task 1 |
| guides 删除+重定向 | Task 2 |
| 学习手册指针 | Task 2 |
| README/syllabus/链接 | Task 3 |
| 题库 14 章 | Task 4–5 |
| 验收 | Task 6 |

## Placeholder Scan

No TBD steps; commands and paths are explicit.
