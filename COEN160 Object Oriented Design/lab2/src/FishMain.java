import java.awt.Graphics2D;

public class FishMain {
	public static void main(String args[]) {
		DrawingKit dk = new DrawingKit();
		Graphics2D myGraphics = dk.getGraphics();
		Graphics2D myGraphics2 = dk.getGraphics();
		
		Swordfish s = new Swordfish();
		s.drawShape(myGraphics);
		
		Goldfish g = new Goldfish();
		g.drawShape(myGraphics2);
		g.displayInformation();
	}
}
