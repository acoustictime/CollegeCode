Homework3: main.o Person.o Employee.o Student.o Faculty.o Staff.o StaffST.o
	g++ main.o Person.o Employee.o Student.o Faculty.o Staff.o StaffST.o -o Homework3
    
Person.o: Person.cpp
	g++ -c Person.cpp
    
Student.o: Student.cpp
	g++ -c Student.cpp

Employee.o: Employee.cpp
	g++ -c Employee.cpp

Faculty.o: Faculty.cpp
	g++ -c Faculty.cpp

Staff.o: Staff.cpp
	g++ -c Staff.cpp

main.o: main.cpp
	g++ -c main.cpp

StaffST.o: StaffST.cpp
	g++ -c StaffST.cpp
