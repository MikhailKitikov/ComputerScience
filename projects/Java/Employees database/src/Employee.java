class Employee extends Person {

    enum Position {DIRECTOR, MANAGER, FIRSTCATEGORY, SECONDCATEGORY, THIRDCATEGORY}

    Position position;

    int salary;

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) throws MyException  {
        if (position == null)
            throw new MyException(1);
        this.position = position;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) throws MyException  {
        if (salary < 0)
            throw new MyException(2);
        this.salary = salary;
    }

    public Employee(String surname, Position position, int salary) throws MyException {
        super(surname);
        if (position == null)
            throw new MyException(1);
        if (salary < 0)
            throw new MyException(2);
        this.position = position;
        this.salary = salary;
    }

    @Override
    double calculateQualification() {
        return salary / 330.0;
    }

    public String toString() {
        return super.toString() + " " + position.toString() + " " + salary;
    }
}
