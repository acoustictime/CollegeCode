CREATE TABLE library_branch (
	branch_id VARCHAR2(10) CONSTRAINT library_branch_PK PRIMARY KEY,
	branch_name VARCHAR2(20) CONSTRAINT library_branch_branch_name__NN NOT NULL,
	address VARCHAR2(15) CONSTRAINT library_branch_address_NN NOT NULL
)
