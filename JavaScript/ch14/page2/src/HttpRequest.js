// 定义构造函数
function HttpRequest(URL, function_callBack) {
	/*
	 *参数说明:
	 *1.URL是XMLHttpRequest对象请求的URL,用于open()方法
	 *2.function_callBack是一个回调函数,当接受到服务器的响应时
	 *  (即XMLHttpRequest对象表示请求状态的属性readyState为4,且
	 *  该对象的status属性——服务器返回的状态码——为200)调用它
	 */
	this.request = this.createXMLHttpRequest();
	// this引用"通过使用new关键字调用构造函数HttpRequest()创建的"对象
	this.request.open("GET", URL, true);
	/*
	 *创建XMLHttpRequest对象后就可以用它请求数据.
	 *该过程第一步是调用该对象的open()方法.open()的参数:
	 *open(requestType, URL, async):
	 *1.requestType是表示请求类型的字符串,为GET或POST;
	 *2.URL是作为请求发送目标的URL;
	 *3.async表示请求是以异步(true)还是同步(false)模式发出,
	 *  以同步模式发出请求会暂停所有javascript代码的执行.
	 */

	/*
	 *下一步是使用XMLHttpRequest对象的send()方法发送请求.
	 *该方法的参数是一个字符串(随请求一起发送的请求体).
	 *GET请求不包含任何信息,所以参数是null
	 */

	var tempRequest = this.request;
	/*
	 *若在request_readyStateChange()中使用"this.request",
	 *则由于this的引用对象发生改变,将出现bug.所以需定义变
	 *量tempRequest作为HttpRequest对象的属性request的引用
	 *("="的这种用法前面的代码中也出现过多次,即当右值是某
	 *个对象时,左值将是该对象的引用而不是其副本.同一个对象
	 *可以有多个引用,这点和Java一样.此处,this.request和
	 *tempRequest引用同一个XMLHttpRequest对象)
	 */

	// 定义闭包函数
	/*
	 *闭包函数只在其容器函数(此处是HttpRequest())内可见,
	 *可以访问容器函数的变量和参数
	 */
	function request_readyStateChange() {
		if (tempRequest.readyState == 4) {
			if (tempRequest.status == 200)
				function_callBack(tempRequest.responseText);
			// responseText属性接收服务器返回的信息,为纯文本
			/*
			 *XMLHttpRequest对象还有一个属性responseXML,用来
			 *将接收到的数据加载到XML DOM对象中(而responseText
			 *返回纯文本)
			 */
			else
				alert("Failed to contact the server");
		}
	}
	this.request.onreadystatechange = request_readyStateChange;
	// 绑定事件处理程序
}

HttpRequest.prototype.createXMLHttpRequest = function() {
	if (window.XMLHttpRequest) {
		var oHttp = new XMLHttpRequest();
		return oHttp;
	}
	else if (window.ActiveXObject) {
		var versions = ["MSXML2.XmlHttp.6.0", "MSXML2.XmlHttp.3.0"];

		for (var i = 0; i < versions.length; i++) {
			try {
				var oHttp = new ActiveXObject(versions[i]);
				return oHttp;
			}catch(error) {
				// do nothing
			}
		}
	}
	return null;
}

HttpRequest.prototype.send = function() {
	this.request.send(null);
}