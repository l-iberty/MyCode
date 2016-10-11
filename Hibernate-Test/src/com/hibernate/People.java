package com.hibernate;

public class People {
	private long id;
	private String name;
	private long number;

	public void setName(String name) {
		this.name = name;
	}

	public void setNumber(long number) {
		this.number = number;
	}

	public void setId(long id) {
		this.id = id;
	}

	public long getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public long getNumber() {
		return number;
	}
}