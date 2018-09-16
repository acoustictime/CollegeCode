CREATE TABLE works_on (
	essn CHAR(9),
	pno VARCHAR2(5),
	hours NUMBER(3,2),
	CONSTRAINT works_on_essn_pno_PK PRIMARY KEY (essn, pno)
)
