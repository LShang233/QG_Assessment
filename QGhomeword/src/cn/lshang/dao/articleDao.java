package cn.lshang.dao;

import cn.lshang.domain.article;

import java.util.List;

public interface articleDao {


    boolean add(article article);

    boolean change(article article);

    article findByAID(int articleID);

    void delete(int articleID);

    List<article> findAllByID(int id);
}
