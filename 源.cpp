#include"qwe.h"
int main()
{
	system("title ѧ������ϵͳ");
	system("mode con cols=60 lines=20");
	system("color 2f");
	initgraph(wig, hig);
	loaddtbk();
	mus();
	if (q1 == 1)
	{
		char usr1[10], mm1[10];
		int w = 1;
		printf("\t		��¼ϵͳ");
		while (w)
		{
			printf("\t\n\n		�û���:");
			scanf("%s", usr1);
			if (strcmp(usr, usr1) == 0)
			{
				w = 0;
			}
			else
			{
				system("cls");
				printf("�û�������������������\n");
			}
		}
		printf("\t\n		�� �룺");
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



//��꺯������
void mus()
{
	MOUSEMSG m;
	FILE* fpz, * fpm;
	while (q)
	{
		//��껬��Ч��
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

		switch (m.uMsg)      //��궯����׽
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
					printf("\t\n\n		�û���:");
					scanf("%s", usr11);
					if (strcmp(usr, usr11) == 0)
					{
						w = 0;
					}
					else
					{
						system("cls");
						printf("�û�����������������\n");
					}
				}
				printf("\t\n		�� �룺");
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
				//�û�ע�����
				closegraph();
				printf("\t\n\n		�û���:");
				fpz = fopen("usr\\zh.txt", "at+");
				scanf("%s", usr);
				fputs(usr, fpz);
				fclose(fpz);
				printf("\t\n		�� �룺");
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


void glimus()    //����������Ч��
{
	MOUSEMSG m1;

	FILE* fp, * pf;
	while (qw)
	{
		//��껬��Ч��
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
			else   //���»���
			{
				anniu(100, 100, 'z');
				anniu(300, 100, 't');
				anniu(100, 300, 'j');
				anniu(300, 300, 'g');
			}
		}
		switch (m1.uMsg)      //��궯����׽
		{
		case WM_LBUTTONDOWN:
			if (sqrt((double)((m1.x - 100) * (m1.x - 100) + (m1.y - 100) * (m1.y - 100))) < 40)     //��ɾ���ҳ��
			{
				int zscg, zsc = 1;
				closegraph();
				system("cls");

				while (zsc)
				{

					printf("\t\t��ѡ��\n");
					printf("\t\t 1.����ѧ��\n");
					printf("\t\t 2.ɾ��ѧ��\n");
					printf("\t\t 3.����ѧ��\n");
					printf("\t\t 4.�޸�ѧ��\n");
					printf("\t\t 5.�˳�ϵͳ\n");
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
			else if (sqrt((double)((m1.x - 300) * (m1.x - 300) + (m1.y - 100) * (m1.y - 100))) < 40)    //ͼ�����ҳ��
			{
				closegraph();
				system("cls");
				lkbook();
				closegraph();
				glishitu();
				glimus;
			}
			else if (sqrt((double)((m1.x - 100) * (m1.x - 100) + (m1.y - 300) * (m1.y - 300))) < 40)     //���ҳ��
			{
				closegraph();
				system("cls");
				jcbook();
				closegraph();
				glishitu();
				glimus;
			}
			else if (sqrt((double)((m1.x - 300) * (m1.x - 300) + (m1.y - 300) * (m1.y - 300))) < 40)     //�黹ҳ��
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


