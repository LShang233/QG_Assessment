package cn.lshang.service.impl;

import cn.lshang.dao.impl.photoDaoImpl;
import cn.lshang.dao.photoDao;
import cn.lshang.domain.Photo;
import cn.lshang.service.photoService;

import java.util.List;

public class photoServiceImpl implements photoService {
    private photoDao photoDao = new photoDaoImpl();

    /**
     * 添加相片
     *
     * @param photo
     * @return
     */
    @Override
    public boolean addPhoto(Photo photo) {
        //添加数据库
        boolean flag = photoDao.add(photo);
        if (flag)
            return true;
        else
            return false;
    }

    /**
     * 通过id找图片
     * @param photo
     * @return
     */
    @Override
    public List<Photo> findAllPhotoByID(Photo photo) {
        //调用Dao完成查询
        return photoDao.findAllByID(photo.getId());
    }

    /**
     * 删除图片
     * @param photo
     * @return
     */
    @Override
    public boolean delete(Photo photo) {
        //添加数据库
        boolean flag = photoDao.delete(photo.getPhotoID());
        if (flag)
            return true;
        else
            return false;

    }

    /**
     * 添加修改头像
     * @param photo
     * @return
     */
    @Override
    public boolean addHeadPhoto(Photo photo) {
        //修改头像
        boolean flag = photoDao.change(photo);

        return flag;
    }
}
