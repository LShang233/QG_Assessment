<%--
  Created by IntelliJ IDEA.
  User: lshan
  Date: 2020/5/4
  Time: 21:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>登录</title>
</head>

<body>

<a href="login.html">登录页面</a>
<a href="registered.html">注册页面</a>

      <form action="uploadHandleServlet" enctype="multipart/form-data" method="post">
          上传用户：<input type="text" name="username"><br/>
          上传文件1：<input type="file" name="file1"><br/>
          上传文件2：<input type="file" name="file2"><br/>
          <input type="submit" value="提交">
      </form>


</body>
</html>