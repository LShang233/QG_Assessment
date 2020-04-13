//登录注册页面转换
function login() {
    let logIn = document.getElementById("logIn");
    let rege = document.getElementById("rege");
    let registered = document.getElementById("registered");
    let log = document.getElementById("log");
    rege.onclick = function () {
        logIn.setAttribute("style", "display:none");
        registered.setAttribute("style", "display:inline")
    }
    log.onclick = function () {
        logIn.setAttribute("style", "display:inline")
        registered.setAttribute("style", "display:none");
    }
}
login();

//登录
function issuccesslogin() {
    //获取内容
    let logininput = document.getElementById("logininput");
    data = logininput.getElementsByTagName("input");
    //获取按钮
    let loginbuttom = document.getElementById("loginbuttom");
    
    loginbuttom.onclick = function () {
        //登录
        $ajax({
            method: "post",
            url: "http://recruit.qgailab.com/ajax/login",
            data: {
                username: data[0].value,
                password: data[1].value,
            },
            success: function (result) {
                //alert(result);
                var obj = JSON.parse(result);
                alert(obj.message);
            },
            error: function (msg) {
                alert(msg);
            }
        })
    }
}
issuccesslogin();

//注册页面判断与上传
function issuccess() {
    //获取input数据
    let zhuce = document.getElementById("zhuce");
    let data = zhuce.getElementsByTagName("input");
    //获取同意协议按钮
    let agree = document.getElementById("agree");
    //获取注册按钮
    let registere = document.getElementById("registere");

    //判断手机号是否正确
    data[1].onblur = function () {
        isphonenum(this.value);
    }

    //判断邮箱
    data[2].onblur = function () {
        isemail(this.value);
    }

    //判断密码是否符合
    data[3].onblur = function () {
        ispassword(this.value);
        let closeeye = document.getElementById("closeeye");
        closeeye.setAttribute("src", "images//img.jpg");
    }

    data[3].onclick = function () {
        let closeeye = document.getElementById("closeeye");
        closeeye.setAttribute("src", "images//img2.png");
    }

    //成功就上传
    registere.onclick = function () {
        if (!data[0].value) {
            alert("请输入用户名！")
        } else {
            if (isphonenum(data[1].value))
                if (isemail(data[2].value))
                    if (ispassword(data[3].value))
                        if (!agree.checked)
                            alert("请同意《xxx协议》！");
                        else {
                            //上传
                            $ajax({
                                method: "post",
                                url: "http://recruit.qgailab.com/ajax/register",
                                data: {
                                    //username为手机号
                                    username: data[1].value,
                                    password: data[3].value,
                                    phone: data[1].value,
                                    email: data[2].value,
                                    name: data[0].value
                                },
                                success: function (result) {
                                    //alert(result);
                                    var obj = JSON.parse(result);
                                    alert(obj.message);
                                },
                                error: function (msg) {
                                    alert(msg);
                                }
                            })
                        }
        }


    }

}
issuccess();

//agree控制注册按钮颜色
function regis() {
    let agree = document.getElementById("agree");
    agree.onclick = function () {
        let registere = document.getElementById("registere");
        if (this.checked) {
            registere.style.backgroundColor = "rgb(85, 111, 181)";
        } else {
            registere.style.backgroundColor = "rgba(85, 111, 181, .7)";
        }
    }
}

function ispassword(password) {
    var num = /^.{8,16}$/;
    if (!num.test(password)) {
        alert("请输入8-16位的密码！");
    } else {
        num = /^[0-9a-zA-Z_]{8,16}$/ig;
        if (!num.test(password)) {
            alert("非法字符输入！\n只能输入数字、英文字符以及‘_’");
        } else {
            return true;
        }
    }
}

function isemail(emailvalue) {
    var num = /@?(\.com)$/;
    if (!num.test(emailvalue)) {
        alert("请输入正确邮箱");
    } else {
        return true;
    }
}

function isphonenum(phonenum) {
    var num = /^1\d{10}$/;
    if (!num.test(phonenum)) {
        alert("请输入正确手机号");
    } else {
        return true;
    }
}
/* //是否成功
function issuccess() {
    let col = document.querySelector(".col");
    let data = document.querySelectorAll(".inputs");
    let registere = document.getElementById("registere");
    col.onclick = function() {
        let inputs = data[0].getElementsByTagName("input");
        console.log(inputs)
        if(!inputs[0].value) alert("请输入用户名/手机号");
        else if(!inputs[1].value) alert("密码为空");
        else alert("success！（点击注册可进入注册页面）");
    }
    registere.onclick = function () {
        let inputs = data[1].getElementsByTagName("input");
        let agree = document.getElementById("agree");
        if(!inputs[0].value) alert("手机号为空！");
        else if(!inputs[1].value) alert("验证码为空！");
        else if(!inputs[2].value) alert("密码为空！");
        else if(!agree.checked) alert("请同意《xxx协议》！");
        else alert("success！");
    }
}
issuccess()

//注册点击agree才能注册
function regis() {
    let agree = document.getElementById("agree");
    agree.onclick = function () {
        let registere = document.getElementById("registere");
        if(this.checked) {
            registere.style.backgroundColor = "rgb(85, 111, 181)";
        } else {
            registere.style.backgroundColor = "rgba(85, 111, 181, .7)";
        }
    }
}
regis();

//手机号码格式确定
function isphonenum() {
    let phonenum = document.getElementById("phone");
    phonenum.onblur = function () {
        var num = /^1\d{10}$/;
        if(num.test(phonenum.value)) {
            let code = document.getElementById("code");
            code.style.color = "rgb(85, 111, 181)";
            code.style.fontWeight = "700";
        } else {
            let code = document.getElementById("code");
            code.style.color = "grey";
            code.style.fontWeight = "400";
            alert("请输入正确手机号");
        }
    }

}
isphonenum();

 */