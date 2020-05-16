package cn.lshang.dao;

import cn.lshang.domain.Photo;

import java.util.List;

public interface photoDao {
    /**
     * 添加至数据库
     * @param photo
     * @return
     */
    boolean add(Photo photo);

    /**
     * 通过id找文章
     * @param id
     * @return
     */
    List<Photo> findAllByID(int id);

    /**
     * 删除图片
     * @param photoID
     * @return
     */
    boolean delete(int photoID);

    boolean change(Photo photo);
}
