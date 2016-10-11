package com.hibernate;

import org.hibernate.cfg.Configuration;
import org.hibernate.*;

public class Client {
	public static void main(String[] args) {
		Configuration cfg = new Configuration().configure("hibernate.cfg.xml");

		SessionFactory sessionFactory = cfg.buildSessionFactory();

		Session session = null;

		try {
			session = sessionFactory.openSession();
			session.beginTransaction();

			People people = new People();
			people.setId(1);
			people.setName("Joe");
			people.setNumber(150624);

			session.save(people);
			session.getTransaction().commit();
		} catch (Exception e) {
			System.err.println("Error from com.hibernate.Client: " + e);
		} finally {
			if ((session != null) && (session.isOpen())) {
				session.close();
				sessionFactory.close();
			}
		}
	}
}