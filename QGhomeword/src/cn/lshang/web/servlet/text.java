package cn.lshang.web.servlet;

import cn.lshang.dao.loginDao;
import cn.lshang.domain.Photo;
import cn.lshang.domain.resultInfo;
import cn.lshang.domain.user;
import cn.lshang.service.impl.photoServiceImpl;
import cn.lshang.service.photoService;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadBase;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.lang.reflect.InvocationTargetException;
import java.util.List;
import java.util.Map;
import java.util.UUID;

@WebServlet("/text")
public class text extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.sendRedirect("diary.html");


    }



//} catch(FileUploadBase.FileSizeLimitExceededException e){
//        e.printStackTrace();
//        info.setFlag(false);
//        info.setErrorMsg("单个文件超出最大值！！！");
//        return;
//        }catch(FileUploadBase.SizeLimitExceededException e){
//        e.printStackTrace();
//        info.setFlag(false);
//        info.setErrorMsg("上传文件的总的大小超出限制的最大值！！！");
//        return;
//        }catch(Exception e){
//        info.setFlag(false);
//        info.setErrorMsg("文件上传失败！");
//        e.printStackTrace();
//        }
//
//        //将info序列化为json
//        ObjectMapper mapper=new ObjectMapper();
//        String json=mapper.writeValueAsString(info);
//
//        //将json数据写回客户端
//        //设置content-type
//        response.setContentType("application/json;charset=utf-8");
//        response.getWriter().write(json);
//
//        }

            private String makeFileName (String filename){ //2.jpg
                //为防止文件覆盖的现象发生，要为上传文件产生一个唯一的文件名
                return UUID.randomUUID().toString() + "_" + filename;
            }


            private String makePath (String filename, String savePath, Photo photo){
                //得到文件名的hashCode的值，得到的就是filename这个字符串对象在内存中的地址
                int hashcode = filename.hashCode();
                int dir1 = hashcode & 0xf; //0--15
                int dir2 = (hashcode & 0xf0) >> 4; //0-15
                //构造新的保存目录
                String dir = savePath + "\\" + dir1 + "\\" + dir2;  //upload\2\3  upload\3\5
                //存入photo
                String dirs = "./img" + "/" + dir1 + "/" + dir2 + "/" + filename; //upload\2\3  upload\3\5
                photo.setPath(dirs);
                //File既可以代表文件也可以代表目录
                File file = new File(dir);
                //如果目录不存在
                if (!file.exists()) {
                    //创建目录
                    file.mkdirs();
                }
                return dir;
            }


            protected void doGet (HttpServletRequest request, HttpServletResponse response)throws
            ServletException, IOException {
                this.doPost(request, response);
            }
        }
