/********************************************************************************
 James Small
 Date Start: 2-27-12  Date End: 2-28-12
 Filename: homework3.cpp
 Description: This program is based on the course registration found in the book.
              There are two classes defined below with most of the functions inline.
              The course registration system will read in from two files, one
              containing all of the classes offered and the amount of students 
              allowed in that class.  It will also read in the names of students
              the classes they would like to register for.  It will then determine
              which student gets which class based on first come first server.  
              It will then output the reports of who got what class.
 *******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Student; // forward declartion, Course needs Student

/**************************************************************************
 Class Name: Course
 Description: Course class definition and inline functions.
 **************************************************************************/

class Course {
public:
    Course (string n, int s) : name(n), max(s) { }
    
    bool full () { return students.size() >= max; }
    void addStudent (Student * s) { students.push_back(s); }
    void generateClassList();
    string getName() {return name; }
    
protected:
    string name;
    int max;
    list <Student *> students;
};

/**************************************************************************
 Class Name: Student
 Description: Student class definition and inline functions.
 **************************************************************************/

class Student {
typedef list <Course *>::iterator citerator;

public:
    Student (string n) : nameText(n) { }
    string name() { return nameText; }
    void addCourse (Course * c) { courses.push_back(c); }
    citerator firstCourse () { return courses.begin(); }
    citerator lastCourse () { return courses.end(); }
    void removeCourse (citerator & citr) { courses.erase(citr); }
    
protected:
    string nameText;
    list <Course *> courses;
};

list <Course *> all_courses;
list <Student *> all_students;

/**************************************************************************
 Function Name: studentCompare()
 Description: Compares the names of students for which is greater
 **************************************************************************/

bool studentCompare(Student * a, Student * b) {
    return a -> name() < b -> name();
}

/**************************************************************************
 Function Name: generateClassList()
 Description: function to generate class list in order
 **************************************************************************/

void Course::generateClassList() {
    students.sort(studentCompare);
    
    cout << "Class list for " << name << endl;
    list <Student *>::iterator start, stop;
    start = students.begin();
    stop = students.end();
    for (; start != stop; start++)
        cout << (*start) -> name() << endl;
    cout << endl;
}

/**************************************************************************
 Function Name: readCourses()
 Description: Read courses and size from input file
 **************************************************************************/

void readCourses(istream & infile) {
    string name;
    int max;
    
    while (infile >> name >> max) {
        Course * newCourse = new Course (name,max);
        all_courses.push_back(newCourse);        
    }
}

/**************************************************************************
 Function Name: findStudent()
 Description: returns a pointer to a student after finding the their name
 **************************************************************************/

Student * findStudent(string & searchName) {
    list <Student *>::iterator start, stop;
    start = all_students.begin();
    stop = all_students.end();
    for (; start != stop; start++) 
        if ((*start) -> name() == searchName)
            return *start;
    
    Student * newStudent = new Student(searchName);
    all_students.push_back(newStudent);
    return newStudent;
}

/**************************************************************************
 Function Name: findCourse()
 Description: returns a pointer to a course after finding by its name
 **************************************************************************/

Course * findCourse(string & searchName) {
    list <Course *>::iterator start, stop;
    start = all_courses.begin();
    stop = all_courses.end();
    for (; start != stop; start++)
        if ((*start) -> getName() == searchName)
            return *start;
    return NULL;
}

/**************************************************************************
 Function Name: readStudents()
 Description: Read Stuents and courses they want from input file
 **************************************************************************/

void readStudents(istream & infile) {
    string name;
    string course;
    
    while (infile >> name >> course) {
        Student * theStudent = findStudent(name);
        Course * theCourse = findCourse(course);
        if (theCourse != 0)
            theStudent -> addCourse(theCourse);
        else
            cout << "student " << name << " requested invalid course " << course << endl;
    }
}

/**************************************************************************
 Function Name: fillCourses()
 Description: Iterates through courses and adds students if they want class. 
              If class is full, removes from list of classes for student
 **************************************************************************/

void fillCourses() {
    list <Student *>::iterator s_start, s_end;
    s_start = all_students.begin();
    s_end = all_students.end();
    
    for (; s_start != s_end; s_start++) {
        list <Course *>::iterator c_start, c_end, c_next;
        c_start = (*s_start) -> firstCourse();
        c_end = (*s_start) -> lastCourse();
        for (; c_start != c_end; c_start = c_next) {
            c_next = c_start; 
            c_next++;
            
            if (! (*c_start) -> full()) 
                (*c_start) -> addStudent(*s_start);
            else 
                (*s_start) -> removeCourse(c_start);
        }
    }    
}

/**************************************************************************
 Function Name: generateCourseReports()
 Description: Generates course reports for teachers
 **************************************************************************/

void generateCourseReports() {
    list <Course *>::iterator start, stop;
    start = all_courses.begin();
    stop = all_courses.end();
    for (; start != stop; start++) 
        (*start) -> generateClassList();
}

/**************************************************************************
 Function Name: generateStudentReports
 Description: Generates student reports for students
 **************************************************************************/

void generateStudentReports() {
    list <Student *>::iterator s_start, s_stop;
    list <Course *>::iterator c_start, c_stop;
    s_start = all_students.begin();
    s_stop = all_students.end();
    
    for (; s_start != s_stop; s_start++) {
        cout << "Class list for " << (*s_start) -> name() << endl;
        c_start = (*s_start) -> firstCourse();
        c_stop = (*s_start) -> lastCourse();
        for (; c_start != c_stop; c_start++)
            cout << (*c_start) -> getName() << endl;
        cout << endl;
    }
}


int main() {
    
    string classList = "classes.txt";
    string studentList = "students.txt";
    
    // read in courses

    ifstream infile;
    
    infile.open(classList.c_str());
    
    if (infile.good())
        readCourses(infile);
    
    infile.close();
    
    // read in students

    infile.open(studentList.c_str());
    
    if (infile.good())
        readStudents(infile);
    
    infile.close();
    
     //fill courses
    
    fillCourses();
    
    //generate course report
    
    cout << "\n\nCourse Reports\n\n";
    generateCourseReports();
    
    // generate student report
    
    cout << "\n\nStudent Reports\n\n";
    generateStudentReports();
}