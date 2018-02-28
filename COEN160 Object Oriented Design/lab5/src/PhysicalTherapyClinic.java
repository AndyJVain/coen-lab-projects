import treatments.*;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.ArrayList;

public class PhysicalTherapyClinic implements Serializable {
	private String name;
	private String location;
	private String contactName;
	private int contactNumber;
	private int counter;

	private ArrayList<Customer> customers = new ArrayList<>();
	private ArrayList<Therapist> therapists = new ArrayList<>();
	private ArrayList<Appointment> appointments = new ArrayList<>();

	public Treatment treatments[] = {new Ultrasound(), new Traction(), new Massage(),
			new HeatTherapy(), new Exercise(), new LightTherapy(), new Hydrotherapy()};

	public PhysicalTherapyClinic(String name, String location, String contactName, int contactNumber) {
		this.name = name;
		this.location = location;
		this.contactName = contactName;
		this.contactNumber = contactNumber;
		this.counter = 0;
	}

	// Accessor methods
	public String getName() {
		return name;
	}

	public String getLocation() {
		return location;
	}

	public String getContactName() {
		return contactName;
	}

	public int getContactNumber() {
		return contactNumber;
	}

	public int getCounter() {
		return counter;
	}

	// Adds a customer to the list of customers
	public void addCustomer(Customer c ) {
		customers.add(c);
		counter++;
	}
	
	// Adds a therapist to the array of therapists
	public void addTherapist(Therapist t) {
		therapists.add(t);
		counter++;
	}

	// Adds an appointment to a given customer with ID
	public void addAppointment(Appointment appointment, double duration) {
		// Adds the treatment to the customer's billing
		for (Customer c : customers) {
			if (c.getId() == appointment.getClientID()) {
				c.addToBilling(appointment.getTreatment());
			}
		}

		for (Therapist t : therapists) {
			if (t.getId() == appointment.getTherapistID()) {
				t.updateTotalHours(duration);
				appointments.add(appointment);
				return;
			}
		}
	}
	
	// Prints the names of the customer array to the console
	public String listCustomers() {
		String result = "";
		for (Customer c : this.customers) {
			result += (c.getName() + "\n");
		}
		return result;
	}
	
	// Prints the names of the therapists array to the console
	public String listTherapists() {
		String result = "";
		for (Therapist t : this.therapists) {
			result += (t.getName() + "\n");
		}
		return result;
	}
	
	// Prints the treatments offered by the clinic
	public void listTreatments() {
		for (Treatment t : treatments) {
			System.out.println(t.getName());
		}
	}

	// Prints the list of rooms and when they are booked
	public String listRooms() {
		StringBuilder result = new StringBuilder();
		int id;
		for (Appointment a : appointments) {
			id = a.getClientID();
			for (Customer c : customers) {
				if (c.getId() == id) {
					result.append("Room " + a.getRoomNumber() + " has an appointment:" + "\n");
					result.append("Name: " + c.getName() + "\n");
					result.append("Date: " + a.getDay() + " from " + a.getStartTime() + " to " + a.getEndTime() + "\n");
					Treatment t = a.getTreatment();
					result.append("Therapy Type: " + t.getName() + "\n");
					result.append("\n");
				}
			}
		}
		return result.toString();
	}

	// Prints the appointment schedule for a given client
	public String listClientAppointments(Customer customer) {
		StringBuilder result = new StringBuilder();
		for (Appointment a : appointments) {
			if (customer.getId() == a.getClientID()) {
				result.append(customer.getName());
				result.append(" has an appointment on: ");
				result.append(a.getDay());
				result.append(" from ");
				result.append(a.getStartTime());
				result.append(" to ");
				result.append(a.getEndTime());
				result.append("\n");
			}
		}
		return result.toString();
	}

	// Prints available time slots for a give therapist (displays when they have appointments)
	public String listTherapistAppointments(Therapist therapist) {
		StringBuilder result = new StringBuilder();

		for (Appointment a : appointments) {
			if (a.getTherapistID() == therapist.getId()) {
				result.append(therapist.getName() + " has an appointment on: " + a.getDay()
						+ " from " + a.getStartTime() + " to " + a.getEndTime() + "\n");
			}
		}
		return result.toString();
	}

	// Prints the total hours worked by a given therapist
	public String listTotalHours(Therapist therapist) {
		StringBuilder result = new StringBuilder();
		result.append(therapist.getName() + " has worked " + therapist.getTotalHours() + " hours.");
		return result.toString();
	}

	// Prints billing information for each customer
	public String listBilling() {
		StringBuilder result = new StringBuilder();
		result.append("Customer Billing" + "\n");
		result.append("________________________________" + "\n");
		for (Customer c : customers) {
			result.append(c.getName() + " has the following billing info: " + "\n");
			result.append("Total amount due: " + c.getBilling().getAmountToPay() + "\n" + "\n");
		}

		result.append("Therapist Payments" + "\n");
		result.append("________________________________" + "\n");
		for (Therapist t : therapists) {
			result.append(t.getName() + " is paid " + t.getAmountToPay() + " dollars this month." + "\n");
		}
		return result.toString();
	}

	// Finds a treatment in the treatment array
	public int treatmentIndex(String a) {
		for (int i = 0; i < treatments.length; ++i) {
			if (treatments[i].getName().equals(a))
				return i;
		}
		return 0;
	}

	// Updates the cost of a given therapy
	public void setCost(String therapy, int cost) {
		BigDecimal d = new BigDecimal(cost);
		int i = treatmentIndex(therapy);
		treatments[i].setCost(d);
	}

	// Finds a customer class by name
	public Customer findCustomer(String name) {
		for (Customer c : customers) {
			if (c.getName().equals(name)) {
				return c;
			}
		}
		return null;
	}

	// Finds a therapist class by name
	public Therapist findTherapist(String name) {
		for (Therapist t : therapists) {
			if (t.getName().equals(name)) {
				return t;
			}
		}
		return null;
	}

	// Returns true if customer exists, false if they do not exist
	public boolean customerExists(String name) {
		for (Customer c : customers) {
			if (c.getName().equals(name)) {
				return true;
			}
		}
		return false;
	}

	// Returns true if therapist exists, false if they do not exist
	public boolean therapistExists(String name) {
		for (Therapist t : therapists) {
			if (t.getName().equals(name)) {
				return true;
			}
		}
		return false;
	}

	// Returns true if the treatment exists, false if it does not exist
	public boolean treatmentExists(String name) {
		for (Treatment t : treatments) {
			if (t.getName().equals(name))
				return true;
		}
		return false;
	}

	// Returns true if room is available, false if it is not available
	public boolean roomAvailable(int number, String day, int startTime) {
		for (Appointment a : appointments) {
			if (a.getRoomNumber() == number) {
				if (a.getDay().equals(day)) {
					if (a.getStartTime() == startTime) {
						return false;
					}
				}
			}
		}
		return true;
	}

	// Returns true if therapist is available, false if they are not available
	public boolean therapistAvailable(Therapist Therapist, String day, int startTime) {
		for (Appointment a : appointments) {
			if (a.getTherapistID() == Therapist.getId()) {
				if (a.getDay().equals(day)) {
					if (a.getStartTime() == startTime) {
						return false;
					}
				}
			}
		}
		return true;
	}
}