package coreservlets;

public class UpperCaseBean {
    private String origString = "Missing Input";

    public String getOrigString() {
        return origString;
    }

    public String getUpperString() {
        return origString.toUpperCase();
    }

    public void setOrigString(String origString) {
        this.origString = origString;
    }
}
