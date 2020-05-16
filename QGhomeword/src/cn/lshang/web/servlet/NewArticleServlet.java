package cn.lshang.web.servlet;

import cn.lshang.domain.article;
import cn.lshang.domain.resultInfo;
import cn.lshang.domain.user;
import cn.lshang.service.articleService;
import cn.lshang.service.impl.articleServiceImpl;
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
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Map;

@WebServlet("/newArticleServlet")
public class NewArticleServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //设置编码
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        //response.setContentType("text/html;charset=UTF-8");

        //1.获取数据
        Map<String, String[]> map = request.getParameterMap();

        //2.封装对象
        article article = new article();
        try {
            BeanUtils.populate(article,map);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

        resultInfo info = new resultInfo();

        //3.调用service
        articleService service = new articleServiceImpl();
        if (article.getArticleID() == 0) {
            // 增加
            boolean flag = service.add(article);
            //4.响应结果
            if(flag){
                //添加成功
                info.setFlag(true);
                info.setErrorMsg("添加成功!");
            }else{
                //注册失败
                info.setFlag(false);
                info.setErrorMsg("添加失败！");
            }
        } else {
            //修改
            boolean flag = service.change(article);
            //4.响应结果
            if(flag){
                //成功
                info.setFlag(true);
                info.setErrorMsg("修改成功!");
            }else{
                //失败
                info.setFlag(false);
                info.setErrorMsg("修改失败！");
            }
        }

        //将info对象序列化为json
        ObjectMapper mapper = new ObjectMapper();
        String json = mapper.writeValueAsString(info);

        //将json数据写回客户端
        //设置content-type
        //response.setContentType("application/json;charset=utf-8");
        response.getWriter().write(json);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
