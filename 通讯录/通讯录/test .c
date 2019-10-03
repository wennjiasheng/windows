#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

//1.自定义类型部分知识写一篇博客。
//知识点：
//>结构体类型创建
//>结构体初始化
//>结构体内存对齐
//>位段，位段计算机大小。
//>枚举 + 联合。
//
//2.实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人




//提交作业
void menu()
{
	printf("********************************\n");
	printf("******  0.EXIT     1.ADD  ******\n");
	printf("******  2.DEL      3.FIND ******\n");
	printf("******  4.XIUGAI   5.SHOW ******\n");
	printf("********************************\n");
}
//enum cotion
//{
//	EXIT,
//	ADD,
//	DEL,
//	FIND,
//	XIUGAI,
//	SHOW
//};
void test()
{
	int input = 0;
	contact con;//date sz capacity
	
	Inticontact(&con);
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			SAVEcontact(&con);
			DROPcontact(&con);
			break;
		case 1:
			ADDcontact(&con);
			break;
		case 2:
			DELcontact(&con);
			break;
		case 3:
			FINDcontact1(&con);
			break;
		case 4:
			XIUGAIcontact(&con);
			break;
		case 5:
			SHOWcontact(&con);
			break;
		default:
			printf("输入有误，请重新选择：>");
			scanf("%d", &input);
			break;
		}
	} while (input);
}
int main()
{

	test();
	system("pause");
	return 0;
}