import java.io.Serializable;
import java.math.BigDecimal;

public class Therapist implements Payable, Serializable {
	private int id;
	private String name;
	private String address;
	private String contactNumber;
	private int age;
	private String credentials;
	private String specialization;
	private double totalHours;
	private BigDecimal hourlyRate;

	public Therapist(int id, String name, String address, String contactNumber, int age, BigDecimal hourlyRate) {
		this.id = id;
		this.name = name;
		this.address = address;
		this.contactNumber = contactNumber;
		this.age = age;
		this.totalHours = 0.0;
		this.hourlyRate = hourlyRate;
	}

	// Accessor methods
	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public String getAddress() {
		return address;
	}

	public String getContactNumber() {
		return contactNumber;
	}

	public int getAge() {
		return age;
	}

	public String getCredentials() {
		return credentials;
	}

	public String getSpecialization() {
		return specialization;
	}

	public BigDecimal getHourlyRate() {
		return hourlyRate;
	}

	public double getTotalHours() {
		return totalHours;
	}

	// Mutator methods
	public void setId(int id) {
		this.id = id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setContactNumber(String contactNumber) {
		this.contactNumber = contactNumber;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setCredentials(String credentials) {
		this.credentials = credentials;
	}

	public void setSpecialization(String specialization) {
		this.specialization = specialization;
	}

	public void setHourlyRate(BigDecimal hourlyRate) {
		this.hourlyRate = hourlyRate;
	}

	public void setTotalHours(double totalHours) {
		this.totalHours = totalHours;
	}

	public void updateTotalHours(double hours) {
		totalHours += hours;
	}

	public BigDecimal getAmountToPay() {
		BigDecimal total = hourlyRate;
		double monthlyHours = totalHours * 4;
		total = total.multiply(new BigDecimal(monthlyHours));
		return total;
	}
}