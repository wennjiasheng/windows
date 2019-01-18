#include"ChessBoard.h"
#include<graphics.h>
#include"Game.h"



ChessBoard::ChessBoard()
{
	
}


ChessBoard::~ChessBoard()
{
	
}

//绘制棋盘 
void ChessBoard::Draw()
{
	//清空(屏幕)绘图设备
	cleardevice(); 
	
	int x1,x2,y1,y2;
	
	//绘制水平线
	for(int i=0;i<=Game::_gridCount;++i)
	{
		x1=Game::_xStart;
		x2=Game::_winWidth-x1;
		
		y1=y2=Game::_yStart+Game::_gridSize*i;
		
		line(x1,y1,x2,y2);
	} 
	
	int x3,x4,y3,y4;
	
	//绘制垂直线
	for(int j=0;j<=Game::_gridCount;++j)
	{
		y3=Game::_yStart;
		y4=Game::_winHeigh-y3;
		
		x3=x4=Game::_xStart+Game::_gridSize*j;
		
		line(x3,y3,x4,y4);
	} 
 }

