package treatments;

public class Exercise extends Treatment {

	int intensity;

	public Exercise() {
		this.setName("Exercise");
		this.intensity = 5;
	}

	public int getIntensity() {
		return intensity;
	}

	public void setIntensity(int intensity) {
		this.intensity = intensity;
	}
}
