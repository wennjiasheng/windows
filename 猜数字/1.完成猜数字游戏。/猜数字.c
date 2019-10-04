#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("**************************\n");
	printf("*****1.play   2.exit *****\n");
	printf("**************************\n");
}
void game()
{
	int i = 0;
	int j = 0;
	i = rand() % 100;
	printf("请输入你猜测的数：>");
	scanf("%d", &j);
	while (1)

	{
		if (j > i)
		{
			printf("数值较大，请重新输入");
			scanf("%d", &j);
		}
		else if (j < i)
		{
			printf("数值较小，请重新输入");
			scanf("%d", &j);
		}
		else
			break;
	}
	printf("恭喜你猜对了");
	printf("%d", j);
}
int main()
{
	int j = 0;
	menu();
	srand((unsigned int)time(NULL));
	printf("请选择：>");
	scanf("%d", &j);
	switch (j)
	{
	case 0:
		printf("游戏结束：>");
		break;
	case 1:
		game();
	default:
		printf("输入有误，请重新输入：>");
		scanf("%d", &j);
	}
	system("pause");

	return 0;
}