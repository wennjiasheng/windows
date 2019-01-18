#include"Layout.h"
#include"Game.h" 
#include<graphics.h>


Layout::Layout()
{

	//给容器分配内存
	_layout.resize(Game::_gridCount);
	
	for(int i=0;i<Game::_gridCount;++i)
	{
		_layout[i].resize(Game::_gridCount);
	}
	
	//初始化棋盘格子的内容 
	for(int i=0;i<Game::_gridCount;++i)
	{
		for(int j=0;j<Game::_gridCount;++j)
		{
			_layout[i][j]=CP_NOTHING; 
		}
	}
	//设置对应的位置为白棋
	_layout[3][3]=_layout[4][4]=CP_WHITE;
	
	//设置对应的位置为黑棋 
	_layout[3][4]=_layout[4][3]=CP_BLACK;
	
	//设置玩家
	_player=CP_BLACK; 
	

}


Layout::~Layout()
{
	
}

// 绘制落子 
void Layout::Draw()
{
	for(int i=0;i<Game::_gridCount;++i)
	{
		for(int j=0;j<Game::_gridCount;++j)
		{
			//如果是黑棋 
			if(_layout[i][j]==CP_BLACK)
			{
				//设置填充色为黑色 
				setfillcolor(EGERGB(0,0,0));
			}
			else if(_layout[i][j]==CP_WHITE) 
			{
				//如果是白棋
				//设置填充色为白色
				setfillcolor(EGERGB(255,255,255));
			}
			else
			{
				continue;
			}
			
			//圆心的坐标
			int x=Game::_xStart+j*Game::_gridSize+Game::_gridSize/2;
			int y=Game::_yStart+i*Game::_gridSize+Game::_gridSize/2;
			
			//绘制棋子
			fillellipse(x,y,Game::_pieceSize,Game::_pieceSize);
			 
		}
	}

} 

//落子下棋
void Layout::SetPieces(POS pos)
{
	// 根据玩家 ，设置对应位置的棋子颜色
	_layout[pos.row][pos.col]=_player;
	
	// 切换玩家
	_player=(CHESS_PIECE)(3-_player);
	
} 




