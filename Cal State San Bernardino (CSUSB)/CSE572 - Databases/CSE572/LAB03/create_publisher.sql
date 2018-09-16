CREATE TABLE publisher (
	pname VARCHAR2(20) CONSTRAINT publisher_pname_PK PRIMARY KEY,
	address VARCHAR2(20) CONSTRAINT publisher_address_NN NOT NULL,
	phone	CHAR(10)
)
