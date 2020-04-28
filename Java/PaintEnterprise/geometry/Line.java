package geometry;


import javafx.scene.canvas.GraphicsContext;


public class Line extends Ray {

    public Line(Ray other) {
        super(other);
    }

    public Line() {
    }

    public void draw(GraphicsContext gc) {
        super.draw(gc);
        int vectorX = this.center.x - this.secondPoint.x;
        int vectorY = this.center.y - this.secondPoint.y;
        this.secondPoint.x = this.center.x + vectorX;
        this.secondPoint.y = this.center.y + vectorY;
        super.draw(gc);
    }

    @Override
    public String info() {
        return "Line";
    }
}