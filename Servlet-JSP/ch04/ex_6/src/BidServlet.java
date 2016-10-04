package coreservlets;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import coreservlets.beans.*;
import coreservlets.ServletUtilities;

public class BidServlet extends HttpServlet {
	@Override
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		BidInfo bid = new BidInfo();
		BeanUtilities.populateBean(bid, request);
		if (bid.isComplete()) {
			showBid(request, response, bid);
		} else {
			showEntryForm(request, response, bid);
		}
	}

	private void showBid(HttpServletRequest request, HttpServletResponse response, BidInfo bid)
			throws ServletException, IOException {
		response.setContentType("text/html");
		String title = "Bid Submitted";
		PrintWriter out = response.getWriter();
		out.println(ServletUtilities.headWithTitle(title) +
					"<body><center>\n" +
					"<h1>" + title + "</h1>\n" +
					"<table border=1>\n" +
					"<tr><th>" + bid.getItemName() + "</tr></th>\n" +
					"<tr><th>Item ID: " + bid.getItemID() + "</tr></th>\n" +
					"<tr><th>Name: " + bid.getBidderName() + "</tr></th>\n" +
					"<tr><th>Email Address: " + bid.getEmailAddress() + "</tr></th>\n" +
					"<tr><th>Bid Price: " + bid.getBidPrice() + "</tr></th>\n" +
					"<tr><th>Auto-increment price: " + bid.isAutoIncrement() + "</tr></th>\n" +
					"</table></center></body></html>");
		out.close();
	}

	private void showEntryForm(HttpServletRequest request, HttpServletResponse response, BidInfo bid)
			throws ServletException, IOException {
		boolean isPartlyComplete = bid.isPartlyComplete();
		response.setContentType("text/html");
		String title = "Welcome to Auction-R-Us.\nPlease Enter Bid.";
		PrintWriter out = response.getWriter();
		out.println(ServletUtilities.headWithTitle(title) +
					"<body><center>\n" +
					"<h1>" + title + "</h1>\n" +
					warning(isPartlyComplete) +
					"<form>\n" +
					inputElement("Item ID", "itemID", bid.getItemID(), isPartlyComplete) +
					inputElement("Item Name", "itemName", bid.getItemName(), isPartlyComplete) +
					inputElement("Your Name", "bidderName", bid.getBidderName(), isPartlyComplete) +
					inputElement("Your Email Address", "emailAddress", bid.getEmailAddress(), isPartlyComplete) +
					inputElement("Amount Bid", "bidPrice", bid.getBidPrice(), isPartlyComplete) +
					checkbox("Auto-increment bid to match other bidders?", "autoIncrement", bid.isAutoIncrement()) +
					"<input type=\"submit\" value=\"Submit Bid\">\n" +
					"</form></center></body></html>");
		out.close();
	}

	private String warning(boolean isFormPartlyComplete) {
		if (isFormPartlyComplete) {
			return ("<h2>Required Data Missing! Enter and Resubmit.</h2>\n");
		} else {
			return "";
		}
	}

	private String inputElement(String prompt, String name,
		String value, boolean shouldPrompt) {

		String msg = "";
		if (shouldPrompt && ((value == null) || value.equals(""))) {
			msg = "<b>Required field!</b>  ";
		}

		return (msg + prompt + ": " +
				"<input type=\"text\" name=\"" + name + "\"" +
				" value=\"" + value + "\" /></br>");
	}

	private String inputElement(String prompt, String name,
		double value, boolean shouldPrompt) {

		String num;
		if (value == 0.0) {
			num = "";
		} else {
			num = String.valueOf(value);
		}

		return inputElement(prompt, name, num, shouldPrompt);
	}

	private String checkbox(String prompt, String name, boolean isChecked) {

		String result = prompt + ": " +
				"<input type=\"checkbox\"" + "name=\"" + name + "\"";
		if (isChecked) {
			result = result + " checked=\"checked\"";
		}

		result = result + " /></br>";
		return result;
	}
}