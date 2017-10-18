package coreservlets;

/**
 * Simple bean to illustrate the various forms
 * of jsp:setpProperty.
 */

public class SaleEntry {
	private String itemID = "unknown";
	private double discountCode = 1.0;
	private int numItems = 0;

	public String getItemID() {
		return this.itemID;
	}

	public double getDiscountCode() {
		return this.discountCode;
	}

	public int getNumItems() {
		return this.numItems;
	}

	public void setItemID(String itemID) {
		this.itemID = itemID;
	}

	public void setDiscountCode(double discountCode) {
		this.discountCode = discountCode;
	}

	public void setNumItems(int numItems) {
		this.numItems = numItems;
	}

	public double getItemCost() {
		double cost;
		if (itemID.equals("a1234")) {
			cost = 12.99 * getDiscountCode();
		} else {
			cost = -9999;
		}
		return roundToPennies(cost);
	}

	public double roundToPennies(double cost) {
		return Math.floor(cost * 100) / 100.0;
	}

	public double getTotalCost() {
		return getNumItems() * getItemCost();
	}
}