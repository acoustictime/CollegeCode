CREATE TABLE book_authors (
	book_id VARCHAR2(10) CONSTRAINT book_authors_FK REFERENCES Book(book_id),
	author_name VARCHAR2(15),
	CONSTRAINT book_authors_bid_aname_PK PRIMARY KEY (book_id,author_name)
)
