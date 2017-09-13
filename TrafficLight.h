#pragma once
#include "Light.h"

class TrafficLight
{
public:	
	TrafficLight();
	~TrafficLight();
	void run();
	void pause();
	void draw();
	void initialize();
	void keyPressed();
	void sleep(const int& timeInSecs);
private:
	Light red;
	Light yellow;
	Light green;
};