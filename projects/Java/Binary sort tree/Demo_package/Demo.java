package Demo_package;

import BynarySortTree_package.BinarySortTree;
import BynarySortTree_package.MyException;
import BynarySortTree_package.Personage;

import java.util.ArrayList;

public class Demo {

    public static void main(String[] args) {
        try {
            System.out.println("\t\tTest #1\n");

            System.out.println("Создадим дерево из массива целых чисел {11, 2, 0, 43, 24}");
            Integer [] arr1 = {11, 2, 0, 43, 24};
            BinarySortTree<Integer> tree1 = new BinarySortTree<Integer>(arr1);

            System.out.println("Размер дерева: " + tree1.getSize());

            System.out.println("\nЧисло листьев: ");
            System.out.println(tree1.LeavesCount());

            ArrayList<Object> el = new ArrayList<>();
            tree1.InorderTraversal(el, tree1.getRoot());
            System.out.println("Обход ЛЕВЫЙ-КОРЕНЬ-ПРАВЫЙ:");
            System.out.println(el);

            el.clear();
            tree1.PreorderTraversal(el, tree1.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            el.clear();
            tree1.PostorderTraversal(el, tree1.getRoot());
            System.out.println("Обход ЛЕВЫЙ-ПРАВЫЙ-КОРЕНЬ:");
            System.out.println(el);

            System.out.println("\nЕсть ли вершина с ключом 100?: " + tree1.Search(100));

            System.out.println("\nДобавим элементы 56 и 3");
            tree1.Insert(56);
            tree1.Insert(3);
            el.clear();
            tree1.PreorderTraversal(el, tree1.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("\nЧисло листьев: ");
            System.out.println(tree1.LeavesCount());

            System.out.println("\nЕсть ли вершина с ключом 56?: " + tree1.Search(56));

            System.out.println("\nУдалим концевую вершину с ключом 0");
            tree1.Remove(0);
            el.clear();
            tree1.PreorderTraversal(el, tree1.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("\nЧисло листьев: ");
            System.out.println(tree1.LeavesCount());

            System.out.println("\nУдалим внутреннюю вершину с ключом 43");
            tree1.Remove(43);
            el.clear();
            tree1.PreorderTraversal(el, tree1.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("\nЧисло листьев: ");
            System.out.println(tree1.LeavesCount());

            System.out.println("\nУдалим корень (вершина с ключом 11)");
            tree1.Remove(11);
            el.clear();
            tree1.PreorderTraversal(el, tree1.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("Размер дерева: " + tree1.getSize());

            System.out.println("\nСоздадим новое дерево на основе старого:");
            BinarySortTree<Integer> tr = new BinarySortTree<Integer>(tree1.getRoot());
            el.clear();
            tr.PreorderTraversal(el, tr.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("\nЧисло листьев: ");
            System.out.println(tree1.LeavesCount());

            System.out.println("\n\t\tTest #2\n");

            System.out.println("Создадим дерево из массива объектов класса \"Персонаж Ролевой Игры\"");
            System.out.println("(ключ сортировки по умолчанию - Имя)");
            Personage per[] = {
                    new Personage("Dima", "Elf", 20, 20),
                    new Personage("Mike", "Human", 30, 30),
                    new Personage("Sergey Magus 40 40"),
                    new Personage("Alex", "Orc", 10, 10),
                    new Personage("George Orc 100 100")
            };
            BinarySortTree<Personage> tree2 = new BinarySortTree<Personage>(per);

            el.clear();
            tree2.PreorderTraversal(el, tree2.getRoot());
            System.out.println("Обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("\nДобавим игрока Daniel Elf 200 200:");
            tree2.Insert(new Personage("Daniel Elf 200 200"));

            el.clear();
            tree2.PreorderTraversal(el, tree2.getRoot());
            System.out.println("\nОбход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ:");
            System.out.println(el);

            System.out.println("\nРазмер дерева: " + tree2.getSize());

            System.out.println("\nЧисло листьев: ");
            System.out.println(tree2.LeavesCount());

            System.out.println("\n\nСоздадим пустое дерево:");
            BinarySortTree<Integer> tree3 = new BinarySortTree<>();

            //System.out.println("\nЧисло листьев: ");
            //System.out.println(tree3.LeavesCount());

            System.out.println("\nДобавим одно значение 1");
            tree3.Insert(1);
            System.out.println("Число листьев: ");
            System.out.println(tree3.LeavesCount());

            System.out.println("\nДобавим еще одно значение 23");
            tree3.Insert(23);
            System.out.println("Число листьев: ");
            System.out.println(tree3.LeavesCount());

            System.out.println("\nДобавим еще одно значение -45");
            tree3.Insert(-45);
            System.out.println("Число листьев: ");
            System.out.println(tree3.LeavesCount());

            System.out.println("\nДобавим еще одно значение -41");
            tree3.Insert(-41);
            System.out.println("Число листьев: ");
            System.out.println(tree3.LeavesCount());

            System.out.println("\nДобавим еще одно значение -50");
            tree3.Insert(-50);
            System.out.println("Число листьев: ");
            System.out.println(tree3.LeavesCount());

        }
        catch (MyException e) {
            System.err.println(e.toString());
            System.exit(1);
        }
        catch (Exception e) {
            System.err.println("Exception: " + e.toString());
            System.exit(1);
        }
        System.exit(0);
    }
}
