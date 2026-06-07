# 经典 100 题面试宝典

> **难度**：进阶 | **阅读时间**：分章查阅，全书约 3～4 小时 | **前置**：[01 面试准备](01-interview-preparation.md) | **标签**：`interview` `java` `classic` `八股`

## 学习目标

- [ ] 能按「是什么 → 原理 → 注意点」结构回答 100 道经典技术面
- [ ] 识别历史考点（Struts/EJB/JSP）并给出 2020s 现代对应说法
- [ ] 与 [02～04 专题 guide](02-cs-fundamentals.md) 形成速查互补，而非重复背诵

---

## 使用说明

**答题结构**（与 [01 面试准备](01-interview-preparation.md) 一致）：

1. **是什么** — 一句话定义或结论
2. **原理/对比** — 表格或要点，展现理解深度
3. **注意点/反例** — 易错点、边界、现代栈差异

**素材来源**：公开经典 Java 面试题集（含 July 系列、程序员面试宝典类题目），经重写为教程体例；过时框架题归入第八章「历史 → 现代」对照，不展开配置细节。

**现代化约定**：正文标注 `现代栈` 的条目以 REST、Spring Boot、JWT、K8s 等为准；第八章历史考点用 `> 历史考点` 标注。

---

## 目录

| 章 | 题号 | 跳转 |
|----|------|------|
| 一、Java 与面向对象 | Q01–Q22 | [§一](#一java-与面向对象-q01-q22) |
| 二、并发与 JVM | Q23–Q34 | [§二](#二并发与-jvm-q23-q34) |
| 三、集合与 IO | Q35–Q44 | [§三](#三集合与-io-q35-q44) |
| 四、算法与现场编程 | Q45–Q57 | [§四](#四算法与现场编程-q45-q57) |
| 五、数据库与 SQL | Q58–Q72 | [§五](#五数据库与-sql-q58-q72) |
| 六、网络与 Web | Q73–Q84 | [§六](#六网络与-web-q73-q84) |
| 七、框架、设计模式与工程 | Q85–Q94 | [§七](#七框架设计模式与工程-q85-q94) |
| 八、历史考点与现代对应 | Q95–Q100 | [§八](#八历史考点与现代对应-q95-q100) |

> 全书共 **100** 题（Q01–Q100），按章查阅；第八章为历史框架考点与现代栈对照。

**题号速查**：[Q01](#q01) · [Q10](#q10) · [Q20](#q20) · [Q30](#q30) · [Q40](#q40) · [Q50](#q50) · [Q60](#q60) · [Q70](#q70) · [Q80](#q80) · [Q90](#q90) · [Q100](#q100)

---

## 一、Java 与面向对象（Q01–Q22）

### Q01. 一个 `.java` 源文件中是否可以包括多个类？有什么限制？ {#q01}

| 维度 | 说明 |
|------|------|
| 分类 | Java 基础 |
| 难度 | 低 |

**是什么**：可以包含多个类，但最多只能有一个 `public` 类，且 `public` 类名必须与文件名一致。

**原理**：编译器以文件为单位编译；`public` 类作为对外 API 入口，命名与文件名绑定便于 classpath 查找。

**注意点**：非 `public` 类可以是内部类或同文件 package-private 类；一个文件多个 `public` 类会编译失败。

---

### Q02. Java 有没有 `goto`？ {#q02}

**是什么**：`goto` 是 Java 保留字，但语言层面未提供 `goto` 语句。

**原理**：保留字占位防止与 C 习惯冲突；流程控制用 `break`/`continue`（可带标号）、异常、循环替代。

**注意点**：`break label` 可跳出外层循环，类似受限版 goto，面试中可举例说明。

---

### Q03. `&` 和 `&&` 有什么区别？ {#q03}

| | `&` | `&&` |
|---|-----|------|
| 逻辑运算 | 两侧都求值 | 短路：左为 false 不求右 |
| 位运算 | 可用于整数按位与 | 不能用于位运算 |

**是什么**：二者都可作逻辑与；`&&` 有短路，`&` 无短路。

**注意点**：`if (obj != null && obj.equals(x))` 依赖短路防 NPE；若写 `&` 可能空指针。`&` 还可作按位与，如 `0x0f & n` 取低 4 bit。

---

### Q04. 在 Java 中如何跳出当前的多重嵌套循环？ {#q04}

**是什么**：两种常见方式——带标号的 `break`，或外层循环条件受内层变量控制。

**原理**：

```java
outer:
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (done) break outer;
    }
}
```

**注意点**：标号 `break` 只跳一层循环结构；`return` 可直接退出整个方法。

---

### Q05. `switch` 能否作用在 `byte`、`long`、`String` 上？ {#q05}

**是什么**：`byte`/`short`/`char` 可（隐式转 `int`）；`String` 从 Java 7 起支持；`long` 不支持。

**原理**：`switch` 要求 case 为编译期可转为 int 的常量；`long` 无隐式转 `int`。

**现代栈**：Java 14+ 支持 `switch` 表达式与模式匹配（了解即可）。

---

### Q06. `short s1 = 1; s1 = s1 + 1` 与 `s1 += 1` 有何区别？ {#q06}

**是什么**：前者编译错误（`s1 + 1` 结果为 `int`，需强转）；后者合法（复合赋值含隐式强转）。

**原理**：二元 `+` 对小于 `int` 的类型会提升为 `int`；`+=` 由编译器插入 `(short)` 转换。

**反例**：误以为 `short + short` 仍是 `short`。

---

### Q07. `char` 型变量能否存储一个中文汉字？ {#q07}

**是什么**：可以。`char` 存 Unicode 码元（UTF-16），常用汉字在 BMP 内，一个 `char` 可表示。

**原理**：Java `char` 16 bit；增补平面汉字需 `String`（两个 char 代理对）。

**注意点**：面试先说明 Unicode 前提；与 UTF-8 字节序列不是同一层概念。

---

### Q08. 用最有效率的方法计算 2 乘以 8？ {#q08}

**是什么**：`2 << 3`（左移 3 位等于乘以 2³）。

**原理**：CPU 位运算通常比乘法指令快；编译器对常量也可能自动优化。

**注意点**：可读性优先时直接写 `2 * 8`；面试考点是位运算与溢出意识。

---

### Q09. `final` 修饰变量时，是引用不能变还是对象不能变？ {#q09}

**是什么**：修饰引用类型时，**引用不能指向其他对象**；对象内部字段仍可变（除非字段也是 `final`）。

**原理**：`final` 表示变量单次赋值；对基本类型即值不可变。

**反例**：`final List<String> list = new ArrayList<>(); list.add("a")` 合法；`list = new ArrayList<>()` 非法。

---

### Q10. `==` 和 `equals()` 究竟有什么区别？ {#q10}

| | `==` | `equals()` |
|---|------|------------|
| 基本类型 | 比较值 | 不适用 |
| 引用类型 | 比较地址 | 比较内容（需重写） |

**是什么**：`==` 比较引用是否同一对象；`equals()` 默认同 `==`，可重写为值相等。

**注意点**：重写 `equals()` 必须重写 `hashCode()`，满足：相等对象 hash 相同。`String` 已重写，常量池场景常考。

> 延伸阅读：[Q21](#q21) String 常量池

---

### Q11. 静态变量和实例变量的区别？ {#q11}

| | 静态变量 | 实例变量 |
|---|----------|----------|
| 归属 | 类 | 对象实例 |
| 内存 | 方法区/元空间（随类加载） | 堆上对象内 |
| 访问 | 类名.变量 | 实例.变量 |

**注意点**：静态方法不能直接访问实例成员（无 `this`）；多线程下静态变量是共享状态，需同步。

---

### Q12. `Integer` 与 `int` 的区别？ {#q12}

**是什么**：`int` 基本类型；`Integer` 包装类，可 null，参与泛型与集合。

**原理**：自动装箱/拆箱；Java 对 `-128～127` 有 Integer 缓存，`==` 比较缓存内外结果不同。

**反例**：`Integer a = 127; Integer b = 127; a == b` 为 true；`128` 则为 false。比较值用 `equals()`。

---

### Q13. `public`、`private`、`protected` 及默认访问权限的区别？ {#q13}

| 修饰符 | 同类 | 同包 | 子类 | 其他 |
|--------|------|------|------|------|
| private | ✓ | | | |
| 默认 | ✓ | ✓ | | |
| protected | ✓ | ✓ | ✓ | |
| public | ✓ | ✓ | ✓ | ✓ |

**注意点**：子类在**不同包**时只能访问 `protected`/`public` 成员；`protected` 含包访问 + 继承访问。

---

### Q14. Overload 和 Override 的区别？重载能否改变返回值？ {#q14}

| | Overload（重载） | Override（重写） |
|---|------------------|------------------|
| 位置 | 同类 | 子类对父类 |
| 签名 | 参数列表不同 | 相同签名 |
| 返回值 | **可以**不同（仅返回值不同不足以构成重载） | 协变返回类型允许 |

**是什么**：重载编译期多态；重写运行期多态。

**注意点**：重载必须参数不同；仅改返回值不算重载。

---

### Q15. 接口能否继承接口？抽象类能否实现接口？ {#q15}

**是什么**：接口可以 `extends` 多个接口；抽象类可以实现接口；抽象类可以继承具体类。

**原理**：Java 单继承类、多实现接口；抽象类提供部分实现 + 抽象方法。

**现代栈**：Java 8+ 接口可有 `default`/`static` 方法，减少抽象类样板代码。

---

### Q16. 面向对象的特征有哪些？ {#q16}

**是什么**：封装、继承、多态（常加「抽象」作为设计原则）。

| 特征 | 要点 |
|------|------|
| 封装 | 隐藏实现，暴露接口 |
| 继承 | 代码复用，is-a 关系 |
| 多态 | 同一引用调用不同子类实现 |

---

### Q17. Java 中实现多态的机制是什么？ {#q17}

**是什么**：父类引用指向子类对象 + 子类重写父类方法 → 运行时动态绑定调用子类实现。

**原理**：虚方法表（vtable）；接口调用类似，运行期查实际类型。

**注意点**：多态针对方法；字段访问看引用类型，不看实际类型。

---

### Q18. 抽象类（abstract class）和接口（interface）有什么区别？ {#q18}

| 维度 | 抽象类 | 接口 |
|------|--------|------|
| 继承 | 单继承 | 多实现 |
| 构造器 | 可有 | 无 |
| 成员 | 任意访问级别字段/方法 | 常 public abstract/default/static |
| 设计意图 | is-a 模板 | can-do 能力契约 |

**现代栈**：优先接口 + 组合；需要共享状态或非 public 方法时用抽象类。

---

### Q19. `String s = "Hello"; s = s + " world!"` 后，原 String 对象变了吗？ {#q19}

**是什么**：**没变**。`String` 不可变；`s = s + " world!"` 创建新对象并让 `s` 指向它，原 `"Hello"` 仍在常量池/堆中。

**原理**：`+` 拼接编译期可能优化为 `StringBuilder`，但结果仍是新 `String`。

**注意点**：大量拼接用 `StringBuilder`/`StringBuffer`，避免中间对象。

---

### Q20. `String`、`StringBuilder`、`StringBuffer` 的区别？ {#q20}

| | String | StringBuilder | StringBuffer |
|---|--------|---------------|--------------|
| 可变 | 不可变 | 可变 | 可变 |
| 线程安全 | 天然不可变 | 否 | 是（synchronized） |
| 场景 | 常量、少量拼接 | 单线程拼接 | 多线程拼接（少用） |

**是什么**：`"a"+"b"+"c"` 编译器可能合并为常量；循环内拼接应用 `StringBuilder`。

---

### Q21. `new String("xyz")` 创建了几个对象？ {#q21}

**是什么**：0～2 个：若常量池无 `"xyz"`，则堆上 `String` 对象 + 常量池入池；若已有，则仅堆上新对象（JDK 7+ 字符串在堆）。

**注意点**：`String s = "xyz"` 可能只引用常量池，无新堆对象。具体与 JDK 版本及 intern 有关，面试说明前提即可。

---

### Q22. `String` 是最基本的数据类型吗？ {#q22}

**是什么**：不是。基本类型 8 种；`String` 是 `final` 引用类型，不可继承。

---

## 二、并发与 JVM（Q23–Q34）

### Q23. `sleep()` 和 `wait()` 有什么区别？ {#q23}

| | `sleep()` | `wait()` |
|---|-----------|----------|
| 所属 | `Thread` 静态方法 | `Object` 实例方法 |
| 锁 | **不释放** | **释放** |
| 唤醒 | 超时 | `notify`/`notifyAll` |
| 调用位置 | 任意 | 必须在同步块内 |

**是什么**：`sleep` 让当前线程暂停；`wait` 让线程等待并释放监视器。

**反例**：在 `synchronized` 外调用 `wait()` → `IllegalMonitorStateException`。

> 延伸阅读：[02-cs-fundamentals.md](02-cs-fundamentals.md) 操作系统章节

---

### Q24. Java 中有几种方法实现线程？ {#q24}

**是什么**：两种主流方式——继承 `Thread` 或实现 `Runnable`（推荐）；另可 `Callable` + `Future` 获取返回值。

**原理**：Java 单继承，实现 `Runnable` 更灵活；线程池 `ExecutorService` 统一管理。

**现代栈**：优先线程池，避免裸 `new Thread()`。

---

### Q25. 启动线程用 `run()` 还是 `start()`？ {#q25}

**是什么**：必须调用 `start()`，JVM 新建线程并调度 `run()`；直接调 `run()` 只是普通方法调用，仍在当前线程执行。

---

### Q26. 同步有几种实现方式？ {#q26}

**是什么**：`synchronized`（方法/块）、显式 `Lock`（`ReentrantLock`）、并发工具（`Semaphore`、`CountDownLatch`）、原子类（CAS）。

**注意点**：`wait`/`notify` 配合 `synchronized` 使用；`Lock` 用 `Condition` 替代 wait/notify。

---

### Q27. 当一个线程进入对象的 `synchronized` 方法后，其他线程能否进入该对象的其他方法？ {#q27}

**是什么**：非 `synchronized` 方法**可以**进入；其他 `synchronized` 方法**不可以**（需同一把锁）。

**原理**：每个对象有一把监视器锁；同步方法持锁期间，其他同步方法阻塞。

---

### Q28. `synchronized` 和 `Lock` 的异同？ {#q28}

| | `synchronized` | `Lock` |
|---|----------------|--------|
| 释放 | 自动 | 需 `unlock()`（放 finally） |
| 公平 | 非公平 | 可选公平锁 |
| 功能 | 互斥 | 可中断、超时、多 Condition |

**是什么**：都能互斥；`Lock` 更灵活，代码更重。

> 延伸阅读：[02-cs-fundamentals.md](02-cs-fundamentals.md) 第四节答题示例

---

### Q29. 同步和异步有何异同？分别用在什么场景？ {#q29}

**是什么**：同步调用方阻塞等待结果；异步调用方继续执行，结果通过回调/Future/消息通知。

| 场景 | 选择 |
|------|------|
| 线程间共享数据写读 | 同步（锁、volatile） |
| 长耗时 IO、不想阻塞 UI/主线程 | 异步（CompletableFuture、MQ） |

---

### Q30. 运行时异常与一般异常有何异同？ {#q30}

| | Checked（受检） | Unchecked（Runtime） |
|---|-----------------|----------------------|
| 继承 | `Exception`（非 Runtime） | `RuntimeException` |
| 编译器 | 必须处理或 throws | 不强制 |
| 例子 | `IOException` | `NPE`、`IllegalArgumentException` |

**是什么**：`Error` 一般不捕获（如 `OutOfMemoryError`）。

---

### Q31. `final`、`finally`、`finalize` 的区别？ {#q31}

| 关键字 | 作用 |
|--------|------|
| `final` | 类不可继承 / 方法不可重写 / 变量不可改 |
| `finally` | try-catch 后必执行块（除 JVM 退出等） |
| `finalize` | Object 方法，GC 前回调；**已废弃**，勿依赖 |

**反例**：`finally` 中 `return` 会覆盖 try 的返回值。

---

### Q32. 堆（heap）和栈（stack）有什么区别？64K 字符串放哪？ {#q32}

| | 栈 | 堆 |
|---|-----|-----|
| 内容 | 局部变量、引用 | 对象实例、数组 |
| 生命周期 | 方法结束弹栈 | GC 回收 |
| 线程 | 线程私有 | 线程共享 |

**是什么**：64K 字符串对象在**堆**上；栈上仅存引用（几个字节）。

**原理**：栈空间有限（通常 MB 级），大对象放堆；递归过深可能 `StackOverflowError`。

---

### Q33. GC 是什么？为什么要有 GC？ {#q33}

**是什么**：垃圾回收自动释放不再可达的对象内存。

**原理**：标记-清除、复制、标记-整理等；分代收集（新生代/老年代）。

**注意点**：无法保证立刻回收；`System.gc()` 仅建议 JVM 执行，不保证。

---

### Q34. JVM 加载 class 文件的原理机制？ {#q34}

**是什么**：加载 → 验证 → 准备 → 解析 → 初始化（双亲委派模型加载类）。

**原理**：`Bootstrap` → `Extension` → `Application` ClassLoader；子 loader 先委派父 loader。

**注意点**：打破双亲委派场景：SPI、Tomcat 隔离、热部署（了解）。

---

## 三、集合与 IO（Q35–Q44）

### Q35. 介绍 Java Collection 框架结构 {#q35}

**是什么**：根接口 `Collection`（`List`/`Set`/`Queue`）与 `Map` 并列；常用实现 `ArrayList`、`LinkedList`、`HashSet`、`HashMap`、`PriorityQueue` 等。

**原理**：`Collections` 工具类 vs `Collection` 接口勿混淆。

---

### Q36. `ArrayList` 和 `Vector` 的区别？ {#q36}

| | ArrayList | Vector |
|---|-----------|--------|
| 线程安全 | 否 | 是（synchronized） |
| 扩容 | 1.5 倍 | 2 倍 |
| 性能 | 更高 | 遗留类，少用 |

**现代栈**：多线程用 `CopyOnWriteArrayList` 或 Collections.synchronizedList，而非 Vector。

---

### Q37. `ArrayList` 和 `LinkedList` 的存储性能与特性？ {#q37}

| | ArrayList | LinkedList |
|---|-----------|----------|
| 底层 | 动态数组 | 双向链表 |
| 随机访问 | O(1) | O(n) |
| 头尾插入 | 尾 O(1) 均摊；头 O(n) | O(1) |
| 内存 | 连续，缓存友好 | 节点指针开销 |

**选型**：查多用 ArrayList；频繁头插或队列语义考虑 LinkedList/`ArrayDeque`。

---

### Q38. `HashMap` 和 `Hashtable` 的区别？ {#q38}

| | HashMap | Hashtable |
|---|---------|-----------|
| 线程安全 | 否 | 是 |
| null | 允许一 null 键、多 null 值 | 不允许 |
| 迭代 | Iterator 可 fail-fast | Enumerator |

**现代栈**：并发用 `ConcurrentHashMap`；JDK 8+ HashMap 链表过长转红黑树。

---

### Q39. `List`、`Set`、`Map` 的区别？存取元素各有什么特点？ {#q39}

| 接口 | 有序 | 重复 | 典型实现 |
|------|------|------|----------|
| List | 可索引顺序 | 允许 | ArrayList |
| Set | 视实现 | 不允许 | HashSet, TreeSet |
| Map | 键值对 | 键不重复 | HashMap |

**存取**：List 用 index；Set 用元素本身；Map 用 key。

---

### Q40. 如何区分 Set 中元素重复？用 `==` 还是 `equals()`？ {#q40}

**是什么**：用 `equals()`（及 `hashCode` 一致性）。`==` 比较地址，逻辑相等对象会被误判为不重复。

**原理**：`HashSet` 先比 hash 再 equals。

---

### Q41. 两个对象 `equals` 相同，能否 hashCode 不同？ {#q41}

**是什么**：**不可以**（违反规范）。相等对象必须有相同 hashCode。

**反例**：只重写 equals 不重写 hashCode → HashMap/HashSet 行为异常。

---

### Q42. Java 中有几种类型的流？字节流与字符流的区别？ {#q42}

**是什么**：字节流 `InputStream`/`OutputStream`；字符流 `Reader`/`Writer`（带编码转换）。

**原理**：文本用字符流指定 UTF-8；二进制（图片、协议）用字节流。

**注意点**：`InputStreamReader` 桥接字节→字符。

---

### Q43. 什么是 Java 序列化？`Serializable` 的作用？ {#q43}

**是什么**：把对象转为字节序列以便存储或网络传输；实现 `Serializable` 标记可序列化。

**原理**：`serialVersionUID` 保证版本兼容；`transient` 字段不序列化。

**现代栈**：JSON/Protobuf 跨语言更常用；Java 原生序列化安全与兼容性问题多，RPC 慎用。

---

### Q44. `Collection` 和 `Collections` 的区别？ {#q44}

**是什么**：`Collection` 是集合根接口；`Collections` 是工具类（`sort`、`binarySearch`、`synchronizedList`、`unmodifiableList` 等）。

**反例**：面试写 `Collections.add()` —— 应对具体 `List`/`Set` 实例调用 `add`。

---

## 四、算法与现场编程（Q45–Q57）

### Q45. 按字节截取字符串，保证汉字不被劈开（UTF-8） {#q45}

**是什么**：逐字符判断 UTF-8 首字节长度（1～4 字节），累计不超过 limit 则纳入。

**思路**：

```
count = 0, i = 0
while i < len && count + charBytes(s[i]) <= limit:
    count += charBytes(s[i]); i += charBytes(s[i])
return s[0:i]
```

**注意点**：先声明编码前提；C/C++ 注意 `char` 有符号扩展。

> 延伸阅读：[03-data-structures-and-algorithms.md](03-data-structures-and-algorithms.md) 案例 3

---

### Q46. 统计字符串中英文字母、汉字、数字的个数 {#q46}

**是什么**：遍历字符，用 `Character.isDigit/isLetter` 或 Unicode 范围判断汉字（如 `\u4e00-\u9fff`）。

**注意点**：区分全角数字与半角；面试说明分类规则。

---

### Q47. 手写 Singleton（单例）并说明线程安全 {#q47}

**是什么**：保证全局唯一实例；常用写法：

| 写法 | 线程安全 | 说明 |
|------|----------|------|
| 饿汉 | 是 | 类加载即创建 |
| 双重检查锁 | 是 | 需 volatile |
| 静态内部类 | 是 | 懒加载推荐 |
| 枚举 | 是 | 防反射破坏 |

**反例**：懒汉不加锁 → 多线程下多个实例。

> 延伸阅读：[03-data-structures-and-algorithms.md](03-data-structures-and-algorithms.md) 案例 4

---

### Q48. 递归：斐波那契数列，如何优化？ {#q48}

**是什么**：裸递归 `F(n)=F(n-1)+F(n-2)` 时间 O(2^n)。

**优化**：记忆化或 DP 数组 O(n) 时间 O(1) 空间（滚动变量）。

**注意点**：递归需边界 `n<=1`；深度过大可能栈溢出。

---

### Q49. 递归：迷宫或全排列思路 {#q49}

**是什么**：回溯模板——选择 → 递归 → 撤销选择。

**迷宫**：DFS + visited 标记；全排列：固定位置 swap 或 used 数组。

---

### Q50. 排序有哪些方法？简述快速排序 {#q50}

| 算法 | 平均 | 稳定 |
|------|------|------|
| 快排 | O(n log n) | 否 |
| 归并 | O(n log n) | 是 |
| 堆排序 | O(n log n) | 否 |

**快排**：选 pivot → 分区（小于左、大于右）→ 递归子数组。

**注意点**：最坏 O(n²)（已有序 + 坏 pivot）；可随机 pivot 缓解。

> 延伸阅读：[03-data-structures-and-algorithms.md](03-data-structures-and-algorithms.md) 第二节

---

### Q51. 将数组元素顺序颠倒 {#q51}

**是什么**：双指针 `i=0, j=n-1`，交换 `a[i]` 与 `a[j]` 并向中间移动。O(n) 时间 O(1) 空间。

---

### Q52. 栈操作序列：能否用栈得到目标排列？ {#q52}

**是什么**：模拟栈：依次 push 入栈元素，若栈顶等于目标下一元素则 pop。

**结论**：栈空且目标读完 → 可行。经典题「出栈序列合法性」。

> 延伸阅读：[03-data-structures-and-algorithms.md](03-data-structures-and-algorithms.md) 案例 1

---

### Q53. 100 万元素数组中有两个重复，如何找到？ {#q53}

**是什么**：多种方案：

| 方案 | 复杂度 | 说明 |
|------|--------|------|
| 哈希 Set | O(n) 空间 O(n) | 边遍历边查 |
| 排序后扫描 | O(n log n) 空间 O(1) | 改原数组 |
| 异或（仅知一个重复两次） | O(n) O(1) | 两相同异或为 0 |
| 快慢指针 | O(n) O(1) | 抽象为链表环（进阶） |

**注意点**：先澄清「几个重复、重复几次、能否改数组」。

---

### Q54. 两数之和（无序数组） {#q54}

**是什么**：哈希表存「值 → 下标」，遍历 `nums[i]` 查 `target - nums[i]`。O(n) 时间。

**延伸**：有序数组用双指针；TopK 用小根堆/快排 partition。

---

### Q55. 多路归并取 TopK {#q55}

**是什么**：小根堆存各数组当前最小元素 `(值, 数组 id, 下标)`，弹 K 次并补入该数组下一元素。约 O(K log m)。

> 延伸阅读：[03-data-structures-and-algorithms.md](03-data-structures-and-algorithms.md) 案例 2

---

### Q56. 二叉树的遍历方式 {#q56}

**是什么**：前序（根左右）、中序（左根右）、后序（左右根）、层序（BFS 队列）。

**应用**：BST 中序有序；表达式树前序/后序对应前缀/后缀表达式。

---

### Q57. 用栈判断括号是否匹配 {#q57}

**是什么**：遇左括号入栈，遇右括号弹栈匹配；最终栈空则合法。O(n)。

---

## 五、数据库与 SQL（Q58–Q72）

### Q58. 数据库三范式是什么？ {#q58}

1. **1NF**：字段原子，无重复组
2. **2NF**：非主键完全依赖主键（无部分依赖）
3. **3NF**：非主键不传递依赖其他非主键

**反例**：学生表冗余「院系名称」→ 更新异常；应拆院系表。

> 延伸阅读：[02-cs-fundamentals.md](02-cs-fundamentals.md) 三、数据库

---

### Q59. 为什么使用索引？单表索引数量建议？ {#q59}

**是什么**：加速 WHERE/JOIN/ORDER BY；B+ 树支持范围扫描。

**建议**：无固定上限，原则——高频查询列、区分度高的列；避免过多索引拖慢写入；单表常 **5～10 个以内** 视业务而定，合并联合索引优于单列堆砌。

---

### Q60. `PreparedStatement` 和 `Statement` 的区别？ {#q60}

| | PreparedStatement | Statement |
|---|-------------------|-----------|
| SQL | 预编译，参数占位 | 每次完整 SQL |
| 性能 | 重复执行更好 | 每次解析 |
| 安全 | 防 SQL 注入 | 拼接易注入 |

---

### Q61. `INNER JOIN` 和 `LEFT JOIN` 的区别？ {#q61}

**是什么**：INNER 只返回两表匹配行；LEFT 保留左表全部，右表无匹配则 NULL。

**场景**：查「有订单的用户」用 INNER；「所有用户及其订单（含无订单）」用 LEFT。

---

### Q62. `UNION` 和 `UNION ALL` 的区别？ {#q62}

**是什么**：`UNION` 合并结果并**去重**；`UNION ALL` 不去重，性能更好。

**注意点**：列数与类型需兼容；去重有排序开销。

---

### Q63. 分页方案有哪些？深分页如何优化？ {#q63}

| 方案 | 说明 |
|------|------|
| LIMIT offset, size | 简单；offset 大时慢 |
| 游标（上次 max id） | `WHERE id > ? ORDER BY id LIMIT n` |
| 搜索引擎 | 复杂列表场景 |

**是什么**：百万行 `LIMIT 1000000, 10` 需扫描丢弃大量行 → 用 id 游标或覆盖索引优化。

---

### Q64. 查询每门课成绩都大于 80 分的学生 {#q64}

```sql
SELECT student_id
FROM scores
GROUP BY student_id
HAVING MIN(score) > 80;
```

**要点**：`HAVING` 过滤分组；勿用 `WHERE score > 80`（只保证单次成绩）。

---

### Q65. 查询薪水高于本部门平均工资的员工 {#q65}

```sql
SELECT e.*
FROM employees e
JOIN (
  SELECT dept_id, AVG(salary) AS avg_sal
  FROM employees GROUP BY dept_id
) d ON e.dept_id = d.dept_id
WHERE e.salary > d.avg_sal;
```

**变体**：窗口函数 `AVG(salary) OVER (PARTITION BY dept_id)`。

---

### Q66. 删除除 id 外其他字段完全重复的记录 {#q66}

**思路**：`DELETE` 配合子查询保留 `MIN(id)`，或用窗口 `ROW_NUMBER() OVER (PARTITION BY col1,col2 ...)` 删 `rn > 1`。

---

### Q67. 事务隔离级别有哪些？ {#q67}

| 级别 | 脏读 | 不可重复读 | 幻读 |
|------|------|------------|------|
| READ UNCOMMITTED | 可能 | 可能 | 可能 |
| READ COMMITTED | 否 | 可能 | 可能 |
| REPEATABLE READ | 否 | 否 | InnoDB 多数否 |
| SERIALIZABLE | 否 | 否 | 否 |

**是什么**：MySQL InnoDB 默认 RR + MVCC。

---

### Q68. 存储过程和触发器的区别（概念） {#q68}

| | 存储过程 | 触发器 |
|---|----------|--------|
| 调用 | 主动 CALL | 表事件自动触发 |
| 用途 | 批量逻辑、封装 | 审计、同步、约束 |

**现代栈**：业务逻辑多放应用层；DB 侧慎用，便于测试与版本管理。

---

### Q69. 数据库连接池的工作机制？ {#q69}

**是什么**：预先创建连接放入池，请求借出、用完归还，避免频繁建连/断连。

**参数**：最小/最大连接数、超时、空闲回收；HikariCP 等。

---

### Q70. ORM 和 JDBC 有何不同？为什么要用 ORM？ {#q70}

| | JDBC | ORM（JPA/Hibernate） |
|---|------|----------------------|
| 抽象 | SQL + ResultSet | 对象映射 |
| 优点 | 可控、性能调优细 | 开发效率高、跨库 |
| 缺点 | 样板代码多 | 复杂 SQL/N+1 问题 |

**是什么**：ORM 适合 CRUD 为主；报表/复杂查询可回 JDBC 或 MyBatis。

---

### Q71. 缓存穿透、击穿、雪崩是什么？如何防范？ {#q71}

| 问题 | 含义 | 对策 |
|------|------|------|
| 穿透 | 查不存在 key，打到 DB | 布隆过滤器、空值缓存 |
| 击穿 | 热点 key 过期瞬间并发打 DB | 互斥锁、逻辑过期 |
| 雪崩 | 大量 key 同时过期 | 过期时间加随机、多级缓存 |

> 延伸阅读：[02-cs-fundamentals.md](02-cs-fundamentals.md) Redis 简述

---

### Q72. 百万用户积分每年清零，如何设计？ {#q72}

**是什么**：分批 UPDATE（按 id 段）、低峰执行、避免长事务锁表；记录任务日志；考虑异步队列 + 限流；是否物理清零 vs 年度分区表。

---

## 六、网络与 Web（Q73–Q84）

### Q73. HTTP 的 GET 和 POST 有什么区别？ {#q73}

| 维度 | GET | POST |
|------|-----|------|
| 语义 | 获取资源 | 提交/创建 |
| 幂等 | 幂等 | 不一定 |
| Body | 通常无 | 常有 |
| 缓存 | 可缓存 | 一般否 |

**现代栈**：语义优先；HTTP/2 多路复用；敏感数据放 body + HTTPS，勿放 URL。

> 延伸阅读：[02-cs-fundamentals.md](02-cs-fundamentals.md) HTTP 要点

---

### Q74. TCP 三次握手与四次挥手 {#q74}

**三次握手**：SYN → SYN+ACK → ACK（建立连接，同步序列号）。

**四次挥手**：FIN → ACK → FIN → ACK（全双工关闭需两方向分别关闭）。

**注意点**：TIME_WAIT 等待 2MSL；半连接队列与 SYN flood（了解）。

---

### Q75. TCP 和 UDP 的区别？ {#q75}

| | TCP | UDP |
|---|-----|-----|
| 连接 | 面向连接 | 无连接 |
| 可靠 | 重传、有序 | 不保证 |
| 场景 | HTTP、文件 | 视频、DNS、游戏 |

---

### Q76. `forward` 和 `redirect` 的区别？ {#q76}

| | forward | redirect |
|---|---------|----------|
| 次数 | 服务器内部一次 | 两次请求 |
| URL | 不变 | 变（302/301） |
| 数据共享 | request 属性可传 | 不可 |

**现代栈**：服务端内部转发类似网关路由；客户端跳转用 302/前端路由。

---

### Q77. JSP/Servlet 四种会话作用域 {#q77}

| 作用域 | 范围 |
|--------|------|
| page | 当前页 |
| request | 一次请求 |
| session | 一次会话 |
| application | 整个 Web 应用 |

**现代栈**：前后端分离用 **JWT 无状态** 或 Redis Session；JSP 作用域为历史考点。

---

### Q78. Servlet 生命周期？与 Spring Boot 请求处理对照 {#q78}

**是什么**：load → init → service → destroy。

> **历史考点**：传统 Servlet 容器管理生命周期。

**现代栈**：Spring Boot `DispatcherServlet` → HandlerMapping → Controller → 返回 JSON；Filter/Interceptor 链处理鉴权与日志。

---

### Q79. MVC 各部分由什么技术实现？ {#q79}

**是什么**：Model（数据/业务）、View（展示）、Controller（调度）。

**现代栈**：Model=Service+Repository；View=React/Vue SPA；Controller=REST API。

---

### Q80. 同步与异步在 Web 请求中的例子 {#q80}

**同步**：浏览器阻塞等待 HTTP 响应。

**异步**：Ajax/fetch 回调、WebSocket 推送、消息队列削峰后回调通知。

---

### Q81. 常见 HTTP 状态码 {#q81}

| 码 | 含义 |
|----|------|
| 200 | OK |
| 301/302 | 永久/临时重定向 |
| 400 | 请求错误 |
| 401 | 未认证 |
| 403 | 无权限 |
| 404 | 未找到 |
| 500 | 服务器错误 |
| 502/503 | 网关/服务不可用 |

---

### Q82. HTTPS 与 TLS 简述 {#q82}

**是什么**：HTTP + TLS 加密与证书校验，防窃听与篡改。

**握手**：协商 cipher、验证证书、交换密钥 → 对称加密传数据。

---

### Q83. Cookie、Session 与 Token（JWT）的区别？ {#q83}

| | Cookie | Session | JWT |
|---|--------|---------|-----|
| 存储 | 客户端 | 服务端 | 客户端（签名） |
| 状态 | 可带 SessionId | 有状态 | 无状态 |
| 跨域 | 受限 | 需共享存储 | 易用于 API |

**现代栈**：SPA + 后端 API 多用 JWT 或 Session + HttpOnly Cookie。

---

### Q84. REST 幂等性：GET/PUT/DELETE/POST {#q84}

**是什么**：同一请求多次执行效果相同。

| 方法 | 幂等 |
|------|------|
| GET、PUT、DELETE | 是（语义上） |
| POST | 否（常创建新资源） |

**工程**：支付等用幂等键（Idempotency-Key）防重复提交。

> 延伸阅读：[04-system-design-and-engineering.md](04-system-design-and-engineering.md)

---

## 七、框架、设计模式与工程（Q85–Q94）

### Q85. 工厂模式解决什么问题？ {#q85}

**是什么**：将对象创建与使用分离；简单工厂、工厂方法、抽象工厂（产品族）。

**场景**：根据配置创建不同 DB 驱动、不同消息客户端。

---

### Q86. 单例模式要点（与设计模式语境） {#q86}

**是什么**：全局唯一 + 私有构造；见 [Q47](#q47) 线程安全写法。

**注意点**：Spring 默认 Bean 单例是容器级，非 Gang of Four 单例。

---

### Q87. 策略模式与观察者模式 {#q87}

| 模式 | 意图 |
|------|------|
| 策略 | 算法可互换，消除 if-else |
| 观察者 | 一对多依赖，发布-订阅 |

**现代栈**：策略常用于支付/促销路由；观察者 → EventBus、Spring Event、MQ 消费。

---

### Q88. IoC / DI 是什么？ {#q88}

**是什么**：控制反转——对象创建与依赖装配交给容器；依赖注入通过构造器/setter/字段注入实现。

**原理**：Spring 读取配置或注解，构建 Bean 依赖图。

---

### Q89. AOP 的作用？ {#q89}

**是什么**：面向切面，横切关注点（日志、事务、权限）与业务解耦。

**原理**：动态代理（JDK 接口代理 / CGLIB 子类）；`@Transactional` 即 AOP 应用。

---

### Q90. ORM 一对多关系如何映射？ {#q90}

**是什么**：JPA 用 `@OneToMany` / `@ManyToOne`；外键在多方；注意 `mappedBy` 与 cascade、fetch 策略（LAZY/EAGER）。

**反例**：EAGER 一对多 → N+1 或巨大 JOIN；默认 LAZY + fetch join 按需。

---

### Q91. B/S 和 C/S 的区别？ {#q91}

| | B/S | C/S |
|---|-----|-----|
| 客户端 | 浏览器 | 专用客户端 |
| 部署 | 升级在服务端 | 需更新客户端 |
| 例子 | Web 管理后台 | 桌面游戏、旧 ERP |

---

### Q92. 应用服务器与 Web 服务器的区别？ {#q92}

**是什么**：Web 服务器（Nginx、Apache）主要 HTTP 静态/反向代理；应用服务器（Tomcat、传统 WAS）运行 Servlet/EJB 等业务组件。

**现代栈**：Nginx 终止 TLS + 反代 → Spring Boot 内嵌 Tomcat；K8s Ingress 类似角色。

---

### Q93. UML 类图与时序图的用途？ {#q93}

**是什么**：类图——静态结构、继承、关联；时序图——对象间消息时间顺序。

**面试**：系统设计白板常用框图 + 时序说明核心调用链，不必 UML 语法完美。

---

### Q94. 何时用接口，何时用抽象类？ {#q94}

**是什么**：需要多实现、定义能力契约 → **接口**；需要共享代码、模板方法、非 public 成员 → **抽象类**。

**原则**：优先组合 + 接口；「is-a」且需共用实现才抽象类。

---

## 八、历史考点与现代对应（Q95–Q100）

> **历史考点**：以下题目来自 Struts/EJB/JSP/WebLogic 等早期 Java EE 面试；答法以「当时是什么 → 现在用什么」对照，不展开过时配置细节。

### Q95. Struts 工作流程是什么？现代对应？ {#q95}

| 维度 | 历史（Struts 1/2） | 现代栈 |
|------|-------------------|--------|
| 入口 | `ActionServlet` / Filter | Spring Boot `DispatcherServlet` |
| 映射 | `struts-config.xml` | `@RequestMapping` / 路由注解 |
| 表现 | JSP | REST JSON + 前端 SPA |

**是什么**：MVC 框架，请求经 Front Controller 分发到 Action，再转发视图。

**现代栈**：Spring MVC：`Controller` → Service → Repository → JSON；配置外置 `application.yml`。

> 延伸阅读：[04-system-design-and-engineering.md](04-system-design-and-engineering.md)

---

### Q96. EJB 中 SessionBean 与 EntityBean 的区别？现代对应？ {#q96}

| 历史 | 职责 | 现代对应 |
|------|------|----------|
| SessionBean | 业务逻辑、事务 | Spring `@Service` + `@Transactional` |
| EntityBean | 持久化实体（重量级） | JPA Entity / MyBatis PO |

**是什么**：EJB 为服务器端组件模型，容器管理事务、安全、生命周期。

**现代栈**：微服务拆分为独立 REST/gRPC 服务；事务用 Spring 或 Saga；持久化用 ORM，不再用 EntityBean。

---

### Q97. JSP 有哪些内置对象？现代对应？ {#q97}

**历史**：`request`、`response`、`session`、`application`、`out`、`pageContext` 等，脚本式/JSTL 渲染页面。

**现代栈**：前后端分离——后端无 JSP，返回 JSON；`request` 语境 → HTTP 请求上下文 / `HttpServletRequest` 包装；会话 → JWT 或 Redis Session。

---

### Q98. WebLogic 域（Domain）配置与部署？现代对应？ {#q98}

**历史**：管理控制台配置 JMS、连接池、发布 EAR/WAR；内存参数 `-Xmx` 等。

**现代栈**：Docker 镜像 + `docker-compose` / Kubernetes Deployment + ConfigMap/Secret；HikariCP 连接池在应用配置；弹性伸缩用 HPA。

---

### Q99. iBatis 与 Hibernate 有何不同？XML 解析 DOM/SAX？ {#q99}

| 维度 | iBatis/MyBatis | Hibernate/JPA |
|------|----------------|---------------|
| SQL | 手写/映射 XML | 自动生成为主 |
| 学习 | SQL 可控 | 对象关系映射 |

**XML 历史**：DOM 树内存、SAX 事件流解析。

**现代栈**：MyBatis + 注解/XML 混用；配置与 API payload 多用 **JSON**（Jackson）；大配置用 Nacos/Apollo 配置中心。

---

### Q100. CORBA 与 WebService（SOAP/WSDL）？现代对应？ {#q100}

**历史**：CORBA 跨语言 RPC（IDL）；SOAP + WSDL + UDDI 描述 Web 服务。

**现代栈**：**gRPC + Protobuf**（高性能 RPC）；对外 HTTP API 用 **OpenAPI/Swagger + REST**；服务发现用 K8s DNS / Consul，而非 UDDI。

---

## 附录：与现有 guides 对照表

| 宝典章节 | 题号 | 延伸阅读 |
|----------|------|----------|
| Java / OOP | Q01–Q22 | [languages/java/](../../../languages/)（若有） |
| 并发 / JVM | Q23–Q34 | [02-cs-fundamentals.md](02-cs-fundamentals.md) |
| 集合 / IO | Q35–Q44 | [03-data-structures-and-algorithms.md](03-data-structures-and-algorithms.md) |
| 算法 | Q45–Q57 | [fundamentals/01-data-structures/](../../../fundamentals/01-data-structures/) |
| 数据库 | Q58–Q72 | [02-cs-fundamentals.md](02-cs-fundamentals.md)、[fundamentals/05-databases/](../../../fundamentals/05-databases/) |
| 网络 / Web | Q73–Q84 | [02-cs-fundamentals.md](02-cs-fundamentals.md)、[04-system-design-and-engineering.md](04-system-design-and-engineering.md) |
| 框架 / 模式 | Q85–Q94 | [04-system-design-and-engineering.md](04-system-design-and-engineering.md) |
| 历史 → 现代 | Q95–Q100 | [04-system-design-and-engineering.md](04-system-design-and-engineering.md) |

## 本节小结

- 100 题覆盖 Java 基础、并发、集合、算法、SQL、网络、框架与设计模式
- 答题顺序：**是什么 → 原理/对比 → 注意点/反例**
- 第八章历史考点用现代栈对照回答，避免纠缠过时配置
- 与 [01～05 专题 guide](01-interview-preparation.md) 配合：宝典速查，guide 深读

## 练习

1. 任抽 10 题，限时 30 分钟口述答案
2. 将 Q95–Q100 各写一段「历史 vs 2020s」30 秒版
3. 对照 [common-questions-index.md](../references/common-questions-index.md) 标记已掌握与待复习
