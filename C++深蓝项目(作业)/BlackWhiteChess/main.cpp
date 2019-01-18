#include <iostream>
#include <graphics.h>
#include "Game.h" 

int main(int argc, char** argv) {
	
	initgraph(Game::_winWidth,Game::_winHeight);
	
	//设置背景色 
	setbkcolor(EGERGB(40,150,170));
	
	Game game;
	
	//游戏运行 
	game.Run();
	
	getch();
	
	closegraph();
	
	return 0;
}
