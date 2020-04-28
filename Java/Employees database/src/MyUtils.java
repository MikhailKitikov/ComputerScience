import org.xml.sax.SAXException;

import javax.swing.*;
import javax.xml.parsers.ParserConfigurationException;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.*;

class MyUtils {

    Vector<Person> peopleByPosition, peopleBySalary;
    Vector<String> equalSurname;
    Vector<Employee.Position> allPositions;
    Map<Employee.Position, Integer> positionMap;

    private MainFrame mainFrame;

    MyUtils(MainFrame mainFrame)
    {
        this.mainFrame = mainFrame;
    }

    void openFile() {
        clear();

        try {
            FileDialog fileDialog = new FileDialog(mainFrame, "Открыть XML файл", FileDialog.LOAD);
            fileDialog.setVisible(true);

            if (fileDialog.getFile() == null)
                return;

            File file = new File(fileDialog.getDirectory() + fileDialog.getFile());
            MyXMLParser myXMLParser = new MyXMLParser();
            myXMLParser.readData(file, mainFrame.people);

            if (mainFrame.people.isEmpty()) {
                JOptionPane.showMessageDialog(null, "Файл не содержит объектов", "", JOptionPane.WARNING_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(null, "Файл успешно открыт", "", JOptionPane.INFORMATION_MESSAGE);
                this.initData();
            }
        }
        catch (MyException e ) {
            JOptionPane.showMessageDialog(null, e, "", JOptionPane.ERROR_MESSAGE);
        }
        catch (IllegalArgumentException e ) {
            JOptionPane.showMessageDialog(null, "Некорректные данные", "", JOptionPane.ERROR_MESSAGE);
        }
        catch (IOException e ) {
            JOptionPane.showMessageDialog(null, "Ошибка чтения файла", "", JOptionPane.ERROR_MESSAGE);
        }
        catch (ParserConfigurationException | SAXException e ) {
            JOptionPane.showMessageDialog(null, "Файл не соответствует формату", "", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void initData() {

        mainFrame.task1List.setListData(mainFrame.people);

        peopleByPosition = new Vector<>(mainFrame.people);
        peopleByPosition.sort(new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                int res = ((Employee)o1).getPosition().compareTo(((Employee)o2).getPosition());
                if (res != 0)
                    return res;
                return o1.getSurname().compareTo(o2.getSurname());
            }
        });

        peopleBySalary = new Vector<>(mainFrame.people);
        peopleBySalary.sort(new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                return ((Employee)o2).getSalary()-((Employee)o1).getSalary();
            }
        });

        ////

        Set<String> differentSurnames = new TreeSet<>();

        for (Person person : mainFrame.people) {
            int cnt = 0;
            for (Person temp : mainFrame.people) {
                if (temp.getSurname().equals(person.getSurname())) {
                    ++cnt;
                }
            }
            if (cnt > 1)
                differentSurnames.add(person.getSurname());
        }

        equalSurname = new Vector<>(differentSurnames);

        //

        positionMap = new HashMap<>();
        for (Person temp : mainFrame.people) {
            Employee tempEmp = (Employee)temp;
            if (!positionMap.containsKey(tempEmp.getPosition())) {
                positionMap.put(tempEmp.getPosition(), 1);
            } else {
                positionMap.put(tempEmp.getPosition(), positionMap.get(tempEmp.getPosition()) + 1);
            }
        }

        /////////

        allPositions = new Vector<>(positionMap.keySet());
        allPositions.sort(Comparator.reverseOrder());

    }

    public void clear() {

        mainFrame.people.clear();
        mainFrame.task2List.setListData(new Vector());
        mainFrame.task3List.setListData(new Vector());
        mainFrame.task4List.setListData(new Vector());
        mainFrame.task5List.setListData(new Vector());
        mainFrame.updateView();
        mainFrame.repaint();
    }

    void showByPosition() {
        if (mainFrame.people.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Не найдено данных", "", JOptionPane.ERROR_MESSAGE);
            return;
        }
        mainFrame.task2List.setListData(peopleByPosition);
    }

    void showBySalary() {
        if (mainFrame.people.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Не найдено данных", "", JOptionPane.ERROR_MESSAGE);
            return;
        }
        mainFrame.task3List.setListData(peopleBySalary);
    }

    void findEqualSurnames() {
        if (equalSurname == null || equalSurname.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Нет однофамильцев", "", JOptionPane.ERROR_MESSAGE);
            return;
        }
        mainFrame.task4List.setListData(equalSurname);
    }

    void showAllPositions() {
        if (allPositions == null || allPositions.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Не найдено данных", "", JOptionPane.ERROR_MESSAGE);
            return;
        }
        mainFrame.task5List.setListData(allPositions);
    }

    void countEmployees() {

        while (true) {

            if (positionMap == null || positionMap.isEmpty()) {
                JOptionPane.showMessageDialog(null, "Не найдено данных", "", JOptionPane.ERROR_MESSAGE);
                return;
            }

            String res = JOptionPane.showInputDialog("Введите должность:");
            if (res == null) {
                return;
            }
            else if (res.length() == 0) {
                JOptionPane.showMessageDialog(null, "Некорректный ввод", "", JOptionPane.ERROR_MESSAGE);
                continue;
            }

            try {
                if (!positionMap.containsKey(Employee.Position.valueOf(res))) {
                    JOptionPane.showMessageDialog(null, "Не найдено", "", JOptionPane.ERROR_MESSAGE);
                    continue;
                }
            }
            catch (IllegalArgumentException e) {
                JOptionPane.showMessageDialog(null, "Не найдено", "", JOptionPane.ERROR_MESSAGE);
                continue;
            }

            JOptionPane.showMessageDialog(null, positionMap.get(Employee.Position.valueOf(res)), res, JOptionPane.PLAIN_MESSAGE);

            break;
        }

    }
}
