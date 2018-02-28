import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.*;
import java.math.BigDecimal;

public class GUI extends JFrame {

    PhysicalTherapyClinic a = new PhysicalTherapyClinic("Andy's PT", "Santa Clara, CA", "Andy", 100);

    GUI() {
        readFile();
        Object[] options = {"Custom Cost", "Default cost"};
        int costSelection = JOptionPane.showOptionDialog(getContentPane(), "Use default therapy costs ($50/hr) OR enter custom costs?" ,
                "Set Therapy Costs", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, options,
                options[1]);

        // If the user selects default cost, set default values
        if (costSelection == 1) {
            a.setCost("Exercise", 50);
            a.setCost("Heat Therapy", 50);
            a.setCost("Hydrotherapy", 50);
            a.setCost("Light Therapy", 50);
            a.setCost("Massage", 50);
            a.setCost("Traction", 50);
            a.setCost("Ultrasound", 50);
        }

        String[] panelStrings = {"New Customer", "New Therapist", "New Booking", "Set Therapy Costs"};
        JComboBox cb = new JComboBox(panelStrings);

        JPanel cards = new JPanel(new CardLayout());

        JPanel newCustomerPanel = createCustomerPanel();
        JPanel newTherapistPanel = createTherapistPanel();
        JPanel newBookingPanel = createBookingPanel();
        JPanel costPanel = createCostPanel();


        // If the user selected custom costs
        if (costSelection == 0) {
            cb.setSelectedIndex(3);
            cards.add(costPanel, "Set Therapy Costs");
            cards.add(newCustomerPanel, "New Customer");
        } else {
            cb.setSelectedIndex(0);
            cards.add(newCustomerPanel, "New Customer");
            cards.add(costPanel, "Set Therapy Costs");
        }

        cards.add(newTherapistPanel, "New Therapist");
        cards.add(newBookingPanel, "New Booking");

        cb.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                CardLayout cl = (CardLayout)(cards.getLayout());
                cl.show(cards, (String)e.getItem());
            }
        });

        add(cb, BorderLayout.PAGE_START);
        add(cards, BorderLayout.CENTER);

        // create the menuBar for the various actions
        setJMenuBar(createMenuBar());

        setLayout(new BoxLayout(getContentPane(), BoxLayout.PAGE_AXIS));
        setSize(600,600);
        setTitle(a.getName());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public JMenuBar createMenuBar() {
        JMenuBar menuBar = new JMenuBar();

        JMenu info = new JMenu("Info");
        JMenu save = new JMenu("Save");
        menuBar.add(info);
        menuBar.add(save);


        JMenuItem listCustomers = new JMenuItem("Customers");
        JMenuItem listTherapists = new JMenuItem("Therapists");
        JMenuItem listAppointments = new JMenuItem("Customer Appointments");
        JMenuItem listRooms = new JMenuItem("Rooms");
        JMenuItem listHours = new JMenuItem("Hours");
        JMenuItem listAvailability = new JMenuItem("Availability");
        JMenuItem listBilling = new JMenuItem("Billing");
        JMenuItem saveData = new JMenuItem("Save Data");
        info.add(listCustomers);
        info.add(listTherapists);
        info.add(listAppointments);
        info.add(listRooms);
        info.add(listHours);
        info.add(listAvailability);
        info.add(listBilling);
        save.add(saveData);

        listCustomers.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(getContentPane(), a.listCustomers(), "Customer List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        listTherapists.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(getContentPane(), a.listTherapists(), "Therapist List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        listAppointments.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String client = JOptionPane.showInputDialog
                        (getContentPane(), "Enter customer name to list their appointments: ", "Customer Name", JOptionPane.PLAIN_MESSAGE);
                Customer c = a.findCustomer(client);
                if (c == null) {
                    JOptionPane.showMessageDialog(getContentPane(), "That customer does not exist", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }
                JOptionPane.showMessageDialog(getContentPane(), a.listClientAppointments(c), "Appointment List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        listRooms.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(getContentPane(), a.listRooms(), "Room List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        listHours.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String therapist = JOptionPane.showInputDialog
                        (getContentPane(), "Enter therapist name to list their hours: ", "Therapist Name", JOptionPane.PLAIN_MESSAGE);
                Therapist t = a.findTherapist(therapist);
                if (t == null) {
                    JOptionPane.showMessageDialog(getContentPane(), "That therapist does not exist", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }
                JOptionPane.showMessageDialog(getContentPane(), a.listTotalHours(t), "Appointment List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        listAvailability.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String therapist = JOptionPane.showInputDialog
                        (getContentPane(), "Enter therapist name to list their availability: ", "Therapist Name", JOptionPane.PLAIN_MESSAGE);
                Therapist t = a.findTherapist(therapist);
                if (t == null) {
                    JOptionPane.showMessageDialog(getContentPane(), "That therapist does not exist", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }
                JOptionPane.showMessageDialog(getContentPane(), a.listTherapistAppointments(t), "Appointment List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        listBilling.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(getContentPane(), a.listBilling(), "Billing List", JOptionPane.PLAIN_MESSAGE);
            }
        });

        saveData.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                writeFile();
            }
        });

        return menuBar;
    }

    public JPanel createCustomerPanel() {
        // Customer Panel
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        // Name
        JPanel namePanel = new JPanel(new FlowLayout());
        JLabel name = new JLabel("Name: ");
        JTextField nameText = new JTextField();
        nameText.setColumns(20);
        namePanel.add(name);
        namePanel.add(nameText);

        // Address
        JPanel addressPanel = new JPanel(new FlowLayout());
        JLabel address = new JLabel("Address: ");
        JTextField addressText = new JTextField();
        addressText.setColumns(25);
        addressPanel.add(address);
        addressPanel.add(addressText);

        // Contact Number
        JPanel contactPanel = new JPanel(new FlowLayout());
        JLabel number = new JLabel("Phone Number:");
        JFormattedTextField numberText = new JFormattedTextField();
        numberText.setColumns(15);
        contactPanel.add(number);
        contactPanel.add(numberText);

        // Age
        JPanel agePanel = new JPanel(new FlowLayout());
        JLabel age = new JLabel("Age: ");
        JTextField ageText = new JTextField();
        ageText.setColumns(20);
        agePanel.add(age);
        agePanel.add(ageText);

        // Gender
        JPanel genderPanel = new JPanel(new FlowLayout());
        JLabel gender = new JLabel("Gender: ");
        JRadioButton male = new JRadioButton("Male");
        JRadioButton female = new JRadioButton("Female");
        genderPanel.add(gender);
        genderPanel.add(male);
        genderPanel.add(female);
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(male);
        genderGroup.add(female);

        // Symptoms
        JPanel symptomsPanel = new JPanel(new FlowLayout());
        JLabel symptoms = new JLabel("Symptoms: ");
        JTextField symptomsText = new JTextField();
        symptomsText.setColumns(20);
        symptomsPanel.add(symptoms);
        symptomsPanel.add(symptomsText);

        // Submit
        JPanel submitPanel = new JPanel(new FlowLayout());
        JButton submit = new JButton("Submit");
        submitPanel.add(submit);

        submit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameText.getText();
                String address = addressText.getText();
                String number = numberText.getText();
                int age = Integer.parseInt(ageText.getText());
                String gender;
                if (male.isSelected()) {
                    gender = "Male";
                } else if (female.isSelected()) {
                    gender = "Female";
                } else {
                    return;
                }
                String symptoms = symptomsText.getText();
                Customer c = new Customer(a.getCounter(), name, address, number, age, gender, symptoms);
                a.addCustomer(c);

                // clear textFields
                nameText.setText("");
                addressText.setText("");
                numberText.setText("");
                ageText.setText("");
                symptomsText.setText("");
                genderGroup.clearSelection();
                JOptionPane.showMessageDialog(getContentPane(), "Customer successfully added.", "Success", JOptionPane.PLAIN_MESSAGE);
            }
        });

        panel.add(namePanel);
        panel.add(addressPanel);
        panel.add(contactPanel);
        panel.add(agePanel);
        panel.add(genderPanel);
        panel.add(symptomsPanel);
        panel.add(submitPanel);
        return panel;
    }

    public JPanel createTherapistPanel() {
        // Therapist Panel
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        // Name
        JPanel namePanel = new JPanel(new FlowLayout());
        JLabel name = new JLabel("Name: ");
        JTextField nameText = new JTextField();
        nameText.setColumns(20);
        namePanel.add(name);
        namePanel.add(nameText);

        // Address
        JPanel addressPanel = new JPanel(new FlowLayout());
        JLabel address = new JLabel("Address: ");
        JTextField addressText = new JTextField();
        addressText.setColumns(25);
        addressPanel.add(address);
        addressPanel.add(addressText);

        // Contact Number
        JPanel contactPanel = new JPanel(new FlowLayout());
        JLabel number = new JLabel("Phone Number:");
        JFormattedTextField numberText = new JFormattedTextField();
        numberText.setColumns(15);
        contactPanel.add(number);
        contactPanel.add(numberText);

        // Age
        JPanel agePanel = new JPanel(new FlowLayout());
        JLabel age = new JLabel("Age: ");
        JTextField ageText = new JTextField();
        ageText.setColumns(20);
        agePanel.add(age);
        agePanel.add(ageText);

        // Hourly Rate
        JPanel hourlyPanel = new JPanel(new FlowLayout());
        JLabel hourlyRate = new JLabel("Hourly Rate ($): ");
        JFormattedTextField hourlyRateText = new JFormattedTextField();
        hourlyRateText.setColumns(15);
        hourlyPanel.add(hourlyRate);
        hourlyPanel.add(hourlyRateText);

        // Submit
        JPanel submitPanel = new JPanel(new FlowLayout());
        JButton submit = new JButton("Submit");
        submitPanel.add(submit);

        submit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameText.getText();
                String address = addressText.getText();
                String number = numberText.getText();
                int age = Integer.parseInt(ageText.getText());
                BigDecimal hourlyRate = new BigDecimal(Integer.parseInt(hourlyRateText.getText()));

                Therapist t = new Therapist(a.getCounter(), name, address, number, age, hourlyRate);
                a.addTherapist(t);

                // clear textFields
                nameText.setText("");
                addressText.setText("");
                numberText.setText("");
                ageText.setText("");
                hourlyRateText.setText("");
                JOptionPane.showMessageDialog(getContentPane(), "Therapist successfully added.", "Success", JOptionPane.PLAIN_MESSAGE);
            }
        });

        panel.add(namePanel);
        panel.add(addressPanel);
        panel.add(contactPanel);
        panel.add(agePanel);
        panel.add(hourlyPanel);
        panel.add(submitPanel);
        return panel;
    }

    public JPanel createBookingPanel() {
        // Booking Panel
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        // Customer Name
        JPanel cNamePanel = new JPanel(new FlowLayout());
        JLabel cName = new JLabel("Customer Name: ");
        JTextField cNameText = new JTextField();
        cNameText.setColumns(20);
        cNamePanel.add(cName);
        cNamePanel.add(cNameText);

        // Therapist Name
        JPanel tNamePanel = new JPanel(new FlowLayout());
        JLabel tName = new JLabel("Therapist Name: ");
        JTextField tNameText = new JTextField();
        tNameText.setColumns(20);
        tNamePanel.add(tName);
        tNamePanel.add(tNameText);

        // Room Number
        JPanel roomPanel = new JPanel(new FlowLayout());
        JLabel room = new JLabel("Room Number: ");
        JTextField roomText = new JTextField();
        roomText.setColumns(25);
        roomPanel.add(room);
        roomPanel.add(roomText);

        // Day
        JPanel dayPanel = new JPanel(new FlowLayout());
        JLabel day = new JLabel("Day of the Week:");
        JFormattedTextField dayText = new JFormattedTextField();
        dayText.setColumns(15);
        dayPanel.add(day);
        dayPanel.add(dayText);

        // Start Time
        JPanel sTimePanel = new JPanel(new FlowLayout());
        JLabel sTime = new JLabel("Start Time (24hr): ");
        JTextField sTimeText = new JTextField();
        sTimeText.setColumns(20);
        sTimePanel.add(sTime);
        sTimePanel.add(sTimeText);

        // End Time
        JPanel eTimePanel = new JPanel(new FlowLayout());
        JLabel eTime = new JLabel("End Time (24hr): ");
        JTextField eTimeText = new JTextField();
        eTimeText.setColumns(20);
        eTimePanel.add(eTime);
        eTimePanel.add(eTimeText);

        // Duration
        JPanel durationPanel = new JPanel(new FlowLayout());
        JLabel duration = new JLabel("Duration (hrs): ");
        JTextField durationText = new JTextField();
        durationText.setColumns(20);
        durationPanel.add(duration);
        durationPanel.add(durationText);

        // Treatment
        JPanel treatmentPanel = new JPanel(new FlowLayout());
        JLabel treatment = new JLabel("Treatment: ");
        JTextField treatmentText = new JTextField();
        treatmentText.setColumns(20);
        treatmentPanel.add(treatment);
        treatmentPanel.add(treatmentText);

        // Submit
        JPanel submitPanel = new JPanel(new FlowLayout());
        JButton submit = new JButton("Submit");
        submitPanel.add(submit);

        submit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String customerName = cNameText.getText();
                String therapistName = tNameText.getText();

                // Searches both customer and therapist arrays to make sure the name has already been added
                if (!a.customerExists(customerName)) {
                    JOptionPane.showMessageDialog(getContentPane(), "Customer does not exist", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }

                if (!a.therapistExists(therapistName)) {
                    JOptionPane.showMessageDialog(getContentPane(), "Therapist does not exist", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }

                Customer customer = a.findCustomer(customerName);
                Therapist therapist = a.findTherapist(therapistName);
                int roomNumber = Integer.parseInt(roomText.getText());
                String day = dayText.getText();
                int startTime = Integer.parseInt(sTimeText.getText());
                int endTime = Integer.parseInt(eTimeText.getText());
                double duration = Double.parseDouble(durationText.getText());
                String treatment = treatmentText.getText();

                // Checks if room is available
                if (!a.roomAvailable(roomNumber, day, startTime)) {
                    JOptionPane.showMessageDialog(getContentPane(), "The room is not available at that time.", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }

                // Checks if therapist is available
                if (!a.therapistAvailable(therapist, day, startTime)) {
                    JOptionPane.showMessageDialog(getContentPane(), "The therapist is not available at that time.", "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }

                // Checks for valid treatment
                if (!a.treatmentExists(treatment)) {
                    JOptionPane.showMessageDialog
                            (getContentPane(), "Not a valid treatment. Check spelling, make sure it is capitalized, with correct spaces.",
                                    "Error", JOptionPane.PLAIN_MESSAGE);
                    return;
                }

                Appointment appointment = new Appointment
                        (customer.getId(), therapist.getId(), roomNumber, day, startTime, endTime, a.treatments[a.treatmentIndex(treatment)]);

                a.addAppointment(appointment, duration);

                // clear textFields
                cNameText.setText("");
                tNameText.setText("");
                roomText.setText("");
                dayText.setText("");
                sTimeText.setText("");
                eTimeText.setText("");
                durationText.setText("");
                treatmentText.setText("");

                JOptionPane.showMessageDialog(getContentPane(), "Appointment successfully added.", "Success", JOptionPane.PLAIN_MESSAGE);
            }
        });

        panel.add(cNamePanel);
        panel.add(tNamePanel);
        panel.add(roomPanel);
        panel.add(dayPanel);
        panel.add(sTimePanel);
        panel.add(eTimePanel);
        panel.add(durationPanel);
        panel.add(treatmentPanel);
        panel.add(submit);
        return panel;
    }

    public JPanel createCostPanel() {
        // Cost Panel
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        // Exercise
        JPanel exercisePanel = new JPanel(new FlowLayout());
        JLabel exercise = new JLabel("Exercise Cost ($): ");
        JFormattedTextField exerciseText = new JFormattedTextField();
        exerciseText.setColumns(20);
        exercisePanel.add(exercise);
        exercisePanel.add(exerciseText);

        // Heat Therapy
        JPanel heatTherapyPanel = new JPanel(new FlowLayout());
        JLabel heatTherapy = new JLabel("Heat Therapy Cost ($): ");
        JFormattedTextField heatTherapyText = new JFormattedTextField();
        heatTherapyText.setColumns(20);
        heatTherapyPanel.add(heatTherapy);
        heatTherapyPanel.add(heatTherapyText);

        // Hydrotherapy
        JPanel hydrotherapyPanel = new JPanel(new FlowLayout());
        JLabel hydrotherapy = new JLabel("Hydrotherapy Cost ($): ");
        JFormattedTextField hydrotherapyText = new JFormattedTextField();
        hydrotherapyText.setColumns(20);
        hydrotherapyPanel.add(hydrotherapy);
        hydrotherapyPanel.add(hydrotherapyText);

        // Light Therapy
        JPanel lightTherapyPanel = new JPanel(new FlowLayout());
        JLabel lightTherapy = new JLabel("Light Therapy Cost ($): ");
        JFormattedTextField lightTherapyText = new JFormattedTextField();
        lightTherapyText.setColumns(20);
        lightTherapyPanel.add(lightTherapy);
        lightTherapyPanel.add(lightTherapyText);

        // Massage
        JPanel massagePanel = new JPanel(new FlowLayout());
        JLabel massage = new JLabel("Massage Cost ($): ");
        JFormattedTextField massageText = new JFormattedTextField();
        massageText.setColumns(20);
        massagePanel.add(massage);
        massagePanel.add(massageText);

        // Traction
        JPanel tractionPanel = new JPanel(new FlowLayout());
        JLabel traction = new JLabel("Traction Cost ($): ");
        JFormattedTextField tractionText = new JFormattedTextField();
        tractionText.setColumns(20);
        tractionPanel.add(traction);
        tractionPanel.add(tractionText);

        // Ultrasound
        JPanel ultrasoundPanel = new JPanel(new FlowLayout());
        JLabel ultrasound = new JLabel("Ultrasound Cost ($): ");
        JFormattedTextField ultrasoundText = new JFormattedTextField();
        ultrasoundText.setColumns(20);
        ultrasoundPanel.add(ultrasound);
        ultrasoundPanel.add(ultrasoundText);

        // Submit
        JPanel submitPanel = new JPanel(new FlowLayout());
        JButton submit = new JButton("Submit");
        submitPanel.add(submit);

        submit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int exerciseCost = Integer.parseInt(exerciseText.getText());
                int heatTherapyCost = Integer.parseInt(heatTherapyText.getText());
                int hydrotherapyCost = Integer.parseInt(hydrotherapyText.getText());
                int lightTherapyCost = Integer.parseInt(lightTherapyText.getText());
                int massageCost = Integer.parseInt(massageText.getText());
                int tractionCost = Integer.parseInt(tractionText.getText());
                int ultrasoundCost = Integer.parseInt(ultrasoundText.getText());

                a.setCost("Exercise", exerciseCost);
                a.setCost("Heat Therapy", heatTherapyCost);
                a.setCost("Hydrotherapy", hydrotherapyCost);
                a.setCost("Light Therapy", lightTherapyCost);
                a.setCost("Massage", massageCost);
                a.setCost("Traction", tractionCost);
                a.setCost("Ultrasound", ultrasoundCost);

                // clear textFields
                exerciseText.setText("");
                heatTherapyText.setText("");
                hydrotherapyText.setText("");
                lightTherapyText.setText("");
                massageText.setText("");
                tractionText.setText("");
                ultrasoundText.setText("");

                JOptionPane.showMessageDialog(getContentPane(), "Therapy costs successfully updated.", "Success", JOptionPane.PLAIN_MESSAGE);
            }
        });

        panel.add(exercisePanel);
        panel.add(heatTherapyPanel);
        panel.add(hydrotherapyPanel);
        panel.add(lightTherapyPanel);
        panel.add(massagePanel);
        panel.add(tractionPanel);
        panel.add(ultrasoundPanel);
        panel.add(submitPanel);
        return panel;
    }

    public void readFile() {
        File f = new File("/Users/Andy/Documents/SCU/therapy.dat");
        if(f.exists() && !f.isDirectory()) {
            ObjectInputStream objectIn = null;
            try {
                FileInputStream fileIn = new FileInputStream("/Users/Andy/Documents/SCU/therapy.dat");
                objectIn = new ObjectInputStream(fileIn);
                a = (PhysicalTherapyClinic) objectIn.readObject();
                objectIn.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void writeFile() {
        ObjectOutputStream objectOut = null;
        FileOutputStream fileOut = null;
        try{
            fileOut = new FileOutputStream("/Users/Andy/Documents/SCU/therapy.dat");
            objectOut = new ObjectOutputStream(fileOut);
            objectOut.writeObject(a);
            objectOut.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        GUI gui = new GUI();
    }
}
