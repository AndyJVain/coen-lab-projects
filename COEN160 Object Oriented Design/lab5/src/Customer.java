import treatments.*;

import java.io.Serializable;

public class Customer implements Serializable {
	private int id;
	private String name;
	private String address;
	private String contactNumber;
	private int age;
	private String gender;
	private String symptoms;
	private String diagnosis;
	private String insurance;
	private Billing billing;
	private String preferredTherapist;
	private Treatment treatment;

	public Customer(int id, String name, String address, String contactNumber, int age, String gender, String symptoms) {
		this.id = id;
		this.name = name;
		this.address = address;
		this.contactNumber = contactNumber;
		this.age = age;
		this.gender = gender;
		this.symptoms = symptoms;
		this.billing = new Billing();
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

	public String getGender() {
		return gender;
	}

	public String getSymptoms() {
		return symptoms;
	}

	public String getDiagnosis() {
		return diagnosis;
	}

	public String getInsurance() {
		return insurance;
	}

	public Billing getBilling() {
		return billing;
	}

	public String getPreferredTherapist() {
		return preferredTherapist;
	}

	public Treatment getTreatment() {
		return treatment;
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

	public void setGender(String gender) {
		this.gender = gender;
	}

	public void setSymptoms(String symptoms) {
		this.symptoms = symptoms;
	}

	public void setDiagnosis(String diagnosis) {
		this.diagnosis = diagnosis;
	}

	public void setInsurance(String insurance) {
		this.insurance = insurance;
	}

	public void setBilling(Billing billing) {
		this.billing = billing;
	}

	public void setPreferredTherapist(String preferredTherapist) {
		this.preferredTherapist = preferredTherapist;
	}

	public void setTreatment(Treatment treatment) {
		this.treatment = treatment;
	}

	public void addToBilling(Treatment treatment) {
		billing.addTreatment(treatment);
	}
}
