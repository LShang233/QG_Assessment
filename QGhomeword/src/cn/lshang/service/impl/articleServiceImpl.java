package cn.lshang.service.impl;

import cn.lshang.dao.articleDao;
import cn.lshang.dao.impl.articleDaoImpl;
import cn.lshang.domain.article;
import cn.lshang.service.articleService;

import java.util.List;

public class articleServiceImpl implements articleService {
    private articleDao articleDao = new articleDaoImpl();

    /**
     * 添加文章
     * @param article
     * @return
     */
    @Override
    public boolean add(article article) {
        //添加至数据库
        boolean flag = articleDao.add(article);
        if (flag) return true;
        else return false;
    }

    /**
     * 修改文章
     * @param article
     * @return
     */
    @Override
    public boolean change(article article) {
        //修改文章
        boolean flag = articleDao.change(article);
        if (flag) return true;
        else return false;
    }

    /**
     * 根据文章id查找文章
     * @param article
     * @return
     */
    @Override
    public article findByAID(article article) {
        article myArticle = articleDao.findByAID(article.getArticleID());

        return myArticle;
    }

    /**
     * 删除文章
     * @param article
     * @return
     */
    @Override
    public boolean delete(article article) {
        articleDao.delete(article.getArticleID());
        return true;
    }

    @Override
    public List<article> findAllAriticleByID(article article) {
        //调用Dao完成查询
        return articleDao.findAllByID(article.getId());
    }
}
