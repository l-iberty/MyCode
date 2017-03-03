# 测试 Hibernate 过程中的 tips

* 本例中使用的是无参数的 `Configuration.configure()`, 要求将 `hibernate.cfg.xml` 放在 `src/` 目录下
* 将 hibernate 工具包下 `lib/` 下的所有 jar 包导入
* 将 MySql 的 jar 包导入, 或将其拷贝到 `CALSSPATH` 下
* 两个 xml 文件和 POJO java 文件放在 `src/` 目录下
* 一定要写执行那个 sql 脚本, 在执行 java 程序
* `session.createQuery("FROM Employee")` (p1.jpg) 中的 `Employee` 不是数据表的名字, 而是一个映射标识, 对应 `class` 标签的 `name` 属性值 (p2.jpg)