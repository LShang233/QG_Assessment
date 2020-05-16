//注册页面判断与上传

//获取提示框
let tips = document.getElementById("tips");


//获取input数据
let zhuce = document.getElementById("zhuce");
let data = zhuce.getElementsByTagName("input");
//获取注册按钮
let registere = document.getElementById("registere");

//用户名判断
data[0].onblur = function () {
    if (!data[0].value) {
        tips.innerHTML = "请输入用户名！";
    } else {
        tips.innerHTML = "";
    }
}

//判断手机号是否正确
data[1].onblur = function () {
    isphonenum(this.value);
}

//判断邮箱
data[2].onblur = function () {
    isemail(this.value);
}

//判断密码是否符合
let closeeye = document.getElementById("closeeye");
data[3].onblur = function () {
    ispassword(this.value);
    closeeye.setAttribute("src", "images/img.jpg");
}

data[3].onclick = function () {
    closeeye.setAttribute("src", "images/img2.png");
}

//验证码
let img = document.getElementById("codeImg");
img.onclick = function () {
    let data = new Date().getTime();
    img.src = `CheckCodeServlet?${data}`;
}
let checkCode = document.getElementById("checkCode");
checkCode.onblur = function () {
    if (!checkCode.value) {
        tips.innerHTML = "验证码为空！";
    }
}

//成功就上传
registere.onclick = function () {
    if (data[0].value) {
        if (isphonenum(data[1].value))
            if (isemail(data[2].value))
                if (ispassword(data[3].value))
                    if (checkCode.value) {
                        tips.innerHTML = "";
                        //tips.innerHTML = "success"
                        //上传
                        $ajax({
                            method: "post",
                            url: "registerServlet",
                            data: {
                                //username为手机号
                                name: data[0].value,
                                password: data[3].value,
                                phone: data[1].value,
                                email: data[2].value,
                                checkCode: checkCode.value
                            },
                            success: function (result) {
                                let obj = JSON.parse(result);
                                if (obj.flag === true) {
                                    alert("注册成功！");
                                    window.location.href = "login.html";
                                } else {
                                    alert(obj.errorMsg);
                                    let data = new Date().getTime();
                                    img.src = `CheckCodeServlet?${data}`;
                                }

                            },
                            error: function (msg) {
                                let obj = JSON.parse(msg);
                                alert(obj.errorMsg);
                                let data = new Date().getTime();
                                img.src = `CheckCodeServlet?${data}`;

                            }
                        })
                    }
    }
}



/* 加载主题 */
snow();

function ispassword(password) {
    let num = /^.{8,16}$/;
    if (!num.test(password)) {
        tips.innerHTML = "请输入8-16位的密码！"
    } else {
        num = /^[0-9a-zA-Z_]{8,16}$/ig;
        if (!num.test(password)) {
            tips.innerHTML = "非法字符输入！只支持数字、英文以及‘_’"
        } else {
            tips.innerHTML = "";
            return true;
        }
    }
}

function isemail(emailvalue) {
    var num = /^([a-zA-Z\d])(\w|\-)+@[a-zA-Z\d]+\.[a-zA-Z]{2,4}$/;
    if (!num.test(emailvalue)) {
        tips.innerHTML = "请输入正确邮箱!";
    } else {
        tips.innerHTML = "";
        return true;
    }
}

function isphonenum(phonenum) {
    var num = /^1\d{10}$/;
    if (!num.test(phonenum)) {
        tips.innerHTML = "请输入正确手机号!";
    } else {
        tips.innerHTML = "";
        return true;
    }
}