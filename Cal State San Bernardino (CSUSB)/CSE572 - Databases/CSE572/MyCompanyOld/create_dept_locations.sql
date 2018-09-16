CREATE TABLE dept_locations (
	dnumber VARCHAR2(3),
	dlocation VARCHAR2(15),
	CONSTRAINT dept_locations_dnum_dloc_PK PRIMARY KEY (dnumber, dlocation)
)
