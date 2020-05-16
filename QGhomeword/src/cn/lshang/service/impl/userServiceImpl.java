package cn.lshang.service.impl;

import cn.lshang.dao.impl.userDaoImpl;
import cn.lshang.dao.userDao;
import cn.lshang.domain.user;
import cn.lshang.service.userService;

public class userServiceImpl implements userService {
    private userDao userDao = new userDaoImpl();

    @Override
    public boolean register(user user) {
        //获取用户数据
        user u = userDao.findByPhone(user.getPhone());
        if (u != null) {
            //找到说明注册过
            return false;
        }
        //保存数据，注册成功
        userDao.saveUser(user);
        return true;
    }

    @Override
    public user getUserById(user user) {
        //获取用户数据
        user u = userDao.getUserById(user.getId());
        return u;
    }

    @Override
    public boolean changeUser(user user) {
        //获取用户数据
        user u = userDao.getUserById(user.getId());
        if (u == null) {
            //找不到用户
            return false;
        }
        //修改数据
        userDao.changeUser(user);
        return true;
    }
}
