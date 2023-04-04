#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
struct student
{
	int num;		  // ѧ��
	char name[20];	  // ����
	int age;		  // ����
	char sex;		  // �Ա�
	char data[10];	  // ��������
	char address[60]; // ��ַ
	int phone;		  // �绰
	char Email[20];	  // E-mail
} stu[N];
void Menu();
void input(struct student *, int);
void show(struct student *);

int main()
{
	char password[6];
	int j;
	printf("please input password:");
	for (j = 0; j <= 3; j++)
	{
		scanf("%s", password);
		if (strcmp(password, "123456\0") == 0)
		{
			printf("password is right!\n");
			break;
		}
		else
		{
			if (j < 2)
				printf("error input again:");
			else
				printf("password error!\n");
		}
	}
	Menu();
	input(stu, N);
	show(stu);
	return 0;
}

void Menu()
{
	printf("\n������ȷ��\n");
	printf("------ѧ����Ϣ����ϵͳ--------\n");
	printf("*       1. ѧ����Ϣ¼��          *\n");
	printf("*       2. ѧ����Ϣ��ʾ          *\n");
	printf("*       3. ѧ����Ϣ��ѯ          *\n");
	printf("*       4. ѧ����Ϣ����          *\n");
	printf("*       5. ѧ����Ϣ�޸�          *\n");
	printf("*       6. ѧ����Ϣɾ��          *\n");
	printf("*       0. �˳�ϵͳ              *\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	int choise;
	switch (choise)
	{
	case 0:
		exit(0);
		break;
	case 1:
		input(stu, N);
		system("pause");
		system("cls");
		break; // ¼��
	case 2:
		show(stu);
		system("pause");
		system("cls");
		break; // ��ʾ
	case 3:
		found();
		system("pause");
		system("cls");
		break; // ��ѯ
	case 4:
		sort();
		system("pause");
		system("cls");
		break; // ����
	case 5:
		modify();
		system("pause");
		system("cls");
		break; // �޸�
	case 6:
		delet();
		system("pause");
		system("cls");
		break; // ɾ��
	default:
		printf("\n�������������0---6\n\n");
		system("pause");
		system("cls");
		break;
	}
}
void input(struct student *p, int n)
{
	int i;
	FILE *fp;
	if ((fp = fopen("stu_list", "wb")) == NULL)
	{
		printf("Can not open file\n");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		printf("please input Number %d 's information\n :num: \n name:\n  age:\n  sex:\n  data: \n address:\n phone:\n Email:\n ", i + 1);
		scanf("%d%s%d%s%s%s%d%s", &stu[i].num, stu[i].name, &stu[i].age, &stu[i].sex, stu[i].data, stu[i].address, &stu[i].phone, stu[i].Email);
		if (p->num == 0)
			break;
	}
	fwrite(&stu, sizeof(struct student), N, fp);
	for (i = 0; i < n; i++)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, fp))
			printf("Success\n");
		else
			printf("Defeat\n");
	}
	fclose(fp);
}
void show(struct student *p)
{
	int i;
	for (i = 0; i < N; i++)
		printf("Num %d student's information is num:%d name:%s age:%d sex:%s data:%s address:%s phone:%d  Email:%s", i + 1, stu[i].num, stu[i].name, stu[i].age, stu[i].sex, stu[i].data, stu[i].address, stu[i].phone, stu[i].Email);
}
