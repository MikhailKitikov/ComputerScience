package geometry;


import javafx.scene.canvas.GraphicsContext;

import java.awt.*;


public class Rectangle extends Parallelogram {

	public Rectangle(){
        this.points = new Point[2];
	}

    public Rectangle(Polygon other){
        super(other);
    }

    @Override
    public void draw(GraphicsContext gc) {
	    int w = Math.abs(points[0].x - points[1].x);
        int h = Math.abs(points[0].y - points[1].y);
        int x = Math.min(points[0].x, points[1].x);
        int y = Math.min(points[0].y, points[1].y);
        gc.fillRect(x, y, w, h);
        gc.strokeRect(x, y, w, h);
    }

    @Override
    public void move(int a, int b) {
        super.move(a, b);
    }

    public Rectangle(Point a, Point b){
		this.points = new Point[] {a, b};
	}

    public void setStart(Point a) {
        this.points[0] = a;
    }

    public void setEnd(Point b) {
        this.points[1] = b;
    }

    @Override
    public String info() {
        return "Rectangle";
    }
}