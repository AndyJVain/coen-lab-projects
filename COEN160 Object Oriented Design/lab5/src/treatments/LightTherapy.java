package treatments;

public class LightTherapy extends Treatment {

	int intensity;

	public LightTherapy() {
		this.setName("Light Therapy");
		this.intensity = 10;
	}

	public int getIntensity() {
		return intensity;
	}

	public void setIntensity(int intensity) {
		this.intensity = intensity;
	}
}
