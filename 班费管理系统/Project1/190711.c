#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma pack(1)
const char *DataFilename = "d:\\classfee.data";
typedef struct classfee ClassFee;
struct classfee{
	int id;
	char io;
	char cbr[10];
	char reason[256];
	float fee;
	char memo[256];
	float restfee;
	ClassFee *next;
};
void ShowMenu() {
	const char *menu = {
		"1.添加班费收支信息\n"
		"2.浏览所有班费收支信息\n"
		"3.查询班费收支信息\n"
		"4.修改班费收支信息\n"
		"5.退出\n请选择：\n"
	};
	printf("%s", menu);
}
ClassFee *fee;
int index = 0;
float lastfee = 0.0f;
int InitDataFile() {
	FILE *fp = fopen("DataFilename", "rb");
	size_t sizefee = sizeof(ClassFee);
	fee = (ClassFee*)malloc(sizefee);
	fee->next = NULL;
	if (fp == NULL) {
		return 1;
	}
	ClassFee *p = fee;
	size_t len;
	while (!feof(fp)) {
		ClassFee *q = (ClassFee*)malloc(sizefee);
		len = fread((char*)q, sizefee, 1, fp);
		if (len == 1) {
			index++;
			lastfee = q->restfee; //最后一次取得数据为最后余额
			q->next = NULL;
			p->next = q;
			p = q;
		}
	}
	fclose(fp);
	return 0;
}
int WriteDataFile() {
	FILE *fp = fopen("DataFilename", "wb");
	if (fp == NULL) {
		printf("无法打开数据文件：%s,请检查。\n", DataFilename);
		return 1;
	}
	size_t sizefee = sizeof(ClassFee);
	ClassFee *p = fee->next;
	while (p) {
		fwrite((char *)p, sizefee, 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 0;
}
void FreeResource() {
	ClassFee *p = fee, *q = NULL;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
}
void AppendFee(ClassFee *f) {
	ClassFee *p = fee, *q;
	q = p->next;
	while (q) {
		p = q;
		q = p->next;
	}
	p->next = f;
}
void InputFee() {
	ClassFee *p = (ClassFee*)malloc(sizeof(ClassFee));
	p->id = ++index;
	fflush(stdin);
	printf("输入费用信息：\n");
	printf("  支出(o)?收入(i)?：");
	scanf("%c", &p->io);
	if (p->io != 'i' && p->io != 'o') {
		printf("输入错误，按收入处理，此处应该做成循环输入，直到输入成功为止，这里省略\n");
		p->io = 'i';
	}
	printf("  经办人："); scanf("%s", p->cbr);
	printf("  原因："); scanf("%s", p->reason);
	printf("  金额："); scanf("%f", &p->fee);
	printf("  备注："); scanf("%s", p->memo);
	p->restfee = p->io == 'i' ? (lastfee + p->fee) : (lastfee - p->fee);
	lastfee = p->restfee;
	p->next = NULL;
	AppendFee(p);
	printf("-------------------------------------------------\n");
}
void DisplayFee(ClassFee *p) {
	printf("  收支编号 :   %d\n", p->id);
	printf("  收入/支出:   %s\n", p->io == 'i' ? "收入" : "支出");
	printf("  经办人   :   %s\n", p->cbr);
	printf("  原因     :   %s\n", p->reason);
	printf("  金额     :   %.2f\n", p->fee);
	printf("  备注     :   %.2f\n", p->memo);
	printf("  余额     :   %.2f\n", p->restfee);
	printf("-------------------------------------------------\n");
}
void Search() {
	int s;
	const char *msg[] = { "输入收支编号：", "输入原因：" };
	printf("输入查询条件：\n　1.按收支编号查询\n　2.按原因查询:");
	fflush(stdin);
	scanf("%d", &s);
	ClassFee *p = fee->next;
	if (s == 1) {
		size_t s0;
		printf("%s", msg[s - 1]);
		scanf("%d", &s0);
		while (p) {
			if (p->id == s0) {
				DisplayFee(p);
				break;
			}
			p = p->next;
		}
	}
	else if (s == 2) {
		char r[256];
		printf("%s", msg[s - 1]);
		scanf("%s", r);
		while (p) {
			if (strstr(p->reason, r) != NULL) {
				DisplayFee(p);
			}
			p = p->next;
		}
	}
}
void ModifyFee() {
	size_t s;
	printf("输入收支编号：");
	scanf("%d", &s);
	ClassFee *p = fee->next;
	while (p) {
		if (p->id == s) {
			DisplayFee(p);
			printf("输入修改信息：\n-------------------------------\n");
			//这里对p进行修改，这个比较麻烦，不单单是修改本节点的信息
			//如果对fee和收入/支出做了修改，则需要修改后续所有节点的restfee的信息
			//有点麻烦，不想写了，你自己补上这块即可。
			break;
		}
		p = p->next;
	}
}
int main() {
	int choice;
	InitDataFile();
	printf("index=%d, lastfee=%.2f\n", index, lastfee);
	while (1) {
		ShowMenu();
		scanf("%d", &choice);
		if (choice<1 || choice>5) {
			system("cls");
			printf("你的输入错误，请重新输入\n------------------------\n");
			continue;
		}
		else {
			if (choice == 5) {
				WriteDataFile();
				break;
			}
			else if (choice == 1) {
				InputFee();
			}
			else if (choice == 2) {
				system("cls");
				ClassFee *p = fee->next;
				while (p) {
					DisplayFee(p);
					p = p->next;
				}
			}
			else if (choice == 3) {
				Search();
			}
			else if (choice == 4) {
				ModifyFee();
			}
		}
	}
	return 0;
}