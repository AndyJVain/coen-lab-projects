import java.awt.*;
/***  Created by carlos_rivera on 10/1/17.*/
public abstract class Fish {
	protected String type;
	protected double size;
	protected double weight;
	protected String fact;
	
	Fish() {
		type = "fish";
		size = 10.0;
		weight = 10.0;
		fact = "Fish swim in water.";
	}
	
	Fish(String type, double size, double weight, String fact) {
		this.type = type;
		this.size = size;
		this.weight = weight;
		this.fact = fact;
	}
	
	abstract void displayInformation();
	abstract void drawShape(Graphics2D g);
}