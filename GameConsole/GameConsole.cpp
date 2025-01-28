#include <iostream>
#include "GameControler.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	GameControler gameControler;

	while (gameControler.IsRunning())
	{
		gameControler.Update();
		gameControler.Render();
	}
}