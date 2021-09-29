#include "Time.h"
#include <ctime>
using namespace std;

Time::Time()
{
	second = time(0) % 60;
	minute = time(0) / 60 % 60;
	hour = time(0) / 60 / 60 % 24;
}

Time::Time(int elapseTime)
{
	second = elapseTime % 60;
	minute = elapseTime / 60 % 60;
	hour = elapseTime / 60 / 60 % 24;
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

int Time::getSecond()
{
	return second;
}

void Time::setTime(int elapseTime)
{
	second = elapseTime % 60;
	minute = elapseTime / 60 % 60;
	hour = elapseTime / 60 / 60 % 24;
}