/* 获取文章的输入框 */
let odiv = document.querySelector(".newAritcle").getElementsByTagName("div");
let tag = document.querySelector(".newAritcle-tag");
/* 获取按钮 */
/* 上传 */
let update = document.querySelector(".newAritcle-submit");
/* 删除 */
let de = document.querySelector(".newAritcle-distroy");

/* 找到文章id，未找到设置articleID为0 */
let idData = location.search.split("&");
let articleID = 0;
if (idData[1])
    articleID = idData[1].split("=")[1];//取出articleID

/* 判断是修改还是添加 */
/* 若为添加，隐藏删除按钮 */
if (articleID == 0) {
    document.querySelector(".newAritcle-distroy").classList.add("hidden");
}
/* 回写数据 */
if (articleID != 0) {
    $ajax({
        method: "post",
        url: "searchArticleServlet",
        data: {
            articleID: articleID
        },
        success: function (result) {
            let obj = JSON.parse(result);

            if (obj.flag) {
                /* 回写数据 */
                //console.log(obj.data);
                odiv[0].innerHTML = obj.data.title;
                odiv[1].innerHTML = obj.data.article;
                tag.value = obj.data.tag;

            } else {
                alert(obj.errorMsg);
            }
        },
        error: function (msg) {
            let obj = JSON.parse(result);
            alert(obj.errorMsg);
        }
    })
}



/* 简单表单验证,上传 */
update.onclick = function () {
    if (!odiv[0].innerHTML) {
        alert("标题不能为空！");
    } else if (!odiv[1].innerHTML) {
        alert("正文不能为空！");
    } else if (tag.value == "") {
        alert("标签不能为空！");
    } else {
        /* 上传至后台 */
        $ajax({
            method: "post",
            url: "newArticleServlet",
            data: {
                title: odiv[0].innerHTML,
                article: odiv[1].innerHTML,
                id: id,
                tag: tag.value,
                articleID: articleID,
            },
            success: function (result) {
                let obj = JSON.parse(result);
                //console.log(obj)
                if (obj.flag) {
                    alert(obj.errorMsg);
                    window.location.href = `diary.html?id=${id}`;

                } else {
                    alert(obj.errorMsg);
                }
            },
            error: function (msg) {
                let obj = JSON.parse(result);
                alert(obj.errorMsg);
            }
        })
    }
}

/* 删除 */
de.onclick = function () {
    /* 弹出提示框 */
    var msg = "您确定要删除该文章吗？";
    if (confirm(msg) == true) {
        $ajax({
            method: "post",
            url: "deArticleServlet",
            data: {
                articleID: articleID
            },
            success: function (result) {
                let obj = JSON.parse(result);
                //console.log(obj)
                if (obj.flag) {
                    alert(obj.errorMsg);
                    window.location.href = `diary.html?id=${id}`;

                } else {
                    alert(obj.errorMsg);
                }
            },
            error: function (msg) {
                let obj = JSON.parse(result);
                alert(obj.errorMsg);
            }
        })

    } else {
        return false;
    }


}