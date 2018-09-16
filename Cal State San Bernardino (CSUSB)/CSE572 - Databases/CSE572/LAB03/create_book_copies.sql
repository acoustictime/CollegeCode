CREATE TABLE book_copies (
	book_id VARCHAR2(10) CONSTRAINT book_copies_book_id_FK REFERENCES Book(Book_id),
	branch_id VARCHAR2(10) CONSTRAINT book_copies_branch_id_FK REFERENCES Library_branch(branch_id),
	no_copies INTEGER CONSTRAINT book_copies_no_copies_NN NOT NULL,
	CONSTRAINT book_copies_bo_id_br_id_PK PRIMARY KEY (book_id,branch_id)
)


