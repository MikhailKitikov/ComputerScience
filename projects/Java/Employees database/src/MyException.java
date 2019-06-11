class MyException extends Exception {

    private int type;

    MyException(int type) {
        this.type = type;
    }

    public String toString() {
        switch (type) {
            case 0:
                return "Некорректная фамилия";
            case 1:
                return "Некорректная должность";
            case 2:
                return "Некорректная зарплата";
            default:
                return "Неизвестное исключение";
        }
    }
}
