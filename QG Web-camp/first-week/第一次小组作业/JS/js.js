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

function login() { 
    let logIn = document.getElementById("logIn");
    let rege = document.getElementById("rege");
    let registered = document.getElementById("registered");
    let log = document.getElementById("log");
    rege.onclick = function() {
        logIn.setAttribute("style","display:none");
        registered.setAttribute("style","display:inline")
    }
    log.onclick = function() {
        logIn.setAttribute("style","display:inline")
        registered.setAttribute("style","display:none");
    }
}
login();

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