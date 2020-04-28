package geometry;


import java.awt.*;

/**
 * @author User
 * @version 1.0
 * @created 09-мар-2020 23:55:40
 */
public class Parallelogram extends Polygon {

	public Parallelogram(){

	}

	public Parallelogram(Polygon other){
		super(other);
	}

	public void finalize() throws Throwable {
		super.finalize();
	}
	/**
	 * 
	 * @param c
	 * @param a
	 * @param b
	 */
	public Parallelogram(Point c, Point a, Point b){

	}

	public Parallelogram(Parallelogram other){
		super(other);
	}

	@Override
	public String info() {
		return "Parallelogram";
	}
}//end Parallelogram