#define _CRT_SECURE_NO_WARNINGS


#include"game.h"
#include<stdio.h>

void Inticontact(contact *pc)
{

	assert(pc);
	pc->sz = 0;	
	pc->date = malloc(3 * sizeof(people));
	if (pc->date == NULL)
	{
		perror("use malloc");
		return;
	}
	pc->capacity = 3;
	LOADcontact(pc);

}


int CheckCapacity(contact *pc)
{
	assert(pc);
	if (pc->capacity == pc->sz)
	{
		people *str = realloc(pc->date,
			(pc->capacity+3) * sizeof(people));
		if (str == NULL)
		{
			return 0;
		}
		else
			return 1;
	}
	return 1;
}
void ADDcontact(contact *pc)
{
	assert(pc);
	
		if (CheckCapacity(pc) == 0)
		{
			printf("增容失败：>");
			exit(1);
		}
		printf("请输入要添加的人的信息：>\n");
		printf("姓名:\n");
		scanf("%s", &(pc->date[pc->sz].name));
		printf("年龄:\n");
		scanf("%d", &(pc->date[pc->sz].age));
		printf("性别:\n");
		scanf("%s", &(pc->date[pc->sz].sex));
		printf("地址:\n");
		scanf("%s", &(pc->date[pc->sz].addre));
		printf("t电话号:\n");
		scanf("%s", &(pc->date[pc->sz].tele));
		pc->sz++;
		printf("添加成功:\n");
	

}

int FINDcontact(contact *pc)
{
	assert(pc);
	int i = 0;
	char name[10] = { 0 };
	printf("要查找的联系人姓名：>");
	scanf("%s",name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp((pc->date[i].name), name) == 1)
		{
			return i;
		}
	}
	return -1;
}

void DELcontact(contact *pc)
{
	assert(pc);
	int i = 0;
	int j = 0;
	if (pc->sz == 0)
	{
		printf("通讯录为空：>\n");
		return;
	}
	i = FINDcontact(pc);
	if (i == 0)
	{
		printf("不存在该联系人：>\n");
		return;
	}
	else
	for (j = 0; j < pc->sz; j++)
	{
		pc->date[j] = pc->date[j + 1];
	}
	printf("删除成功:>\n");
}

void men()
{
	printf("********************************\n");
	printf("******  0.EXIT     1.name  ******\n");
	printf("******  2.age      3.sex ******\n");
	printf("******  4.addre   5.tele ******\n");
	printf("********************************\n");
}

enum person
{
	EXIT,
	name,
	age,
	sex,
	addre,
	tele
};
void XIUGAIcontact(contact *pc)
{
	assert(pc);
	int input = 0;
	int i = FINDcontact(pc);
	printf("请选择要修改的内容:>");
	men();
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			break;
		case name:
			printf("请输入要修改的信息：>");
			scanf("%s", pc->date[i].name);
			break;
		case age:
			printf("请输入要修改的信息：>");
			scanf("%d", pc->date[i].age);
			break;
		case sex:
			printf("请输入要修改的信息：>");
			scanf("%s", pc->date[i].sex);
			break;
		case addre:
			printf("请输入要修改的信息：>");
			scanf("%s", pc->date[i].addre);
			break;
		case tele:
			printf("请输入要修改的信息：>");
			scanf("%s", pc->date[i].tele);
			break;
		default:
			printf("输入有误，请重新输入：>\n");
			break;
		}
	} while (input);
	printf("修改成功：>\n");
	
}

void SHOWcontact(contact *pc)
{
	assert(pc);
	int i = 0;
	printf("%-10s\t%-5s\t%-4s\t%-20s\t%-12s\n",
		"姓名", "年龄", "性别", "地址", "电话号");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-d\t%-4s\t%-20s\t%-12s\t\n",
			pc->date[i].name,
			pc->date[i].age,
			pc->date[i].sex,
			pc->date[i].addre,
			pc->date[i].tele);
	}
}

void FINDcontact1(contact *pc)
{
	int i = FINDcontact(pc);
	if (i == -1)
	{
		printf("不存在该联系人：>");
	}
	else
	printf("%-10s\t%-5d\t%-4s\t%-20s\t%-12s\t\n",
		pc->date[i].name,
		pc->date[i].age,
		pc->date[i].sex,
		pc->date[i].addre,
		pc->date[i].tele);
}

void DROPcontact(contact *pc)
{
	pc->sz = 0;
	pc->capacity = 0;
	free(pc->date);
	pc->date = NULL;
}

void SAVEcontact(contact *pc)
{
	int i = 0;
	FILE *fp = fopen("test.date", "wb");
	if (fp == NULL)
	{
		perror("SAVEcontact::fopen");
		return;
	}
	while (i<pc->sz)
	{
		fwrite(&(pc->date[i]), sizeof(people), 1, fp);
			i++;
	}
	fclose(fp);
	fp = NULL;
}

void LOADcontact(contact *pc)
{
	people temp = { 0 };;
	FILE *fp = fopen("test.date", "rb");
	if (fp == NULL)
	{
		perror("LOADcontact::fopen");
		return;
	}
	while (fread(&temp, sizeof(people), 1, fp))
	{
		CheckCapacity(pc);
		pc->date[pc->sz] = temp;
		(pc->sz)++;		
		
	}
	fclose(fp);
	fp = NULL;
}
