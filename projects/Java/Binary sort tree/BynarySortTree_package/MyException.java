package BynarySortTree_package;

public class MyException extends Exception {

    int type = 0;

    public MyException(int type) {
        this.type = type;
    }

    public String toString() {
        String result;
        switch(type) {
            case 1:
                result = "Exception: Invalid object initialization.";
                break;
            case 2:
                result = "Exception: Cannot remove element which doesn't exist.";
                break;
            case 3:
                result = "Exception: Tree was empty.";
                break;
            default:
                result = "Exception: Unknown exception detected.";
                break;
        }
        return result;
    }

}
