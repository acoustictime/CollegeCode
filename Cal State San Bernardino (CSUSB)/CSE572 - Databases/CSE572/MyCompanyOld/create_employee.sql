CREATE TABLE employee (
	ssn CHAR(9) CONSTRAINT employee_ssn_pk PRIMARY KEY,
	fname VARCHAR2(15) CONSTRAINT employee_fname_NN NOT NULL,
	minit CHAR(1),
	lname VARCHAR2(15) CONSTRAINT employee_lname_NN NOT NULL,
	bdate DATE,
	address VARCHAR2(40),
	sex CHAR(1),
	salary NUMBER(7,2),
	super_ssn CHAR(9),
	dno VARCHAR2(3) CONSTRAINT employee_dno_NN NOT NULL
)
