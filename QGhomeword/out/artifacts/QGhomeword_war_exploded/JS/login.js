//登录
function issuccesslogin() {
    //获取内容
    let logininput = document.getElementById("logininput");
    let data = logininput.getElementsByTagName("input");
    //获取按钮
    let loginbuttom = document.getElementById("loginbuttom");

    //头像小彩蛋
    let closeeye = document.getElementById("closeeye");
    data[1].onclick = function () {
        closeeye.setAttribute("src", "images/img2.png");
    }

    //密码判断
    data[1].onblur = function () {
        closeeye.setAttribute("src", "images/img.jpg");
        if (!data[1].value) {
            tips.innerHTML = "请输入密码！";
        } else {
            tips.innerHTML = "";
        }
    }

    //判断手机号是否正确
    data[0].onblur = function () {
        isPhoneNum(this.value);
    }

    loginbuttom.onclick = function () {
        //登录
        if (isPhoneNum(data[0].value))
            if (data[1].value) {
                $ajax({
                    method: "post",
                    url: "loginServlet",
                    data: {
                        phone: data[0].value,
                        password: data[1].value
                    },
                    success: function (result) {
                        let obj = JSON.parse(result);
                        console.log(obj)
                        if(obj.flag) {
                            alert("登录成功！");
                            window.location.href = `diary.html?id=${obj.data.id}`;
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
}
issuccesslogin();

snow();

function isPhoneNum(phoneNum) {
    let num = /^1\d{10}$/;
    if (!num.test(phoneNum)) {
        tips.innerHTML = "请输入正确手机号!";
        return false;
    } else {
        tips.innerHTML = "";
        return true;
    }
}