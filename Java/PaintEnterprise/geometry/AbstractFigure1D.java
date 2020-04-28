package geometry;

import java.awt.*;

public abstract class AbstractFigure1D extends AbstractFigure {

    public Point getSecondPoint() {
        return center;
    }

    public void setSecondPoint(Point center) {
        this.secondPoint = center;
    }

    public Point secondPoint;

    @Override
    public void move(int a, int b) {
        super.move(a, b);
        secondPoint.x += a;
        secondPoint.y += b;
    }
}
