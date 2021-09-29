class Fan
{
public:
	Fan();
	int getSpeed();
	double getRadius();
	bool getOn();
	char getColor();
	void setSpeed(int newspeed);
	void setRadius(double newradius);
	void setOn(bool OnOff);
	void setColor(const char newcolor[20]);

private:
	int speed;
	bool on;
	double radius;
	char color[20];
};