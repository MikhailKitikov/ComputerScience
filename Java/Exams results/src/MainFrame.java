package lab13_package;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.event.MenuEvent;
import javax.swing.event.MenuListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

public class MainFrame extends JFrame
{
    SessionDatabase model;
    Controller controller;

    JList entryList, resultList;
    boolean show;
    JLabel label3;

    public MainFrame()
    {
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(300, 100, 700, 600);
        setResizable(false);

    // model and controller

        model = new SessionDatabase();
        controller = new Controller(model);

        model.view = this;
        model.controller = controller;
        controller.view = this;

    // menu

        JMenuBar menuBar = new JMenuBar();
        this.setJMenuBar(menuBar);
    //
        JMenu fileMenu = new JMenu("File");
        menuBar.add(fileMenu);

        JMenuItem openMenuItem = new JMenuItem("Open");
        openMenuItem.addActionListener(e -> controller.readData());
        fileMenu.add(openMenuItem);

        JMenuItem openXMLItem = new JMenuItem("Open XML");
        openXMLItem.addActionListener(e -> controller.readXMLData());
        fileMenu.add(openXMLItem);

        JMenuItem saveMenuItem = new JMenuItem("Save");
        saveMenuItem.addActionListener(e -> controller.writeData());
        fileMenu.add(saveMenuItem);

        JMenuItem saveXMLItem = new JMenuItem("Save as XML");
        saveXMLItem.addActionListener(e -> controller.writeXMLData());
        fileMenu.add(saveXMLItem);
    //
        JMenu workspaceMenu = new JMenu("Workspace");
        menuBar.add(workspaceMenu);

        JMenuItem clearMenuItem = new JMenuItem("clear");
        clearMenuItem.addActionListener(e -> controller.clear());
        workspaceMenu.add(clearMenuItem);

        JMenuItem quitMenuItem = new JMenuItem("quit");
        quitMenuItem.addActionListener(e -> System.exit(0));
        workspaceMenu.add(quitMenuItem);
    //
        JMenu infoMenu = new JMenu("About");
        infoMenu.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                JOptionPane.showMessageDialog(null, "Press Change to change the criterion \n(Ex.: \"2 Math Biology\")", "About", JOptionPane.PLAIN_MESSAGE);
            }
        });
        menuBar.add(infoMenu);

    // data representation

        show = false;
    //
        JPanel mainPanel = new JPanel();
        mainPanel.setSize(this.getSize());
        mainPanel.setLayout(new BorderLayout());
        this.add(mainPanel, BorderLayout.CENTER);
    //
        JPanel entryPanel = new JPanel();
        entryPanel.setLayout(new BorderLayout());
        entryPanel.setBorder(new EmptyBorder(0, 0, 0, 0));
        entryPanel.setSize(new Dimension(mainPanel.getWidth()/2, mainPanel.getHeight()));
        mainPanel.add(entryPanel, BorderLayout.CENTER);
    //
        JLabel label1 = new JLabel("All entries", JLabel.CENTER);
        label1.setPreferredSize(new Dimension(70, 20));
        entryPanel.add(label1, BorderLayout.NORTH);
    //
        entryList = new JList(model);
        entryList.setFont(new Font("", 0, 15));
        entryList.setBorder(new EmptyBorder(30, 30, 30, 30));
        entryList.setPreferredSize(new Dimension(entryPanel.getWidth()+100, entryPanel.getHeight()));
        entryPanel.add(entryList, BorderLayout.CENTER);
    //
        JPanel resultPanel = new JPanel();
        resultPanel.setLayout(new BorderLayout());
        resultPanel.setBorder(new EmptyBorder(0, 0, 0, 0));
        resultPanel.setSize(new Dimension(entryPanel.getWidth(), mainPanel.getHeight()));
        mainPanel.add(resultPanel, BorderLayout.EAST);
    //
        JLabel label2 = new JLabel("Found", JLabel.CENTER);
        label2.setPreferredSize(new Dimension(70, 20));
        resultPanel.add(label2, BorderLayout.NORTH);
    //
        resultList = new JList();
        resultList.setFont(new Font("", 0, 15));
        resultList.setPreferredSize(new Dimension(resultPanel.getWidth()+100, resultPanel.getHeight()));
        resultList.setBorder(new EmptyBorder(30, 30, 30, 30));
        resultPanel.add(resultList, BorderLayout.CENTER);

        pack();

    // buttons

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(1, 4));
        buttonPanel.setPreferredSize(new Dimension(mainPanel.getWidth(), 60));
        mainPanel.add(buttonPanel, BorderLayout.SOUTH);
    //
        JButton addButton = new JButton("Add");
        addButton.addActionListener(e -> {
            AddItemDialog dialog = new AddItemDialog(controller);
            dialog.setVisible(true);
        });
        addButton.setPreferredSize(new Dimension(buttonPanel.getWidth()/5, 50));
        buttonPanel.add(addButton);
    //
        JButton removeButton = new JButton("Remove");
        removeButton.addActionListener(e -> controller.removeItem());
        removeButton.setPreferredSize(new Dimension(buttonPanel.getWidth()/5, 50));
        buttonPanel.add(removeButton);
    //
        JButton findButton = new JButton("Change");
        findButton.addActionListener(e -> {
            show = true;
            controller.changeCriterion();
        });
        findButton.setPreferredSize(new Dimension(buttonPanel.getWidth()/5, 50));
        buttonPanel.add(findButton);
    //
        JButton solveButton = new JButton("Find");
        solveButton.addActionListener(e -> controller.findNotPassed(show));
        solveButton.setPreferredSize(new Dimension(buttonPanel.getWidth()/5, 50));
        buttonPanel.add(solveButton);
    //
        JScrollPane scrollPane1 = new JScrollPane(entryList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        entryPanel.add(scrollPane1);

        JScrollPane scrollPane2 = new JScrollPane(resultList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        resultPanel.add(scrollPane2);

        label3 = new JLabel("Result", JLabel.CENTER);
        label3.setPreferredSize(new Dimension(resultPanel.getWidth(), 30));
        resultPanel.add(label3, BorderLayout.SOUTH);

        JLabel label4 = new JLabel("(number; surname; semester; subject; mark)", JLabel.CENTER);
        label4.setPreferredSize(new Dimension(entryPanel.getWidth(), 30));
        entryPanel.add(label4, BorderLayout.SOUTH);
    }

    public void paint(Graphics g)
    {
        super.paint(g);
        entryList.updateUI();
        resultList.updateUI();
    }

    public static void main(String[] Args)
    {
        MainFrame mainFrame = new MainFrame();
        mainFrame.setVisible(true);
    }
}
