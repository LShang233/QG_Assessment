package cn.lshang.domain;

public class resultInfo {
    private boolean flag;//后端返回结果
    private Object data;//后端返回结果的数据对象
    private String errorMsg;//发生异常的错误信息

    public resultInfo() {
    }

    public resultInfo(boolean flag) {
        this.flag = flag;
    }

    public resultInfo(boolean flag, String errorMsg) {
        this.flag = flag;
        this.errorMsg = errorMsg;
    }

    public resultInfo(boolean flag, Object data, String errorMsg) {
        this.flag = flag;
        this.data = data;
        this.errorMsg = errorMsg;
    }

    public boolean isFlag() {
        return flag;
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public String getErrorMsg() {
        return errorMsg;
    }

    public void setErrorMsg(String errorMsg) {
        this.errorMsg = errorMsg;
    }
}
