CREATE TABLE department (
	dnumber VARCHAR2(3) CONSTRAINT department_dnumber_PK PRIMARY KEY,
	dname VARCHAR2(20) CONSTRAINT department_dname_UK UNIQUE,
	mgr_ssn CHAR(9) CONSTRAINT department_mgr_ssn_NN NOT NULL,
	mgr_start_date	DATE
)
