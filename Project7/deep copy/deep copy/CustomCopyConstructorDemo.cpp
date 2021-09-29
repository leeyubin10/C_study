#include <iostream>
#include "CourseWithCustomCopyConstructor.h"
using namespace std;

int main()
{
	Course course1("C++ Programming", 2);
	Course course2(course1);

	course1.addStudent("Peter Pan");
	course1.addStudent("Lisa Ma");
	course1.addStudent("yujin");
	course2.addStudent("Lisa Ma");

	cout << "students in course1: " << course1.getStudents() << endl;
	cout << "students in course2: " << course2.getStudents() << endl;

	return 0;
}