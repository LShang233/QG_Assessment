if (document.querySelector(".main-header")) {
    //获取背景音乐
    music = document.getElementById("music");

    //控制背景音乐播放与暂停
    stopMusic = document.getElementById("music-controller-stop");
    startMusic = document.getElementById("music-controller-start");

    //点击暂停按钮开始播放
    startMusic.onclick = function () {
        music.pause();
        stopMusic.classList.remove("hidden");
        startMusic.classList.add("hidden");
    }
    //点击播放按钮暂停音乐
    stopMusic.onclick = function () {
        music.play();
        stopMusic.classList.add("hidden");
        startMusic.classList.remove("hidden");
    }

}

//创建放样式的div
let theme = document.createElement("div");
theme.setAttribute("id", "theme");
document.body.appendChild(theme);
//创建放样式的style
let style = document.createElement('style');
document.head.appendChild(style);
//主题的按钮
var themeButtom = document.getElementById("myTheme");

/* 雪主题 */
function snow() {
    //主题换色
    document.body.className = "theme-snow";

    //换背景图
    document.body.setAttribute("style", "background-image:url(\"images/snow.jpg\")");

    //创建theme的snow样式
    theme.setAttribute("style", "filter: drop-shadow(0 0 10px white);position: fixed;");

    //添加snow样式
    let snow = `.snow {
        position: absolute;
        width: 10px;
        height: 10px;
        background: white;
        border-radius: 50%;
    }
    `

    //往theme里添加snow
    for (let i = 1; i < 200; i++) {
        let NewSnow = document.createElement("div");

        let opacity = Math.random();
        let scale = parseInt((Math.random()) * 80 + 20) / 100;
        let x = (Math.random()) * 100;
        let time1 = parseInt((Math.random()) * 10 + 20);
        let time2 = parseInt((Math.random()) * 10 + 10);

        NewSnow.setAttribute("class", "snow");
        theme.appendChild(NewSnow);

        snow += `.snow:nth-child(${i}) {
            opacity:${opacity};
            transform: translate(${x}vw, -10px) scale(${scale});
            animation: fall-${i} ${time1}s -${time2}s linear infinite;
        }
        `


        // 为每一个newsnow创建@keyframes
        let percent = Math.random() * 50 + 30;
        let x1;
        if (Math.random() > 0.5) {
            x1 = x - (Math.random()) * 5;
        } else {
            x1 = x + (Math.random()) * 5;
        }
        let y1 = (Math.random()) * 60 + 30;
        let x2;
        if (Math.random() > 0.5) {
            x2 = (Math.random()) * 3 + x1;
        } else {
            x2 = x1 - (Math.random()) * 3;
        }


        snow += `@keyframes fall-${i}{
            ${percent}%{
                transform: translate(${x1}vw, ${y1}vh) scale(${scale});
            }
            to{
                transform: translate(${x2}vw, 100vh) scale(${scale});
            }
        }
        `

    }

    // 将 snow样式写入style内
    style.innerHTML = snow;


    //设置snow的背景音乐
    if (document.querySelector(".main-header")) {
        music.setAttribute("src", "music/snow.mp3");
    }


    //更新li
    if (themeButtom)
        themeButtom.innerHTML = "SNOW";
}


/** 夜晚 */
function night() {
    //主题换色
    document.body.className = "theme-night";

    //换背景图
    document.body.setAttribute("style", "background-image:url(\"images/night.jpg\")");

    //清空原本的样式
    theme.innerHTML = "";
    style.innerHTML = "";

    //设置snow的背景音乐
    if (document.querySelector(".main-header")) {
        music.setAttribute("src", "music/night.mp3");
    }


    //更新li
    themeButtom.innerHTML = "NIGHT";
}

/**白天 */
function day() {
    //主题换色
    document.body.className = "theme-day";

    //换背景图
    document.body.setAttribute("style", "background-image:url(\"images/day.jpg\")");

    //清空原本的样式
    theme.innerHTML = "";
    style.innerHTML = "";

    //设置snow的背景音乐
    if (document.querySelector(".main-header")) {
        music.setAttribute("src", "music/day.mp3");
    }


    //更新li
    themeButtom.innerHTML = "DAY";
}

/* 防止登录注册页面错误加载 */
if (themeButtom) {
    //按钮控制主题
    themeButtom.onclick = function () {
        if (this.innerHTML === "SNOW") {
            day();
        }
        else if (this.innerHTML === "DAY") {
            night();
        }
        else if (this.innerHTML === "NIGHT") {
            snow();
        }
        stopMusic.classList.add("hidden");
        startMusic.classList.remove("hidden");
    }


    let idData = location.search.split("&");
    id = idData[0].split("=")[1];//取出id
    document.getElementById("myID").innerHTML = id;//写入header

    /* header数据回填 */
    $ajax({
        method: "post",
        url: "getUserServlet",
        data: {
            id: id
        },
        success: function (result) {
            let obj = JSON.parse(result);
            if (obj.flag === true) {
                //写入数据
                
                /* 用户名 */
                document.getElementById("name").innerHTML = obj.data.name;
                /* 个性签名 */
                if (obj.data.status)
                    document.getElementById("signature").innerHTML = obj.data.status;
                /* 若用户有设置头像 */
                if (obj.data.head) {
                    let headI = document.querySelector(".header-main").getElementsByTagName("img")[0];
                    headI.setAttribute("src", obj.data.head);
                    if (document.getElementById("setHead")) {
                        /* 将路径写入头像框 */
                        let setI = document.querySelector(".setting-photo").getElementsByTagName("img")[0];
                        setI.setAttribute("src", obj.data.head);
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


    /* 带着id进行页面跳转 */
    document.getElementById("goToDiary").onclick = function () {
        window.location.href = `diary.html?id=${id}`;
    }
    document.getElementById("goToAlbum").onclick = function () {
        window.location.href = `album.html?id=${id}`;
    }
    document.getElementById("goToSetting").onclick = function () {
        window.location.href = `setting.html?id=${id}`;
    }
    /* diary页面增加文章跳转 */
    if (document.getElementById("new-article"))
        document.getElementById("new-article").onclick = function () {
            window.location.href = `newArticle.html?id=${id}`;
        }
}
