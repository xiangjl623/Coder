# 应用层：HTTP 与 DNS

> **难度**：进阶 | **阅读时间**：约 22 分钟 | **前置**：[传输层 TCP 与 UDP](03-transport-layer-tcp-udp.md) | **标签**：`http` `dns` `https`

## 学习目标

- [ ] 描述浏览器访问 URL 的主要步骤
- [ ] 对比 GET 与 POST、HTTP 与 HTTPS
- [ ] 理解 DNS 解析与常见状态码

## 从 URL 到页面

```
1. DNS 解析 example.com → IP
2. TCP 连接服务器 :443
3. TLS 握手（HTTPS）
4. 发送 HTTP 请求
5. 接收响应，解析 HTML/CSS/JS
6. 可能继续请求子资源
```

素材来自经典「输入 URL 后发生什么」类面试题，按层逐步回答即可。

## HTTP 基础

**请求**：

```http
GET /index.html HTTP/1.1
Host: www.example.com
User-Agent: ...
```

**响应**：

```http
HTTP/1.1 200 OK
Content-Type: text/html
...
<body>
```

### 常用方法

| 方法 | 语义 | 幂等 |
|------|------|------|
| GET | 获取 | 是 |
| POST | 提交/创建 | 否 |
| PUT | 全量更新 | 是 |
| DELETE | 删除 | 是 |

### GET vs POST

| 维度 | GET | POST |
|------|-----|------|
| 参数 | 多在 URL 查询串 | 多在 body |
| 缓存 | 可缓存 | 通常不缓存 |
| 书签/刷新 | 可重复提交 URL | 慎用重复 POST |

**注意**：语义 vs 实现 — POST 也可带查询参数；GET 技术上可有 body（少见）。

### 状态码

| 码 | 含义 |
|----|------|
| 200 | 成功 |
| 301/302 | 重定向 |
| 400 | 客户端错误 |
| 401/403 | 未认证 / 无权限 |
| 404 | 未找到 |
| 500 | 服务器错误 |

## HTTPS

HTTP + **TLS**：加密、完整性、服务器身份（证书）。

握手建立对称密钥，后续 HTTP 载荷加密传输。

## DNS

层次化分布式数据库：域名 → IP（及 MX、CNAME 等）。

```
客户端 → 递归解析器 → 根 → TLD(.com) → 权威 DNS → 答案
```

**缓存**：浏览器、OS、路由器多级缓存 TTL。

## Cookie / Session / JWT

| 机制 | 特点 |
|------|------|
| Cookie | 客户端存 small 状态，随请求发送 |
| Session | 服务端存状态，Cookie 带 session id |
| JWT | 自包含 token，无状态 API 常用 |

## HTTP/2 与 HTTP/3（了解）

- **HTTP/2**：多路复用、头部压缩，单 TCP 连接
- **HTTP/3**：基于 QUIC（UDP），减少队头阻塞

## 本节小结

- DNS → TCP → TLS → HTTP 是 HTTPS 访问主链
- GET/POST 看语义与幂等，不只「参数放哪」
- 状态码与 Cookie/JWT 为面试高频

## 练习

1. 用 curl 查看响应头：`curl -I https://example.com`
2. 解释 302 与 301 对 SEO/缓存的差异（简述）

## 延伸阅读

- [career/interview/guides/04-system-design-and-engineering.md](../../../career/interview/guides/04-system-design-and-engineering.md)
- [network-cheatsheet.md](../references/network-cheatsheet.md)
