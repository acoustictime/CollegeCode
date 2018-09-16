CREATE TABLE borrower (
	card_no VARCHAR2(10) CONSTRAINT borrower_card_no_PK PRIMARY KEY,
	bname VARCHAR(15) CONSTRAINT borrower_bname_NN NOT NULL,
	address VARCHAR(15) CONSTRAINT borrower_address_NN NOT NULL,
	phone CHAR(10)
)
