Lab9: main.o UserPw.o PasswordFile.o
	g++ main.o UserPw.o PasswordFile.o -o Lab9
    
main.o: main.cpp
	g++ -c main.cpp
    
UserPw.o: UserPw.cpp
	g++ -c UserPw.cpp
    
PasswordFile.o: PasswordFile.cpp
	g++ -c PasswordFile.cpp
