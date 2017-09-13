#include "Light.h"

Light::Light()
{
}


Light::Light(char newCharActiveLight, ConsoleCharColor newColorActiveLight, char newCharBoundLight)
{
	charActiveLight = newCharActiveLight;
	colorActiveLight = newColorActiveLight;
	charBoundLight = newCharBoundLight;
}


Light::~Light()
{
}

void SetColor(ConsoleCharColor text, ConsoleCharColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Light::draw() const
{
	for (int i = 0; i < lightHeight; ++i) {
		for (int j = 0; j < lightWidth; ++j) {
			if (active && i != 0 && i != lightHeight - 1 && j != 0 && j != lightWidth - 1) {
				SetColor(colorActiveLight, Black);
				cout << charActiveLight;
			}
			else {
				SetColor(White, Black);
				cout << charBoundLight;
			}
		}
		cout << endl;
	}
	cout << endl;
}
