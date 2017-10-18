package coreservlets;

/**
 * A simple bean that has a single String property
 * called `message`.
 */

public class StringBean {
	private String message = "Default message from `StringBean`";

	public String getMessage() {
		return this.message;
	}

	public void setMessage(String message) {
		this.message = message;
	}
}