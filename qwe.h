#pragma once
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>


#define wig 600
#define hig 600

int q = 1, qw = 1;   //控制变量
char imagepath[400];
IMAGE bk, dtbk[150], dl, zc;
int q1 = 0;
char usr[10];
char mm[10];

struct book
{
	int bianhao;
	char name[25];
	char auot[25];
	char chubanshe[25];
	int number;
	char status[100];
	char reader[100];
};
book bk1;
book* bok = &bk1;


void loaddtbk();            //加载动态背景
void loadbk();              //加载功能模块背景
void anniu(int x, int y, char pos);          //加载登录注册，增删查改按钮
void mus();               //登录注册页面鼠标控制
void djanniu(int x, int y, char pos);          //鼠标移动过去效果
void glishitu();              //功能页面视图和效果
void glimus();              //管理页面鼠标控制
void addbook();             //图书增加
void serbook();            //图书搜索
void delbook();              //图书删除
void xgbook();              //图书修改
void lkbook();                //图书浏览
void jcbook();              //图书借出
void ghbook();             //图书归还



//系统初始化
void loaddtbk()
{
	int a = 1;
	for (int i = 0; i < 42; i++)
	{
		sprintf(imagepath, "123\\%d.jpg", a);
		loadimage(&dtbk[i], imagepath, 600, 900);
		putimage(0, -160, &dtbk[i]);
		Sleep(1);
		a++;
	}
	anniu(300, 300, 's');
	anniu(300, 400, 'x');

}

void loadbk()
{
	loadimage(&bk, "11.jpg", 600, 600);
	putimage(0, 0, &bk);
}

//按钮初始化
void anniu(int x, int y, char pos)
{
	setfillcolor(WHITE);
	solidcircle(x, y, 40);
	setlinestyle(PS_SOLID, 3);
	circle(x, y, 50);
	if (pos == 's')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "登录");
	}
	else if (pos == 'x')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "注册");
	}
	else if (pos == 'z')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "增删");
		outtextxy(x - 20, y + 15, "改查");
	}
	else if (pos == 't')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "学生");
		outtextxy(x - 20, y + 15, "浏览");
	}
	/*else if (pos == 'j')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "借出");
	}
	else if (pos == 'g')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "归还");
	}*/
}


//功能模块图标
void glishitu()
{
	initgraph(wig, hig);
	loadbk();
	anniu(100, 100, 'z');
	anniu(300, 100, 't');
	/*anniu(100, 300, 'j');
	anniu(300, 300, 'g');*/
}


//鼠标点击
void djanniu(int x, int y, char pos)
{
	setfillcolor(RED);
	solidcircle(x, y, 40);
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 3);
	circle(x, y, 50);
	if (pos == 's')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "登录");
	}
	else if (pos == 'x')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "注册");
	}
	else if (pos == 'z')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "增删");
		outtextxy(x - 20, y + 15, "改查");
	}
	else if (pos == 't')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "学生");
		outtextxy(x - 20, y + 15, "浏览");
	}
	//else if (pos == 'j')
	//{
	//	settextcolor(BLACK);
	//	settextstyle(25, 0, "黑体");
	//	setbkmode(TRANSPARENT);
	//	outtextxy(x - 20, y - 20, "借出");
	//}
	//else if (pos == 'g')
	//{
	//	settextcolor(BLACK);
	//	settextstyle(25, 0, "黑体");
	//	setbkmode(TRANSPARENT);
	//	outtextxy(x - 20, y - 20, "归还");
	//}
}            //鼠标点击



//增加图书
void addbook()
{
	int zs = 1;
	FILE* fp;
	while (zs)
	{

		fp = fopen("data\\book.txt", "at+");
		printf("----------新增学生----------\n\n");
		printf("请输入学生编号:");
		scanf("%d", &bok->bianhao);
		printf("请输入学生姓名:");
		scanf("%s", &bok->name);
		printf("学生班主任是：");
		scanf("%s", &bok->auot);
		printf("请输入学生所在院系：");
		scanf("%s", &bok->chubanshe);
		printf("请输入学生的年龄：");
		scanf("%d", &bok->number);
		printf("请输入学生性别：");
		scanf("%s", &bok->reader);
		printf("请输入学生班级");
		scanf("%s", &bok->status);
		fprintf(fp, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
		fclose(fp);
		fflush(stdin);
		printf("是否继续录入，是请输入1，否请输入0\n");
		scanf("%d", &zs);
		system("cls");

	}
}


//查找图书
void serbook()
{
	FILE* fp;
	fp = fopen("data\\book.txt", "at+");
	int num;
	int find = 0;
	printf("按编号查找学生信息\n");
	printf("请输入要查找的学生编号：");
	scanf("%d", &num);
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
		if (num == bok->bianhao)
		{
			printf("图学生的学号是%d", bok->bianhao);
			printf("学生的名字是%s", bok->name);
			printf("学生的班主任是%s", bok->auot);
			printf("学生所在院系是%s", bok->chubanshe);
			printf("学生的年龄是%d", bok->number);
			printf("学生的性别是%s", bok->reader);
			printf("学生的班级是%s", bok->status);
			printf("\n");
			find = 1;
		}
	}
	if (!find)
	{
		printf("查无此人\n");
	}
	fclose(fp);

}

//删除图书
void delbook()
{
	int qw = 1;
	while (qw)
	{
		FILE* fp;
		FILE* fpen;
		fp = fopen("data\\book.txt", "at+");
		fpen = fopen("data\\bk.txt", "at+");
		int num;
		int fin = 0;
		printf("按学生编号删除\n");
		printf("请输入要删除的学生编号");
		scanf("%d", &num);
		while (!feof(fp))
		{
			fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
			if (num != bok->bianhao)
			{
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
			}
			else
			{
				printf("图学生的学号是%d\n", bok->bianhao);
				printf("学生的名字是%s\n", bok->name);
				printf("学生的班主任是%s\n", bok->auot);
				printf("学生所在院系是%s\n", bok->chubanshe);
				printf("学生的年龄是%d\n", bok->number);
				printf("学生的性别是%s\n", bok->reader);
				printf("学生的班级是%s\n", bok->status);
				printf("删除成功\n");
				fin = 1;
			}
		}
		if (!fin)
		{
			printf("查无此人");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("是否继续删除学生，是打1，否打0：");
		scanf("%d", &qw);
		system("cls");
	}
}


//修改图书

void xgbook()
{
	int qw_xg = 1;
	while (qw_xg)
	{
		FILE* fp;
		FILE* fpen;
		fp = fopen("data\\book.txt", "at+");
		fpen = fopen("data\\bk.txt", "at+");
		int num;
		char name[20], aut[20], cbs[20], jyr[20], jc[10];
		int find = 0, nub;
		printf("按编号修改学生的名字\n");
		printf("请输入需要修改的学生编号：");
		scanf("%d", &num);
		while (!feof(fp))
		{
			fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
			if (num != bok->bianhao)
			{
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
			}
			else
			{
				printf("请输入修改后的名字");
				scanf("%s", name);
				strcpy(bok->name, name);
				printf("\n请输入修改后的班主任");
				scanf("%s", aut);
				strcpy(bok->auot, aut);
				printf("\n请输入修改后所在院系");
				scanf("%s", cbs);
				strcpy(bok->chubanshe, cbs);
				printf("\n请输入修改后的年龄");
				scanf("%d", &nub);
				bok->number = nub;
				printf("\n请输入修改后的性别");
				scanf("%s", jyr);
				strcpy(bok->reader, jyr);
				printf("\n请输入修改后的班级");
				scanf("%s", jc);
				strcpy(bok->status, jc);
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
				printf("图学生的学号是%d\n", bok->bianhao);
				printf("学生的名字是%s\n", bok->name);
				printf("学生的班主任是%s\n", bok->auot);
				printf("学生所在院系是%s\n", bok->chubanshe);
				printf("学生的年龄是%d\n", bok->number);
				printf("学生的性别是%s\n", bok->reader);
				printf("学生的班级是%s\n", bok->status);
				printf("修改成功");
				printf("\n");
				find = 1;
			}
		}
		if (!find)
		{
			printf("查无此人");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("是否继续修改，是请安1，否请按0: ");
		scanf("%d", &qw_xg);
		system("cls");
	}
}

//浏览全部图书	
void lkbook()
{
	FILE* fp;
	printf("--------输出学生信息--------\n");
	fp = fopen("data\\book.txt", "at+");
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
		printf("图学生的学号是%d\n", bok->bianhao);
		printf("学生的名字是%s\n", bok->name);
		printf("学生的班主任是%s\n", bok->auot);
		printf("学生所在院系是%s\n", bok->chubanshe);
		printf("学生的年龄是%d\n", bok->number);
		printf("学生的性别是%s\n", bok->reader);
		printf("学生的班级是%s\n", bok->status);
		printf("\n");
	}
	fclose(fp);
	printf("按任意键继续");
	getchar();
}

//借出图书
void jcbook()
{
	int qw_jy = 1;
	while (qw_jy)
	{
		FILE* fp;
		FILE* fpen;
		printf("请输入借出的图书编号");
		int nub, find = 0;
		char qs[10] = "借出";
		char name[20];
		scanf("%d", &nub);
		fp = fopen("data\\book.txt", "at+");
		fpen = fopen("data\\bk.txt", "at+");
		while (!feof(fp))
		{
			fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
			if (nub != bok->bianhao)
			{

				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
			}
			else
			{
				strcpy(bok->reader, qs);
				printf("请输入的姓名：");
				scanf("%s", name);
				strcpy(bok->status, name);
				bok->number--;
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
				printf("图书的编号是%d\n", bok->bianhao);
				printf("图书的名字是%s\n", bok->name);
				printf("图书的作者是%s\n", bok->auot);
				printf("图书的出版社是%s\n", bok->chubanshe);
				printf("图书的数量是%d\n", bok->number);
				printf("图书的借阅情况%s\n", bok->reader);
				printf("图书的借阅人是%s\n", bok->status);
				printf("借出成功");
				printf("\n");
				find = 1;
			}
		}
		if (!find)
		{
			printf("查无此书");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("是否继续借阅，是请安1，否请按0: ");
		scanf("%d", &qw_jy);
		system("cls");
	}
}

//归还图书
void ghbook()
{
	int qw_gh = 1;
	while (qw_gh)
	{
		FILE* fp;
		FILE* fpen;
		printf("请输入归还的图书编号");
		int nub, find = 0;
		char qs[10] = "存入";
		char name[20] = "无";
		scanf("%d", &nub);
		fp = fopen("data\\book.txt", "at+");
		fpen = fopen("data\\bk.txt", "at+");
		while (!feof(fp))
		{
			fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
			if (nub != bok->bianhao)
			{

				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
			}
			else
			{
				strcpy(bok->reader, qs);
				strcpy(bok->status, name);
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
				printf("图书的编号是%d\n", bok->bianhao);
				printf("图书的名字是%s\n", bok->name);
				printf("图书的作者是%s\n", bok->auot);
				printf("图书的出版社是%s\n", bok->chubanshe);
				printf("图书的数量是%d\n", bok->number);
				printf("图书的借阅情况%s\n", bok->reader);
				printf("图书的借阅人是%s\n", bok->status);
				printf("归还成功");
				printf("\n");
				find = 1;
			}
		}
		if (!find)
		{
			printf("查无此书");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("是否继续归还，是请安1，否请按0: ");
		scanf("%d", &qw_gh);
		system("cls");
	}
}