CREATE TABLE project (
	pnumber VARCHAR2(5) CONSTRAINT project_pnumber_PK PRIMARY KEY,
	pname VARCHAR2(20) CONSTRAINT project_pname_UK UNIQUE,
	plocation VARCHAR2(20),
	dnum VARCHAR2(3)
)
