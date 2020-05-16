let tips = document.getElementById("tips");

//获取input数据
let data = document.querySelector(".setting-information").getElementsByTagName("input");
//获取注册按钮
let sendMess = document.getElementById("sendMess");

//数据回填
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
            data[0].value = obj.data.name;
            data[1].value = obj.data.password;
            if (obj.data.sex)
                data[2].value = obj.data.sex;
            if (obj.data.age)
                data[3].value = obj.data.age;
            if (obj.data.status)
                data[4].value = obj.data.status;
            data[5].value = obj.data.phone;
            data[6].value = obj.data.email;
        } else {
            alert(obj.errorMsg);
        }
    },
    error: function (msg) {
        let obj = JSON.parse(msg);
        alert(obj.errorMsg);
    }
})


//用户名判断
data[0].onblur = function () {
    if (!data[0].value) {
        tips.innerHTML = "用户名不能为空！";
    } else {
        tips.innerHTML = "";
    }
}

//判断密码是否符合
data[1].onblur = function () {
    ispassword(this.value);
}

//判断性别输入
data[2].onblur = function () {
    isSex(this.value);
}

//年龄
data[3].onblur = function () {
    isAge(this.value);
}


//成功就上传
sendMess.onclick = function () {
    if (data[0].value) {
        if (ispassword(data[1].value))
            if (isSex(data[2].value))
                if (isAge(data[3].value)) {
                    tips.innerHTML = "";
                    //上传
                    $ajax({
                        method: "post",
                        url: "settingServlet",
                        data: {
                            //username为手机号
                            name: data[0].value,
                            password: data[1].value,
                            sex: data[2].value,
                            age: data[3].value,
                            status: data[4].value,
                            id: id
                        },
                        success: function (result) {
                            let obj = JSON.parse(result);
                            if (obj.flag === true) {
                                alert("修改成功！");
                                window.location.href = `setting.html?id=${id}`;
                            } else {
                                alert(obj.errorMsg);
                            }
                        },
                        error: function (msg) {
                            let obj = JSON.parse(msg);
                            alert(obj.errorMsg);
                        }
                    })
                }
    }
}


/* 修改头像 */
/* 控制提交图片按钮 */
document.getElementById("pID").value = id;
let setHead = document.getElementById("setHead");
let closeAP = document.getElementById("closeAP");
document.querySelector(".avtar-border").onclick = function() {
    setHead.classList.remove("hidden");
}
closeAP.onclick = function() {
    setHead.classList.add("hidden");
}





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

function isSex(sexValue) {
    if (sexValue === "男" || sexValue === "女" || sexValue === "保密") {
        tips.innerHTML = "";
        return true;
    } else {
        tips.innerHTML = "性别只能为\"男\"，\"女\"或\"保密\"";
        return false;
    }
}

function isAge(ageValue) {
    let num = /^[0-9]{1,3}$/;
    if (num.test(ageValue) || ageValue === "保密") {
        tips.innerHTML = "";
        return true;
    } else {
        tips.innerHTML = "请输入正确年龄（0-9的数字）或\"保密\"！";
        return false
    }
}