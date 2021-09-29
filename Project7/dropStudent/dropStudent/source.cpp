#include <iostream>
#include "Course.h"
using namespace std;

int main() {
	Course course1("Data Structures", 10);

	course1.addStudent("S1");
	course1.addStudent("S2");
	course1.addStudent("S3");
	course1.addStudent("S4");
	course1.addStudent("S5");
	course1.addStudent("S6");
	course1.addStudent("S7");
	course1.dropStudent("S4");
	course1.dropStudent("T4");
	course1.dropStudent("S2");
	course1.addStudent("S8");
	course1.dropStudent("S7");

	cout << "Number of students in course1: "
		<< course1.getNumberOfStudents() << endl;
	string *students = course1.getStudents();
	int size = course1.getNumberOfStudents();
	for (int i = 0; i < size; i++)
		cout << students[i] << (i < size - 1 ? ", " : "");
	cout << endl;


	return 0;
}
