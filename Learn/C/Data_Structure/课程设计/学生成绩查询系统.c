/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-06-12 13:16:23
 * @LastEditTime: 2023-10-16 15:13:39
 * @FilePath: /Learn/C/Data_Structure/课程设计/学生成绩查询系统.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#pragma GCC commit(lib, "mysqlclient", "ncursesw")
// 编译命令(¿):
// gcc main.c -o main -lmysqlclient -lncursesw

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>

#ifdef _WIN32     // 如果是Windows系统
char *op = "cls"; // 将system函数赋值给清屏函数指针变量
#include <conio.h>
#include <Windows.h>
LARGE_INTEGER freq, start_time, end_time; // freq为计时器的频率
#endif
#ifdef __APPLE__            // 如果是macOS系统
char *op = "clear";         // 将system函数赋值给清屏函数指针变量
#include <mach/mach_time.h> // macOS内核时间头文件
#include <locale.h>
#include <ncurses.h>
uint64_t start, stop;
mach_timebase_info_data_t info;
#endif
unsigned long interval;

#define MAX_FILENAME_LENGTH 100

// 定义学生信息结构体，包含学号、姓名和成绩
typedef struct Student
{
    long id;       // 学号，最多9个字符
    char name[20]; // 姓名，最多19个字符
    int score;     // 成绩，0到100之间的整数
} Student;

// 定义学生信息二叉排序树节点，包含一个学生信息结构体和左右子节点
typedef struct BSTNode
{
    Student student;       // 学生信息结构体
    struct BSTNode *left;  // 左子节点指针
    struct BSTNode *right; // 右子节点指针
} BSTNode;

// 两个全局变量，一会会用到
int choice = 7, count, flag = 0;

// 定义一个动态数组，初始大小为0，用于存储任意个数的学生信息
Student *students = NULL;
int size = 0;     // 数组的当前大小
int capacity = 0; // 数组的当前容量
// 定义一个变量，用于存储二叉排序树的根节点指针，并初始化为空
BSTNode *bst_root = NULL;

void menu();
void add_student(Student student);
void free_students();
void readStuInfo();
int show_menu();
int read_from_database();
int read_from_file(char *filename);
int read_from_stdin();
void search_stu_info();
void show_menu_search();
int get_input();
void show_result(long id, Student stu);
int sequential_search(long id);
void sort_by_id();
int binary_search(long id);
BSTNode *insert_bst(BSTNode *bst_root, Student student);
BSTNode *build_bst();
BSTNode *bst_search(BSTNode *bst_root, long id);
void export_file();
void show_menu_save();
void save_to_txt(char *filename);
void save_to_csv(char *filename);
void write_file(FILE *fp, char *option);
int input_password(char password[]);

int main(int argc, char const *argv[])
{
// 获取时钟频率
#ifdef __APPLE__
    setlocale(LC_ALL, "");
    mach_timebase_info(&info);
#endif
#ifdef _WIN32
    QueryPerformanceFrequency(&freq);
#endif

    do
    {
        system(op);
        menu();
        printf("\n");
    } while (choice != 0);
    return 0;
}

void menu()
{
    if (flag)
    {
        printf("         ******************************************\n");
        printf("         *                                        *\n");
        printf("         *       欢迎使用学生成绩查询系统         *\n");
        printf("         *                                        *\n");
        printf("         *           已读取学生信息               *\n");
        printf("         *                                        *\n");
        printf("         *           1：查找学生信息              *\n");
        printf("         *           2：学生信息排序              *\n");
        printf("         *           3：导出数据文件              *\n");
        printf("         *           0：退出系统                  *\n");
        printf("         *                                        *\n");
        printf("         ******************************************\n");
        printf("\n");
        // printf("---------------------------------------------------------------------\n");
        printf("         请按键选择你的操作:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system(op);
            search_stu_info();
            system(op);
            break;

        case 2:
            system(op);
            sort_by_id();
            for (int i = 0; i < size; i++)
                printf("         学生 %d: %ld %s %d\n", i + 1, students[i].id, students[i].name, students[i].score);
            printf("         学生信息按学号排序完成，按任意键继续");
            fflush(stdin);
            getchar();
            system(op);
            break;

        case 3:
            system(op);
            export_file();
            fflush(stdin);
            getchar();
            system(op);
            break;

        case 0:
            printf("         您是否要退出系统?(Y/N):");
            fflush(stdin);
            getchar();
            char check;
            scanf("%c", &check);
            if (check == 'y' || check == 'Y')
            {
                free_students();
                exit(0);
            }
        }
    }
    else
        readStuInfo();
}

// 定义一个函数，用于向动态数组中添加一个学生信息
void add_student(Student student)
{
    // 判断当前容量是否足够，如果不够，则扩大一倍，并重新分配内存
    if (size == capacity)
    {
        capacity = capacity == 0 ? 1 : capacity * 2;
        students = (Student *)realloc(students, capacity * sizeof(Student));
    }
    // 将学生信息复制到数组的末尾，并更新大小
    students[size++] = student;
}

// 定义一个函数，用于释放动态数组占用的内存
void free_students()
{
    // 如果数组不为空，则释放内存，并将指针置为空，大小和容量置为0
    if (students != NULL)
    {
        free(students);
        students = NULL;
        size = 0;
        capacity = 0;
    }
}

// 定义readStuInfo函数，根据用户的选择，从不同的来源读取学生信息，并显示读取到的数量
void readStuInfo()
{
    // 根据用户的选择执行相应的操作，直到用户选择退出
    while (choice != 0)
    {
        show_menu();
        if (choice == 1)
        {
            if (read_from_database())
                choice = show_menu();
            else
            {
                flag = 1;
                break;
            }
        }
        else if (choice == 2)
        {
            // 如果用户选择文件，获取文件名，并调用读取文件的函数，显示读取到的学生信息的数量
            char filename[20];
            printf("         请输入文件及后缀名:");
            scanf("%s", filename);
            if (read_from_file(filename))
                choice = show_menu();
            else
            {
                flag = 1;
                break;
            }
            fflush(stdin);
            getchar();
        }
        else if (choice == 3)
        {
            // 如果用户选择标准键盘输入，提示用户输入每个学生的信息，并调用读取标准键盘输入的函数，显示读取到的学生信息的数量
            printf("         请以“学号 姓名 分数”的格式填写学生资料，每行一人，以回车结尾:\n");
            read_from_stdin();
            printf("         从键盘输入中读取了 %d 个学生信息\n.\n", count);
        }
        else if (choice == 0)
        {
            printf("         您是否要退出系统?(Y/N):");
            fflush(stdin);
            getchar();
            char check;
            scanf("%c", &check);
            if (check == 'y' || check == 'Y')
                return;
        }
        else
            // 如果用户选择其他选项，提示错误信息，并返回主菜单
            printf("         非法选项!\n");
    }
    bst_root = build_bst();
    return;
}

// 定义一个函数，用于显示选择界面，并获取用户的选择
int show_menu()
{
    system(op);
    // 显示选择界面，并获取用户的选择
    printf("         ******************************************\n");
    printf("         *                                        *\n");
    printf("         *       欢迎使用学生成绩查询系统         *\n");
    printf("         *                                        *\n");
    printf("         *          暂无数据，请选择              *\n");
    printf("         *          1.数据库                      *\n");
    printf("         *          2.文件                        *\n");
    printf("         *          3.键盘输入                    *\n");
    printf("         *          0.退出系统                    *\n");
    printf("         *                                        *\n");
    printf("         ******************************************\n");
    printf("\n");
    // printf("---------------------------------------------------------------------\n");
    printf("          请选择数据源：");
    scanf("%d", &choice);
    return choice;
}

int read_from_database()
{
    // 如果用户选择数据库，获取数据库和表的信息，并连接数据库，如果失败，则提示错误信息，并返回主菜单
    MYSQL *db;                   // 数据库连接句柄
    MYSQL_RES *result;           // 执行数据库语言结果
    MYSQL_ROW row;               // 存放一个数据记录
    char server[] = "localhost"; // 本地连接
    char user[20];               // 用户名
    char password[20];           // 密码
    char db_name[20];            // 数据库名
    char table_name[20];         // 数据表名
    printf("         请输入数据库用户名:");
    scanf("%s", user);
#ifdef _WIN32
    printf("         请输入数据库密码:");
    input_password(password);
#endif
#ifdef __APPLE__
    input_password(password);
#endif
    printf("         请输入数据库名称:");
    scanf("%s", db_name);
    printf("         请输入数据表名:");
    scanf("%s", table_name);
    db = mysql_init(NULL);
    if (db == NULL)
    {
        printf("         初始化数据库: %s 失败\n\n", mysql_error(db));
        fflush(stdin);
        getchar();
        return 1;
    }
    if (mysql_real_connect(db, server, user, password, db_name, 3306, NULL, 0) == NULL)
    {
        printf("         无法连接到数据库 %s: %s\n\n", db_name, mysql_error(db));
        mysql_close(db);
        fflush(stdin);
        getchar();
        return 2;
    }
    // 构建查询语句，并执行查询，如果失败，则提示错误信息，并返回主菜单
    char sql[100];
    sprintf(sql, "SELECT * FROM %s;", table_name);
    if (mysql_query(db, sql))
    {
        printf("         *无法从表 %s 中查询: %s\n\n", table_name, mysql_error(db));
        mysql_close(db);
        fflush(stdin);
        getchar();
        return 3;
    }
    // 获取查询结果，并遍历每一行，创建学生信息结构体，并打印
    result = mysql_store_result(db);
    if (result == NULL)
    {
        printf("         *无法存储结果: %s\n\n", mysql_error(db));
        mysql_close(db);
        fflush(stdin);
        getchar();
        return 4;
    }

    while ((row = mysql_fetch_row(result)))
    {
        // 增加计数器
        count++;
        // 创建一个学生信息结构体，并赋值
        Student student;
        student.id = atoi(row[1]);
        strcpy(student.name, row[2]);
        student.score = atoi(row[3]);
        add_student(student);
        // 打印学生信息
        printf("         学生 %d: %ld %s %d\n", count, student.id, student.name, student.score);
    }
    // 释放结果集和关闭数据库，并显示读取到的学生信息的数量
    mysql_free_result(result);
    mysql_close(db);
    printf("         Read %d student(s) from database %s and table %s.\n", count, db_name, table_name);
    printf("         按下任意键继续");
    fflush(stdin);
    getchar();
    return 0;
}

// 定义一个函数，用于从txt文件中读取学生信息，并打印在屏幕上
int read_from_file(char *filename)
{
    char poin = '.';
    char *exten = strrchr(filename, poin);
    if (exten == NULL || *(exten + 1) == 0 && strcmp(exten, ".txt"))
    {
        printf("\n");
        printf("         文件格式有误，请重新输入!\n\n");
        fflush(stdin);
        getchar();
        return 1;
    }

    // 打开文件，如果失败，则提示错误信息，并返回
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\n");
        printf("         打开文件 %s 失败!\n\n", filename);
        fflush(stdin);
        getchar();
        return 2;
    }
    // 创建一个学生信息结构体，用于存储每行的数据
    Student student;
    // 读取文件中的每一行，直到文件结束或者出错
    if (!strcmp(exten, ".txt"))
    {
        while (fscanf(fp, "%ld %s %d", &student.id, student.name, &student.score) == 3)
        {
            add_student(student);
            // 增加计数器
            count++;
            // 打印学生信息
            printf("         学生 %d: %ld %s %d\n", count, student.id, student.name, student.score);
        }
    }
    // 关闭文件
    fclose(fp);
    printf("         从文件 %s 中读取了 %d 个学生信息\n", filename, count);
    printf("         按下任意键继续");
    return 0;
}

// 定义一个函数，用于从标准键盘输入读取学生信息，并打印在屏幕上
int read_from_stdin()
{
    // 创建一个学生信息结构体，用于存储每行的数据
    Student student;
    // 读取标准键盘输入中的每一行，直到输入为空或者出错
    while (scanf("%ld %s %d", student.id, student.name, &student.score) == 3)
    {
        add_student(student);
        // 增加计数器
        count++;
        // 打印学生信息
        printf("         学生 %d: %ld %s %d\n", count, &student.id, student.name, student.score);
    }
}

// 打印菜单
void show_menu_search()
{
    printf("         ******************************************\n");
    printf("         *                                        *\n");
    printf("         *                                        *\n");
    printf("         *           请选择查找类型               *\n");
    printf("         *                                        *\n");
    printf("         *           1：顺序查找                  *\n");
    printf("         *           2：折半查找                  *\n");
    printf("         *           3：二叉排序树查找            *\n");
    printf("         *           10：返回上一级               *\n");
    printf("         *                                        *\n");
    printf("         ******************************************\n");
    printf("\n");
}

// 获取用户的输入，并检查是否合法
int get_input()
{
    int input;
    scanf("%d", &input);
    // 如果输入不是1,2,3或10，则提示错误，并重新输入
    while (input != 1 && input != 2 && input != 3 && input != 10)
    {
        printf("         非法选项，请重新输入:");
        scanf("%d", &input);
    }
    return input;
}

// 显示查找结果和所用时间
void show_result(long id, Student stu)
{
    if (stu.id != -1) // 如果找到了学生
    {
        printf("         查找到学生: %ld %s %d", stu.id, stu.name, stu.score);
        printf("         所用时间: %luns\n", interval);
        printf("         按下任意键继续");
    }
    else // 如果没有找到学生
    {
        printf("         找不到学号为 %ld 的学生", id);
        printf("         按下任意键继续");
    }
}

void search_stu_info()
{
    int choice;  // 用户的选择
    long id;     // 要查询的学号
    int index;   // 学生在数组中的索引
    Student stu; // 学生结构体变量
    do
    {
        show_menu_search(); // 打印菜单
        printf("         请按键选择你的操作:");
        choice = get_input(); // 获取用户的输入
        if (choice == 10)
            return; // 如果用户选择返回上一级，则返回
        system(op); // 清屏
        printf("\n");
        printf("         请输入查询的学号:");
        scanf("%ld", &id); // 获取用户要查询的学号
        switch (choice)    // 根据用户的选择调用相应的查找函数
        {
        case 1:                            // 如果用户选择顺序查找
            index = sequential_search(id); // 调用顺序查找函数，返回学生在数组中的索引
            if (index != -1)               // 如果找到了学生
                stu = students[index];     // 将学生信息赋值给stu变量
            else                           // 如果没有找到学生
                stu.id = -1;               // 将stu的id设为-1，表示无效
            show_result(id, stu);          // 显示查找结果和所用时间
            fflush(stdin);
            getchar();
            system(op);
            break;

        case 2:                        // 如果用户选择折半查找
            index = binary_search(id); // 调用折半查找函数，返回学生在数组中的索引
            if (index != -1)           // 如果找到了学生
                stu = students[index]; // 将学生信息赋值给stu变量
            else                       // 如果没有找到学生
                stu.id = -1;           // 将stu的id设为-1，表示无效
            show_result(id, stu);      // 显示查找结果和所用时间
            fflush(stdin);
            getchar();
            system(op);
            break;

        case 3:                                      // 如果用户选择二叉排序树查找
            BSTNode *obj = bst_search(bst_root, id); // 调用二叉排序树查找函数，返回与学号匹配的节点指针
            if (obj != NULL)                         // 如果找到了节点
                stu = obj->student;                  // 将节点中的学生信息赋值给stu变量
            else                                     // 如果没有找到节点
                stu.id = -1;                         // 将stu的id设为-1，表示无效
            show_result(id, stu);                    // 显示查找结果和所用时间
            fflush(stdin);
            getchar();
            system(op);
            break;
        }
    } while (choice != 10); // 重复循环，直到用户选择返回上一级
}

// 定义一个函数，用于按学号的顺序查找学生信息，并传入学生结构体数组、数组大小和目标学号作为参数，返回查找结果的索引或者-1
int sequential_search(long id)
{
#ifdef __APPLE__
    // 获取开始时间
    start = mach_absolute_time();
#endif
#ifdef _WIN32
    // 获取开始时间
    QueryPerformanceCounter(&start_time);
#endif
    // 使用一个循环，从头到尾遍历数组中的每个元素
    for (int i = 0; i < size; i++)
    {
        // 比较当前元素的学号和目标学号是否相等
        if (students[i].id == id)
        {
#ifdef __APPLE__
            // 获取截止时间
            stop = mach_absolute_time();
            interval = ((stop - start) * info.numer) / info.denom;
#endif
#ifdef _WIN32
            // 获取结束时间
            QueryPerformanceCounter(&end_time);
            // 计算时间差，乘以10^9得到纳秒
            interval = (unsigned long)(end_time.QuadPart - start_time.QuadPart) / freq.QuadPart * 1e9;
#endif
            return i;
        }
    }
#ifdef __APPLE__
    // 获取截止时间
    stop = mach_absolute_time();
    interval = ((stop - start) * info.numer) / info.denom;
#endif
#ifdef _WIN32
    // 获取结束时间
    QueryPerformanceCounter(&end_time);
    // 计算时间差，乘以10^9得到纳秒
    interval = (unsigned long)(end_time.QuadPart - start_time.QuadPart) / freq.QuadPart * 1e9;
#endif
    // 如果遍历完所有元素都没有找到匹配的元素，则返回-1表示查找失败
    return -1;
}

// 定义一个函数，用于按学号排序后折半查找学生信息，并传入学生结构体数组、数组大小和目标学号作为参数，返回查找结果的索引或者-1
int binary_search(long id)
{
    // 使用一种排序算法，比如快速排序或者归并排序等，对数组中的元素按照学号进行升序或者降序排序，并将排序后的结果存储在数组中
    sort_by_id(students, size);
#ifdef __APPLE__
    // 获取开始时间
    start = mach_absolute_time();
#endif
#ifdef _WIN32
    // 获取开始时间
    QueryPerformanceCounter(&start_time);
#endif
    // 定义两个变量，分别表示查找范围的左右边界
    int left = 0;
    int right = size - 1;
    // 使用一个循环或者递归，每次比较数组中间的元素和目标学号的大小关系
    while (left <= right)
    {
        // 计算中间元素的索引
        int mid = (left + right) / 2;
        // 比较中间元素的学号和目标学号是否相等
        if (students[mid].id == id)
        {
#ifdef __APPLE__
            // 获取截止时间
            stop = mach_absolute_time();
            interval = ((stop - start) * info.numer) / info.denom;
#endif
#ifdef _WIN32
            // 获取结束时间
            QueryPerformanceCounter(&end_time);
            // 计算时间差，乘以10^9得到纳秒
            interval = (unsigned long)(end_time.QuadPart - start_time.QuadPart) / freq.QuadPart * 1e9;
#endif
            // 如果相等，则返回中间元素的索引
            return mid;
        }
        else if (students[mid].id < id)
        {
            // 如果小于，则缩小查找范围，在右半部分查找
            left = mid + 1;
        }
        else
        {
            // 如果大于，则缩小查找范围，在左半部分查找
            right = mid - 1;
        }
    }
#ifdef __APPLE__
    // 获取截止时间
    stop = mach_absolute_time();
    interval = ((stop - start) * info.numer) / info.denom;
#endif
#ifdef _WIN32
    // 获取结束时间
    QueryPerformanceCounter(&end_time);
    // 计算时间差，乘以10^9得到纳秒
    interval = (unsigned long)(end_time.QuadPart - start_time.QuadPart) / freq.QuadPart * 1e9;
#endif
    // 如果范围为空，则返回-1表示查找失败
    return -1;
}

// 定义一个函数，用于对学生结构体数组按照学号进行排序，并传入学生结构体数组和数组大小作为参数
void sort_by_id()
{
    // 使用一种排序算法，比如快速排序或者归并排序等，对数组中的元素按照学号进行升序或者降序排序，并将排序后的结果存储在数组中
    // 这里以快速排序为例，使用一个辅助函数，用于交换两个元素的位置
    void swap(Student * a, Student * b)
    {
        Student temp = *a;
        *a = *b;
        *b = temp;
    }
    // 使用一个辅助函数用于划分数组，选择一个基准元素，将小于或者等于基准元素的元素放在左边，将大于基准元素的元素放在右边，并返回基准元素的索引
    int partition(Student * students, int low, int high)
    {
        // 选择最右边的元素作为基准元素
        Student pivot = students[high];
        // 定义一个变量，用于记录小于或者等于基准元素的元素的个数
        int i = low - 1;
        // 使用一个循环，从左到右遍历数组中除了基准元素之外的每个元素
        for (int j = low; j < high; j++)
        {
            // 比较当前元素的学号和基准元素的学号是否小于或者等于
            // 使用数值比较而不是字符串比较
            if (students[j].id <= pivot.id)
            {
                // 如果小于或者等于，则增加计数器，并交换当前元素和计数器对应的元素的位置
                i++;
                swap(&students[i], &students[j]);
            }
        }
        // 最后，交换基准元素和计数器加一对应的元素的位置，并返回计数器加一作为基准元素的索引
        swap(&students[i + 1], &students[high]);
        return i + 1;
    }
    // 使用一个辅助函数，用于递归地对数组中的某个范围内的元素进行快速排序
    void quick_sort(Student * students, int low, int high)
    {
        // 判断范围是否有效，如果有效，则继续排序
        if (low < high)
        {
            // 调用划分函数，获取基准元素的索引，并将数组划分为两部分
            int pivot_index = partition(students, low, high);
            // 对左半部分进行快速排序
            quick_sort(students, low, pivot_index - 1);
            // 对右半部分进行快速排序
            quick_sort(students, pivot_index + 1, high);
        }
    }
    // 调用快速排序函数，对整个数组进行排序
    quick_sort(students, 0, size - 1);
}

// 定义一个函数，用于以学号为关键字的学生信息构建二叉排序树，并传入学生结构体数组和数组大小作为参数，返回二叉排序树的根节点指针
BSTNode *build_bst()
{
    // 使用一个循环或者递归，从数组中的第一个元素开始，依次将每个元素插入到一棵二叉排序树中
    for (int i = 0; i < size; i++)
    {
        // 调用一个辅助函数，用于将当前元素插入到二叉排序树中，并更新根节点指针
        bst_root = insert_bst(bst_root, students[i]);
    }
    // 返回二叉排序树的根节点指针
    return bst_root;
}

// 定义一个辅助函数，用于将一个元素插入到二叉排序树中，并传入二叉排序树的根节点指针和要插入的元素作为参数，返回更新后的根节点指针
BSTNode *insert_bst(BSTNode *bst_root, Student student)
{
    // 判断根节点是否为空，如果为空，则创建一个新的节点，并赋值，并返回该节点作为新的根节点
    if (bst_root == NULL)
    {
        BSTNode *new_node = malloc(sizeof(BSTNode));
        new_node->student = student;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    // 比较要插入的元素的学号和根节点的学号的大小关系
    if (student.id <= bst_root->student.id)
    {
        // 如果小于或者等于，则将要插入的元素插入到左子树中，并更新左子节点指针
        bst_root->left = insert_bst(bst_root->left, student);
    }
    else
    {
        // 如果大于，则将要插入的元素插入到右子树中，并更新右子节点指针
        bst_root->right = insert_bst(bst_root->right, student);
    }
    // 返回更新后的根节点指针
    return bst_root;
}

// 定义一个函数，用于对学号进行二叉排序树查找，并传入二叉排序树的根节点指针和目标学号作为参数，返回查找结果的节点指针或者NULL
BSTNode *bst_search(BSTNode *bst_root, long id)
{
    // 判断根节点是否为空，如果为空，则返回NULL表示查找失败
    if (bst_root == NULL)
    {
        return NULL;
    }
#ifdef __APPLE__
    // 获取开始时间
    start = mach_absolute_time();
#endif
#ifdef _WIN32
    // 获取开始时间
    QueryPerformanceCounter(&start_time);
#endif
    // 比较目标学号和根节点的学号是否相等
    if (id == bst_root->student.id)
    {
#ifdef __APPLE__
        // 获取截止时间
        stop = mach_absolute_time();
        interval = ((stop - start) * info.numer) / info.denom;
#endif
#ifdef _WIN32
        // 获取结束时间
        QueryPerformanceCounter(&end_time);
        // 计算时间差，乘以10^9得到纳秒
        interval = (unsigned long)(end_time.QuadPart - start_time.QuadPart) / freq.QuadPart * 1e9;
#endif
        // 如果相等，则返回根节点指针表示查找成功
        return bst_root;
    }
    else if (id < bst_root->student.id)
    {
        // 如果小于，则沿着左子树继续查找，并返回查找结果
        return bst_search(bst_root->left, id);
    }
    else
    {
        // 如果大于，则沿着右子树继续查找，并返回查找结果
        return bst_search(bst_root->right, id);
    }
}

void export_file()
{
    show_menu_save();
    scanf("%d", &choice);
    if (choice == 10)
        return;
    char *filename = (char *)malloc(sizeof(char) * MAX_FILENAME_LENGTH);
    system(op);
    printf("\n");
    printf("         请输入保存文件名:");
    scanf("%s", filename);
    switch (choice)
    {
    case 1:
        save_to_txt(filename);
        printf("         文件保存完成！按任意键继续");
        system(op);
        free(filename);
        filename = NULL;
        break;

    case 2:
        save_to_csv(filename);
        printf("         文件保存完成！按任意键继续");
        system(op);
        free(filename);
        filename = NULL;
        break;

    default:
        free(filename);
        filename = NULL;
        return;
    }
}

void show_menu_save()
{
    printf("         ******************************************\n");
    printf("         *                                        *\n");
    printf("         *                                        *\n");
    printf("         *           请选择导出类型               *\n");
    printf("         *                                        *\n");
    printf("         *           1：导出为txt文本             *\n");
    printf("         *           2：导出为csv表格             *\n");
    printf("         *           10：返回上一级               *\n");
    printf("         *                                        *\n");
    printf("         ******************************************\n");
    printf("\n");
    // printf("---------------------------------------------------------------------\n");
    printf("         请按键选择你的操作:");
}

void save_to_txt(char *filename)
{
    strcat(filename, ".txt");
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("\n");
        printf("         创建文件 %s 失败!\n\n", filename);
        return;
    }
    char *option = "%ld %s %d\n";
    write_file(fp, option);
}

void save_to_csv(char *filename)
{
    strcat(filename, ".csv");
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("\n");
        printf("         *创建文件 %s 失败!\n\n", filename);
        return;
    }
    char *option = "%ld,%s,%d\n";
    write_file(fp, option);
}

void write_file(FILE *fp, char *option)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, option, students[i].id, students[i].name, students[i].score);
    }
    fclose(fp);
}

#ifdef _WIN32
// 定义一个函数，用于实现密码隐式输入
int input_password(char password[])
{
    // 定义一个整数变量，用于记录密码长度
    int i = 0;
    // 定义一个字符变量，用于实现密码隐式输入
    char c;
    // 使用while循环，不断读取用户输入的字符
    while (1)
    {
        // 使用_getch()函数输入，字符不会显示在屏幕上
        c = _getch();
        // 如果遇到回车，表明密码输入结束
        if (c == '\r')
        {
            break; // 跳出while循环
        }
        else if (c == '\b')
        {                    // 如果遇到退格，需要删除前一个星号
            printf("\b \b"); // 退格，打一个空格，再退格，实质上是用空格覆盖掉星号
            --i;             // 密码长度减一
        }
        else
        {
            password[i++] = c; // 将字符放入数组
            printf("*");       // 在屏幕上打印一个星号
        }
    }
    // 返回密码长度
    return i;
}
#endif

#ifdef __APPLE__
// 定义一个函数，用于实现密码隐式输入
int input_password(char password[])
{
    // 定义一个整数变量，用于记录密码长度
    int i = 0;
    // 定义一个字符变量，用于实现密码隐式输入
    char c;
    // 初始化 curses 库
    initscr();
    // 设置不回显输入的字符
    noecho();
    // 设置非阻塞模式
    // nodelay(stdscr, TRUE); // 添加这一行
    printw("         请输入数据库密码:");
    // 使用while循环，不断读取用户输入的字符
    while (1)
    {
        // 使用 getch() 函数输入，字符不会显示在屏幕上
        c = getch();
        // 如果遇到回车，表明密码输入结束
        if (c == '\n')
        {
            password[i] = 0;
            break; // 跳出while循环
        }
        else if (c == '\b' || c == 127)
        {                    // 如果遇到退格或删除键，需要删除前一个星号
            printw("\b \b"); // 退格，打一个空格，再退格，实质上是用空格覆盖掉星号
            refresh();       // 刷新屏幕，添加这一行
            --i;             // 密码长度减一
        }
        else
        {
            password[i++] = c; // 将字符放入数组
            printw("*");       // 在屏幕上打印一个星号
            refresh();         // 刷新屏幕，添加这一行
        }
    }
    // 结束 curses 库
    endwin();
    // 返回密码长度
    return i;
}
#endif
