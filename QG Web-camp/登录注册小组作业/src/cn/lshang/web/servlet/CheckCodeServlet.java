package cn.lshang.web.servlet;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

@WebServlet("/CheckCodeServlet")
public class CheckCodeServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //服务器通知浏览器不要缓存
        response.setHeader("pragma","no-cache");
        response.setHeader("cache-control","no-cache");
        response.setHeader("expires","0");

        int height = 30;
        int width = 100;

        //1.创建一对象
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        //2.美化图片
        //填充背景色
        Graphics g = image.getGraphics();//画笔对象
        g.setColor(Color.PINK);//设置画笔颜色
        g.fillRect(0, 0, width, height);
        //画边框
        g.setColor(Color.black);
        g.drawRect(0,0,width-1,height-1);
        //写验证码
        String str = "ABCDEFGHJKLMNOPQRSTUVWXYZqwertyuiopkjhgfdsazxcvbnm234567890";

        //生成随机角标
        Random ran = new Random();
        //将验证码存进session
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= 4; i++){
            int index = ran.nextInt(str.length());
            //获取字符
            char ch = str.charAt(index);
            sb.append(ch);

            g.drawString(ch+"",width / 5 * i,height / 2);
        }
        String check_Code = sb.toString();
        //将验证码放进session
        request.getSession().setAttribute("check_Code", check_Code);

        //划线
        g.setColor(Color.GREEN);
        //随机生成线
        for(int i = 0; i < 5; i ++){
            int x1 = ran.nextInt(width);
            int x2 = ran.nextInt(width);
            int y1 = ran.nextInt(height);
            int y2 = ran.nextInt(height);
            g.drawLine(x1,y1,x2,y2);
        }



        //3.将图片输出到页面
        ImageIO.write(image, "jpg", response.getOutputStream());
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}
