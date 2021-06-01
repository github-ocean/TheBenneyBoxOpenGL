#include <iostream>
#include <GL/glew.h>
#include "Display.h"

int main()
{
	Display display(800, 600, "Hello World");

	while (!display.IsCloseed())
	{
		display.Clear(0.f, 0.15f, 0.3f, 0.f);

		display.Update();
	}

	return 0;
}