package geometry;

import javafx.scene.paint.Color;


public abstract class AbstractFigure extends AbstractGeometricObject {

    @Override
    public void move(int a, int b) {
        center.x += a;
        center.y += b;
    }

    public Color borderColor;
}
