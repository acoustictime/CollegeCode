CREATE TABLE book (
	book_id VARCHAR2(10) CONSTRAINT book_book_id_PK PRIMARY KEY,
	title VARCHAR2(20) CONSTRAINT book_title_NN NOT NULL,
	publisher_name VARCHAR2(20) CONSTRAINT book_publisher_pname_FK REFERENCES publisher(pname) CONSTRAINT book_publisher_pname_NN NOT NULL
)
