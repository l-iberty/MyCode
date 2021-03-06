package coreservlets.beans;

import coreservlets.ServletUtilities;

public class BidInfo {
	private String itemID = "";
	private String itemName = "";
	private String bidderName = "";
	private String emailAddress = "";
	private double bidPrice = 0;
	private boolean autoIncrement = false;

	public String getItemID() {
		return itemID;
	}

	public void setItemID(String itemID) {
		this.itemID = ServletUtilities.filter(itemID);
	}

	public String getItemName() {
		return itemName;
	}

	public void setItemName(String itemName) {
		this.itemName = ServletUtilities.filter(itemName);
	}

	public String getBidderName() {
		return bidderName;
	}

	public void setBidderName(String bidderName) {
		this.bidderName = ServletUtilities.filter(bidderName);
	}

	public String getEmailAddress() {
		return emailAddress;
	}

	public void setEmailAddress(String emailAddress) {
		this.emailAddress = ServletUtilities.filter(emailAddress);
	}

	public double getBidPrice() {
		return bidPrice;
	}

	public void setBidPrice(double bidPrice) {
		this.bidPrice = bidPrice;
	}

	public boolean isAutoIncrement() {
		return autoIncrement;
	}

	public void setAutoIncrement(boolean autoIncrement) {
		this.autoIncrement = autoIncrement;
	}


	public boolean isComplete() {
		return (hasValue(getItemID()) &&
				hasValue(getItemName()) &&
				hasValue(getBidderName()) &&
				hasValue(getEmailAddress()) &&
				(getBidPrice() > 0));
	}

	public boolean isPartlyComplete() {
		return (hasValue(getItemID()) ||
				hasValue(getItemName()) ||
				hasValue(getBidderName()) ||
				hasValue(getEmailAddress()) ||
				(getBidPrice() > 0));
	}

	private boolean hasValue(String val) {
		return (!(val == null ) || !(val.equals("")));
	}
}