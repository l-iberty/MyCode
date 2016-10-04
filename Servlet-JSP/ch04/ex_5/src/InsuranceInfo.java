package coreservlets.beans;

public class InsuranceInfo {
	private String name = "No name";
	private String employeeID = "No ID";
	private int numChildren = 0;
	private boolean isMarried = false;

	public String getName() {
		return name;
	}

	public String getEmployeeID() {
		return employeeID;
	}

	public int getNumChildren() {
		return numChildren;
	}

	public boolean isMarried() {
		return isMarried;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setEmployeeID(String employeeID) {
		this.employeeID = employeeID;
	}

	public void setNumChildren(int numChildren) {
		this.numChildren = numChildren;
	}

	public void setMarried(boolean isMarried) {
		this.isMarried = isMarried;
	}
}