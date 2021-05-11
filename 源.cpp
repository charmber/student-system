#include"qwe.h"
int main()
{
	system("title 学生管理系统");
	system("mode con cols=60 lines=20");
	system("color 2f");
	initgraph(wig, hig);
	loaddtbk();
	mus();
	if (q1 == 1)
	{
		char usr1[10], mm1[10];
		int w = 1;
		printf("\t		登录系统");
		while (w)
		{
			printf("\t\n\n		用户名:");
			scanf("%s", usr1);
			if (strcmp(usr, usr1) == 0)
			{
				w = 0;
			}
			else
			{
				system("cls");
				printf("用户名不存在请重新输入\n");
			}
		}
		printf("\t\n		密 码：");
		for (int i = 0; i < 10; i++)
		{
			mm1[i] = getch();
			if (mm1[i] == '\r')
			{
				mm1[i] = '\0';
				break;
			}
			printf("*");
		}
		printf("sceelsss\n");
	}
	glishitu();
	glimus();
	printf("end");
	system("pause");
	return 0;
}



//鼠标函数处理
void mus()
{
	MOUSEMSG m;
	FILE* fpz, * fpm;
	while (q)
	{
		//鼠标滑过效果
		m = GetMouseMsg();
		if (q == 1)
		{
			if (sqrt((double)((m.x - 300) * (m.x - 300) + (m.y - 300) * (m.y - 300))) < 40)
			{
				djanniu(300, 300, 's');
			}
			else if (sqrt((double)((m.x - 300) * (m.x - 300) + (m.y - 400) * (m.y - 400))) < 40)
			{
				djanniu(300, 400, 'x');
			}
			else
			{
				anniu(300, 300, 's');
				anniu(300, 400, 'x');
			}
		}

		switch (m.uMsg)      //鼠标动作捕捉
		{
		case WM_LBUTTONDOWN:
			if (sqrt((double)((m.x - 300) * (m.x - 300) + (m.y - 300) * (m.y - 300))) < 40)
			{
				closegraph();
				char usr11[10], mm1[10];
				int w = 1;
				fpz = fopen("usr\\zh.txt", "at+");
				fgets(usr, 10, fpz);
				while (w)
				{
					printf("\t\n\n		用户名:");
					scanf("%s", usr11);
					if (strcmp(usr, usr11) == 0)
					{
						w = 0;
					}
					else
					{
						system("cls");
						printf("用户不存在请重新输入\n");
					}
				}
				printf("\t\n		密 码：");
				for (int i = 0; i < 10; i++)
				{
					mm1[i] = getch();
					if (mm1[i] == '\r')
					{
						mm1[i] = '\0';
						break;
					}
					printf("*");
				}
				printf("sceelsss");
				//system("cls");
				q = 0;
			}
			else if (sqrt((double)((m.x - 300) * (m.x - 300) + (m.y - 400) * (m.y - 400))) < 40)
			{
				//用户注册界面
				closegraph();
				printf("\t\n\n		用户名:");
				fpz = fopen("usr\\zh.txt", "at+");
				scanf("%s", usr);
				fputs(usr, fpz);
				fclose(fpz);
				printf("\t\n		密 码：");
				fpm = fopen("usr\\mm.txt", "at+");
				for (int i = 0; i < 10; i++)
				{
					mm[i] = getch();
					if (mm[i] == '\r')
					{
						mm[i] = '\0';
						break;
					}
					printf("*");
				}

				printf("%s", mm);
				fputs(mm, fpm);
				fclose(fpm);
				system("cls");
				q = 0;
				q1 = 1;
			}
			break;
		}
	}

}


void glimus()    //管理面板鼠标效果
{
	MOUSEMSG m1;

	FILE* fp, * pf;
	while (qw)
	{
		//鼠标滑过效果
		m1 = GetMouseMsg();
		if (qw == 1)
		{
			if (sqrt((double)((m1.x - 100) * (m1.x - 100) + (m1.y - 100) * (m1.y - 100))) < 40)
			{
				djanniu(100, 100, 'z');
			}
			else if (sqrt((double)((m1.x - 300) * (m1.x - 300) + (m1.y - 100) * (m1.y - 100))) < 40)
			{
				djanniu(300, 100, 't');
			}
			else if (sqrt((double)((m1.x - 100) * (m1.x - 100) + (m1.y - 300) * (m1.y - 300))) < 40)
			{
				djanniu(100, 300, 'j');
			}
			else if (sqrt((double)((m1.x - 300) * (m1.x - 300) + (m1.y - 300) * (m1.y - 300))) < 40)
			{
				djanniu(300, 300, 'g');
			}
			else   //重新绘制
			{
				anniu(100, 100, 'z');
				anniu(300, 100, 't');
				anniu(100, 300, 'j');
				anniu(300, 300, 'g');
			}
		}
		switch (m1.uMsg)      //鼠标动作捕捉
		{
		case WM_LBUTTONDOWN:
			if (sqrt((double)((m1.x - 100) * (m1.x - 100) + (m1.y - 100) * (m1.y - 100))) < 40)     //增删查改页面
			{
				int zscg, zsc = 1;
				closegraph();
				system("cls");

				while (zsc)
				{

					printf("\t\t请选择\n");
					printf("\t\t 1.增加学生\n");
					printf("\t\t 2.删除学生\n");
					printf("\t\t 3.查找学生\n");
					printf("\t\t 4.修改学生\n");
					printf("\t\t 5.退出系统\n");
					scanf("%d", &zscg);
					switch (zscg)
					{
					case 1:
						addbook();
						break;
					case 2:
						//delete_book();
						delbook();
						break;
					case 3:
						serbook();
						break;
					case 4:
						xgbook();
						break;
					case 5:
						zsc = 0;
						closegraph();
						glishitu();
						glimus;
						break;
					}
				}

			}
			else if (sqrt((double)((m1.x - 300) * (m1.x - 300) + (m1.y - 100) * (m1.y - 100))) < 40)    //图书浏览页面
			{
				closegraph();
				system("cls");
				lkbook();
				closegraph();
				glishitu();
				glimus;
			}
			else if (sqrt((double)((m1.x - 100) * (m1.x - 100) + (m1.y - 300) * (m1.y - 300))) < 40)     //借出页面
			{
				closegraph();
				system("cls");
				jcbook();
				closegraph();
				glishitu();
				glimus;
			}
			else if (sqrt((double)((m1.x - 300) * (m1.x - 300) + (m1.y - 300) * (m1.y - 300))) < 40)     //归还页面
			{
				closegraph();
				system("cls");
				ghbook();
				closegraph();
				glishitu();
				glimus;
			}
			break;
		}
	}
}


