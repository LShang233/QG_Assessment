/*
    method : get 或者 post 方法
    url    ：上传地址
    data   ：上传的数据集合
    success：成功的回调函数
    error  ：失败的回调函数
*/

function $ajax({method = "get", url, data, success, error}){
    var xhr = null;
    try{
        xhr = new XMLHttpRequest();
    }catch(error){
        xhr = new ActiveXObject("Microsoft.XMLHTTP");
    }

    if(data){
        data = querystring(data);
    }

    if(method == "get" && data){
        url += "?" + data;
    }

    xhr.open(method, url, true);

    if(method == "get"){
        xhr.send();
    }else{
        xhr.setRequestHeader("content-type", "application/x-www-form-urlencoded");
        xhr.send(data);
    }

    xhr.onreadystatechange = function(){
        if(xhr.readyState == 4){
            if(xhr.status == 200){
                //回调函数
                if(success)
                    success(xhr.responseText);
            }else{
                if(error)
                    error(xhr.responseText);
            }
        }
    }
}

function querystring(obj){
    var str = "";
    for(var attr in obj){
        str += attr + "=" + obj[attr] + "&";
    }
    return str.substring(0, str.length - 1);
}