// 轮播图七张的地址
var imgArr = [
    { "path": "images/1.jpg" },
    { "path": "images/2.jpg" },
    { "path": "images/3.jpg" },
    { "path": "images/4.jpg" },
    { "path": "images/5.jpg" },
    { "path": "images/6.jpg" },
    { "path": "images/7.jpg" }
];
/**轮播图函数
 * 轮播七张图片
 */
function banner(imgArr) {
    var size = [
        { "top": 60, "left": 0, "width": 240, "height": 240, "zIndex": 1, "opacity": 0 },
        { "top": 60, "left": 0, "width": 240, "height": 240, "zIndex": 2, "opacity": 40 },
        { "top": 30, "left": 15, "width": 300, "height": 300, "zIndex": 3, "opacity": 70 },
        { "top": 0, "left": 35, "width": 360, "height": 360, "zIndex": 4, "opacity": 100 },
        { "top": 30, "left": 60, "width": 300, "height": 300, "zIndex": 3, "opacity": 70 },
        { "top": 60, "left": 80, "width": 240, "height": 240, "zIndex": 2, "opacity": 40 },
        { "top": 60, "left": 80, "width": 240, "height": 240, "zIndex": 1, "opacity": 0 }
    ];
    var banner = document.getElementById('banner');
    var cont = banner.firstElementChild || banner.firstChild; //按顺序添加图片
    var btnArr = banner.getElementsByTagName('div');
    var flag = true;
    var speed = 4000;

    // 左右移动按钮
    banner.onmouseover = function () {
        for (var i = 0; i < btnArr.length; i++) {
            btnArr[i].style.display = 'block';
        }
        clearInterval(banner.timer);
    }
    banner.onmouseout = function () {
        for (var i = 0; i < btnArr.length; i++) {
            btnArr[i].style.display = 'none';
        }
        banner.timer = setInterval(function () {
            move(true);
        }, speed);
    }

    //设置轮播图
    for (var i = 0; i < imgArr.length; i++) {
        var lis = document.createElement('li');
        var img = document.createElement('img');
        img.setAttribute("src", imgArr[i].path);
        lis.setAttribute("style", `top:${size[i].top}px;
                                    width:${size[i].width}px;
                                    height:${size[i].height}px;
                                    z-index:${size[i].zIndex};
                                    opacity:${size[i].opacity / 100}`);
        lis.appendChild(img);
        cont.appendChild(lis);
    }

    //移动
    var liArr = cont.children;
    move();
    banner.timer = setInterval(function () {
        move(true);
    }, speed);
    btnArr[1].onclick = function () {
        if (flag) {
            move(true);
        }
    }
    btnArr[0].onclick = function () {
        if (flag) {
            move(false);
        }
    }

    function move(bool) {
        if (bool != undefined) {
            if (bool) {
                size.unshift(size.pop());
            } else {
                size.push(size.shift());
            }
        }
        //旋转一次
        for (var i = 0; i < liArr.length; i++) {
            startMove(liArr[i], size[i], function () {
                flag = true;
            });
        }
    }
}
banner(imgArr);

/**
 * 轮播图特制动画效果
 * banner特制
 *
 * @param {*} node 节点
 * @param {*} cssObj 动画效果
 * @param {*} complete 回调函数
 */
function startMove(node, cssObj, complete) {
    //每一个节点一个定时器
    clearInterval(node.timer);
    node.timer = setInterval(function () {
        //假设所有动画都到目的值
        var isEnd = true;
        //遍历多个css样式
        for (var attr in cssObj) {
            var iTarget = cssObj[attr];
            //计算速度
            var iCur = null;
            if (attr == "opacity") {
                iCur = parseInt(parseFloat(getStyle(node, "opacity")) * 100);
                if (iTarget <= 1) iTarget *= 100;
            } else if (attr == "left") {
                var parent = parseInt(getStyle(node.parentElement, "width"));
                var child = parseInt(getStyle(node, attr));
                if (child == 0) {
                    iCur = 0;
                } else {
                    iCur = parseInt(node.style.left);
                }
            } else {
                iCur = parseInt(getStyle(node, attr));
            }

            var speed = (iTarget - iCur) / 8;

            speed = speed > 0 ? Math.ceil(speed) : Math.floor(speed);

            //透明度
            if (attr == "opacity") {
                iCur += speed;
                node.style.opacity = iCur / 100;
                node.style.filter = "alpha(opacity=" + iCur + ")";
            } else if (attr == "zIndex") {
                //z-index
                node.style[attr] = iTarget;
            } else if (attr == "left") {
                node.style[attr] = iCur + speed + '%';
            } else {
                node.style[attr] = iCur + speed + 'px';
            }

            //有一个不符合即未完成
            if (iCur != iTarget) {
                isEnd = false;
            }
        }

        //结束判断以及回调函数
        if (isEnd) {
            clearInterval(node.timer)
            if (complete) {
                complete.call(node);
            }
        }
    }, 30);
}
/**
 * 获取css（浏览器兼容）
 *
 * @param {*} node 节点
 * @param {*} attr 样式
 * @returns 该样式的数值
 */
function getStyle(node, attr) {
    return getComputedStyle ? getComputedStyle(node)[attr] : node.currentStyle[attr];
}



// 获取到浏览器顶部的距离
function getTop(e) {
    return e.offsetTop;
}

/* 上传图片框 */
document.getElementById("pID").value = id;
let addPDiv = document.querySelector(".addPDiv");
document.getElementById("new-photo").onclick = function () {
    if (addPDiv.className == "addPDiv hidden") {
        addPDiv.classList.remove("hidden");
    }
}
document.getElementById("closeAP").onclick = function () {
    addPDiv.classList.add("hidden");
}

/* 获取路径 */
//懒加载时所有图片对应的路径
var imgsPath = new Array();
//对应日期
var imgsDay = new Array();
/* 获取数据 */
$ajax({
    method: "post",
    url: "getPhotoServlet",
    data: {
        id: id
    },
    success: function (result) {
        let obj = JSON.parse(result);
        if (obj.flag === true) {
            let bannerImgs = document.querySelector(".banner-ul").getElementsByTagName("img");

            for (var j = 0; j < obj.data.length; j++) {
                if (j < 7) bannerImgs[j].setAttribute("src", obj.data[j].path);
                imgsPath[j] = obj.data[j].path;
                imgsDay[j] = obj.data[j].day;
            }

            let nowDay = "";
            let photosByDay = ""
            /* 根据day写标签 */
            let i = 0;
            while (i < imgsDay.length) {
                /* 循环每个日期 */
                if (imgsDay[i] != nowDay) {
                    nowDay = imgsDay[i];
                    photosByDay = photosByDay + `
                    <p class="album-day">${nowDay}</p>
                    <div class="albums">`;
                    /* 循环添加单个照片 */
                    while (imgsDay[i] == nowDay && i < imgsDay.length) {
                        photosByDay = photosByDay + `
                        <div class="album">
                            <div class="album-photo">
                                <img src="images/loading.jpg" class="oPhoto">
                                <div class="dePhoto">
                                    <p class="photoID hidden">${obj.data[i].photoID}</p>
                                    删除
                                </div>
                            </div>
                        </div>
                    `;
                        i++;
                    }
                    photosByDay = photosByDay + `</div>`;
                }

            }
            /* 插入页面 */
            document.getElementById("albums-main").innerHTML = photosByDay;




            // 获取图片列表
            var imgs = document.getElementById("albums-main").getElementsByTagName("img");

            // 懒加载实现
            function lazyLoad(imgs) {
                // 可视区域高度
                let h = window.innerHeight;
                //滚动区域高度
                let s = document.documentElement.scrollTop || document.body.scrollTop;

                for (var i = 0; i < imgs.length; i++)
                    //图片距离顶部的距离小于可视区域和滚动区域之和时懒加载
                    if ((h + s) > getTop(imgs[i]))
                        imgs[i].setAttribute("src", imgsPath[i]);
            }
            lazyLoad(imgs);

            // 滚屏函数
            window.onscroll = function () {
                lazyLoad(imgs);
            }

            //鼠标移入放大
            //查看图片


            let photos = document.querySelectorAll(".oPhoto");
            let see = document.querySelector(".see-photo");
            let seeDiv = document.querySelector(".see-div");
            let seePhoto = see.getElementsByTagName("img")[0];

            for (let i = 0; i < photos.length; i++) {
                photos[i].onclick = function () {
                    //设置图片
                    seePhoto.setAttribute("src", imgsPath[i]);
                    //显示section
                    see.classList.remove("hidden")
                    //放大显示
                    let h = parseInt(getStyle(seeDiv, "height"));
                    seePhoto.style.height = "0"
                    startMove(seePhoto, { "height": h }, null);
                }
            }

            see.onclick = function () {
                //隐藏section
                see.classList.add("hidden")
            }


            /* 删除图片 */
            let dePhoto = document.querySelectorAll(".dePhoto");
            for (let i = 0; i < dePhoto.length; i++) {
                dePhoto[i].onclick = function() {
                    /* 获取图片id */
                    let PID = dePhoto[i].querySelector(".photoID").innerHTML;
                    
                    /* 进行删除 */
                    $ajax({
                        method: "post",
                        url: "dePhotoServlet",
                        data: {
                            photoID: PID,
                        },
                        success: function (result) {
                            let obj = JSON.parse(result);
                            if (obj.flag) {
                                /* 刷新页面 */
                                alert(obj.errorMsg);
                                //window.location.href = `album.html?id=${id}`;
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


        } else {
            alert(obj.errorMsg);
        }
    },
    error: function (msg) {
        let obj = JSON.parse(msg);
        alert(obj.errorMsg);
    }
})




