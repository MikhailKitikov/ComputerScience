package Kitikov_Task2;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.image.BufferedImage;
import java.util.Random;

public class MyMainPanelMouseMotionListener extends MouseMotionAdapter {

    MyWindow wnd;

    MyMainPanelMouseMotionListener(MyWindow wnd) {
        this.wnd = wnd;
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        if (wnd.state == 5) {
            wnd.img = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(), wnd.img.getType());
            Graphics2D imgGraphics = (Graphics2D)wnd.img.getGraphics();
            imgGraphics.setColor(Color.black);
            imgGraphics.drawImage(wnd.tempImg, 0, 0, wnd.tempImg.getWidth(), wnd.tempImg.getHeight(), null);
            imgGraphics.drawRect(e.getX() - 20, e.getY() - 20, 40, 40);
            wnd.repaint();
        }
    }
    public void mouseDragged(MouseEvent e) {
        if (wnd.areaSelected) {
            wnd.img = wnd.tempImg;
            wnd.repaint();
            wnd.areaSelected = false;
        }
        switch(wnd.state) {
            case 0: {
                if (wnd.shift) {
                    wnd.img = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(), wnd.img.getType());
                    Graphics2D imgGraphics = (Graphics2D)wnd.img.getGraphics();
                    imgGraphics.setColor(wnd.currColor.getBackground());
                    imgGraphics.setStroke(new BasicStroke(wnd.weight));
                    imgGraphics.drawImage(wnd.tempImg, 0, 0, wnd.tempImg.getWidth(), wnd.tempImg.getHeight(), null);
                    imgGraphics.drawLine(wnd.x, wnd.y, e.getX(), e.getY());
                    wnd.repaint();
                    return;
                }
                else {
                    Graphics2D imgGraphics = (Graphics2D)wnd.img.getGraphics();
                    imgGraphics.setColor(wnd.currColor.getBackground());
                    imgGraphics.setStroke(new BasicStroke(wnd.weight));
                    imgGraphics.drawLine(wnd.x, wnd.y, e.getX(), e.getY());
                    wnd.repaint();
                    wnd.x = e.getX();
                    wnd.y = e.getY();
                }
                break;
            }
            case 1: {
                wnd.img = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(), wnd.img.getType());
                Graphics2D imgGraphics = (Graphics2D)wnd.img.getGraphics();
                imgGraphics.setColor(wnd.currColor.getBackground());
                imgGraphics.setStroke(new BasicStroke(wnd.weight));
                imgGraphics.drawImage(wnd.tempImg, 0, 0, wnd.tempImg.getWidth(), wnd.tempImg.getHeight(), null);
                int w = Math.abs(wnd.x - e.getX());
                int h = Math.abs(wnd.y - e.getY());
                if (wnd.shift) {
                    int r = Math.min(w, h);
                    imgGraphics.drawOval(wnd.x - r, wnd.y - r, 2 * r, 2 * r);

                } else {
                    imgGraphics.drawOval(Math.min(wnd.x, e.getX()), Math.min(wnd.y, e.getY()), w, h);
                }
                wnd.repaint();
                break;
            }
            case 2: {
                wnd.img = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(), wnd.img.getType());
                Graphics2D imgGraphics = wnd.img.createGraphics();
                imgGraphics.setColor(wnd.currColor.getBackground());
                imgGraphics.setStroke(new BasicStroke(wnd.weight));
                imgGraphics.drawImage(wnd.tempImg, 0, 0, wnd.tempImg.getWidth(), wnd.tempImg.getHeight(), null);
                int w = Math.abs(wnd.x - e.getX());
                int h = Math.abs(wnd.y - e.getY());
                if (wnd.shift) {
                    int r = Math.min(w, h);
                    imgGraphics.drawRect(wnd.x - r, wnd.y - r, 2 * r, 2 * r);
                } else {
                    imgGraphics.drawRect(Math.min(wnd.x, e.getX()), Math.min(wnd.y, e.getY()), w, h);
                }
                wnd.repaint();
                break;
            }
            case 3: {
                Graphics2D imgGraphics = wnd.img.createGraphics();
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
                break;
            }
            case 4: {
                wnd.img = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(),wnd. img.getType());
                Graphics2D imgGraphics = (Graphics2D)wnd.img.getGraphics();
                imgGraphics.setColor(Color.black);
                Stroke dashed = new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL,
                        0, new float[]{3}, 0);
                imgGraphics.setStroke(dashed);
                imgGraphics.drawImage(wnd.tempImg, 0, 0, wnd.tempImg.getWidth(), wnd.tempImg.getHeight(), null);
                int w = Math.abs(wnd.x - e.getX());
                int h = Math.abs(wnd.y - e.getY());
                imgGraphics.drawRect(Math.min(wnd.x, e.getX()), Math.min(wnd.y, e.getY()), w, h);
                wnd.repaint();
                break;
            }
            case 5: {
                wnd. img = new BufferedImage(wnd.img.getWidth(), wnd.img.getHeight(), wnd.img.getType());
                Graphics2D imgGraphics = (Graphics2D)wnd.img.getGraphics();
                imgGraphics.setStroke(new BasicStroke(1));
                imgGraphics.setColor(Color.black);
                imgGraphics.drawImage(wnd.tempImg, 0, 0, wnd.tempImg.getWidth(), wnd.tempImg.getHeight(), null);
                imgGraphics.drawRect(e.getX() - 20, e.getY() - 20, 40, 40);
                Graphics2D tempImgGraphics = (Graphics2D)wnd.tempImg.getGraphics();
                tempImgGraphics.setColor(wnd.mainPanel.getBackground());
                tempImgGraphics.fillRect(e.getX() - 22, e.getY() - 22, 44, 44);
                wnd.repaint();
                break;
            }
        }
    }
}
