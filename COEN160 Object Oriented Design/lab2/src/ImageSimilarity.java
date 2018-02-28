import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class ImageSimilarity {
	private int[] red = new int[256];
	private int[] green = new int[256];
	private int[] blue = new int[256];
	
	// Constructor for the ImageSimilarity class
	public ImageSimilarity() {
		
		// Initializes the 3 histogram arrays to 0
		for(int i = 0; i < 256; i++) {
			red[i] = 0;
			green[i] = 0;
			blue[i] = 0;
		}
	}
	
	public int[] getRed() {
		return red;
	}
	
	public int[] getGreen() {
		return green;
	}
	
	public int[] getBlue() {
		return blue;
	}
	
	public void histogram(String imageName) {
		// Creates an image using the path from the parameter imageName
		BufferedImage image = null;
		try {
			image = ImageIO.read(new File(imageName));
		} catch (IOException e) {
			System.out.println("There is an error with your imageName: " + imageName);
		}
		
		int pixelRGB = image.getRGB(0, 0);
		Color pixelColor = new Color(pixelRGB);
		
		// Loops through each pixel and adds to the correct array position
		for(int x = 0; x < image.getWidth(); x++) {
			for(int y = 0; y < image.getHeight(); y++) {
				pixelColor = new Color(image.getRGB(x, y));
				red[pixelColor.getRed()]++;
				green[pixelColor.getGreen()]++;
				blue[pixelColor.getBlue()]++;
			}
		}
	}
	
	public double euclideanDistance(ImageSimilarity otherImage) {
		int[] otherRed = otherImage.getRed();
		int[] otherGreen = otherImage.getGreen();
		int[] otherBlue = otherImage.getBlue();
		double result = 0;
		
		// Continuously add to result each power of RGB values from both objects
		for(int i = 0; i < 256; i++) {
			result += Math.pow((red[i] - otherRed[i]), 2);
			result += Math.pow((green[i] - otherGreen[i]), 2);
			result += Math.pow((blue[i] - otherBlue[i]), 2);
		}
		return Math.sqrt(result);
	}
}
