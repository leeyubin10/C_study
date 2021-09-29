#include <iostream>
#include <iomanip>
#include "CircleWithPrivateDataFields.h"
using namespace std;

double sum(Circle circleArray[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += circleArray[i].getArea();

	return sum;
}

void printCircleArray(Circle circleArray[], int size)
{
	cout << setw(35) << left << "Radius" << setw(8) << "Area" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(35) << left << circleArray[i].getRadius() << setw(8) << circleArray[i].getArea() << endl;
	}

	cout << "=================================================" << endl;

	cout << setw(35) << left << "The total area of circles is" << setw(8) << sum(circleArray, size) << endl;
}

int main()
{
	cout << "<¸®½ºÆ® 10.5>" << endl;
	const int SIZE = 10;

	Circle circleArray[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		circleArray[i].setRadius(i + 1);
	}

	printCircleArray(circleArray, SIZE);

	return 0;
}

