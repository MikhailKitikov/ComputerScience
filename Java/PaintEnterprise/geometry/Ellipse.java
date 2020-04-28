package geometry;


import javafx.scene.canvas.GraphicsContext;

import java.awt.*;

/**
 * @author User
 * @version 1.0
 * @created 09-мар-2020 23:55:40
 */
public class Ellipse extends AbstractFigure2D {

	public Point firstPoint;
	public Point secondPoint;

	public Ellipse(){

	}

	public void finalize() throws Throwable {
		super.finalize();
	}
	/**
	 * 
	 * @param a
	 * @param b
	 */
	public Ellipse(Point a, Point b){

	}

	public Ellipse(Ellipse other){
		super(other);
	}

	@Override
	public String info() {
		return "Ellipse";
	}

	/**
	 * 
	 * @param c
	 */
	public void draw(GraphicsContext gc){

	}
}//end Ellipse