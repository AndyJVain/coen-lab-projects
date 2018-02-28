package treatments;

public class Massage extends Treatment {

	String oilType;

	public Massage() {
		this.setName("Massage");
		this.oilType = "Normal";
	}

	public String getOilType() {
		return oilType;
	}

	public void setOilType(String oilType) {
		this.oilType = oilType;
	}
}
