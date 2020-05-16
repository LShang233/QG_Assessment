package cn.lshang.dao.impl;

import cn.lshang.dao.articleDao;
import cn.lshang.domain.article;
import cn.lshang.domain.user;
import cn.lshang.util.jdbcUtil;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

public class articleDaoImpl implements articleDao {
    private JdbcTemplate template = new JdbcTemplate(jdbcUtil.getDataSource());

    /**
     * 添加文章
     * @param article
     * @return
     */
    @Override
    public boolean add(article article) {
        //定义sql
        String sql = "insert into article(id,title,article,tag,day)" +
                "values(?,?,?,?,?)";

        String now = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd"));

        //上传数据
        template.update(sql,
                article.getId(),
                article.getTitle(),
                article.getArticle(),
                article.getTag(),
                now);
        return true;
    }

    /**
     * 修改文章
     * @param article
     * @return
     */
    @Override
    public boolean change(article article) {
        //定义sql
        String sql = "update article set title=?,article=?,tag=? where articleID=?";
        //上传数据
        template.update(sql,
                article.getTitle(),
                article.getArticle(),
                article.getTag(),
                article.getArticleID());
        return true;
    }

    /**
     * 查找文章
     * @param articleID
     * @return
     */
    @Override
    public article findByAID(int articleID) {
        article article = null;
        try{
            //找用户
            String sql = "select * from article where articleID = ?";
            article = template.queryForObject(sql,
                    new BeanPropertyRowMapper<article>(article.class),
                    articleID);
        } catch (Exception e) {
            //找不到返回null
            return null;
        }
        //找到返回对象
        return article;
    }

    /**
     * 根据文章id删除
     * @param articleID
     */
    @Override
    public void delete(int articleID) {
        //定义sql
        String sql = "delete from article where articleID=?";
        //上传数据
        template.update(sql, articleID);
    }

    /**
     * 查找所有文章
     * @param id
     * @return
     */
    @Override
    public List<article> findAllByID(int id) {
        //使用JDBC操作数据库...
        //1.定义sql
        String sql = "select * from article where id=?";
        List<article> articles = template.query(sql,
                new BeanPropertyRowMapper<article>(article.class),
                id);

        return articles;
    }
}
