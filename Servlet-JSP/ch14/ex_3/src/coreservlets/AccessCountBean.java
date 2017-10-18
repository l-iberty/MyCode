package coreservlets;

public class AccessCountBean {
    private String firstPage;
    private int accessCount = 1;

    public String getFirstPage() {
        return firstPage;
    }

    public int getAccessCount() {
        return accessCount;
    }

    public void setFirstPage(String firstPage) {
        this.firstPage = firstPage;
    }

    public void setAccessCount(int accessCount) {
        this.accessCount = accessCount;
    }

    public void setAccessCountIncrement(int increment) {
        accessCount += increment;
    }
}
