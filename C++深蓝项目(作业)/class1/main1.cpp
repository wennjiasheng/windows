/*

#include <iostream>
#include<graphics.h> 

// run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv)
{
	//初始化绘图环境 
	initgraph(640,480);
	
	getch();
	
	//关闭绘图环境 
	closegraph();
	return 0;
}

*/




#if 1 
#include <iostream>
#include<graphics.h> 

int _gridSize=50;    //格子的大小
int _gridCount=8;    //格子的个数
int _winWidth=640;   
int _winHeigh=480;


int _xStart=(_winWidth-_gridSize*_gridCount)/2;
int _yStart=(_winHeigh-_gridSize*_gridCount)/2; 

int main()
{
	
	//初始化绘图环境 
	initgraph(640,480);
	
	//设置背景颜色 
	setbkcolor(EGERGB(255,110,110));
	
	// 设置前景颜色
	setcolor(EGERGB(255,255,255));
	
	setfont(30,0,"华文彩云"); 
	
	//输出文字
	outtextxy(10,10,"棋盘");
	

	
	//绘制直线
//	line(10,60,300,60); 
	
	int x1,x2,y1,y2;
	
	//绘制水平线
	for(int i=0;i<=_gridCount;++i)
	{
		x1=_xStart;
		x2=_winWidth-x1;
		
		y1=y2=_yStart+_gridSize*i;
		
		line(x1,y1,x2,y2);
	} 
	
	int x3,x4,y3,y4;
	
	//绘制垂直线
	for(int j=0;j<=_gridCount;++j)
	{
		y3=_yStart;
		y4=_winHeigh-y3;
		
		x3=x4=_xStart+_gridSize*j;
		
		line(x3,y3,x4,y4);
	} 
	
	getch();
	
	//关闭绘图环境 
	closegraph();
	
	return 0;
}

#endif


