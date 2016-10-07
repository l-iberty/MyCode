* 创建一个表示资源网络地址的URL对象；
* 使用ASCII对数据进行编码
* 使用URL对象的openConnection()打开连接，该方法返回URLConnection对象，将其转换为HttpURLConnection对象
* 本次HTTP请求不遵循重定向，请求方式为POST
* 设置请求报文的Content-Type(该属性指定响应的HTTP内容类型)和Content-Length(消息实体的传输长度，这里设置为和消息内容的传输长度一致)
* 本次请求使用URL进行输出
* 使用HttpURLConnection的getOutputStream()获得输出流对象后，向输出流写入信息，该信息是经encode()编码后的字符串转换为的字节数组byte[]
* 获取请求状态码，如果值为HTTP_MOVED_TEMP(302)或HTTP_MOVED_PERM(301)，表示发生了资源的重定向，302表示资源被临时转移，即原来的网络资源还在客户机的缓存中；301表示资源被永久转移，原来的资源已经不在客户机缓存中了
* getHeaderField(String)直接return null，所以我也不知道它到底干什么的. *getHeaderField(String)--Returns:
the value of the named header field, or null if there is no such field in the header.*
* 使用HttpURLConnection的getInputStream()获得输入流对象，从网页读取信息，并将其写入文件bbc.txt(具体的读写操作由Files.copy()完成，这种手段因其太抽象所以我从来都是自己编写代码完成读写操作)，若该文件存在则替换之
