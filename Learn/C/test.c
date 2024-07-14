#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __APPLE__
char str[20] = {0};
char *itoa(int num) // 10����
{
    int i = 0;   // ָʾ���str
    if (num < 0) // ���numΪ��������num����
    {
        num = -num;
        str[i++] = '-';
    }
    // ת��
    do
    {
        str[i++] = num % 10 + 48; // ȡnum���λ �ַ�0~9��ASCII����48~57������˵����0+48=48��ASCII���Ӧ�ַ�'0'
        num /= 10;                // ȥ�����λ
    } while (num); // num��Ϊ0����ѭ��

    str[i] = '\0';

    // ȷ����ʼ������λ��
    int j = 0;
    if (str[0] == '-') // ����и��ţ����Ų��õ���
    {
        j = 1; // �ӵڶ�λ��ʼ����
        ++i;   // �����и��ţ����Խ����ĶԳ���ҲҪ����1λ
    }
    // �Գƽ���
    for (; j < i / 2; j++)
    {
        // �Գƽ������˵�ֵ ��ʵ����ʡ���м��������a+b��ֵ��a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i - 1 - j];
        str[i - 1 - j] = str[j] - str[i - 1 - j];
        str[j] = str[j] - str[i - 1 - j];
    }
    return str; // ����ת�����ֵ
}
#endif

struct people
{
    int num;            // ���
    char name[20];      // ����
    char sex[10];       // �Ա�
    char birth[20];     // ��������
    char education[20]; // ѧ��
    char post[20];      // ְ��
    char phone[20];     // �绰
    char position[100]; // סַ
} s[100];

int k = 0;       // Ա����Ϣ��
char title[100]; //

void readfile()
{
    // FILE *fp = fopen("D:\\Ա����Ϣ.txt", "r");
    FILE *fp = fopen("Ա����Ϣ.txt", "r");
    if (fp == NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fgets(title, 100, fp);
    while (!feof(fp))
    {
        fscanf(fp, "%d%s%s%s%s%s%s%s", &s[k].num, s[k].name, s[k].sex, s[k].birth, s[k].education, s[k].post, s[k].phone, s[k].position);
        k++;
    }
    fclose(fp);
}

void find_by_name()
{
    int flag;
    flag = 0;
    char a[20];
    printf("��������Ҫ��ѯ��������", a);
    fflush(stdin);
    fgets(a, 20, stdin);
    a[strlen(a) - 1] = 0;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(a, s[i].name) == 0)
        {
            printf("��ţ�%d ����:%s �Ա�%s �������£�%s ѧ����%s ְλ��%s �绰��%s סַ��%s\n", s[i].num, s[i].name, s[i].sex, s[i].birth, s[i].education, s[i].post, s[i].phone, s[i].position);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("��Ա�������ڣ�����������");
}

void find_by_num()
{
    int flag;
    flag = 0;
    char a[20];
    fflush(stdin);
    printf("��������Ҫ��ѯ�ı�ţ�");
    fgets(a, 20, stdin);
    a[strlen(a) - 1] = 0;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(a, itoa(s[i].num)) == 0)
        {
            printf("��ţ�%d ����:%s �Ա�%s ���������գ�%s ѧ����%s ְλ��%s �绰��%s סַ��%s\n", s[i].num, s[i].name, s[i].sex, s[i].birth, s[i].education, s[i].post, s[i].phone, s[i].position);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("��Ա�������ڣ�����������\n");
}

void print()
{
    char title1[100] = {0};
    strcpy(title1, title);
    title1[strlen(title1) - 1] = 0;
    puts(title1);
    for (int i = 0; i < k; i++)
    {
        printf("%d %s %s %s %s %s %s %s\n", s[i].num, s[i].name, s[i].sex, s[i].birth, s[i].education, s[i].post, s[i].phone, s[i].position);
    }
}

void sort_by_birth()
{
    struct people p;
    for (int i = k - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(s[j + 1].birth, s[j].birth) < 0)
            {
                p = s[j];
                s[j] = s[j + 1];
                s[j + 1] = p;
            }
        }
    }
    printf("*******************������������Ϊ******************\n");
    print();
}

void sort_by_num()
{
    struct people p;
    for (int i = k - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[j + 1].num < s[j].num)
            {
                p = s[j];
                s[j] = s[j + 1];
                s[j + 1] = p;
            }
        }
    }
    printf("*******************�����������Ϊ******************\n");
    print();
}

void add()
{
    char number[20];
    printf("������Ҫ�����Ա����ţ�");
    scanf("%s", number);
    for (int i = 0; i < k; i++)
    {
        if (strcmp(number, itoa(s[i].num)) == 0)
        {
            printf("��Ա����Ϣ�Ѵ���\n");
            return;
        }
    }
    printf("**************��������Ϣ��****************\n");
    printf("����������:");
    scanf("%s", s[k].name);
    printf("�������Ա�:");
    scanf("%s", s[k].sex);
    printf("�������������:");
    scanf("%s", s[k].birth);
    printf("������ѧ��:");
    scanf("%s", s[k].education);
    printf("������ְ��:");
    scanf("%s", s[k].post);
    printf("������绰:");
    scanf("%s", s[k].phone);
    printf("������סַ:");
    scanf("%s", s[k].position);
    sscanf(number, "%d", &(s[k].num));
    k++;
    print();
}

void del_by_name()
{
    char xm[20];
    int flag = 0;
    printf("������Ҫɾ����Ա��������");
    scanf("%s", xm);
    for (int i = 0; i < k; i++)
    {
        if (strcmp(xm, s[i].name) == 0)
        {
            flag = 1;
            for (int j = i + 1; j < k; j++)
                s[j - 1] = s[j];
            k--;
            print();
            break;
        }
    }
    if (flag == 0)
    {
        printf("û���ҵ���Ա�����޷�ɾ��Ա����Ϣ\n");
    }
}

void del_by_num()
{
    char bh[10];
    int flag = 0;
    printf("������Ҫɾ����ϢԱ���ı�ţ�");
    scanf("%s", bh);
    for (int i = 0; i < k; i++)
    {
        if (strcmp(bh, itoa(s[i].num)) == 0)
        {
            flag = 1;
            for (int j = i + 1; j < k; j++)
                s[j - 1] = s[j];
            k--;
            print();
            break;
        }
    }
    if (flag == 0)
    {
        printf("û���ҵ���ѧ�����޷�ɾ��ѧ����Ϣ\n");
    }
}

void renew()
{ // ����
    char num[20];
    int flag = 0;
    printf("������Ҫ�޸ĵ�Ա���ı�ţ�");
    scanf("%s", num);
    for (int i = 0; i < k; i++)
    {
        if (strcmp(num, itoa(s[i].num)) == 0)
        {
            printf("**************�������޸ĺ����Ϣ��****************\n");
            printf("����������:");
            scanf("%s", s[i].name);
            printf("�������Ա�:");
            scanf("%s", s[i].sex);
            printf("�������������:");
            scanf("%s", s[i].birth);
            printf("������ѧ��:");
            scanf("%s", s[i].education);
            printf("������ְ��:");
            scanf("%s", s[i].post);
            printf("������绰:");
            scanf("%s", s[i].phone);
            printf("������סַ:");
            scanf("%s", s[i].position);
            // strcpy(s[k].num, number);
            print();
            flag = 1;
        }
        if (flag == 0)
        {
            printf("ϵͳ���޴�Ա����Ϣ\n");
        }
    }
}

void write()
{
    // FILE *fp = fopen("D:\\Ա����Ϣ.txt", "w");
    FILE *fp = fopen("Ա����Ϣ.txt", "w");
    if (fp == NULL)
    {
        printf("�ļ���ʧ��");
        exit(0);
    }
    fputs(title, fp);
    for (int i = 0; i < k; i++)
    {
        fprintf(fp, "%d %s %s %s %s %s %s %s\n", s[i].num, s[i].name, s[i].sex, s[i].birth, s[i].education, s[i].post, s[i].phone, s[i].position);
    }
    fclose(fp);
}

void menu()
{
    int a, b;
    printf("            ***********************************\n");
    printf("            *       ��ӭʹ��Ա������ϵͳ      *\n");
    printf("            *             1.��ѯ              *\n");
    printf("            *             2.����              *\n");
    printf("            *             3.����              *\n");
    printf("            *             4.����              *\n");
    printf("            *             5.ɾ��              *\n");
    printf("            *             6.�˳�              *\n");
    printf("            ***********************************\n");
    printf("������ָ�");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("            ***********************************\n");
        printf("            *           1.��������ѯ           *\n");
        printf("            *           2.����Ų�ѯ           *\n");
        printf("            *           3.��ʾȫ����Ϣ         *\n");
        printf("            *           4.������һ��           *\n");
        printf("            ***********************************\n");
        printf("������ָ�");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            find_by_name();
            break;

        case 2:
            find_by_num();
            break;

        case 3:
            print();
            break;

        case 4:
            return;
            break;

        default:
            break;
        }
        break;

    case 2:
    {
        printf("            ***********************************\n");
        printf("            *           1.���������           *\n");
        printf("            *           2.����������           *\n");
        printf("            *           3.������һ��           *\n");
        printf("            ***********************************\n");
    };
        printf("������ָ�");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            sort_by_num();
            break;

        case 2:
            sort_by_birth();
            break;

        case 3:
            return;
        }
        break;

    case 3:
    {
        renew();
    };
    break;

    case 4:
    {
        add();
    };
    break;

    case 5:
    {
        printf("            ***********************************\n");
        printf("            *           1.������ɾ��          *\n");
        printf("            *           2.�����ɾ��          *\n");
        printf("            ***********************************\n");
    }
        printf("������ָ�");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
        {
            del_by_name();
        };
        break;

        case 2:
        {
            del_by_num();
        };
        break;
        }
        break;

    case 6:
        write();
        exit(0);
        break;
    }
}

int main()
{
    readfile();
    do
    {
        menu();
    } while (1);
    return 0;
}

// int main()
// {
//     int number1 = 123456;
//     int number2 = -123456;
//     char string[16] = {0};
//     Int2String(number1, string);
//     printf("���֣�%d ת������ַ���Ϊ��%s\n", number1, string);
//     Int2String(number2, string);
//     printf("���֣�%d ת������ַ���Ϊ��%s\n", number2, string);
//     return 0;
// }
