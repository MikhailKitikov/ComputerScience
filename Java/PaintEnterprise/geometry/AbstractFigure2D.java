package geometry;


import javafx.scene.paint.Color;

/**
 * @author User
 * @version 1.0
 * @created 09-мар-2020 23:55:40
 */
public abstract class AbstractFigure2D extends AbstractFigure {

	public Color fillColor;

	public AbstractFigure2D(){

	}

	public AbstractFigure2D(AbstractFigure2D other){
		this.fillColor = other.fillColor;
	}

	public void finalize() throws Throwable {
		super.finalize();
	}
}//end AbstractFigure2D