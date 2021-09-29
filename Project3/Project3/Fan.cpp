#pragma warning(disable:4996)
#include "Fan.h"
#include <cstring>
#include<iostream>
#include <string>
using namespace std;

Fan::Fan()
{
	speed = 1;
	on = false;
	radius = 5;
	strcpy(color, "white");
}

int Fan::getSpeed()
{
	return speed;
}

double Fan::getRadius()
{
	return radius;
}

bool Fan::getOn()
{
	return on;
}

char Fan::getColor()
{
	for (int i = 0; color[i] != '\0'; i++)
	{
		cout << color[i];
	}
	return 0;
}

void Fan::setSpeed(int newspeed)
{
	if(newspeed >=1 && newspeed <=3)
		speed = newspeed;
}

void Fan::setRadius(double newradius)
{
	radius = newradius;
}

void Fan::setOn(bool OnOff)
{
	on = OnOff;
}

void Fan::setColor(const char newcolor[20])
{
	strcpy(color, newcolor);
}