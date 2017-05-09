# 图书管理系统

## 目录文件说明
* `sql/init.sql` 初始化数据库（创建数据库db_lib和表book, 并录入数据）
* `sql/view.sql` 创建视图
* `sql/user.sql, sql/admin.sql` 录入普通用户和管理员信息, 用于登录验证
* `webapps` 发布到Tomcat服务器目录下的文件
* `LibraryManagementSystem` Intellij IDEA工程文件. 需将编译的*.class文件拷贝到`$TOMCAT_HOME/webapps/ROOT/WEB-INF/classes`目录下，并保留原始的包结构.

## 使用说明
启动Tomcat服务器

### 用户登录
浏览器地址栏输入`http://localhost:8080/MyPage/userlogin.html`

### 管理员登录
浏览器地址栏输入`http://localhost:8080/MyPage/adminlogin.html`