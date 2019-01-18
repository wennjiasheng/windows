#include"Game.h"
#include<graphics.h>


int Game::_gridSize=50;    //格子的大小
int Game::_gridCount=8;    //格子的个数
int Game::_winWidth=640;   //窗口的宽度 
int Game::_winHeigh=480;   //窗口的高度 
int Game::_pieceSize=_gridSize/2-2;   //棋子大小 

//开始位置的x坐标 
int Game::_xStart=(_winWidth-_gridSize*_gridCount)/2;

//开始位置的y坐标 
int Game::_yStart=(_winHeigh-_gridSize*_gridCount)/2; 



Game::Game()
{
	
}


Game::~Game()
{
	
}


//游戏运行 
void Game::Run()
{
	//绘制棋盘 
    _cb.Draw();
    
    //绘制下棋
	_layout.Draw();
	
	POS pos;
	
	for(;is_run();delay_fps(100))
	{
		//获取鼠标位置
		while(!GetMouseHit(pos));
		
		//落子下棋 
		_layout.SetPieces(pos);

		//绘制棋盘
		_cb.Draw(); 
		
		//绘制落子 
		_layout.Draw();
		
	
		delay_fps(100);
	}
 
    
    
} 

//获取鼠标位置
bool Game::GetMouseHit(POS& pos)
{
	mouse_msg msg=getmouse();
	
	if(msg.is_left()&&msg.is_down())
	{
		if(msg.x-_xStart>0 && msg.y-_yStart>0)
		{
			pos.row=(msg.y-_yStart)/_gridSize;
			
			pos.col=(msg.x-_xStart)/_gridSize;
			
			if(pos.row>=0 && pos.row<_gridCount && 
			    pos.col>=0 && pos.col<_gridCount)
			{
				return true;
			}
		}
	}
	return false;
}























