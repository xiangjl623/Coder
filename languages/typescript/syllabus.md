### 专栏定位

- **目标读者**：有 JavaScript 基础或希望从事 Web/Node 开发的开发者
- **核心价值**：系统掌握 TypeScript 类型系统，能编写类型安全的浏览器与 Node.js 应用

> 本课程位于 monorepo 的 [languages/typescript/](README.md) 目录。教程见 `guides/`，速查见 `references/`，示例见 `examples/`。

## 文章主题规划（共 15 篇）

### 第一部分：入门基础（4 篇）

| 序号 | 主题 | 目录 | 核心内容 |
|------|------|------|----------|
| 1 | TypeScript 入门：JS 的超集与 Web 开发 | guides/01-getting-started/ | TS 历史、与 JS 关系、浏览器/Node 适用场景 |
| 2 | 开发环境搭建 | guides/01-getting-started/ | Node.js、npm、VS Code、tsc、ts-node、Vite 简介 |
| 3 | 程序结构：模块与编译流程 | guides/01-getting-started/ | ES Module、import/export、tsc 编译、.ts → .js |
| 4 | 基础类型与变量 | guides/01-getting-started/ | 类型注解、基本类型、any/unknown、类型推断 |

### 第二部分：核心语法（5 篇）

| 序号 | 主题 | 目录 | 核心内容 |
|------|------|------|----------|
| 5 | 运算符与表达式 | guides/02-core-syntax/ | JS 运算符 + TS 类型约束 |
| 6 | 流程控制 | guides/02-core-syntax/ | if/switch；类型收窄初识 |
| 7 | 循环与迭代 | guides/02-core-syntax/ | for/while/for...of；数组遍历 |
| 8 | 数组、元组与字符串 | guides/02-core-syntax/ | Array\<T\>、tuple、template literal types 初识 |
| 9 | 函数 | guides/02-core-syntax/ | 参数/返回值类型、可选/默认参数、箭头函数、函数类型 |

### 第三部分：进阶概念（3 篇）

| 序号 | 主题 | 目录 | 核心内容 |
|------|------|------|----------|
| 10 | 对象与接口 | guides/03-advanced/ | interface、type alias、可选属性、索引签名 |
| 11 | 类与继承 | guides/03-advanced/ | class、修饰符、implements、抽象类 |
| 12 | 泛型与工具类型 | guides/03-advanced/ | 泛型函数/类、Partial/Pick/Omit、keyof |

### 第四部分：实战与应用（3 篇）

| 序号 | 主题 | 目录 | 核心内容 |
|------|------|------|----------|
| 13 | 异步编程 | guides/04-projects/ | Promise、async/await、fetch API |
| 14 | 综合实战：Todo 全栈小项目 | guides/04-projects/ | 前端 TS + 简单 API（或 CLI Todo） |
| 15 | 学习路线与资源推荐 | guides/04-projects/ | TS Handbook、DefinitelyTyped、进阶方向 |

## 格式规范

详见仓库 [CONTRIBUTING.md](../../CONTRIBUTING.md)。

## 专栏特色

1. **Web 路径**：聚焦浏览器与 Node.js 场景，简要回顾 JS 核心
2. **类型安全**：从基础类型到泛型与工具类型的完整路径
3. **原理 + 实战**：每篇包含可运行 `.ts` 示例
4. **互动性**：每篇结尾设置练习题（后续补充）

## 发布节奏

| 阶段 | 内容 | 状态 |
|------|------|------|
| 第一阶段 | 目录骨架 + README/syllabus | 进行中 |
| 第二阶段 | 入门 4 篇 + 速查前 4 主题 + 示例 chapter01～04 | 计划中 |
| 第三阶段 | 05～15 篇 + 完整速查/示例 | 计划中 |
| 第四阶段 | 考试题库 + certifications 专题（可选） | 计划中 |
