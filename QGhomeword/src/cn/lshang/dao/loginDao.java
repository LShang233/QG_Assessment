package cn.lshang.dao;

import cn.lshang.domain.user;
import cn.lshang.util.jdbcUtil;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class loginDao {
    //声明jdbcTemplate对象共用
    private JdbcTemplate template = new JdbcTemplate(jdbcUtil.getDataSource());

    /**
     * 登录方法
     * @param loginUser 只有用户名和密码
     * @return 包含用户全部数据
     */
    public user login(user loginUser){
        try {
            //1.编写sql
            String sql = "select * from login where phone = ? and password = ?";
            //2.调用query方法
            user user = template.queryForObject(sql,
                    new BeanPropertyRowMapper<user>(cn.lshang.domain.user.class),
                    loginUser.getPhone(),
                    loginUser.getPassword());
            return user;
        } catch (DataAccessException e) {
            e.printStackTrace();
            return null;
        }
    }
}
