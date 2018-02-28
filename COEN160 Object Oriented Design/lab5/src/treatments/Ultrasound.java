package treatments;

public class Ultrasound extends Treatment {

	int levelOfDetail;

	public Ultrasound() {
		this.setName("Ultrasound");
		this.levelOfDetail = 5;
	}

	public int getLevelOfDetail() {
		return levelOfDetail;
	}

	public void setLevelOfDetail(int levelOfDetail) {
		this.levelOfDetail = levelOfDetail;
	}
}