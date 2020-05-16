package cn.lshang.service;

import cn.lshang.domain.article;

import java.util.List;

public interface articleService {

    boolean add(article article);

    boolean change(article article);

    article findByAID(article article);

    boolean delete(article article);

    List<article> findAllAriticleByID(article article);

}
