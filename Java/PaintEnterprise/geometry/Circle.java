package geometry;


import javafx.scene.canvas.GraphicsContext;

import java.awt.*;

/**
 * @author User
 * @version 1.0
 * @created 09-мар-2020 23:55:40
 */
public class Circle extends Ellipse {

	public double radius;

	public Circle(){

	}

    public Circle(Circle other){
	    super(other);
        this.center = new Point(other.center);
        this.radius = other.radius;
    }

	public void finalize() throws Throwable {
		super.finalize();
	}

    @Override
    public void draw(GraphicsContext gc) {
        gc.strokeOval(center.x - radius, center.y - radius, 2*radius,2*radius);
        gc.fillOval(center.x - radius, center.y - radius, 2*radius,2*radius);
    }

    @Override
    public String info() {
        return "Circle";
    }
}//end Circle