//添加diary页面的样式
if (document.getElementById("articles")) {
    document.querySelector(".main").classList.add("main-left");
    document.querySelector(".main-header").classList.add("shadow");
    var mainA = document.getElementById("articles");
    var searchMain = document.querySelector(".search-article");
}

let mainFlag = false;

//根据id写入文章
$ajax({
    method: "post",
    url: "getAllArticleServlet",
    data: {
        id: id
    },
    success: function (result) {
        let obj = JSON.parse(result);
        if (obj.flag && obj.data.length) {
            /* 回写数据 */
            let articles = obj.data;
            let tagArray = new Array();
            let arrI = 0;
            searchMain.innerHTML = "";
            mainA.innerHTML = "";

            /* 插入正文以及搜索栏内容 */
            for (let i = 0; i < articles.length; i++) {


                /* 插入文章 */
                let article = `
                <article class="article">
                    <header class="article-header">
                        <h1>
                            <p class="article-title">${articles[i].title}</p>
                        </h1>
                        <a>${articles[i].day}</a>
                    </header>
    
                    <div class="article-body article-close">
                        <p>${articles[i].article}</p>
                    </div>
                    <a class="article-more">more&gt;&gt;</a>
                    <div class="article-tags">
                        <svg viewBox="0 0 17 16">
                            <g stroke="none" stroke-width="1" fill-rule="evenodd">
                                <path
                                    d="M5.546,15.951 C5.037,16.46 5.031,10.969 5.031,10.969 C5.031,10.969 -0.462,10.962 0.0480000001,10.453 L10.061,0.439 C10.569,-0.069 11.418,-0.045 11.957,0.492 L15.507,4.043 C16.046,4.582 16.068,5.431 15.561,5.939 L5.546,15.951 L5.546,15.951 Z">
                                </path>
                            </g>
                        </svg>
                        <ul class="article-tag">
                        <p class="hidden article-id">${articles[i].articleID}</p>`;
                /* 标签 */
                let tags = "";
                let tag = articles[i].tag.split("，");
                for (let j = 0; j < tag.length; j++) {
                    tags = tags + "<li><a href=\"#\">" + tag[j] + "</a></li>";
                    /* 添加进总标签 */
                    for (var k = 0; k < tagArray.length; k++) {
                        if (tagArray[k] == tag[j]) {
                            break;
                        }
                    }
                    if (k == tagArray.length) tagArray.push(tag[j]);
                }

                article = article + tags + `</ul>
                        <span class="article-change">编辑</span>
                    </div>
                </article>
                 `;
                /* 插入页面 */
                mainA.innerHTML = article + mainA.innerHTML;



                /* 插入搜索栏 */
                let mySearch = ` <li>
                    <div class="search-title">${articles[i].title}</div>
                    <div class="search-article-tags">
                    <div class="search-day">${articles[i].day}</div>
                        <svg viewBox="0 0 17 16">
                            <g stroke="none" stroke-width="1" fill="white" fill-rule="evenodd">
                                <path
                                    d="M5.546,15.951 C5.037,16.46 5.031,10.969 5.031,10.969 C5.031,10.969 -0.462,10.962 0.0480000001,10.453 L10.061,0.439 C10.569,-0.069 11.418,-0.045 11.957,0.492 L15.507,4.043 C16.046,4.582 16.068,5.431 15.561,5.939 L5.546,15.951 L5.546,15.951 Z">
                                </path>
                            </g>
                        </svg>`;
                tags = "";
                for (let j = 0; j < tag.length; j++) {
                    tags = tags + "<span class=\"search-article-tag\">" + tag[j] + "</span>";
                }
                mySearch = mySearch + tags + ` </div>
                </li>
                `;
                /* 插入页面 */
                searchMain.innerHTML = mySearch + searchMain.innerHTML;

            }


            /* 标签写入搜索栏 */
            let searchAllTag = document.querySelector(".search").querySelector(".article-tag");
            let taggs = "";
            for (let j = 0; j < tagArray.length; j++) {
                taggs = taggs + "<li><a href=\"#\">" + tagArray[j] + "</a></li>";
            }
            /* 插入页面 */
            searchAllTag.innerHTML = taggs;




            //获取输入框内容
            let searchInput = document.getElementById("search-input");
            //获取search的标题
            let searchTitle = document.querySelectorAll(".search-title");
            //获取正文模块
            let articleA = document.querySelectorAll(".article");
            //获取搜索栏所有的标签
            let tagsA = document.querySelectorAll(".search-article-tags");


            //搜索用户在输入框的内容
            searchInput.onkeyup = function () {
                for (let i in searchTitle) {
                    if (searchTitle[i].innerHTML) {
                        //对标题进行关键字切割，如果字符串长度大于1，说明搜索到了
                        let str = searchTitle[i].innerHTML.split(searchInput.value);

                        if (str.length > 1) {
                            searchTitle[i].parentElement.classList.remove("hidden");
                        } else {
                            searchTitle[i].parentElement.classList.add("hidden");
                        }
                    }
                }
            }



            //遍历每一个标题对应的tags,放在tagsValue
            let tagsValue = new Array();
            for (let i in tagsA) {
                if (tagsA[i].innerHTML) {
                    let str = "";
                    //每个标题对应的单个tag
                    let tagA = tagsA[i].getElementsByTagName("span");

                    for (let j in tagA) {
                        if (tagA[j].innerHTML)
                            str += `#${tagA[j].innerHTML}`;
                    }
                    tagsValue[i] = str;
                }
            }


            //标签搜索
            let articleTags = document.querySelectorAll(".article-tag");
            for (let k = 0; k < articleTags.length; k++) {
                let articleTag = articleTags[k].getElementsByTagName("li");

                for (let i = 0; i < articleTag.length; i++) {
                    if (articleTag[i] != undefined)
                        articleTag[i].onclick = function () {
                            let search = `#${this.getElementsByTagName("a")[0].innerHTML}`;
                            //输入框内填写标签内容
                            searchInput.value = `${search}`;
                            //搜索
                            for (let i in tagsValue) {
                                if (tagsValue[i]) {
                                    //对关键字切割，如果字符串长度大于1，说明搜索到了
                                    var str = tagsValue[i].split(search);
                                    if (searchTitle[i] != undefined) {
                                        if (str.length > 1) {
                                            searchTitle[i].parentElement.classList.remove("hidden");
                                        } else {
                                            searchTitle[i].parentElement.classList.add("hidden");
                                        }
                                    }
                                }
                            }
                        }
                }
            }

            //搜索文章
            for (let i = 0; i < searchTitle.length; i++) {
                //点击搜索栏标题
                searchTitle[i].onclick = function () {
                    let searchTitleValue = this.innerHTML;
                    //遍历所有文章标题
                    for (let j = 0; j < articleA.length; j++) {
                        let title = articleA[j].querySelector(".article-title").innerHTML;
                        //匹配显示
                        if (searchTitleValue === title) {
                            articleA[j].classList.remove("hidden");
                        } else {
                            articleA[j].classList.add("hidden");
                        }
                    }
                }
            }

            //显示所有文章
            let tagSvgs = document.querySelectorAll(".article-tags");
            for (let i = 0; i < tagSvgs.length; i++) {
                let tagSvg = tagSvgs[i].getElementsByTagName("svg")[0];

                tagSvg.onclick = function () {
                    for (let j = 0; j < articleA.length; j++) {
                        articleA[j].classList.remove("hidden");
                    }
                }
            }



            //展开隐藏
            for (let i = 0; i < articleA.length; i++) {
                articleA[i].querySelector(".article-more").onclick = function () {
                    let articleClass = articleA[i].querySelector(".article-body").classList;
                    if (articleClass == "article-body article-close") {
                        //页面展开
                        articleClass.toggle("article-close");
                        //修改提示
                        articleA[i].querySelector(".article-more").innerHTML = "&lt;&lt; close"
                    } else {
                        //页面关上
                        articleClass.toggle("article-close");
                        //修改提示
                        articleA[i].querySelector(".article-more").innerHTML = "more&gt;&gt;"
                    }
                }
            }

            //修改的页面跳转
            //增加跳转在theme.js
            let articleChange = document.querySelectorAll(".article-change");
            for (let i = 0; i < articleChange.length; i++) {
                articleChange[i].onclick = function () {
                    /* 获取文章id */
                    let artiID = this.parentElement.querySelector(".article-id").innerHTML;
                    console.log(artiID);
                    /* 页面跳转 */
                    window.location.href = `newArticle.html?id=${id}&articleID=${artiID}`;
                }
            }


        } else {
            alert(obj.errorMsg);
        }
    },
    error: function (msg) {
        let obj = JSON.parse(result);
        alert(obj.errorMsg);
    }
})







