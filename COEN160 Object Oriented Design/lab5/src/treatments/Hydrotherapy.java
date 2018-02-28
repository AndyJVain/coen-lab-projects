package treatments;

public class Hydrotherapy extends Treatment {

	int temperature;

	public Hydrotherapy() {
		this.setName("Hydrotherapy");
		this.temperature = 30;
	}

	public int getTemperature() {
		return temperature;
	}

	public void setTemperature(int temperature) {
		this.temperature = temperature;
	}
}
