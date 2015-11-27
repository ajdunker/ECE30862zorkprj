#include "objects/Game.h"

int main(void)
{
	cout << "Using sample.xml" << endl;
	string filename = "samples/sample.xml";

	Game * game = new Game(filename);
	if(game->gameReady) {
		cout << "Game starting" << endl;
		game->startGame();
	}

	delete game;
	return 0;
}
