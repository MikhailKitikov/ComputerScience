package geometry;


import javafx.scene.canvas.GraphicsContext;

import java.awt.*;
import java.io.Serializable;


public abstract class AbstractGeometricObject implements Serializable {

	public Point getCenter() {
		return center;
	}

	public void setCenter(Point center) {
		this.center = center;
	}

	public Point center;

	public AbstractGeometricObject(){

	}

	/**
	 * 
	 * @param c
	 */
	public abstract void draw(GraphicsContext gc);

	public Point location(){
		return null;
	}

	/**
	 * 
	 * @param a
	 * @param b
	 */
	public abstract void move(int a, int b);

	public String info() {
		return "object";
	}
}//end AbstractGeometricObject