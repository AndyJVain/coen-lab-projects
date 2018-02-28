import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Goldfish extends Fish {
	String imageName = new String("\\\\SAMBA1\\avainaus\\dcengr\\My Documents\\eclipse-workspace\\Lab 2\\img\\images\\goldfish.jpg");

	Goldfish() {
		type = "Carassius auratus";
		size = 1.2;
		weight = 0.1;
		fact = "This fish is one of the most common pets.";
	}
	
	Goldfish(String goldfishType, double goldfishSize, double goldfishWeight, String goldfishFact) {
		type = goldfishType;
		size = goldfishSize;
		weight = goldfishWeight;
		fact = goldfishFact;
	}
	
	public String getType() {
		return type; 
	}
	
	public double getSize() {
		return size;
	}
	
	public double getWeight() {
		return weight;
	}
	
	public String getFact() {
		return fact;
	}
	
	// Method for displaying various object fields and data
	public void displayInformation() {
		System.out.println("This fish is a goldfish.");
		System.out.println("Its type is: " + type);
		System.out.println("Its size is: " + size);
		System.out.println("Its weight is: " + weight);
		System.out.println(fact);
	}
	
	// Displays an image of a goldfish
	public void drawShape(Graphics2D g) {
		BufferedImage image = null;
		try {
			image = ImageIO.read(new File(imageName));
		} catch (IOException e) {
			System.out.println("There is an error with your imageName: " + imageName);
		}
		g.drawImage(image, 0, 0, null);
	}
}
