package geometry;


import javafx.scene.canvas.GraphicsContext;

import java.awt.*;

/**
 * @author User
 * @version 1.0
 * @created 09-мар-2020 23:55:40
 */
public class Polygon extends AbstractFigure2D {

	public Point[] getPoints() {
		return points;
	}

	public void setPoints(Point[] points) {
		this.points = points;
	}


	public Polygon(Polygon other){
		super(other);
        this.points = new Point[other.points.length];
		System.arraycopy(other.points, 0, this.points, 0, other.points.length);
	}

	public Point[] points;

	public Polygon(){

	}

	public void finalize() throws Throwable {
		super.finalize();
	}

	public void draw(GraphicsContext gc){

        double[] x = new double[points.length];
        double[] y = new double[points.length];
        for (int i =0; i < points.length; ++i) {
            x[i] = points[i].x;
            y[i] = points[i].y;
        }
        gc.fillPolygon(x,y,points.length);
	}

	public void move(int a, int b){
		for (int i = 0; i < points.length; ++i) {
			points[i].x += a;
			points[i].y += b;
		}
	}

	@Override
	public String info() {
		return "Polygon";
	}
}//end Polygon