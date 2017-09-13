#include "TrafficLight.h"

int main()
{
	TrafficLight trafficLight;
	trafficLight.initialize();
	while (true) {
		trafficLight.run();
	}
	return 0;
}
