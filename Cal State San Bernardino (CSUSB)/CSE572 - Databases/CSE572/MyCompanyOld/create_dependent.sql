CREATE TABLE dependent (
	essn CHAR(9),
	dependent_name VARCHAR2(20),
	sex CHAR(1),
	bdate DATE,
	relationship VARCHAR2(15) CONSTRAINT dependent_relationship_NN NOT NULL,
	CONSTRAINT dependent_essn_dep_name_PK PRIMARY KEY (essn, dependent_name)
)
