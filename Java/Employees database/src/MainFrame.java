import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.util.HashMap;
import java.util.Vector;

public class MainFrame extends JFrame {

    Vector<Person> people;
    MyUtils myUtils;

    JTabbedPane tabbedPane;
    JMenuItem task2Item, task3Item, task4Item, task5Item, task7Item;
    JPanel mainPanel1, mainPanel2, mainPanel3, mainPanel4, mainPanel5;
    JList task1List, task2List, task3List,  task4List,  task5List;
    JPanel rightPanel, infoPanel;
    JTextField surnameField, positionField, salaryField;

    void updateView() {

        if (task1List.isSelectionEmpty() || task1List.getSelectedIndex() >= people.size()) {
            infoPanel.setVisible(false);
            return;
        }

        int ind = task1List.getSelectedIndex();
        Employee tempEmployee = (Employee)people.get(ind);

        infoPanel.setVisible(true);
        surnameField.setText(tempEmployee.getSurname());
        positionField.setText(tempEmployee.getPosition().toString());
        salaryField.setText(Integer.toString(tempEmployee.getSalary()));
    }

    void loadGUI() {

        // menu

        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);
        //
        JMenu fileMenu = new JMenu("Файл");
        menuBar.add(fileMenu);

        JMenuItem openFileItem = new JMenuItem("Открыть");
        openFileItem.addActionListener(e -> myUtils.openFile());
        fileMenu.add(openFileItem);

        JMenuItem quitItem = new JMenuItem("Выход");
        quitItem.addActionListener(e -> System.exit(0));
        fileMenu.add(quitItem);
        //
        JMenu taskMenu = new JMenu("Данные");
        menuBar.add(taskMenu);

        task2Item = new JMenuItem("По должности");
        task2Item.addActionListener(e -> {
            myUtils.showByPosition();
            tabbedPane.setSelectedComponent(mainPanel2);
        });
        taskMenu.add(task2Item);

        task3Item = new JMenuItem("По зарплате");
        task3Item.addActionListener(e -> {
            myUtils.showBySalary();
            tabbedPane.setSelectedComponent(mainPanel3);
        });
        taskMenu.add(task3Item);

        task4Item = new JMenuItem("Однофамильцы");
        task4Item.addActionListener(e -> {
            myUtils.findEqualSurnames();
            tabbedPane.setSelectedComponent(mainPanel4);
        });
        taskMenu.add(task4Item);

        task5Item = new JMenuItem("Должности");
        task5Item.addActionListener(e -> {
            myUtils.showAllPositions();
            tabbedPane.setSelectedComponent(mainPanel5);
        });
        taskMenu.add(task5Item);

        task7Item = new JMenuItem("Количество");
        task7Item.addActionListener(e -> myUtils.countEmployees());
        taskMenu.add(task7Item);

        // tabs

        tabbedPane = new JTabbedPane();
        this.add(tabbedPane);

        mainPanel1 = new JPanel();
        mainPanel1.setSize(this.getSize());
        tabbedPane.add("Все работники", mainPanel1);

        mainPanel2 = new JPanel();
        mainPanel2.setSize(this.getSize());
        tabbedPane.add("По должности", mainPanel2);

        mainPanel3 = new JPanel();
        mainPanel3.setSize(this.getSize());
        tabbedPane.add("По зарплате", mainPanel3);

        mainPanel4 = new JPanel();
        mainPanel4.setSize(this.getSize());
        tabbedPane.add("Однофамильцы", mainPanel4);

        mainPanel5 = new JPanel();
        mainPanel5.setSize(this.getSize());
        tabbedPane.add("Должности", mainPanel5);

        // task 1

        JPanel list1Panel = new JPanel();
        list1Panel.setPreferredSize(new Dimension(mainPanel1.getWidth()/2, mainPanel1.getHeight()));
        mainPanel1.add(list1Panel);

        task1List = new JList();
        task1List.setFont(new Font("", 0, 15));
        task1List.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        task1List.addListSelectionListener(e -> updateView());
        task1List.setBorder(new EmptyBorder(10, 10, 10, 10));

        list1Panel.setLayout(new BorderLayout());

        list1Panel.add(new JScrollPane(task1List), BorderLayout.CENTER);

        /*
         * делаем левую панель listPanel
         * не делаем preferred size у JList
         * делаем list1Panel.setLayout(new BorderLayout());
         * list1Panel.add(task1List, BorderLayout.CENTER);
         */
        //
        rightPanel = new JPanel();
        rightPanel.setPreferredSize(new Dimension(mainPanel1.getWidth()/2, mainPanel1.getHeight()));
        mainPanel1.add(rightPanel, BorderLayout.EAST);
        rightPanel.setBorder(new EmptyBorder(10, 10, 10, 10));

        infoPanel = new JPanel();
        rightPanel.add(infoPanel, BorderLayout.NORTH);
        infoPanel.setVisible(false);

        GridLayout gridLayout = new GridLayout(9, 1);
        infoPanel.setLayout(gridLayout);

        infoPanel.add(new JLabel("Фамилия:", JLabel.LEFT));
        surnameField = new JTextField();
        surnameField.setFont(new Font("", 0, 15));
        surnameField.setPreferredSize(new Dimension(200, 30));
        surnameField.setEnabled(false);
        infoPanel.add(surnameField);
        //
        infoPanel.add(new JLabel("Должность:", JLabel.LEFT));
        positionField = new JTextField();
        positionField.setPreferredSize(new Dimension(200, 30));
        positionField.setFont(new Font("", 0, 15));
        positionField.setEnabled(false);
        infoPanel.add(positionField);
        //
        infoPanel.add(new JLabel("Зарплата:", JLabel.LEFT));
        salaryField = new JTextField();
        salaryField.setPreferredSize(new Dimension(20, 30));
        salaryField.setFont(new Font("", 0, 15));
        salaryField.setEnabled(false);
        infoPanel.add(salaryField);

        // task 2

        task2List = new JList();
        task2List.setFont(new Font("", 0, 15));
        task2List.setBorder(new EmptyBorder(10, 10, 10, 10));
        mainPanel2.setLayout(new BorderLayout());
        mainPanel2.add(new JScrollPane(task2List));

        // task 3

        task3List = new JList();
        task3List.setFont(new Font("", 0, 15));
        task3List.setBorder(new EmptyBorder(10, 10, 10, 10));
        mainPanel3.setLayout(new BorderLayout());
        mainPanel3.add(new JScrollPane(task3List));

        // task 4

        task4List = new JList();
        task4List.setFont(new Font("", 0, 15));
        task4List.setBorder(new EmptyBorder(10, 10, 10, 10));
        mainPanel4.setLayout(new BorderLayout());
        mainPanel4.add(new JScrollPane(task4List));

        // task 5

        task5List = new JList();
        task5List.setFont(new Font("", 0, 15));
        task5List.setBorder(new EmptyBorder(10, 10, 10, 10));
        mainPanel5.setLayout(new BorderLayout());
        mainPanel5.add(new JScrollPane(task5List));
    }

    MainFrame() {

        people = new Vector<>();
        myUtils = new MyUtils(this);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(300, 0, 600, 600);
        setResizable(false);
        loadGUI();
        pack();
    }

    public static void main(String[] Args) {

        MainFrame mainFrame = new MainFrame();
        mainFrame.setVisible(true);
    }
}
