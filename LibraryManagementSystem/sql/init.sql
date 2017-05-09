CREATE DATABASE db_lib;
USE db_lib;

CREATE TABLE book (
	id VARCHAR(20) NOT NULL,
	name VARCHAR(40) NOT NULL,
	author VARCHAR(20),
	catagory VARCHAR(20),
	state VARCHAR(5) DEFAULT 'in',
	PRIMARY KEY(id),
	CHECK (state IN ('in','out')));
	
INSERT INTO book (id,name,author,catagory) VALUES
				('E32045001','Teach yourserf Java','Rogers Cadenhead','Programming'),
				('E34005020','Thinking in Java','Bruce Eckel','Programming'),
				('D08523000','Digital Design','F. Wakerly','Electical'),
				('F88387110','Windows Core Programming','Jeffrey','OS/Programming'),
				('F11040400','Data Structrue','Makt Allen','CS');
	