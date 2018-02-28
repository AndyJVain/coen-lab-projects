import treatments.Treatment;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.ArrayList;

public class Billing implements Payable, Serializable {
	private int customerID;
	private ArrayList<Treatment> treatments;
	private BigDecimal totalPrice;

	public Billing() {
		this.customerID = 0;
		this.treatments = new ArrayList<>();
		this.totalPrice = new BigDecimal(0);
	}

	public Billing(int customerID, ArrayList<Treatment> treatments, BigDecimal totalPrice) {
		this.customerID = customerID;
		this.treatments = treatments;
		this.totalPrice = totalPrice;
	}

	// Accessor methods
	public int getCustomerID() {
		return customerID;
	}

	public ArrayList<Treatment> getTreatments() {
		return treatments;
	}

	public BigDecimal getTotalPrice() {
		totalPrice = getAmountToPay();
		return totalPrice;
	}


	// Mutator methods
	public void setCustomerID(int customerID) {
		this.customerID = customerID;
	}

	public void setTreatments(ArrayList<Treatment> treatments) {
		this.treatments = treatments;
	}

	public void setTotalPrice(BigDecimal totalPrice) {
		this.totalPrice = totalPrice;
	}


	public BigDecimal getAmountToPay() {
		BigDecimal result = new BigDecimal(0);

		for (Treatment t : treatments) {
			result = result.add(t.getCost());
		}
		return result;
	}

	public void addTreatment(Treatment treatment) {
		treatments.add(treatment);
	}
}