#include "objects/Game.h"

int main(void)
{
	cout << "Using containerssample.xml" << endl;
	string filename = "samples/creaturesample.xml";

	Game * game = new Game(filename);
	if(game->gameReady) {
		game->startGame();
	}

	delete game;
	return 0;
}
