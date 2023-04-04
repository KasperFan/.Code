#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
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
// ��ѯѧ����Ϣ
void Search_Printf(struct student *stu)
{
    system("cls");
    int choice = 0;
    printf("����ѧ�Ų�ѯ ---- 1\n");
    printf("����������ѯ ---- 2\n");
    printf("�������ѯ��ʽ��");
    scanf("%d", &choice);

    int id;
    char name[50];
    struct student *st;
    if (choice == 1)
    {
        printf("������Ҫ��ѯ��ѧ�ţ�");
        scanf("%d", &id);
        st = Search(id, stu);

        if (st == NULL)
        {
            printf("���޴��ˣ�\n");
        }
        else
        {
            printf("________________________________________________________________\n");
            printf("|ѧ��\t|����\t|����\t|�Ա�\t|��������\t\t|��ַ\t\t|�绰\t|E-mail\t|\n");
            printf("________________________________________________________________\n");
            printf("%d|%s\t|%d\t|%c\t|%s\t|%s\t|%d\t|%s\t|\n", st->num, st->name, st->age, st->sex, st->data, st->address, st->phone, st->Email);
            printf("________________________________________________________________\n");
        }
    }
    else if (choice == 2)
    {
        printf("������Ҫ��ѯ��������");
        scanf("%s", name);
        st = Search(name, stu);

        if (st == NULL)
        {
            printf("���޴��ˣ�\n");
        }
        else
        {
            printf("________________________________________________________________\n");
            printf("|ѧ��\t|����\t|����\t|�Ա�\t|��������\t\t|��ַ\t\t|�绰\t|E-mail\t|\n");
            printf("________________________________________________________________\n");
            printf("%d|%s\t|%d\t|%c\t|%s\t|%s\t|%d\t|%s\t|\n", st->num, st->name, st->age, st->sex, st->data, st->address, st->phone, st->Email);
            printf("________________________________________________________________\n");
        }
    }
}
// ��ѧ�Ž��в���
struct student *Search_id(int id, struct student *stu)
{
    struct student *p = stu;

    while (p++ <= stu + N)
    {
        if (p->num == id)
        {
            return p;
        }
    }
    return NULL;
}
// ���������в���
struct student *Search_name(char name[], struct student *stu)
{
    struct student *p = stu;

    while (p++ <= stu + N)
    {
        if (strcmp(name, p->name))
        {
            return p;
        }
    }
    return NULL;
}