#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个学生结构体
typedef struct Student
{
    int num;       // 学号
    char name[20]; // 姓名
    double elec;   // 选修课成绩
    double expe;   // 实验课成绩
    double requ;   // 必修课成绩
    double sum;    // 总成绩
} Student;

// 定义一个链表节点结构体
typedef struct Node
{
    Student stu;       // 学生信息
    struct Node *next; // 指向下一个节点的指针
} Node;

// 定义一个链表结构体
typedef struct List
{
    Node *head; // 指向链表头节点的指针
    int size;   // 链表的长度
} List;

// 初始化一个空链表
void initList(List *list)
{
    list->head = NULL;
    list->size = 0;
}

// 创建一个新的节点
Node *newNode(Student stu)
{
    Node *node = (Node *)malloc(sizeof(Node)); // 分配内存空间
    node->stu = stu;                           // 赋值学生信息
    node->next = NULL;                         // 指针置空
    return node;                               // 返回节点指针
}

// 释放一个节点的内存
void freeNode(Node *node)
{
    free(node); // 释放内存空间
}

// 在链表尾部插入一个节点
void insertNode(List *list, Node *node)
{
    if (list->head == NULL)
    {                      // 如果链表为空
        list->head = node; // 直接将节点作为头节点
    }
    else
    {                         // 如果链表不为空
        Node *p = list->head; // 定义一个指针指向头节点
        while (p->next != NULL)
        { // 遍历链表，找到尾节点
            p = p->next;
        }
        p->next = node; // 将节点插入到尾节点后面
    }
    list->size++; // 链表长度加一
}

// 根据学号查找一个节点，返回节点指针，如果没有找到，返回NULL
Node *findNodeByNum(List *list, int num)
{
    Node *p = list->head; // 定义一个指针指向头节点
    while (p != NULL)
    { // 遍历链表
        if (p->stu.num == num)
        {             // 如果学号匹配
            return p; // 返回节点指针
        }
        p = p->next; // 指针后移
    }
    return NULL; // 没有找到，返回NULL
}

// 根据姓名查找一个节点，返回节点指针，如果没有找到，返回NULL
Node *findNodeByName(List *list, char *name)
{
    Node *p = list->head; // 定义一个指针指向头节点
    while (p != NULL)
    { // 遍历链表
        if (strcmp(p->stu.name, name) == 0)
        {             // 如果姓名匹配
            return p; // 返回节点指针
        }
        p = p->next; // 指针后移
    }
    return NULL; // 没有找到，返回NULL
}

// 删除一个节点，返回被删除的节点指针，如果没有找到，返回NULL
Node *deleteNode(List *list, Node *node)
{
    if (list->head == NULL)
    {                // 如果链表为空
        return NULL; // 返回NULL
    }
    if (list->head == node)
    {                            // 如果要删除的节点是头节点
        list->head = node->next; // 将头节点指向下一个节点
        list->size--;            // 链表长度减一
        return node;             // 返回被删除的节点指针
    }
    Node *p = list->head; // 定义一个指针指向头节点
    while (p->next != NULL)
    { // 遍历链表，找到要删除的节点的前一个节点
        if (p->next == node)
        {                         // 如果找到
            p->next = node->next; // 将前一个节点的指针指向要删除的节点的下一个节点
            list->size--;         // 链表长度减一
            return node;          // 返回被删除的节点指针
        }
        p = p->next; // 指针后移
    }
    return NULL; // 没有找到，返回NULL
}

// 修改一个节点的学生信息，返回修改后的节点指针，如果没有找到，返回NULL
Node *modifyNode(List *list, Node *node, Student stu)
{
    Node *p = findNodeByNum(list, node->stu.num); // 根据学号查找节点
    if (p != NULL)
    {                 // 如果找到
        p->stu = stu; // 修改学生信息
        return p;     // 返回修改后的节点指针
    }
    return NULL; // 没有找到，返回NULL
}

// 计算一个节点的学生的总成绩，根据不同专业的权重设置
double calcSum(Node *node, char *major)
{
    double sum = 0; // 初始化总成绩为0
    if (strcmp(major, "计算机") == 0)
    {                                                                             // 如果专业是计算机
        sum = node->stu.elec * 0.3 + node->stu.expe * 0.4 + node->stu.requ * 0.3; // 选修课占30%，实验课占40%，必修课占30%
    }
    else if (strcmp(major, "数学") == 0)
    {                                                                             // 如果专业是数学
        sum = node->stu.elec * 0.2 + node->stu.expe * 0.2 + node->stu.requ * 0.6; // 选修课占20%，实验课占20%，必修课占60%
    }
    else if (strcmp(major, "英语") == 0)
    {                                                                             // 如果专业是英语
        sum = node->stu.elec * 0.4 + node->stu.expe * 0.2 + node->stu.requ * 0.4; // 选修课占40%，实验课占20%，必修课占40%
    }
    else
    {                                                                             // 其他专业
        sum = node->stu.elec * 0.3 + node->stu.expe * 0.3 + node->stu.requ * 0.4; // 选修课占30%，实验课占30%，必修课占40%
    }
    return sum; // 返回总成绩
}

// 对链表中的节点按照总成绩进行降序排序，使用冒泡排序算法
void sortList(List *list, char *major)
{
    if (list->head == NULL || list->head->next == NULL)
    {           // 如果链表为空或只有一个节点
        return; // 直接返回
    }
    Node *p, *q, *r; // 定义三个指针
    for (p = list->head; p->next != NULL; p = p->next)
    { // 外层循环，从头节点开始
        for (q = list->head, r = q->next; r != NULL; q = r, r = r->next)
        { // 内层循环，从头节点和下一个节点开始
            if (calcSum(q, major) < calcSum(r, major))
            { // 如果前一个节点的总成绩小于后一个节点的总成绩
                // 交换两个节点的学生信息
                Student temp = q->stu;
                q->stu = r->stu;
                r->stu = temp;
            }
        }
    }
}

// 打印链表中的所有节点的学生信息
void printList(List *list)
{
    if (list->head == NULL)
    { // 如果链表为空
        printf("链表为空，没有学生信息。\n");
        return; // 直接返回
    }
    Node *p = list->head;                                   // 定义一个指针指向头节点
    printf("学号\t姓名\t选修课\t实验课\t必修课\t总成绩\n"); // 打印表头
    while (p != NULL)
    { // 遍历链表
        // 打印每个节点的学生信息
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", p->stu.num, p->stu.name, p->stu.elec, p->stu.expe, p->stu.requ, p->stu.sum);
        p = p->next; // 指针后移
    }
}

// 释放链表中的所有节点的内存
void freeList(List *list)
{
    Node *p = list->head; // 定义一个指针指向头节点
    while (p != NULL)
    {                      // 遍历链表
        Node *q = p->next; // 保存下一个节点的指针
        freeNode(p);       // 释放当前节点的内存
        p = q;             // 指针后移
    }
    list->head = NULL; // 头节点置空
    list->size = 0;    // 链表长度置零
}

// 定义一个菜单函数，显示系统的功能选项
void menu()
{
    printf("欢迎使用学生成绩管理系统！\n");
    printf("请选择你要进行的操作：\n");
    printf("1. 添加学生信息\n");
    printf("2. 删除学生信息\n");
    printf("3. 修改学生信息\n");
    printf("4. 查询学生信息\n");
    printf("5. 排序学生信息\n");
    printf("6. 打印学生信息\n");
    printf("7. 退出系统\n");
}

// 定义一个主函数，实现系统的主要逻辑
int main()
{
    List list;       // 定义一个链表
    initList(&list); // 初始化链表
    char major[20];  // 定义一个字符串存储专业名称
    printf("请输入你的专业名称：\n");
    scanf("%s", major); // 输入专业名称
    int choice;         // 定义一个整型变量存储用户的选择
    do
    {
        menu();               // 显示菜单
        scanf("%d", &choice); // 输入选择
        switch (choice)
        {       // 根据选择执行不同的操作
        case 1: // 添加学生信息
        {
            Student stu; // 定义一个学生结构体变量
            printf("请输入学生的学号、姓名、选修课成绩、实验课成绩、必修课成绩，用空格隔开：\n");
            scanf("%d %s %lf %lf %lf", &stu.num, stu.name, &stu.elec, &stu.expe, &stu.requ); // 输入学生信息
            stu.sum = calcSum(newNode(stu), major);                                          // 计算总成绩
            insertNode(&list, newNode(stu));                                                 // 插入节点
            printf("添加成功！\n");
        }
        break;
        case 2: // 删除学生信息
        {
            int num; // 定义一个整型变量存储学号
            printf("请输入要删除的学生的学号：\n");
            scanf("%d", &num);                      // 输入学号
            Node *node = findNodeByNum(&list, num); // 查找节点
            if (node == NULL)
            { // 如果没有找到
                printf("没有找到该学生的信息！\n");
            }
            else
            {                            // 如果找到
                deleteNode(&list, node); // 删除节点
                printf("删除成功！\n");
            }
        }
        break;
        case 3: // 修改学生信息
        {
            int num; // 定义一个整型变量存储学号
            printf("请输入要修改的学生的学号：\n");
            scanf("%d", &num);                      // 输入学号
            Node *node = findNodeByNum(&list, num); // 查找节点
            if (node == NULL)
            { // 如果没有找到
                printf("没有找到该学生的信息！\n");
            }
            else
            {                // 如果找到
                Student stu; // 定义一个学生结构体变量
                printf("请输入学生的新的学号、姓名、选修课成绩、实验课成绩、必修课成绩，用空格隔开：\n");
                scanf("%d %s %lf %lf %lf", &stu.num, stu.name, &stu.elec, &stu.expe, &stu.requ); // 输入学生信息
                stu.sum = calcSum(newNode(stu), major);                                          // 计算总成绩
                modifyNode(&list, node, stu);                                                    // 修改节点
                printf("修改成功！\n");
            }
        }
        break;
        case 4: // 查询学生信息
        {
            int option; // 定义一个整型变量存储查询方式
            printf("请选择你要查询的方式：\n");
            printf("1. 根据学号查询\n");
            printf("2. 根据姓名查询\n");
            scanf("%d", &option); // 输入查询方式
            if (option == 1)
            {            // 根据学号查询
                int num; // 定义一个整型变量存储学号
                printf("请输入要查询的学生的学号：\n");
                scanf("%d", &num);                      // 输入学号
                Node *node = findNodeByNum(&list, num); // 查找节点
                if (node == NULL)
                { // 如果没有找到
                    printf("没有找到该学生的信息！\n");
                }
                else
                { // 如果找到
                    // 打印学生信息
                    printf("学号\t姓名\t选修课\t实验课\t必修课\t总成绩\n");
                    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", node->stu.num, node->stu.name, node->stu.elec, node->stu.expe, node->stu.requ, node->stu.sum);
                }
            }
            else if (option == 2)
            {                  // 根据姓名查询
                char name[20]; // 定义一个字符串存储姓名
                printf("请输入要查询的学生的姓名：\n");
                scanf("%s", name);                        // 输入姓名
                Node *node = findNodeByName(&list, name); // 查找节点
                if (node == NULL)
                { // 如果没有找到
                    printf("没有找到该学生的信息！\n");
                }
                else
                { // 如果找到
                    // 打印学生信息
                    printf("学号\t姓名\t选修课\t实验课\t必修课\t总成绩\n");
                    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", node->stu.num, node->stu.name, node->stu.elec, node->stu.expe, node->stu.requ, node->stu.sum);
                }
            }
            else
            { // 其他方式
                printf("无效的选择！\n");
            }
        }
        break;
        case 5: // 排序学生信息
        {
            sortList(&list, major); // 对链表进行排序
            printf("排序成功！\n");
        }
        break;
        case 6: // 打印学生信息
        {
            printList(&list); // 打印链表
        }
        break;
        case 7: // 退出系统
        {
            printf("感谢使用学生成绩管理系统！\n");
            freeList(&list); // 释放链表
            return 0;        // 退出程序
        }
        break;
        default: // 其他选择
        {
            printf("无效的选择！\n");
        }
        break;
        }
    } while (choice != 7); // 循环直到选择退出系统
}
