#pragma once
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>


#define wig 600
#define hig 600

int q = 1, qw = 1;   //���Ʊ���
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


void loaddtbk();            //���ض�̬����
void loadbk();              //���ع���ģ�鱳��
void anniu(int x, int y, char pos);          //���ص�¼ע�ᣬ��ɾ��İ�ť
void mus();               //��¼ע��ҳ��������
void djanniu(int x, int y, char pos);          //����ƶ���ȥЧ��
void glishitu();              //����ҳ����ͼ��Ч��
void glimus();              //����ҳ��������
void addbook();             //ͼ������
void serbook();            //ͼ������
void delbook();              //ͼ��ɾ��
void xgbook();              //ͼ���޸�
void lkbook();                //ͼ�����
void jcbook();              //ͼ����
void ghbook();             //ͼ��黹



//ϵͳ��ʼ��
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

//��ť��ʼ��
void anniu(int x, int y, char pos)
{
	setfillcolor(WHITE);
	solidcircle(x, y, 40);
	setlinestyle(PS_SOLID, 3);
	circle(x, y, 50);
	if (pos == 's')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "��¼");
	}
	else if (pos == 'x')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "ע��");
	}
	else if (pos == 'z')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "��ɾ");
		outtextxy(x - 20, y + 15, "�Ĳ�");
	}
	else if (pos == 't')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "ѧ��");
		outtextxy(x - 20, y + 15, "���");
	}
	/*else if (pos == 'j')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "���");
	}
	else if (pos == 'g')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "�黹");
	}*/
}


//����ģ��ͼ��
void glishitu()
{
	initgraph(wig, hig);
	loadbk();
	anniu(100, 100, 'z');
	anniu(300, 100, 't');
	/*anniu(100, 300, 'j');
	anniu(300, 300, 'g');*/
}


//�����
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
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "��¼");
	}
	else if (pos == 'x')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "ע��");
	}
	else if (pos == 'z')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "��ɾ");
		outtextxy(x - 20, y + 15, "�Ĳ�");
	}
	else if (pos == 't')
	{
		settextcolor(BLACK);
		settextstyle(25, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(x - 20, y - 20, "ѧ��");
		outtextxy(x - 20, y + 15, "���");
	}
	//else if (pos == 'j')
	//{
	//	settextcolor(BLACK);
	//	settextstyle(25, 0, "����");
	//	setbkmode(TRANSPARENT);
	//	outtextxy(x - 20, y - 20, "���");
	//}
	//else if (pos == 'g')
	//{
	//	settextcolor(BLACK);
	//	settextstyle(25, 0, "����");
	//	setbkmode(TRANSPARENT);
	//	outtextxy(x - 20, y - 20, "�黹");
	//}
}            //�����



//����ͼ��
void addbook()
{
	int zs = 1;
	FILE* fp;
	while (zs)
	{

		fp = fopen("data\\book.txt", "at+");
		printf("----------����ѧ��----------\n\n");
		printf("������ѧ�����:");
		scanf("%d", &bok->bianhao);
		printf("������ѧ������:");
		scanf("%s", &bok->name);
		printf("ѧ���������ǣ�");
		scanf("%s", &bok->auot);
		printf("������ѧ������Ժϵ��");
		scanf("%s", &bok->chubanshe);
		printf("������ѧ�������䣺");
		scanf("%d", &bok->number);
		printf("������ѧ���Ա�");
		scanf("%s", &bok->reader);
		printf("������ѧ���༶");
		scanf("%s", &bok->status);
		fprintf(fp, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
		fclose(fp);
		fflush(stdin);
		printf("�Ƿ����¼�룬��������1����������0\n");
		scanf("%d", &zs);
		system("cls");

	}
}


//����ͼ��
void serbook()
{
	FILE* fp;
	fp = fopen("data\\book.txt", "at+");
	int num;
	int find = 0;
	printf("����Ų���ѧ����Ϣ\n");
	printf("������Ҫ���ҵ�ѧ����ţ�");
	scanf("%d", &num);
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
		if (num == bok->bianhao)
		{
			printf("ͼѧ����ѧ����%d", bok->bianhao);
			printf("ѧ����������%s", bok->name);
			printf("ѧ���İ�������%s", bok->auot);
			printf("ѧ������Ժϵ��%s", bok->chubanshe);
			printf("ѧ����������%d", bok->number);
			printf("ѧ�����Ա���%s", bok->reader);
			printf("ѧ���İ༶��%s", bok->status);
			printf("\n");
			find = 1;
		}
	}
	if (!find)
	{
		printf("���޴���\n");
	}
	fclose(fp);

}

//ɾ��ͼ��
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
		printf("��ѧ�����ɾ��\n");
		printf("������Ҫɾ����ѧ�����");
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
				printf("ͼѧ����ѧ����%d\n", bok->bianhao);
				printf("ѧ����������%s\n", bok->name);
				printf("ѧ���İ�������%s\n", bok->auot);
				printf("ѧ������Ժϵ��%s\n", bok->chubanshe);
				printf("ѧ����������%d\n", bok->number);
				printf("ѧ�����Ա���%s\n", bok->reader);
				printf("ѧ���İ༶��%s\n", bok->status);
				printf("ɾ���ɹ�\n");
				fin = 1;
			}
		}
		if (!fin)
		{
			printf("���޴���");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("�Ƿ����ɾ��ѧ�����Ǵ�1�����0��");
		scanf("%d", &qw);
		system("cls");
	}
}


//�޸�ͼ��

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
		printf("������޸�ѧ��������\n");
		printf("��������Ҫ�޸ĵ�ѧ����ţ�");
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
				printf("�������޸ĺ������");
				scanf("%s", name);
				strcpy(bok->name, name);
				printf("\n�������޸ĺ�İ�����");
				scanf("%s", aut);
				strcpy(bok->auot, aut);
				printf("\n�������޸ĺ�����Ժϵ");
				scanf("%s", cbs);
				strcpy(bok->chubanshe, cbs);
				printf("\n�������޸ĺ������");
				scanf("%d", &nub);
				bok->number = nub;
				printf("\n�������޸ĺ���Ա�");
				scanf("%s", jyr);
				strcpy(bok->reader, jyr);
				printf("\n�������޸ĺ�İ༶");
				scanf("%s", jc);
				strcpy(bok->status, jc);
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
				printf("ͼѧ����ѧ����%d\n", bok->bianhao);
				printf("ѧ����������%s\n", bok->name);
				printf("ѧ���İ�������%s\n", bok->auot);
				printf("ѧ������Ժϵ��%s\n", bok->chubanshe);
				printf("ѧ����������%d\n", bok->number);
				printf("ѧ�����Ա���%s\n", bok->reader);
				printf("ѧ���İ༶��%s\n", bok->status);
				printf("�޸ĳɹ�");
				printf("\n");
				find = 1;
			}
		}
		if (!find)
		{
			printf("���޴���");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("�Ƿ�����޸ģ����밲1�����밴0: ");
		scanf("%d", &qw_xg);
		system("cls");
	}
}

//���ȫ��ͼ��	
void lkbook()
{
	FILE* fp;
	printf("--------���ѧ����Ϣ--------\n");
	fp = fopen("data\\book.txt", "at+");
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s %s %d %s %s\n", &bok->bianhao, &bok->name, &bok->auot, &bok->chubanshe, &bok->number, &bok->reader, &bok->status);
		printf("ͼѧ����ѧ����%d\n", bok->bianhao);
		printf("ѧ����������%s\n", bok->name);
		printf("ѧ���İ�������%s\n", bok->auot);
		printf("ѧ������Ժϵ��%s\n", bok->chubanshe);
		printf("ѧ����������%d\n", bok->number);
		printf("ѧ�����Ա���%s\n", bok->reader);
		printf("ѧ���İ༶��%s\n", bok->status);
		printf("\n");
	}
	fclose(fp);
	printf("�����������");
	getchar();
}

//���ͼ��
void jcbook()
{
	int qw_jy = 1;
	while (qw_jy)
	{
		FILE* fp;
		FILE* fpen;
		printf("����������ͼ����");
		int nub, find = 0;
		char qs[10] = "���";
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
				printf("�������������");
				scanf("%s", name);
				strcpy(bok->status, name);
				bok->number--;
				fprintf(fpen, "%d %s %s %s %d %s %s\n", bok->bianhao, bok->name, bok->auot, bok->chubanshe, bok->number, bok->reader, bok->status);
				printf("ͼ��ı����%d\n", bok->bianhao);
				printf("ͼ���������%s\n", bok->name);
				printf("ͼ���������%s\n", bok->auot);
				printf("ͼ��ĳ�������%s\n", bok->chubanshe);
				printf("ͼ���������%d\n", bok->number);
				printf("ͼ��Ľ������%s\n", bok->reader);
				printf("ͼ��Ľ�������%s\n", bok->status);
				printf("����ɹ�");
				printf("\n");
				find = 1;
			}
		}
		if (!find)
		{
			printf("���޴���");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("�Ƿ�������ģ����밲1�����밴0: ");
		scanf("%d", &qw_jy);
		system("cls");
	}
}

//�黹ͼ��
void ghbook()
{
	int qw_gh = 1;
	while (qw_gh)
	{
		FILE* fp;
		FILE* fpen;
		printf("������黹��ͼ����");
		int nub, find = 0;
		char qs[10] = "����";
		char name[20] = "��";
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
				printf("ͼ��ı����%d\n", bok->bianhao);
				printf("ͼ���������%s\n", bok->name);
				printf("ͼ���������%s\n", bok->auot);
				printf("ͼ��ĳ�������%s\n", bok->chubanshe);
				printf("ͼ���������%d\n", bok->number);
				printf("ͼ��Ľ������%s\n", bok->reader);
				printf("ͼ��Ľ�������%s\n", bok->status);
				printf("�黹�ɹ�");
				printf("\n");
				find = 1;
			}
		}
		if (!find)
		{
			printf("���޴���");
		}
		fclose(fp);
		fclose(fpen);
		remove("data\\book.txt");
		rename("data\\bk.txt", "data\\book.txt");
		printf("�Ƿ�����黹�����밲1�����밴0: ");
		scanf("%d", &qw_gh);
		system("cls");
	}
}