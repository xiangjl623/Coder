# C++ 目录优化整合设计

> 日期：2026-07-26  
> 状态：已确认待实现  
> 对齐对象：`languages/c/`（方案 2：彻底单入口）

## 目标

参考 `languages/c` 的目录与入口形态，对 `languages/cpp` 做一次完整整合：

1. 教程收敛为 `学习指导/` 单文件主入口  
2. `学习手册/` 仅作指针，不双份维护正文  
3. 新增按章 `题库/`  
4. 删除 `guides/` 原文，仅留重定向  
5. 更新 `README.md` / `syllabus.md` 及仓库内相关链接  

## 目标目录树

```text
languages/cpp/
  README.md
  syllabus.md
  学习指导/
    C++从入门到精通.md      # 14 天计划 + 附录 guide-01～15
    assets/                 # 按需
  学习手册/
    README.md               # 指向学习指导，不含全文副本
  题库/
    C++题库.md              # 14 主题，先题后答 + 知识点总结
  references/               # 保留
  examples/                 # 保留
  exercises/                # 保留
  exams/                    # 保留
  guides/
    README.md               # 仅重定向说明，无原文
```

## 学习指导

**路径：** `languages/cpp/学习指导/C++从入门到精通.md`

**结构（对齐 C 学习指导形态）：**

1. 前言 / 目标读者 / 学习建议（可强调先修 C）  
2. 14 天学习计划表（主题映射到 guide-01～15）  
3. 附录：15 篇专栏全文，锚点 `#guide-01` … `#guide-15`  

**内容来源：** 现有 `guides/01-getting-started/`～`guides/04-projects/` 共 15 篇 Markdown，按序号汇编；保留正文，统一标题层级以便锚点跳转。

**迁移后：** 删除上述 15 个 guide 文件；`guides/README.md` 写明「已迁至学习指导」并给出链接。

## 学习手册

**路径：** `languages/cpp/学习手册/README.md`

**约定（用户确认：指向、不双维护）：**

- 说明主文档位于 `学习指导/C++从入门到精通.md`  
- 提供目录链接与使用建议  
- **不**复制全文  

## 题库

**路径：** `languages/cpp/题库/C++题库.md`（单文件）

**章节：** 对齐 `references/README.md` 的 14 主题：

1. 程序基础  
2. 数据类型与常量  
3. 运算符  
4. 流程控制  
5. 函数与重载  
6. 引用与指针  
7. 数组与 string  
8. 类与对象  
9. 继承与多态  
10. 模板  
11. STL 容器  
12. STL 算法  
13. 文件流  
14. 智能指针与常用头文件  

**每章结构：**

```text
## 第 N 章 · 主题
### 本章知识点速览
### 一、题目
### 二、参考答案与解析
### 三、本章知识点总结
```

**题量：** 每章约 20～25 题，全书约 280～350 题。  
**题型：** 选择 / 填空 / 读程序写结果 / 简答或小编程。  
**取材：** `references/C++常用语法汇总.md`、`exams/`、学习指导附录（改编去重，不整卷照搬）。

## README / syllabus

- `README.md`：学习路径、内容索引（学习指导、手册、题库、references、examples、exercises、exams）、教程目录改为学习指导锚点链接。  
- `syllabus.md`：教程位置改为学习指导；注明 `guides/` 已收敛为重定向。  

## 链接迁移范围

至少更新以下位置中指向 `guides/...` 的链接（以仓库实际检索为准）：

- `languages/cpp/README.md`  
- `languages/cpp/syllabus.md`  
- `languages/cpp/exams/**`（若有）  
- `languages/cpp/references/**`（若有）  
- `certifications/university/cpp-language/**`（若有）  
- 其他仓库内引用 `languages/cpp/guides` 的文档  

## 非目标

- 不删除或重写 `exams/` 题型分册（与题库并存）  
- 不强制生成 PDF  
- 不改动 `languages/c/`（除必要时修正错误的交叉链接）  
- 不在本规格中扩展为 C++20 全特性教程重写  

## 实现顺序建议

1. 汇编 `学习指导/C++从入门到精通.md`（计划表 + 15 篇）  
2. 写 `学习手册/README.md`、`guides/README.md` 重定向；删除 guides 原文  
3. 更新 README、syllabus、全库 guides 链接  
4. 生成 `题库/C++题库.md`  
5. 通读检查：锚点、断链、题库章结构与题号  

## 验收标准

- [ ] `guides/` 下仅剩重定向 README，无 15 篇原文  
- [ ] 学习指导含 14 天计划与 `#guide-01`～`#guide-15`  
- [ ] 学习手册无全文副本，明确指向学习指导  
- [ ] 题库 14 章齐全，章内先题后答，每章约 20～25 题  
- [ ] README 内容索引与 C 模块同级清晰  
- [ ] 仓库内原 `cpp/guides/` 深链已更新或失效处已处理  
