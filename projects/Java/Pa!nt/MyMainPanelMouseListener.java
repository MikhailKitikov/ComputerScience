package Kitikov_Task2;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.util.Random;

public class MyMainPanelMouseListener extends MouseAdapter {

    MyWindow wnd;

    MyMainPanelMouseListener(MyWindow wnd) {
        this.wnd = wnd;
    }

    @Override
    public void mousePressed(MouseEvent e) {
        if (wnd.areaSelected) {
            wnd.img = wnd.tempImg;
            wnd.repaint();
            wnd.areaSelected = false;
        }
        wnd.shift = (e.getButton() == 3);
        wnd.x = e.getX();
        wnd.y = e.getY();

        if (wnd.shift || wnd.state != 3) {
            wnd.tempImg = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(), wnd.img.getType());
            wnd.tempImg.createGraphics().drawImage(wnd.img, 0, 0, wnd.img.getWidth(), wnd.img.getHeight(), null);
        }

        if (wnd.state == 3) {
            Graphics2D imgGraphics = (Graphics2D) wnd.img.getGraphics();
            imgGraphics.setColor(wnd.currColor.getBackground());
            imgGraphics.setStroke(new BasicStroke(wnd.weight));

            int posX = e.getX() - 20;
            int posY;
            Random rand = new Random(System.currentTimeMillis());
            for (int i = 0; i < 20; ++i) {
                posY = e.getY() - 20;
                for (int j = 0; j < 20; ++j) {
                    if (rand.nextInt(5) == 1) {
                        imgGraphics.drawOval(posX - 1, posY - 1, 2, 2);
                    }
                    posY += 2;
                }
                posX += 2;
            }
            wnd.repaint();
        }

        if (wnd.state == 5) {
            Graphics2D imgGraphics = (Graphics2D) wnd.tempImg.getGraphics();
            imgGraphics.setColor(wnd.mainPanel.getBackground());
            imgGraphics.setStroke(new BasicStroke(1));
            imgGraphics.fillRect(e.getX() - 22, e.getY() - 22, 44, 44);

            Graphics2D graphics = (Graphics2D) wnd.img.getGraphics();
            graphics.setColor(wnd.mainPanel.getBackground());
            graphics.setStroke(new BasicStroke(1));
            graphics.fillRect(e.getX() - 20, e.getY() - 20, 41, 41);

            wnd.repaint();
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        if (wnd.state == 4) {
            int w = Math.abs(wnd.x - e.getX());
            int h = Math.abs(wnd.y - e.getY());
            wnd.rect = new Rectangle(Math.min(wnd.x, e.getX()), Math.min(wnd.y, e.getY()), w, h);
            wnd.areaSelected = true;
        }
        if (wnd.state == 5) {
            wnd.img = wnd.tempImg;
            wnd.repaint();
        }
    }
}
