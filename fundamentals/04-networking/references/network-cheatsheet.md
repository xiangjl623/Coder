# 网络速查

## 模型

OSI 7 层 / TCP/IP 4 层：应用 → 传输 → 网络 → 链路

## 地址

MAC：链路层；IP：主机；端口：进程

私有 IP + NAT；127.0.0.1 本机

## 传输

| | TCP | UDP |
|---|-----|-----|
| 可靠 | 是 | 否 |
| 连接 | 有 | 无 |

三次握手 / 四次挥手

## 应用

HTTP 方法：GET POST PUT DELETE

200 404 500；HTTPS = HTTP + TLS

DNS：域名 → IP

## URL 访问链

DNS → TCP → TLS → HTTP → 渲染

## 教程

- [01 体系结构](../guides/01-network-architecture.md)
- [02 链路与 IP](../guides/02-link-layer-and-ip.md)
- [03 TCP/UDP](../guides/03-transport-layer-tcp-udp.md)
- [04 HTTP/DNS](../guides/04-application-layer-http.md)
