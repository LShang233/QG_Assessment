package cn.lshang.web.servlet;

import cn.lshang.dao.impl.userDaoImpl;
import cn.lshang.dao.loginDao;
import cn.lshang.dao.userDao;
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

@WebServlet("/getUserServlet")
public class getUserServlet extends HttpServlet {
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


        //4.调用userService的getUserById方法
        userService service = new userServiceImpl();
        user user = service.getUserById(loginUser);

        //5.判断user
        resultInfo info = new resultInfo();
        if(user == null){
            //登录失败
            info.setFlag(false);
            info.setErrorMsg("用户查询失败！");
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
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
