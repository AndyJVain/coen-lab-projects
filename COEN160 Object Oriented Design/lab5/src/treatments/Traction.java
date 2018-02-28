package treatments;

public class Traction extends Treatment {

	int tension;

	public Traction() {
		this.setName("Traction");
		this.tension = 3;
	}

	public int getTension() {
		return tension;
	}

	public void setTension(int tension) {
		this.tension = tension;
	}
}
