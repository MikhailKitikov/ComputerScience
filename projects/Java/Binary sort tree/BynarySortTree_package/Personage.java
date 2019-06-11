package BynarySortTree_package;

import java.util.*;

public class Personage implements Iterator<Object>, Comparable<Personage>, Iterable<Object> {

    enum Race {Magus, Orc, Elf, Human, Undefined}
    private static int nextID;

    String name = "";
    final Race race;
    final int id;
    int age;
    int power;

    static {
        nextID = 0;
    }

    {
        id = nextID++;
        this.name = "NewPersonage";
        this.age = 0;
        this.power = 0;
    }

    public Personage() {
        this.name = "NewPersonage";
        this.race = Race.Undefined;
        this.age = 0;
        this.power = 0;
    }

    public Personage(String name, String race, int age, int power) throws MyException {
        if (name == null || race == null) {
            throw new MyException(1);
        }
        this.name = name;
        this.age = age;
        this.power = power;
        try {this.race = Race.valueOf(race);}
        catch (IllegalArgumentException e) {
            throw new MyException(1);
        }
    }

    public Personage(String InitStr) throws MyException {
        StringTokenizer tok = new StringTokenizer(InitStr, " ");
        if (tok.countTokens() != 4) {
            throw new MyException(1);
        }
        this.name = tok.nextToken();
        try {
            this.race = Race.valueOf(tok.nextToken());
            this.age = Integer.parseInt(tok.nextToken());
            this.power = Integer.parseInt(tok.nextToken());
        }
        catch(IllegalArgumentException e) {
            throw new MyException(1);
        }
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        for (Object field:this) {
            result.append(field.toString() + " ");
        }
        return result.toString();
    }

    // Iterator

    protected int iterator_idx = 0;

    public boolean hasNext() {
        return iterator_idx <= 4;
    }

    public void reset() {
        iterator_idx = 0;
    }

    public Iterator<Object> iterator() {
        reset();
        return this;
    }

    public Object next() {
        Object obj;
        switch(iterator_idx) {
            case 0:
                obj = new String(this.name);
                break;
            case 1:
                obj = this.race;
                break;
            case 2:
                obj = this.id;
                break;
            case 3:
                obj = this.age;
                break;
            case 4:
                obj = this.power;
                break;
            default:
                obj = null;
                break;
        }
        iterator_idx++;
        return obj;
    }

    // Comparable

    private static int compare_by = 0;

    public static void compareBy(int which_field) throws MyException {
        if (which_field < 0 || which_field > 4) {
            throw new MyException(2);
        }
        compare_by = which_field;
    }

    public int compareTo(Personage other) {
        int result = 0;
        switch(Personage.compare_by) {
            case 0:
                return name.compareTo(other.name);
            case 1:
                return race.compareTo(other.race);
            case 2:
                return Integer.compare(this.id, other.id);
            case 3:
                return Integer.compare(this.age, other.age);
            case 4:
                return Integer.compare(this.power, other.power);
        }
        return 404;
    }
}
