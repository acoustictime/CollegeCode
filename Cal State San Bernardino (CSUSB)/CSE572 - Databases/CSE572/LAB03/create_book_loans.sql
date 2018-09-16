CREATE TABLE book_loans (
	book_id VARCHAR2(10) CONSTRAINT book_loans_book_id_FK REFERENCES Book(book_id),
	branch_id VARCHAR2(10) CONSTRAINT book_loans_branch_id_FK REFERENCES Library_branch(branch_id),
	card_no VARCHAR2(10) CONSTRAINT book_loans_card_no_FK REFERENCES Borrower(card_no),
	date_out DATE,
	due_date DATE,
	CONSTRAINT book_loans_boid_br_id_ca_no_PK PRIMARY KEY (book_id,branch_id,card_no)
)


