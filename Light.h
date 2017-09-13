#pragma once
#include <iostream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include "ConsoleCharColor.h"

using namespace std;


class Light
{
public:
	Light();
	Light(char newCharActiveLight, ConsoleCharColor newColorActiveLight, char newCharBoundLight);
	~Light();
	void toggle() { active = active ? false : true; }
	bool isActive() const { return active; }
	void draw() const;
private:
	ConsoleCharColor colorActiveLight = ConsoleCharColor::White;
	char charActiveLight = '*';
	char charBoundLight = '#';
	int lightHeight = 8;
	int lightWidth = 16;
	bool active = false;
};

