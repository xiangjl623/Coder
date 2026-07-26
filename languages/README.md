# 编程语言

按语言组织的系统教程（学习手册）、速查表与按章题库。

## 语言选型指南

| 目标 | 推荐语言 | 入口 |
|------|----------|------|
| 理解底层、备考期末 | C | [c/](c/) |
| C 基础上进阶、OOP/STL | C++ | [cpp/](cpp/) |
| 快速上手、数据分析 | Python | 计划中 |
| Web 全栈 | TypeScript | [typescript/](typescript/) |
| Web 全栈（JS 基础） | JavaScript | 计划中 |
| 企业后端 | Java | 计划中 |
| 云原生 / 基础设施 | Go | 计划中 |

**建议路径**：C 语言打基础 → [C++](cpp/) 或任选一门高级语言深入 → 按岗位补专项语言。

## 已发布语言

| 语言 | 学习手册 | 速查 | 题库 |
|------|----------|------|------|
| C | [C语言从入门到精通](c/学习手册/C语言从入门到精通.md) | [references](c/references/) | [题库](c/题库/) |
| C++ | [C++从入门到精通](cpp/学习手册/C++从入门到精通.md) | [references](cpp/references/) | [题库](cpp/题库/) |
| TypeScript | [guides](typescript/guides/) | [references](typescript/references/) | 计划中 |

## 新增语言

复制 [\_template/](_template/) 目录，重命名为语言 slug 后开始编写。详见 [CONTRIBUTING.md](../CONTRIBUTING.md)。

## 目录结构（C / C++）

```
languages/<lang>/
├── README.md
├── syllabus.md
├── 学习手册/      # 系统教程与学习计划
├── references/    # 语法速查
└── 题库/          # 按章题库
```
