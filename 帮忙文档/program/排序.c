#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
#define bool int
#define true 1
#define false 0
struct student
{
    int num;
    char name[20];
    int age;
    char sex;
    char data[10];
    char address[60];
    int phone;
    char Email[20];
} stu[N];
// ����ѧ����Ϣ
void Sort(struct student *L)
{
    system("cls");
    int choice = 0;
    printf("����ѧ�ŴӴ�С���� ---- 1\n");
    printf("����ѧ�Ŵ�С�������� ---- 2\n");
    printf("��������Ӵ�С���� ---- 3\n");
    printf("���������С�������� ---- 4\n");
    printf("��ѡ������ʽ��");
    scanf("%d", &choice);

    int flag = 0;
    for (struct student *p = L; p < L + N; p++)
    {
        for (struct student *q = p; q < L - p; q++)
        {
            switch (choice)
            {
            case 1:
                if (!cmp_big_ID(*p, *q))
                {
                    flag = 1;
                }
                break;
            case 2:
                if (!cmp_small_ID(*p, *q))
                {
                    flag = 1;
                }
                break;
            case 3:
                if (!cmp_big_Age(*p, *q))
                {
                    flag = 1;
                }
                break;
            case 4:
                if (!cmp_small_Age(*p, *q))
                {
                    flag = 1;
                }
                break;
            }
            if (flag == 1)
            {
                // ����������
                struct student t = *p;
                *p = *q;
                *q = t;
                flag = 0;
            }
        }
    }
}

// ѧ�ŴӴ�С
bool cmp_big_ID(struct student e1, struct student e2)
{
    return e1.num > e2.num;
}
// �ɼ��Ӵ�С
bool cmp_big_Age(struct student e1, struct student e2)
{
    return e1.age > e2.age;
}

// ѧ�Ŵ�С����
bool cmp_small_ID(struct student e1, struct student e2)
{
    return e1.num < e2.num;
}
// �ɼ���С����
bool cmp_small_Age(struct student e1, struct student e2)
{
    return e1.age < e2.age;
}