package geometry;


import javafx.scene.canvas.Canvas;

import java.awt.*;
import java.util.List;

/**
 * @author User
 * @version 1.0
 * @created 09-мар-2020 23:55:40
 */
public abstract class AbstractFigureComposition extends AbstractGeometricObject {

	protected List<AbstractFigure> elements;
	public AbstractFigure m_AbstractFigure;

	public AbstractFigureComposition(){

	}

	public void finalize() throws Throwable {
		super.finalize();
	}
	/**
	 * 
	 * @param c
	 */
	public void draw(Canvas c){

	}

	/**
	 * 
	 * @param a
	 * @param v
	 */
	public void move(int a, int v){

	}
}//end AbstractFigureComposition