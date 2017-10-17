package coreservlets;

import java.util.*;

/**
 * Bean to represent a bank customer.
 */

public class BankCustomer {
    private String id;
    private String firstName;
    private String lastName;
    private double balance;

    public BankCustomer(String id, String firstName, String lastName, double balance) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.balance = balance;
    }

    public String getId() {
        return id;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public double getBalance() {
        return balance;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    // Make a small table of customers.

    private static Map<String, BankCustomer> customers;

    static {
        customers = new HashMap<>();

        customers.put("id001",
                new BankCustomer("id001",
                        "John",
                        "Hacker",
                        -3456.78));

        customers.put("id002",
                new BankCustomer("id002",
                        "Jane",
                        "Hacker",
                        1234.56));

        customers.put("id003",
                new BankCustomer("id003",
                        "Juan",
                        "Hacker",
                        98765.432));
    }

    /**
     * Find the customer with the given ID.
     * Return null if there is no match.
     */

    public static BankCustomer getCustomer(String id) {
        return customers.get(id);
    }
}
