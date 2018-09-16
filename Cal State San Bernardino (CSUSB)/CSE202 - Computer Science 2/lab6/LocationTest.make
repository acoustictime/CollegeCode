LocationTest: LocationTest.o Location.o
	g++ LocationTest.o Location.o -o LocationTest
    
Location.o: Location.cpp
	g++ -c Location.cpp
    
LocationTest.o: LocationTest.cpp
	g++ -c LocationTest.cpp
