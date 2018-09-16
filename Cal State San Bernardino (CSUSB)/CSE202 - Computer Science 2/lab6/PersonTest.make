PersonTest: PersonTest.o Person.o
	g++ PersonTest.o Person.o -o PersonTest
    
Person.o: Person.cpp
	g++ -c Person.cpp
    
PersonTest.o: PersonTest.cpp
	g++ -c PersonTest.cpp
