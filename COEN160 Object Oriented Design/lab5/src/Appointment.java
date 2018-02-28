import treatments.*;

import java.io.Serializable;

public class Appointment implements Serializable {
	private int clientID;
	private int therapistID;
	private int roomNumber;
	private String day;
	private int startTime;
	private int endTime;
	private Treatment treatment;

	public Appointment(int clientID, int therapistID, int roomNumber, String day, int startTime, int endTime, Treatment treatment) {
		this.clientID = clientID;
		this.therapistID = therapistID;
		this.roomNumber = roomNumber;
		this.day = day;
		this.startTime = startTime;
		this.endTime = endTime;
		this.treatment = treatment;
	}

	// Accessor methods
	public int getTherapistID() {
		return therapistID;
	}

	public int getClientID() {
		return clientID;
	}

	public int getRoomNumber() {
		return roomNumber;
	}

	public String getDay() {
		return day;
	}

	public int getStartTime() {
		return startTime;
	}

	public int getEndTime() {
		return endTime;
	}

	public Treatment getTreatment() {
		return treatment;
	}

	// Mutator methods
	public void setTherapistID(int therapistID) {
		this.therapistID = therapistID;
	}

	public void setClientID(int clientID) {
		this.clientID = clientID;
	}

	public void setRoomNumber(int roomNumber) {
		this.roomNumber = roomNumber;
	}

	public void setDay(String day) {
		this.day = day;
	}

	public void setStartTime(int startTime) {
		this.startTime = startTime;
	}

	public void setEndTime(int endTime) {
		this.endTime = endTime;
	}

	public void setTreatment(Treatment treatment) {
		this.treatment = treatment;
	}
}