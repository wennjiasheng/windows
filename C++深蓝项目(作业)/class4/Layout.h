#ifndef LAYOUT_H
#define LAYOUT_H

#include<vector> 
using namespace std;


//定义枚举，表示棋盘格子中的内容
typedef enum{CP_NOTHING,CP_BLACK,CP_WHITE}CHESS_PIECE;



//定义鼠标位置的结构体
struct POS
{
	int row;    // 行
	int col;    // 列 
	
	//操作符重载
	bool operator==(const POS& pos)
	{
		return row==pos.row&&col==pos.col;
	}	
};



/*
游戏下棋布局类 
*/

class Layout
{
	public:
		Layout();
		~Layout();
		void Draw(); // 绘制落子 
		void SetPieces(POS pos);//落子下棋 
		bool IsHasPieces(POS pos);//判断对应的位置是否有落子(黑子或白子) 
		void ChangePlayer();//玩家切换
		bool IsInMaybePos(POS pos);// 
		
		
		
	protected:
		vector<vector<CHESS_PIECE> > _layout; //存放棋盘的格子

		CHESS_PIECE _player; 	//玩家 
		
		
		vector<POS> _allMaybePos;//记录所有可以落子的位置
		void GetAllMaybePos();//获取所有可以落子的位置
		bool IsMaybePos(POS pos);//判断是否可以落子
		bool IsLegalPos(POS pos);//判断位置是否合法 
		
		
		

};

#endif


















