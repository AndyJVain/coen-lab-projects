import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class PizzaOrder {

	// Used to save the selected pizza size and toppings
	private String size;
	private String toppings;
	
	// Used for topping checkboxes
	private boolean cheeseSelected;
	private boolean pepperoniSelected;
	private boolean olivesSelected;
	private boolean mushroomsSelected;
	private boolean peppersSelected;
	
	private JLabel name;

	private JRadioButton small;
	private JRadioButton medium;
	private JRadioButton large;

	private JCheckBox cheese;
	private JCheckBox pepperoni;
	private JCheckBox olives;
	private JCheckBox mushrooms;
	private JCheckBox peppers;
	
	private JButton button;
	
	// Initializes all fields
	public PizzaOrder() {
		name = new JLabel();
		
		small = new JRadioButton();
		medium = new JRadioButton();
		large = new JRadioButton();
		
		cheese = new JCheckBox();
		pepperoni = new JCheckBox();
		olives = new JCheckBox();
		mushrooms = new JCheckBox();
		peppers = new JCheckBox();
		
		button = new JButton();
		
		size = "";
		toppings = "";
		
		cheeseSelected = false;
		pepperoniSelected = false;
		olivesSelected = false;
		mushroomsSelected = false;
		peppersSelected = false;
		
		addActions();
	}
	
	// Adds actions to each button
	public void addActions() {
		small.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				size = "small";
				medium.setSelected(false);
				large.setSelected(false);
			}
		});
		
		medium.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				size = "medium";
				small.setSelected(false);
				large.setSelected(false);
			}
		});
		
		large.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				size = "large";
				small.setSelected(false);
				medium.setSelected(false);
			}
		});
		
		cheese.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (cheese.isSelected()) {
					cheeseSelected = true;
				} else {
					cheeseSelected = false;
				}
			}
		});
		
		pepperoni.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (pepperoni.isSelected()) {
					pepperoniSelected = true;
				} else {
					pepperoniSelected = false;
				}
			}
		});
		
		olives.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (olives.isSelected()) {
					olivesSelected = true;
				} else {
					olivesSelected = false;
				}
			}
		});
		
		mushrooms.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (mushrooms.isSelected()) {
					mushroomsSelected = true;
				} else {
					mushroomsSelected = false;
				}
			}
		});
		
		peppers.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (peppers.isSelected()) {
					peppersSelected = true;
				} else {
					peppersSelected = false;
				}
			}
		});

		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				printOrder();
			}
		});
		
	}
	
	// Returns a JPanel that contains the name label
	public JPanel namePanel() {
		JPanel name = new JPanel();
		this.name.setText("Andy's Pizza Shop");
		name.add(this.name);
		return name;
	}
	
	// Returns a JPanel that contains the pizza size buttons
	public JPanel sizePanel() {
		JPanel size = new JPanel();
		size.setLayout(new FlowLayout());
		small.setText("Small");
		medium.setText("Medium");
		large.setText("Large");
		size.add(small);
		size.add(medium);
		size.add(large);
		return size;
	}
	
	// Returns a JPanel that contains the topping buttons
	public JPanel toppingsPanel() {
		JPanel toppings = new JPanel();
		toppings.setLayout(new FlowLayout());
		cheese.setText("Cheese");
		pepperoni.setText("Pepperoni");
		olives.setText("Olives");
		mushrooms.setText("Mushrooms");
		peppers.setText("Peppers");
		toppings.add(cheese);
		toppings.add(pepperoni);
		toppings.add(olives);
		toppings.add(mushrooms);
		toppings.add(peppers);
		return toppings;
	}
	
	// Returns a JPanel that contains the submit button
	public JPanel submitPanel() {
		JPanel submit = new JPanel();
		button.setText("Submit");
		submit.add(button);
		return submit;
	}
	
	// Prints out the selected order when the submit button is called
	public void printOrder() {
		toppings = "";
		if (cheeseSelected) {
			toppings += " cheese";
		}
		if (pepperoniSelected) {
			toppings += " pepperoni";
		}
		if (olivesSelected) {
			toppings += " olives";
		}
		if (mushroomsSelected) {
			toppings += " mushrooms";
		}
		if (peppersSelected) {
			toppings += " peppers";
		}
		System.out.println("You have ordered a " + size + " pizza with the following topping(s):" + toppings);
	}
	
	
	public static void main(String[] args) {
		PizzaOrder pizzaOrder = new PizzaOrder();
		JFrame frame = new JFrame();
		Dimension d = new Dimension(600,400);
		frame.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		
		// Arranges the name panel in the frame
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 0;
		c.gridy = 0;
		frame.add(pizzaOrder.namePanel(), c);
		
		// Arranges the pizza size panel in the frame
		c.fill = GridBagConstraints.HORIZONTAL;
		c.ipady = 40;
		c.weightx = 0.0;
		c.gridwidth = 3;
		c.gridx = 0;
		c.gridy = 1;
		frame.add(pizzaOrder.sizePanel(), c);
		
		// Arranges the toppings panel in the frame
		c.fill = GridBagConstraints.HORIZONTAL;
		c.ipady = 40;
		c.weightx = 0.0;
		c.gridwidth = 3;
		c.gridx = 0;
		c.gridy = 2;
		frame.add(pizzaOrder.toppingsPanel(), c);
		
		// Arranges the submit button in the frame
		c.fill = GridBagConstraints.HORIZONTAL;
		c.ipady = 40;
		c.weightx = 0.0;
		c.gridwidth = 3;
		c.gridx = 0;
		c.gridy = 3;
		frame.add(pizzaOrder.submitPanel(), c);
		
		frame.setPreferredSize(d);
		frame.pack();
		frame.setVisible(true);
	}

}
