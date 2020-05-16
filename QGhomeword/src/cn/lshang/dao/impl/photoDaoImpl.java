package cn.lshang.dao.impl;

import cn.lshang.dao.photoDao;
import cn.lshang.domain.Photo;
import cn.lshang.domain.article;
import cn.lshang.util.jdbcUtil;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

public class photoDaoImpl implements photoDao {
    private JdbcTemplate template = new JdbcTemplate(jdbcUtil.getDataSource());

    /**
     * 添加至数据库
     * @param photo
     * @return
     */
    @Override
    public boolean add(Photo photo) {
        //定义sql
        String sql = "insert into photo(id,path,day)" +
                "values(?,?,?)";

        String now = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd"));

        //上传数据
        template.update(sql,
                photo.getId(),
                photo.getPath(),
                now);
        return true;
    }

    /**
     * 查询所有图片路径
     * @param id
     * @return
     */
    @Override
    public List<Photo> findAllByID(int id) {
        //使用JDBC操作数据库...
        //1.定义sql
        String sql = "select * from photo where id=?";
        List<Photo> photos = template.query(sql,
                new BeanPropertyRowMapper<Photo>(Photo.class),
                id);

        return photos;

    }

    /**
     * 删除照片
     * @param photoID
     * @return
     */
    @Override
    public boolean delete(int photoID) {
        //定义sql
        String sql = "delete from photo where photoID=?";
        //上传数据
        template.update(sql, photoID);
        return true;
    }


    /**
     * 修改头像路径
     * @param photo
     * @return
     */
    @Override
    public boolean change(Photo photo) {
        //定义sql
        String sql = "update login set head=? where id=?";
        //上传数据
        template.update(sql,
                photo.getPath(),
                photo.getId());
        return true;
    }
}
