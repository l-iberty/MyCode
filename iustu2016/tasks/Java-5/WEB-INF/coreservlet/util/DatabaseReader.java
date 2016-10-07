package coreservlets.util;

import java.util.StringTokenizer;
import java.sql.SQLException;
import coreservlets.util.DatabaseUtilities;

public class DatabaseReader {
	public static String getFmtRecords(String origRecords) {
		StringTokenizer token = new StringTokenizer(origRecords, ";");
		StringBuffer buff = new StringBuffer();
		String style = "style=\"list-style-position:inside\"";

		buff.append("<ul>");
		while (token.hasMoreTokens()) {
			buff.append("<li " + style + ">" + token.nextToken() + "</li>");
		}
		buff.append("</ul>");

		return buff.toString();
	}

	public static String getRecords(String tbName) {
		try {
			DatabaseUtilities database = new DatabaseUtilities("directory");
			String origRecords = database.getRecords(tbName);

			return getFmtRecords(origRecords);
		} catch (SQLException e) {
			return null;
		}
	}
}