package geometry;


import javafx.scene.canvas.GraphicsContext;


public class Ray extends Segment {

    public Ray(Ray other) {
        super(other);
    }

    public Ray() {
    }

    public void draw(GraphicsContext gc){

		int vectorX = secondPoint.x - center.x;
        int vectorY = secondPoint.y - center.y;

		gc.strokeLine(this.center.x, this.center.y,
                this.center.x + 1000 * vectorX, this.center.y + 1000 * vectorY);
	}

    @Override
    public String info() {
        return "Ray";
    }
}