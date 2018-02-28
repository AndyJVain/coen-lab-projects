// Main.java
// This is the main file for Lab 1.
// This program draws a spaceship in a separate window, and it includes my name in the top left corner.


import java.awt.*;
import java.awt.geom.*;

import javax.swing.JLabel;

public class Main {
	public static void main(String[] args) {
		
		// Creates a new window titled "Lab 1" for the various shapes
		DrawingKit dk = new DrawingKit("Lab 1");
		
		// Creates my name in the upper left corner with a custom font
		dk.drawString("Andy Vainauskas", 10, 20);
		Font myFont = new Font("Helvetica", Font.BOLD,14);
		dk.setFont(myFont);
		
		// Draws a line underneath my name
		Line2D.Float underline = new Line2D.Float(10, 30, 105, 30);
		dk.draw(underline);
		
		// Creates the rectangle for the body of the spaceship, with a black fill
		Rectangle2D.Float rect = new Rectangle2D.Float(200, 100, 80, 250);
		dk.draw(rect);
		dk.fill(rect);
		
		// Creates the ellipse for the window with a green fill
		Ellipse2D.Float top = new Ellipse2D.Float(210, 150, 60, 60);
		dk.draw(top);
		dk.setPaint(Color.green);
		dk.fill(top);
		
		// Creates the curve for the top of the rocket with a blue fill
		QuadCurve2D.Float curve = new QuadCurve2D.Float(200, 100, 240, 40, 280, 100);
		dk.setPaint(Color.blue);
		dk.fill(curve);
		dk.draw(curve);
	}
}
