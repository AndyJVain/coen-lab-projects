package treatments;

public class HeatTherapy extends Treatment {

	int temperature;

	public HeatTherapy() {
		this.setName("Heat Therapy");
		this.temperature = 100;
	}

	public int getTemperature() {
		return temperature;
	}

	public void setTemperature(int temperature) {
		this.temperature = temperature;
	}
}
