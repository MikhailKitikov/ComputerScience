package geometry;

import javafx.scene.canvas.GraphicsContext;

import java.awt.*;

class RotationalPolygon extends Polygon {

    public Point[] getPoints() {
        return points;
    }

    public void setPoints(Point[] points) {
        this.points = points;
    }

    public void setRotate(Point ct, Point not, int n){
        points = new Point[n];
        double a = ct.getX();
        double b = ct.getY();
        double c = not.getX();
        double d = not.getY();
        double r = Point.distance((int)a,(int)b,(int)c,(int)d);

        double ang = Math.asin((b-d)/r);

        if (a > c) {
            ang = Math.PI - ang;
        }

        double di = 2*Math.PI/n;

        points[0] = new Point((int)not.getX(),(int)not.getY());
        for (int i = 1; i < n; ++i) {
            points[i] = new Point((int)(a+r*Math.cos(ang+i*di)),(int)(b - r*Math.sin(ang+i*di)));
        }

    }


    public RotationalPolygon(RotationalPolygon other){
        super(other);
        this.points = new Point[other.points.length];
        System.arraycopy(other.points, 0, this.points, 0, other.points.length);
    }

    public Point[] points;

    public RotationalPolygon(){

    }

    public void finalize() throws Throwable {
        super.finalize();
    }

    public void draw(GraphicsContext gc){
        super.draw(gc);
    }

    public void move(int a, int b){
        for (int i = 0; i < points.length; ++i) {
            points[i].x += a;
            points[i].y += b;
        }
    }

    @Override
    public String info() {
        return "RotationalPolygon";
    }
}//end Polygon