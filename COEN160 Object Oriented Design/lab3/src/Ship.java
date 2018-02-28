import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class Ship extends Vehicle {
	private String imageName = "\\\\SAMBA1\\avainaus\\dcengr\\My Documents\\eclipse-workspace\\Lab 3\\img\\independece_ots.png";
	
	public Ship(float x, float y) {
		this.x = x;
		this.y = y;
	}
	
	public void drawShape(Graphics2D myGraphics) {
		BufferedImage image = null;
		try {
			image = ImageIO.read(new File(imageName));
		} catch (IOException e) {
			System.out.println("There is an error with your imageName: " + imageName);
		}
		myGraphics.drawImage(image, (int) this.x, (int) this.y, null);
	}
	
	protected void step() {
		this.x++;
	}
	
	public static void main(String args[]) {
		Ship ship = new Ship(100,100);
		View view = new View(ship);
		Controller controller = new Controller(ship, view);
		view.setVisible(true);
	}
}
