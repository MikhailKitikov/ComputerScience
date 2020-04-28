package Kitikov_Task2;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;

public class MyWindow extends JFrame
{
    protected int x, y;
    protected int currentColor = 0;
    protected int weight = 3;
    protected int state = 0;
    protected boolean shift = false;
    protected Rectangle rect;
    protected boolean areaSelected = false;

    protected BufferedImage img = new BufferedImage(1500, 1000, BufferedImage.TYPE_INT_ARGB);
    protected BufferedImage tempImg = new BufferedImage(1500, 1000, BufferedImage.TYPE_INT_ARGB);

    protected JButton colorButtons[] = new JButton[6];
    protected JButton currColor = new JButton();
    protected JButton chooseColor = new JButton(". . .");
    protected JButton circleButton = new JButton();
    protected JButton lineButton = new JButton();
    protected JButton rectButton = new JButton();
    protected JButton graffitiButton = new JButton();
    protected JButton markButton = new JButton();
    protected JButton eraseButton = new JButton();
    protected Choice strokeChoice = new Choice();
    protected JPanel mainPanel;
    protected JPanel colorButtonPanel;

    private class ColorButtonActionListener implements ActionListener
    {
        private int ind;
        ColorButtonActionListener(int ind) {
            this.ind = ind;
        }

        @Override
        public void actionPerformed(ActionEvent e)
        {
            updateCurrentColor(ind);
        }
    }

    private void updateCurrentColor(int ind)
    {
        currentColor = ind;
        currColor.setBackground(colorButtons[ind].getBackground());
        mainPanel.getGraphics().setColor(colorButtons[ind].getBackground());
    }

    private void changeState(int newState) {
        if (state == 5) {
            img = tempImg;
        }
        state = newState;
    }

    private void resizeImage() {
        int w = Math.max(this.getWidth(), img.getWidth());
        int h = Math.max(this.getHeight(), img.getHeight());
        BufferedImage buf = new BufferedImage(w, h, img.getType());
        Graphics2D g = buf.createGraphics();
        g.drawImage(img, 0, 0, img.getWidth(), img.getHeight(), null);
        img = buf;
    }

    private void loadMainPanel() {

        mainPanel = new JPanel() {
            @Override
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                resizeImage();
                updateCurrentColor(currentColor);
                g.drawImage(img, 0, 0, null);
                setPreferredSize(new Dimension(img.getWidth(), img.getHeight()));
            }
        };

        mainPanel.addMouseListener(new MyMainPanelMouseListener(this));

        mainPanel.addMouseMotionListener(new MyMainPanelMouseMotionListener(this));
    }

    private void loadScrollbar() {

        JScrollPane scrolling = new JScrollPane(mainPanel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        this.add(scrolling);
    }

    private void loadMenu(JFileChooser fileChooser) {

        JMenuBar menuBar = new JMenuBar();
        JMenu workspaceMenu = new JMenu("Workspace");
        workspaceMenu.setFont(new Font("", 0, 15));

        JMenuItem clearItem = new JMenuItem("Clear");
        clearItem.addActionListener(e -> {
            img = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            tempImg = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            repaint();
        });
        workspaceMenu.add(clearItem);

        JMenuItem quitItem = new JMenuItem("Quit");
        quitItem.addActionListener(e -> System.exit(0));
        workspaceMenu.add(quitItem);

        JMenu fileMenu = new JMenu("File");
        fileMenu.setFont(new Font("", 0, 15));

        JMenuItem openItem = new JMenuItem("Open image");
        openItem.addActionListener(e -> {
            try {
                if (fileChooser.showOpenDialog(null) == JFileChooser.CANCEL_OPTION)
                    return;
                img = ImageIO.read(new File(fileChooser.getSelectedFile().getAbsolutePath()));
                tempImg = img;
                mainPanel.repaint();
            }
            catch(IOException exc) {
                JOptionPane.showMessageDialog(null, "Wrong file name",
                        "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
        fileMenu.add(openItem);

        JMenuItem saveItem = new JMenuItem("Save image");
        saveItem.addActionListener(e -> {
            try {
                fileChooser.setSelectedFile(null);
                if (fileChooser.showSaveDialog(null) == JFileChooser.CANCEL_OPTION)
                    return;
                ImageIO.write(img, "png", new File(fileChooser.getSelectedFile().getAbsolutePath()));
            }
            catch(IOException exc) {
                JOptionPane.showMessageDialog(null, "Wrong file name",
                        "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
        fileMenu.add(saveItem);

        menuBar.add(workspaceMenu);
        menuBar.add(fileMenu);
        this.setJMenuBar(menuBar);
    }

    private void loadColorPanel(GridBagConstraints gbc) {

        currColor.setEnabled(false);
        currColor.setPreferredSize(new Dimension(50, 50));
        colorButtonPanel.add(currColor, gbc);

        gbc.gridwidth = 1;
        gbc.insets = new Insets(10, 10, 10, 10);

        Color[] colors = {Color.red, Color.green, Color.blue, Color.YELLOW, Color.orange, Color.CYAN};

        for (int i = 0; i < colors.length; ++i) {
            gbc.gridx = i % 2;
            gbc.gridy = i / 2 + 2;

            colorButtons[i] = new JButton();
            colorButtons[i].setPreferredSize(new Dimension(50, 50));
            colorButtons[i].setBackground(colors[i]);
            colorButtons[i].addActionListener(new ColorButtonActionListener(i));
            colorButtonPanel.add(colorButtons[i], gbc);
        }

        gbc.gridx = 0; gbc.gridy += 1; gbc.gridwidth = 2;

        chooseColor.setPreferredSize(new Dimension(100, 50));
        chooseColor.setFont(new Font("", 0, 30));
        JColorChooser colorChooser = new JColorChooser();

        chooseColor.addActionListener(e -> {
            Color color = colorChooser.showDialog(null, "Choose color", currColor.getBackground());
            if (color == null)
                return;
            colorButtons[currentColor].setBackground(color);
            currColor.setBackground(color);
        });
        colorButtonPanel.add(chooseColor, gbc);
    }

    private void loadFontWeightPanel(GridBagConstraints gbc) {

        gbc.gridx = 0; gbc.gridy += 1; gbc.gridwidth = 2;
        strokeChoice.setPreferredSize(new Dimension(100, 50));
        strokeChoice.addItem("1 pt");
        strokeChoice.addItem("3 pt");
        strokeChoice.addItem("5 pt");
        int strokes[] = {1, 3, 5};
        strokeChoice.addItemListener(e -> weight = strokes[strokeChoice.getSelectedIndex()]);
        strokeChoice.select(1);
        colorButtonPanel.add(strokeChoice, gbc);
    }

    private void loadButtonPanel(GridBagConstraints gbc) {

        BufferedImage circleImg = null, lineImg = null, rectImg = null, graffitiImg = null,
                markImg = null, eraseImg = null;
        try{
            lineImg = ImageIO.read(new File("line.png"));
            circleImg = ImageIO.read(new File("ellipse.png"));
            rectImg = ImageIO.read(new File("rect.png"));
            graffitiImg = ImageIO.read(new File("graffiti.png"));
            markImg = ImageIO.read(new File("mark.png"));
            eraseImg = ImageIO.read(new File("erase.png"));

        }
        catch(IOException e) {System.exit(1);}

        lineButton.setPreferredSize(new Dimension(50, 50));
        lineButton.setIcon(new ImageIcon(lineImg));
        lineButton.addActionListener(e -> changeState(0));
        gbc.gridx = 0; gbc.gridy += 1; gbc.gridwidth = 1;
        colorButtonPanel.add(lineButton, gbc);

        circleButton.setPreferredSize(new Dimension(50, 50));
        circleButton.setIcon(new ImageIcon(circleImg));
        circleButton.addActionListener(e -> {
            changeState(1);
            tempImg = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            tempImg.createGraphics().drawImage(img, 0, 0, img.getWidth(), img.getHeight(), null);
        });
        gbc.gridx += 1;
        colorButtonPanel.add(circleButton, gbc);

        rectButton.setPreferredSize(new Dimension(50, 50));
        rectButton.setIcon(new ImageIcon(rectImg));
        rectButton.addActionListener(e -> {
            changeState(2);
            tempImg = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            tempImg.createGraphics().drawImage(img, 0, 0, img.getWidth(), img.getHeight(), null);
        });
        gbc.gridy += 1; gbc.gridx = 0;
        colorButtonPanel.add(rectButton, gbc);

        graffitiButton.setPreferredSize(new Dimension(50, 50));
        graffitiButton.setIcon(new ImageIcon(graffitiImg));
        graffitiButton.addActionListener(e -> changeState(3));
        gbc.gridx += 1;
        colorButtonPanel.add(graffitiButton, gbc);

        markButton.setPreferredSize(new Dimension(50, 50));
        markButton.setIcon(new ImageIcon(markImg));
        markButton.addActionListener(e -> {
            changeState(4);
            tempImg = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            tempImg.createGraphics().drawImage(img, 0, 0, img.getWidth(), img.getHeight(), null);
        });
        gbc.gridy += 1; gbc.gridx = 0;
        colorButtonPanel.add(markButton, gbc);
        markButton.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
                if (areaSelected && e.getKeyChar() == KeyEvent.VK_DELETE) {
                    Graphics2D graphics = tempImg.createGraphics();
                    graphics.setColor(mainPanel.getBackground());
                    graphics.fillRect(rect.x - 2, rect.y - 2, rect.width + 4, rect.height + 4);
                    img.createGraphics().drawImage(tempImg, 0, 0, tempImg.getWidth(), tempImg.getHeight(), null);
                    repaint();
                    areaSelected = false;
                }
            }
        });

        eraseButton.setPreferredSize(new Dimension(50, 50));
        eraseButton.setIcon(new ImageIcon(eraseImg));
        eraseButton.addActionListener(e -> {
            changeState(5);
            tempImg = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            tempImg.createGraphics().drawImage(img, 0, 0, img.getWidth(), img.getHeight(), null);
        });
        gbc.gridx += 1;
        colorButtonPanel.add(eraseButton, gbc);
        eraseButton.addActionListener(e -> {
            tempImg = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            tempImg.createGraphics().drawImage(img, 0, 0, img.getWidth(), img.getHeight(), null);
        });
    }

    public void loadComponents() {

        JFileChooser fileChooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter("*.png", "png");
        fileChooser.setFileFilter(filter);
        fileChooser.setCurrentDirectory(new File("D:\\Computer Science\\BSU\\2 course\\Java\\Labs\\Kitikov_Lab11_Task2_ext"));
        fileChooser.setPreferredSize(new Dimension(1000,500));

    // main panel

        loadMainPanel();

    // scrollbar

        loadScrollbar();

    // menu

        loadMenu(fileChooser);

    // control panel

        colorButtonPanel = new JPanel();
        add(colorButtonPanel, BorderLayout.WEST);
        colorButtonPanel.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints(0,0,2,1,
                0,0,GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(10,10,20,10),0,0);

        loadColorPanel(gbc);
        loadFontWeightPanel(gbc);
        loadButtonPanel(gbc);

    }

    private MyWindow() {

        this.setTitle("Pa!nt");
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLayout(new BorderLayout());
        this.setBounds(100, 0, 1200, 900);
        this.setBackground(Color.lightGray);
    }

    static public MyWindow newInstance() {

        MyWindow myWindow = new MyWindow();
        myWindow.loadComponents();
        return myWindow;
    }

    public static void main(String Args[]) {

        MyWindow myWindow = MyWindow.newInstance();
        myWindow.setVisible(true);
    }
}
