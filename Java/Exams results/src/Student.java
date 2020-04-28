package lab13_package;

class Student implements Comparable<Student> {
    String name;
    int number;
    Student(String name, int number) {
        this.number = number;
        this.name = name;
    }

    @Override
    public int compareTo(Student o) {
        if (!this.name.equals(o.name))
            return name.compareTo(o.name);
        return number - o.number;
    }
}