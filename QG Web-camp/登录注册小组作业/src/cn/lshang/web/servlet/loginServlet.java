package cn.lshang.web.servlet;

import cn.lshang.dao.loginDao;
import cn.lshang.domain.resultInfo;
import cn.lshang.domain.user;
import cn.lshang.service.impl.userServiceImpl;
import cn.lshang.service.userService;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

@WebServlet("/loginServlet")
public class loginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //设置编码
        request.setCharacterEncoding("utf-8");

        //2.获取所有请求参数
        Map<String, String[]> map = request.getParameterMap();

        //3.创建user对象
        user loginUser = new user();
        //3.2使用beanUtils封装
        try {
            BeanUtils.populate(loginUser, map);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

        //4.调用LoginDao的login方法
        loginDao dao = new loginDao();
        user user = dao.login(loginUser);

        //5.判断user
        resultInfo info = new resultInfo();
        if(user == null){
            //登录失败
            info.setFlag(false);
            info.setErrorMsg("登录失败！用户名或密码错误！");
        }else{
            //登录成功
            info.setFlag(true);
            info.setData(user);
        }

        //将info序列化为json
        ObjectMapper mapper = new ObjectMapper();
        String json = mapper.writeValueAsString(info);

        //将json数据写回客户端
        //设置content-type
        response.setContentType("application/json;charset=utf-8");
        response.getWriter().write(json);


        /*//设置编码
        //response.setContentType("application/json;charset=utf-8");
        //设置编码
        //获取数据
        Map<String, String[]> map;
        map = request.getParameterMap();
        //封装对象
        user loginUser = new user();
        try {
            BeanUtils.populate(loginUser, map);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

        //调用service/dao完成注册
        loginDao dao = new loginDao();
        //System.out.println("loginUser:" + loginUser);
        //返回一个user对象
        user user = dao.login(loginUser);
        System.out.println("user:" + user);

        //响应结果
        if(user == null){
            resultInfo info = new resultInfo();
            //登录失败
            info.setFlag(false);
            info.setErrorMsg("注册失败");
            //request.getRequestDispatcher("/login.html").forward(request, response);

            //将info序列化为json
            ObjectMapper mapper = new ObjectMapper();
            String json = mapper.writeValueAsString(info);

            //将json数据写回客户端
            //设置content-type
            response.setContentType("application/json;charset=utf-8");
            response.getWriter().write(json);
        }else{
            //info.setFlag(true);
            //info.setErrorMsg("注册成功");
            //登录成功
            //存储数据
            //request.setAttribute("user", user);
            //转发
            request.getRequestDispatcher("/main.html").forward(request, response);
            //response.getWriter().out("<script>alert(\"账号或密码错误！\");</script>");
        }*/

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
