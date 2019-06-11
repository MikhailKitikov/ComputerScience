package lab13_package;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

class AddItemDialog extends JDialog {

    Controller controller;
    JPanel mainPanel;
    JTextField numberField, surnameField, semesterField, subjectField, markField;

    AddItemDialog(Controller controller) {

        this.controller = controller;
        setModal(true);
        setBounds(100, 100, 600, 600);
        setTitle("Add item");

        GridLayout g = new GridLayout(6, 2);
        g.setHgap(20);
        g.setVgap(20);

        mainPanel = new JPanel();
        mainPanel.setLayout(g);
        mainPanel.setBorder(new EmptyBorder(50, 50, 50, 50));
        mainPanel.setPreferredSize(new Dimension(500, 500));
        mainPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
        mainPanel.setAlignmentY(Component.CENTER_ALIGNMENT);
        this.add(mainPanel);

        JScrollPane scrollPane = new JScrollPane(mainPanel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        this.add(scrollPane);

        JLabel numberLabel = new JLabel("Record book number:", JLabel.RIGHT);
        mainPanel.add(numberLabel);

        numberField = new JTextField();
        numberField.setPreferredSize(new Dimension(100, 40));
        mainPanel.add(numberField);
    //
        JLabel surnameLabel = new JLabel("Surname:", JLabel.RIGHT);
        mainPanel.add(surnameLabel);

        surnameField = new JTextField();
        numberField.setPreferredSize(new Dimension(100, 40));
        mainPanel.add(surnameField);
    //
        JLabel semesterLabel = new JLabel("Semester:", JLabel.RIGHT);
        mainPanel.add(semesterLabel);

        semesterField = new JTextField();
        numberField.setPreferredSize(new Dimension(100, 40));
        mainPanel.add(semesterField);
    //
        JLabel subjectLabel = new JLabel("Subject:", JLabel.RIGHT);
        mainPanel.add(subjectLabel);

        subjectField = new JTextField();
        numberField.setPreferredSize(new Dimension(100, 40));
        mainPanel.add(subjectField);
    //
        JLabel markLabel = new JLabel("Mark:", JLabel.RIGHT);
        mainPanel.add(markLabel);

        markField = new JTextField();
        numberField.setPreferredSize(new Dimension(100, 40));
        mainPanel.add(markField);

        JButton addButton = new JButton("Add");
        addButton.setPreferredSize(new Dimension(50, 40));
        addButton.addActionListener(new AddItemListener(this));
        mainPanel.add(addButton);

        JButton cancelButton = new JButton("Cancel");
        cancelButton.setPreferredSize(new Dimension(50, 40));
        cancelButton.addActionListener(e -> setVisible(false));
        mainPanel.add(cancelButton);
    }
}
