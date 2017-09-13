// TrafficLight.cpp : Defines the entry point for the console application.
//
#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
}

TrafficLight::~TrafficLight()
{
}

void clearConsole() {
	system("cls");
}

void TrafficLight::keyPressed() {
	char key = _getch();
	fflush(stdin);
	switch (key) {
	case 'S':
		break;
	case 'P':
		pause();
		break;
	case 'E':
		exit(0);
	default:
		break;
	}
}

void TrafficLight::sleep(const int& timeInSecs) {
	clock_t delta = CLOCKS_PER_SEC * timeInSecs;
	clock_t now = clock();
	clock_t end = now + delta;
	do {
		Sleep(1);
		now = clock();
		if (_kbhit())
			keyPressed();
	} while ((now < end));
}

void TrafficLight::draw() {
	clearConsole();
	red.draw();
	yellow.draw();
	green.draw();
}

void TrafficLight::pause() {
	while (!_kbhit()) {
	}
	keyPressed();
}

void TrafficLight::initialize() {
	red = Light('*', Red, '#');
	yellow = Light('*', Yellow, '#');
	green = Light('*', Green, '#');
	clearConsole();
}

void TrafficLight::run() {
	red.toggle();
	draw();
	sleep(2);
	red.toggle();

	for (int i = 0; i < 4; ++i) {
		yellow.toggle();
		draw();
		sleep(1);
	}

	green.toggle();
	draw();
	sleep(3);
	green.toggle();
}