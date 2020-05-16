package cn.lshang.service;

import cn.lshang.domain.Photo;

import java.util.List;

public interface photoService {
    /**
     * 上传照片
     * @param photo
     * @return
     */
    boolean addPhoto(Photo photo);

    /**
     * 通过id找图片
     * @param photo
     * @return
     */
    List<Photo> findAllPhotoByID(Photo photo);

    boolean delete(Photo photo);

    /**
     * 添加修改头像
     * @param photo
     * @return
     */
    boolean addHeadPhoto(Photo photo);
}
