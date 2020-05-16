package cn.lshang.service;

import cn.lshang.domain.user;

public interface userService {
    /**
     * 注册用户
     * @param user
     * @return
     */
    boolean register(user user);

    user getUserById(user user);

    boolean changeUser(user user);
}
