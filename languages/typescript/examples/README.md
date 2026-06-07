# TypeScript 代码示例

按教程章节分目录存放，与 [guides/](../guides/) 一一对应。

## 目录结构

| 目录 | 对应教程 | 状态 |
|------|----------|------|
| chapter01/ | 01 TypeScript 入门 | 计划中 |
| chapter02/ | 02 开发环境搭建 | 计划中 |
| chapter03/ | 03 程序结构 | 计划中 |
| chapter04/ | 04 基础类型与变量 | 计划中 |
| chapter05/ … chapter15/ | 05～15 篇教程 | 计划中 |

## 编译与运行

```bash
# 安装 TypeScript（需 Node.js）
npm install -g typescript ts-node

# 编译单文件
tsc example.ts

# 直接运行（开发）
ts-node example.ts

# 项目构建（含 tsconfig.json）
tsc

# 前端项目（Vite 等）
npm create vite@latest my-app -- --template vanilla-ts
```

## 命名约定

- `example_NN.ts`：章节内按序号排列的示例
- 描述性名称：`hello_world.ts`、`interface_demo.ts` 等
- 实战篇可使用 `.tsx`（React 组件场景）
