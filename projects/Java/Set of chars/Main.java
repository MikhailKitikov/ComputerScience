package Kitikov_v4;

public class Main {

    public static void main(String[] args) {
        Test();
        System.exit(0);
    }

    public static void Test() {
        try {
            System.out.println("Creating empty set1:");
            CharSet set1 = new CharSet();
            set1.Print();
            System.out.println();

            System.out.println("Adding element 'a' to set1: ");
            set1.Add('a');
            set1.Print();
            System.out.println();

            System.out.println("Looking for element 'a' in set1: ");
            System.out.println(set1.In('a'));

            System.out.println("Looking for element 'b': ");
            System.out.println(set1.In('b'));


            System.out.println();
            char [] arr = {' ', 'b', 'b', 'c', 'a', 'c', 'd', ' '};
            System.out.println("Creating set2 by array {' ', 'b', 'b', 'c', 'a', 'c', 'd', ' '}:");
            CharSet set2 = new CharSet(arr);
            set2.Print();
            System.out.println();

            System.out.println();
            System.out.println("Creating new set3 on set2:");
            CharSet set3 = new CharSet(set2);
            set3.Print();
            System.out.println();

            System.out.println("Removing element 't' from set3: ");
            System.out.println(set3.Remove('t'));

            System.out.println("Removing element 'a' from set3: ");
            System.out.println(set3.Remove('a'));

            System.out.println("Adding element 'x' to set3: ");
            set3.Add('x');
            set3.Print();
            System.out.println();

            System.out.println();
            System.out.println("Finding set2 and set3 intersection:");
            SetIntersection(set2, set3).Print();
            System.out.println();

            System.out.println("Finding set2 and set3 union:");
            SetUnion(set2, set3).Print();
            System.out.println();

            System.out.println("Finding set2 and set3 difference:");
            SetDifference(set2, set3).Print();
            System.out.println();

            System.out.println("Finding set3 and set2 difference:");
            SetDifference(set3, set2).Print();
            System.out.println();

            System.out.println("Clearing set3.");
            set3.Clear();
            System.out.println("Is set3 empty?");
            System.out.println(set3.Empty());
            System.out.println();

        }
        catch (Exception e) {
            System.err.println("\nException:");
            System.err.println(e.getClass().getName());
            System.exit(1);
        }
    }

    public static CharSet SetIntersection(CharSet s1, CharSet s2) throws Exception {
        CharSet s = new CharSet(s1);
        s.Intersection(s2);
        return s;
    }

    public static CharSet SetUnion(CharSet s1, CharSet s2) throws Exception {
        CharSet s = new CharSet(s1);
        s.Union(s2);
        return s;
    }

    public static CharSet SetDifference(CharSet s1, CharSet s2) throws Exception {
        CharSet s = new CharSet(s1);
        s.Difference(s2);
        return s;
    }

}
