package geometry;


import javafx.scene.canvas.GraphicsContext;

public class Segment extends AbstractFigure1D {


	public Segment(Segment other) {
		this.center = other.center;
		this.setSecondPoint(other.secondPoint);
	}

    public Segment() {
    }

    public void draw(GraphicsContext gc){
        gc.strokeLine(this.center.x, this.center.y, this.secondPoint.x, this.secondPoint.y);
	}

	@Override
	public String info() {
		return "Segment";
	}


    @Override
    public void move(int a, int b) {
        super.move(a, b);
    }
}