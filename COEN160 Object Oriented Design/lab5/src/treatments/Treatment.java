package treatments;
import java.io.Serializable;
import java.math.BigDecimal;

public abstract class Treatment implements Serializable {
	protected String name;
	protected String prognosis;
	protected double duration;
	protected BigDecimal cost;
	
	// Mutator methods for the Treatment superclass
	public void setName(String name) {
		this.name = name;
	}
	
	public void setPrognosis(String prognosis) {
		this.prognosis = prognosis;
	}
	
	public void setDuration(double duration) {
		this.duration = duration;
	}
	
	public void setCost(BigDecimal cost) {
		this.cost = cost;
	}
	
	// Accessor methods for the Treatment superclass
	public String getName() {
		return this.name;
	}
	
	public String getPrognosis() {
		return this.prognosis;
	}
	
	public double getDuration() {
		return this.duration;
	}
	
	public BigDecimal getCost() {
		return this.cost;
	}
}
