#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 15
#define MAX_NO 11
#define MAX_BIRTH 30
#define MAX_ADDRESS 50
#define MAX_TELEPH 11
#define MAX_EMAIL 20
#define MAX_PASSWORD 20
#define MAX_ACCOUNTNUM 20
typedef struct Student
{
    char no[MAX_NO];
    char name[MAX_NAME];
    int age;
    char sex;
    char birth[MAX_BIRTH];
    char address[MAX_ADDRESS];
    char teleph[MAX_TELEPH];
    char eMail[MAX_EMAIL];
} Student;
typedef struct DataBase
{
    Student *student;
    int size;
    int space;
} DataBase;

int signIn(char password[], char accountNum[]);
int registration(char (*password)[], char (*accountNum)[]);
void setPasswordCheck(char (*password)[]);
void initDataBase(DataBase *dataBase);
void add(DataBase *dataBase);
void show(DataBase *dataBase);
int query(DataBase *dataBase);
void del(DataBase *dataBase);
void modify(DataBase *dataBase);
void sort(DataBase *dataBase);
void freeSpace(DataBase *dataBase);
void documentStorage(DataBase *dataBase);
#define _CRT_SECURE_NO_WARNINGS 1
void menu()
{
    printf("-------------------菜单------------------\n");
    printf("-----------1.录入          2.浏览--------\n");
    printf("-----------3.查询          4.排序--------\n");
    printf("-----------5.删除          6.修改--------\n");
    printf("------------------7.退出-----------------\n");
}

int main()
{
    char accountNum[MAX_ACCOUNTNUM];
    char password[MAX_PASSWORD];
    int btn, sure = 0;
    DataBase dataBase;
    initDataBase(&dataBase);
    int loop = 1;
    int key;
    do
    {
        menu();
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            add(&dataBase);
            break;
        case 2:
            show(&dataBase);
            break;
        case 3:
            query(&dataBase);
            break;
        case 4:
            sort(&dataBase);
            break;
        case 5:
            del(&dataBase);
            break;
        case 6:
            modify(&dataBase);
            break;
        case 7:
            loop = 0;
            documentStorage(&dataBase);
            freeSpace(&dataBase);
            break;
        default:
            break;
        }
    } while (loop);
    printf("退出学生管理系统\n");
}
#define _CRT_SECURE_NO_WARNINGS 1
int myStrlen(char arr[])
{
    int length = 0;
    while (1)
    {
        if (arr[length] == 0 || length == strlen(arr))
        {
            break;
        }
        length++;
    }
    return length;
}
int compareTo(char str1[], char str2[])
{
    int length1 = myStrlen(str1);
    int length2 = myStrlen(str2);
    int minLength = length1 > length2 ? length2 : length1;
    for (int i = 0; i < minLength + 1; i++)
    {
        if (i == minLength)
        {
            return length1 - length2;
        }
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        continue;
    }
}

void freeSpace(DataBase *dataBase)
{
    free(dataBase->student);
    dataBase->student = NULL;
}

void reSpace(DataBase *dataBase)
{
    if (dataBase->space == dataBase->size)
    {
        Student *newSpace = realloc(dataBase->student, 10 * sizeof(Student));
        if (newSpace != NULL)
        {
            dataBase->student = newSpace;
            dataBase->space += 10;
            return;
        }
        printf("spaceOpeningException");
    }
}
void infoPrint(int index, DataBase *dataBase)
{
    printf("学号：%s\n", dataBase->student[index].no);
    printf("姓名：%s\n", dataBase->student[index].name);
    printf("性别：%c\n", dataBase->student[index].sex);
    printf("年龄：%d\n", dataBase->student[index].age);
    printf("出生年月：%s\n", dataBase->student[index].birth);
    printf("地址：%s\n", dataBase->student[index].address);
    printf("电话：%s\n", dataBase->student[index].teleph);
    printf("E-mail：%s\n", dataBase->student[index].eMail);
}

void transferData(DataBase *dataBase)
{
    FILE *data = fopen("DataBase.dat", "rb");
    if (data == NULL)
    {
        printf("文件打开异常\n");
        return;
    }
    Student student;
    while (fread(&student, sizeof(Student), 1, data))
    {
        reSpace(dataBase);
        dataBase->student[dataBase->size++] = student;
    }
    fclose(data);
    data = NULL;
}

void initDataBase(DataBase *dataBase)
{

    Student *def = (Student *)malloc(sizeof(Student) * 16);
    if (def != NULL)
    {
        dataBase->student = def;
        dataBase->size = 0;
        dataBase->space = 16;
        transferData(dataBase);
        return;
    }
    printf("spaceOpeningException");
}

int setPassword(char (*password)[])
{
    int letterFlag = 0;
    int numberFlag = 0;
    printf("请输入密码：(不能少于8位,不能超过18位，必须包含英文字母和数字)");
    scanf("%s", password);
    int passwordLength = myStrlen(*password);
    if (passwordLength < 8)
    {
        printf("密码不能少于8位\n");
        return 0;
    }
    if (passwordLength > 18)
    {
        printf("密码不能超过18位\n");
        return 0;
    }
    for (int i = 0; i < passwordLength; i++)
    {
        char cur = (*password)[i];
        if (cur >= '0' && cur <= '9')
        {
            numberFlag = 1;
        }
        if (cur >= 'A' && cur <= 'z')
        {
            letterFlag = 1;
        }
    }
    if (numberFlag && letterFlag)
    {
        return 1;
    }
    printf("必须包含英文字母和数字\n");
    return 0;
}
int registration(char (*password)[], char (*accountNum)[])
{
    printf("欢迎注册学生管理系统\n");
    char exit;
    do
    {
        printf("输入账号：");
        scanf("%s", accountNum);
        if (setPassword(password))
        {
            printf("注册成功\n");
            return 1;
        }
        else
        {
            memset(password, '*', sizeof(password));
            printf("是否继续注册？y/n\n");
            scanf("%c", &exit);
            if (exit == 'n')
            {
                printf("注册失败");
                return 0;
            }
            printf("请重新输入:\n");
        }
    } while (1);
}

int signIn(char password[], char accountNum[])
{
    printf("欢迎登录学生管理系统\n");
    char exit;
    char myacc[20];
    char mypass[20];
    printf("请输入账号：");
    scanf("%s", myacc);
    do
    {
        printf("请输入密码：");
        scanf("%s", mypass);
        if (!strcmp(password, mypass))
        {
            printf("成功登录\n");
            return 1;
        }
        else
        {
            printf("密码错误\n");
            printf("是否继续尝试? y/n\n");
            scanf("%c", &exit);
            if (exit == 'n')
            {
                return 0;
            }
            printf("请重新输入:\n");
        }
    } while (1);
}

void add(DataBase *dataBase)
{
    reSpace(dataBase);
    Student student;
    printf("请输入学生信息：\n");
    printf("学号：");
    scanf("%s", student.no);
    printf("姓名：");
    scanf("%s", student.name);
    printf("年龄：");
    scanf("%d", &(student.age));
    printf("性别："); // 男：M 女：F
    scanf("%s", &(student.sex));
    printf("出生年月：");
    scanf("%s", student.birth);
    printf("地址：");
    scanf("%s", student.address);
    printf("电话：");
    scanf("%s", student.teleph);
    printf("E-mail：");
    scanf("%s", student.eMail);
    for (int i = 0; i < dataBase->size; i++)
    {
        if (!strcmp(student.name, dataBase->student[i].name))
        {
            printf("已有该学生,添加失败\n");
            return;
        }
    }
    dataBase->student[dataBase->size++] = student;
    printf("添加成功\n");
}
void show(DataBase *dataBase)
{
    // DataBase *temp = dataBase;
    for (int i = 0; i < dataBase->size; i++)
    {
        infoPrint(i, dataBase);
        printf("---------------------------------------\n");
    }
}
int query(DataBase *dataBase)
{
    int key;
    char name[MAX_NAME];
    char no[MAX_NO];
    printf("请输入查询方式：1.姓名\t2.学号\n");
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        printf("请输入要检索学生的姓名：");
        scanf("%s", name);
        for (int i = 0; i < dataBase->size; i++)
        {
            if (strcmp(name, dataBase->student[i].name) == 0)
            {
                printf("姓名为%s的学生的信息如下：\n", name);
                infoPrint(i, dataBase);
                return i;
            }
        }
        return -1;
    case 2:
        printf("请输入要检索学生的学号：");
        scanf("%s", no);
        for (int i = 0; i < dataBase->size; i++)
        {
            if (strcmp(no, dataBase->student[i].no) == 0)
            {
                printf("学号为%s的学生的信息如下：\n", no);
                infoPrint(i, dataBase);
                return i;
            }
        }
        return -1;
    default:
        break;
    }
}
void del(DataBase *dataBase)
{
    int index = query(dataBase);
    if (index == -1)
    {
        printf("列表中无该学生，删除失败\n");
        return;
    }
    for (int i = index; i < dataBase->size - 1; i++)
    {
        dataBase[i] = dataBase[i + 1];
    }
    dataBase->size--;
    printf("删除成功\n");
}
void modify(DataBase *dataBase)
{
    int index = query(dataBase);
    if (index == -1)
    {
        printf("列表中无该学生\n");
        return;
    }
    printf("请选择要修改的数据:\n");
    int key;
    char falg; // 是否继续修改
    do
    {
        printf("1.学号\t2.性别\t3.年龄\t4.出生年月\n5.地址\t6.电话\t7.E-mail(单选)\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            printf("学号：");
            scanf("%s", dataBase->student[index].no);
            break;
        case 2:
            printf("性别：");
            scanf("%s", dataBase->student[index].sex);
            break;
        case 3:
            printf("年龄：");
            scanf("%d", dataBase->student[index].age);
            break;
        case 4:
            printf("出生年月：");
            scanf("%s", dataBase->student[index].birth);
            break;
        case 5:
            printf("地址：");
            scanf("%s", dataBase->student[index].address);
            break;
        case 6:
            printf("电话：");
            scanf("%s", dataBase->student[index].teleph);
            break;
        case 7:
            printf("E-mail：");
            scanf("%s", dataBase->student[index].eMail);
            break;
        default:
            break;
        }
        printf("是否继续修改？y/n\n");
        scanf("%c", &falg);
        if (falg == 'n')
        {
            break;
        }
    } while (1);
}

void sort(DataBase *dataBase)
{
    for (int i = 0; i < dataBase->size - 1; i++)
    {
        for (int j = 0; j < dataBase->size - i - 1; j++)
        {
            if (compareTo(dataBase->student[j].name, dataBase->student[j + 1].name) > 0)
            {
                Student temp = dataBase->student[j];
                dataBase->student[j] = dataBase->student[j + 1];
                dataBase->student[j + 1] = temp;
            }
        }
    }
}
void documentStorage(DataBase *dataBase)
{
    FILE *data = fopen("DataBase.dat", "wb");
    int count;
    if (data == NULL)
    {
        printf("文件打开异常");
        return;
    }
    for (int i = 0; i < dataBase->size; i++)
    {
        count = fwrite(&(dataBase->student[i]), sizeof(Student), 1, data);
        printf("%d", count);
    }
    fclose(data);
    data = NULL;
}
