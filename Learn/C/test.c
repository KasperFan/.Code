#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __APPLE__
char str[20] = {0};
char *itoa(int num) // 10进制
{
    int i = 0;   // 指示填充str
    if (num < 0) // 如果num为负数，将num变正
    {
        num = -num;
        str[i++] = '-';
    }
    // 转换
    do
    {
        str[i++] = num % 10 + 48; // 取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0'
        num /= 10;                // 去掉最低位
    } while (num); // num不为0继续循环

    str[i] = '\0';

    // 确定开始调整的位置
    int j = 0;
    if (str[0] == '-') // 如果有负号，负号不用调整
    {
        j = 1; // 从第二位开始调整
        ++i;   // 由于有负号，所以交换的对称轴也要后移1位
    }
    // 对称交换
    for (; j < i / 2; j++)
    {
        // 对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i - 1 - j];
        str[i - 1 - j] = str[j] - str[i - 1 - j];
        str[j] = str[j] - str[i - 1 - j];
    }
    return str; // 返回转换后的值
}
#endif

struct people
{
    int num;            // 编号
    char name[20];      // 姓名
    char sex[10];       // 性别
    char birth[20];     // 出生年月
    char education[20]; // 学历
    char post[20];      // 职务
    char phone[20];     // 电话
    char position[100]; // 住址
} s[100];

int k = 0;       // 员工信息数
char title[100]; //

void readfile()
{
    // FILE *fp = fopen("D:\\员工信息.txt", "r");
    FILE *fp = fopen("员工信息.txt", "r");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
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
    printf("请输入需要查询的姓名：", a);
    fflush(stdin);
    fgets(a, 20, stdin);
    a[strlen(a) - 1] = 0;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(a, s[i].name) == 0)
        {
            printf("编号：%d 姓名:%s 性别：%s 出生年月：%s 学历：%s 职位：%s 电话：%s 住址：%s\n", s[i].num, s[i].name, s[i].sex, s[i].birth, s[i].education, s[i].post, s[i].phone, s[i].position);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("该员工不存在，请重新输入");
}

void find_by_num()
{
    int flag;
    flag = 0;
    char a[20];
    fflush(stdin);
    printf("请输入需要查询的编号：");
    fgets(a, 20, stdin);
    a[strlen(a) - 1] = 0;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(a, itoa(s[i].num)) == 0)
        {
            printf("编号：%d 姓名:%s 性别：%s 出生年月日：%s 学历：%s 职位：%s 电话：%s 住址：%s\n", s[i].num, s[i].name, s[i].sex, s[i].birth, s[i].education, s[i].post, s[i].phone, s[i].position);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("该员工不存在，请重新输入\n");
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
    printf("*******************按姓名排序结果为******************\n");
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
    printf("*******************按编号排序结果为******************\n");
    print();
}

void add()
{
    char number[20];
    printf("请输入要插入的员工编号：");
    scanf("%s", number);
    for (int i = 0; i < k; i++)
    {
        if (strcmp(number, itoa(s[i].num)) == 0)
        {
            printf("该员工信息已存在\n");
            return;
        }
    }
    printf("**************请输入信息：****************\n");
    printf("请输入姓名:");
    scanf("%s", s[k].name);
    printf("请输入性别:");
    scanf("%s", s[k].sex);
    printf("请输入出生年月:");
    scanf("%s", s[k].birth);
    printf("请输入学历:");
    scanf("%s", s[k].education);
    printf("请输入职务:");
    scanf("%s", s[k].post);
    printf("请输入电话:");
    scanf("%s", s[k].phone);
    printf("请输入住址:");
    scanf("%s", s[k].position);
    sscanf(number, "%d", &(s[k].num));
    k++;
    print();
}

void del_by_name()
{
    char xm[20];
    int flag = 0;
    printf("请输入要删除的员工姓名：");
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
        printf("没有找到该员工，无法删除员工信息\n");
    }
}

void del_by_num()
{
    char bh[10];
    int flag = 0;
    printf("请输入要删除信息员工的编号：");
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
        printf("没有找到该学生，无法删除学生信息\n");
    }
}

void renew()
{ // 更新
    char num[20];
    int flag = 0;
    printf("请输入要修改的员工的编号：");
    scanf("%s", num);
    for (int i = 0; i < k; i++)
    {
        if (strcmp(num, itoa(s[i].num)) == 0)
        {
            printf("**************请输入修改后的信息：****************\n");
            printf("请输入姓名:");
            scanf("%s", s[i].name);
            printf("请输入性别:");
            scanf("%s", s[i].sex);
            printf("请输入出生年月:");
            scanf("%s", s[i].birth);
            printf("请输入学历:");
            scanf("%s", s[i].education);
            printf("请输入职务:");
            scanf("%s", s[i].post);
            printf("请输入电话:");
            scanf("%s", s[i].phone);
            printf("请输入住址:");
            scanf("%s", s[i].position);
            // strcpy(s[k].num, number);
            print();
            flag = 1;
        }
        if (flag == 0)
        {
            printf("系统中无此员工信息\n");
        }
    }
}

void write()
{
    // FILE *fp = fopen("D:\\员工信息.txt", "w");
    FILE *fp = fopen("员工信息.txt", "w");
    if (fp == NULL)
    {
        printf("文件打开失败");
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
    printf("            *       欢迎使用员工管理系统      *\n");
    printf("            *             1.查询              *\n");
    printf("            *             2.排序              *\n");
    printf("            *             3.更新              *\n");
    printf("            *             4.插入              *\n");
    printf("            *             5.删除              *\n");
    printf("            *             6.退出              *\n");
    printf("            ***********************************\n");
    printf("请输入指令：");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("            ***********************************\n");
        printf("            *           1.按姓名查询           *\n");
        printf("            *           2.按编号查询           *\n");
        printf("            *           3.显示全部信息         *\n");
        printf("            *           4.返回上一步           *\n");
        printf("            ***********************************\n");
        printf("请输入指令：");
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
        printf("            *           1.按编号排序           *\n");
        printf("            *           2.按生日排序           *\n");
        printf("            *           3.返回上一步           *\n");
        printf("            ***********************************\n");
    };
        printf("请输入指令：");
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
        printf("            *           1.按姓名删除          *\n");
        printf("            *           2.按编号删除          *\n");
        printf("            ***********************************\n");
    }
        printf("请输入指令：");
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
//     printf("数字：%d 转换后的字符串为：%s\n", number1, string);
//     Int2String(number2, string);
//     printf("数字：%d 转换后的字符串为：%s\n", number2, string);
//     return 0;
// }
