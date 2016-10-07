# 访问www.uestc.edu.cn:
* HTTP的客户机端在端口号80发起一个到服务器主机www.uestc.edu.cn的TCP连接；
* HTTP客户机经其套接字向服务器发出一个HTTP请求报文，其中包含路径/；
* 服务器主机www.uestc.edu.cn经它的套接字接收该报文，从其存储器中加载index对象，在HTTP响应报文中封装对象，并通过套接字向客户机发送响应报文；
* HTTP服务器进程通知TCP断开该TCP连接，TCP确认客户机已经完整接收响应报文后就会中断连接；
* HTTP客户机接收响应报文，TCP连接关闭；客户机从响应报文中提取文件index并在浏览器中加载之.