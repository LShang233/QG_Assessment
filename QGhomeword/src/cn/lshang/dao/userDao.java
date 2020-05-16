package cn.lshang.dao;

import cn.lshang.domain.user;

public interface userDao {

    /**
     * 根据手机号找用户
     * @param phone
     * @return
     */
    public user findByPhone(String phone);

    /**
     * 保存用户信息
     * @param user
     */
    public void saveUser(user user);

    user getUserById(String id);

    void changeUser(user user);
}
