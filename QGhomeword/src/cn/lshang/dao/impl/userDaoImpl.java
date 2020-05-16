package cn.lshang.dao.impl;

import cn.lshang.dao.userDao;
import cn.lshang.domain.user;
import cn.lshang.util.jdbcUtil;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class userDaoImpl implements userDao {

    private JdbcTemplate template = new JdbcTemplate(jdbcUtil.getDataSource());

    /**
     * 根据手机号找用户
     * @param phone
     * @return
     */
    @Override
    public user findByPhone(String phone) {
        user user = null;
        try{
            //找用户
            String sql = "select * from login where phone = ?";
            user = template.queryForObject(sql,
                    new BeanPropertyRowMapper<user>(user.class),
                    phone);
        } catch (Exception e) {
            //找不到返回null
            return null;
        }
        //找到返回user对象
        return user;
    }

    /**
     * 保存用户数据
     * @param user
     */
    @Override
    public void saveUser(user user) {
        //定义sql
        String sql = "insert into login(name,phone,email,password)" +
                "values(?,?,?,?)";
        //上传数据
        template.update(sql,
                user.getName(),
                user.getPhone(),
                user.getEmail(),
                user.getPassword());

    }

    /**
     * 根据id找用户
     * @param id
     * @return
     */
    @Override
    public user getUserById(String id) {
        user user = null;
        try{
            //找用户
            String sql = "select * from login where id = ?";
            user = template.queryForObject(sql,
                    new BeanPropertyRowMapper<user>(user.class),
                    id);

        } catch (Exception e) {
            //找不到返回null
            return null;
        }
        //找到返回user对象
        return user;
    }

    /**
     * 修改用户信息
     * @param user
     */
    @Override
    public void changeUser(user user) {
        //定义sql
        String sql = "update login set name=?,password=?,sex=?,age=?,status=? where id=?";
        //上传数据
        template.update(sql,
                user.getName(),
                user.getPassword(),
                user.getSex(),
                user.getAge(),
                user.getStatus(),
                user.getId());
    }
}
