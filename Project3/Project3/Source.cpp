#include "Fan.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "===========================================" << endl;
	cout << "<Exercise 09-02>" << endl;

	Fan f1;
	f1.setSpeed(3);
	f1.setRadius(10);
	f1.setOn(true);
	f1.setColor("yellow");

	Fan f2;
	f2.setSpeed(2);
	f2.setRadius(5);
	f2.setOn(false);
	f2.setColor("white");

	cout << "First fan properties: " << endl;
	cout << "Fan speed: " << f1.getSpeed() << endl;
	cout << "Fan radius: " << f1.getRadius() << endl;
	cout << "Fan on? ";
	if (f1.getOn() == true)
		cout << "on" << endl;
	else
		cout << "off" << endl;
	cout << "Fan color: ";
	cout << f1.getColor() << endl << endl;

	cout << "Second fan properties: " << endl;
	cout << "Fan speed: " << f2.getSpeed() << endl;
	cout << "Fan radius: "<< f2.getRadius() << endl;
	cout << "Fan on? ";
	if (f2.getOn() == true)
		cout << "on" << endl;
	else
		cout << "off" << endl;
	cout << "Fan color: ";
	cout << f2.getColor() << endl;

	cout << "\n===========================================" << endl;
	cout << "<Exercise 09-05>" << endl;

	Time t1;
	Time t2(555550);

	cout << "Current Time = " << t1.getHour() << "h: " << t1.getMinute() << "m: " << t1.getSecond() << "s" << endl;
	cout << "Time(555550) = " << t2.getHour() << "h: " << t2.getMinute() << "m: " << t2.getSecond() << "s" << endl;

	return 0;
}