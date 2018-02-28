import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class ButtonLayout {
	
	// Button fields
	private Button b1;
	private Button b2;
	private Button b3;
	private Button b4;
	
	// Initializes each button to a new button and adds their actions to print their name to the console
	public ButtonLayout() {
		b1 = new Button("Button1");
		b2 = new Button("Button2");
		b3 = new Button("Button3");
		b4 = new Button("Button4");
		
		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(b1.getLabel());
			}
		});
		
		b2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(b2.getLabel());
			}
		});
		
		b3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(b3.getLabel());
			}
		});
		
		b4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(b4.getLabel());
			}
		});
	}
	
	// Arranges the buttons in the "FlowLayout" configuration
	public void flowLayout() {
		JFrame frame = new JFrame("FlowLayout");
		JPanel panel = new JPanel();
		Dimension d = new Dimension(400,400);
		panel.setLayout(new FlowLayout());
		frame.add(panel);
		panel.add(b1);
		panel.add(b2);
		panel.add(b3);
		panel.add(b4);
		frame.setPreferredSize(d);
		frame.pack();
		frame.setVisible(true);
	}
	
	// Arranges the buttons in the "BorderLayout" configuration
	public void borderLayout() {
		JFrame frame = new JFrame("BorderLayout");
		JPanel panel = new JPanel();
		Dimension d = new Dimension(400,400);
		panel.setLayout(new BorderLayout());
		frame.add(panel);
		panel.add(b1, BorderLayout.NORTH);
		panel.add(b2, BorderLayout.WEST);
		panel.add(b3, BorderLayout.EAST);
		panel.add(b4, BorderLayout.SOUTH);
		frame.setPreferredSize(d);
		frame.pack();
		frame.setVisible(true);
	}
	
	// Arranges the buttons in the "GridBagLayout" configuration
	public void gridBagLayout() {
		JFrame frame = new JFrame("GridLayout");
		JPanel panel = new JPanel();
		frame.add(panel);
		
		Dimension d = new Dimension(400,400);
		panel.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 0;
		c.gridy = 0;
		panel.add(b1, c);
		
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 1;
		c.gridy = 0;
		panel.add(b2, c);
		
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 2;
		c.gridy = 0;
		panel.add(b3, c);
		
		c.fill = GridBagConstraints.HORIZONTAL;
		c.ipady = 40;
		c.weightx = 0.0;
		c.gridwidth = 3;
		c.gridx = 0;
		c.gridy = 1;		
		panel.add(b4, c);
		
		frame.setPreferredSize(d);
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void main(String[] args) {
		ButtonLayout flow = new ButtonLayout();
		ButtonLayout border = new ButtonLayout();
		ButtonLayout grid = new ButtonLayout();
		
		flow.flowLayout();
		border.borderLayout();
		grid.gridBagLayout();
	}

}
