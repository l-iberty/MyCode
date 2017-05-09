USE db_lib;

CREATE TABLE admin(
	username VARCHAR(13) NOT NULL,
	passwd VARCHAR(6) NOT NULL,
	PRIMARY KEY(username));
	
INSERT INTO admin (username,passwd) VALUES ('root','root');