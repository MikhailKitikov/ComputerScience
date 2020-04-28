abstract class Person {

    String surname;

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) throws MyException {
        if (surname == null || surname.length() == 0)
            throw new MyException(0);
        this.surname = surname;
    }

    public Person(String surname) throws MyException {
        if (surname == null || surname.length() == 0)
            throw new MyException(0);
        this.surname = surname;
    }

    public String toString() {
        return surname;
    }

    public boolean equals(Object o) {
        if (!(o instanceof Person))
            return false;
        return this.getSurname().equals(((Person)o).getSurname());
    }

    abstract double calculateQualification();
}
