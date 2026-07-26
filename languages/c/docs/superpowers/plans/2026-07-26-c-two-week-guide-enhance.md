# C语言两周学习指导增强 Implementation Plan

> **For agentic workers:** 按任务顺序修改同一 Markdown 文件；每任务完成后自检对应章节标题与清单项。

**Goal:** 将 `大一新生/C语言两周学习指导.md` 改为以 Dev-C++ 为主环境，并按档位 A 适度加深知识点与练习。

**Architecture:** 单文件原地改写；Day 1 整章替换；Day 2–14 在保留基础内容上增「进阶/易错」与「挑战题」；同步总表与学习建议。

**Tech Stack:** Markdown 教学文档；Embarcadero Dev-C++（Windows）

## Global Constraints

- 难度档位 A：适度加深，不增天数，不加文件 I/O/多文件为主线
- 主推 Dev-C++，不再以 VS Code + MinGW 为默认
- 修改文件：`大一新生/C语言两周学习指导.md`
- 不主动 git commit（除非用户另行要求）

---

### Task 1: Day 1 + 总表 + 学习建议

**Files:**
- Modify: `大一新生/C语言两周学习指导.md`（开篇总表、Day 1 全章、文末学习建议）

- [x] 总表 Day 1 改为 Dev-C++ 安装与操作
- [x] Day 1 写入：为何用 Dev-C++、安装步骤、操作步骤、调试、常见问题、编译链接、作业与挑战题
- [x] 学习建议中调试改为 Dev-C++，去掉 VS Code/GDB 主推表述

### Task 2: Day 2–7 加深

**Files:**
- Modify: 同一文件 Day 2–7 各节

- [x] 每天增加进阶/易错小节 + 挑战题（按设计清单）

### Task 3: Day 8–14 加深

**Files:**
- Modify: 同一文件 Day 8–14 各节

- [x] 每天增加进阶/易错小节 + 挑战题；Day 14 三项目各加加分项

### Task 4: 全文验收

- [x] 检索确认不再默认主推 VS Code/MinGW 配置流程
- [x] 确认 14 天均有挑战题或加分项
- [x] 确认 Day 1 含安装与操作步骤
