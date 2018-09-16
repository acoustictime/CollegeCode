Lab8: Main.o Data.o
	g++ Main.o Data.o -o Lab8
    
Main.o: Main.cpp
	g++ -c Main.cpp
    
Data.o: Data.cpp
	g++ -c Data.cpp
