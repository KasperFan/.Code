// 用到的全部头文件和定义的结构体
#include <stdio.h>   //常规
#include <string.h>  //字符串
#include <stdlib.h>  //链表相关
#include <math.h>    //数学函数相关
#include <windows.h> //清屏函数头文件
#include <time.h>    //调用并显示当前时间
#include <conio.h>   //隐藏密码输入函数getch()的头文件
#include <limits.h>  //无穷大或无穷小相关

#define Error -1; // 定义错误信息
#define MVNum 700 // 全中国大概有661座城市

typedef struct ENode
{                              // 定义边的结构体
    int v1, v2;                // 表示顶点（即城市所在的邻接表的位置的下标）
    char city1[10], city2[10]; // 顶点/城市的名称
    int mileage, cost, time;   // 边的权重:路程、费用、时间（单位为分钟）
} *edge;

typedef struct AdjVNode
{                            // 定义邻接点的结构体
    int adjv;                // 邻接点,表示所连接的城市的位置，也就是下标
    char CityName[10];       // 表示所连接的城市名称
    int mileage, cost, time; // 边的权重：路程、费用、时间
    struct AdjVNode *Next;   // 指向下一个邻接点的指针
} *adjoin;

typedef struct VNode
{                      // 定义顶点表头结点的结构体
    char CityName[10]; // 顶点数据，即为城市名称
    adjoin FirstEdge;  // 边的表头指针
} adjlist[MVNum];

typedef struct GNode
{               // 定义图的结构体
    int Nv, Ne; // 图的顶点数、边数
    adjlist G;  // 邻接表
} *graph;

typedef int DataType; // 定义数据类型，可改为其他

typedef struct Queue
{                       // 创建结构体
    DataType Data;      // 队列的元素/数据
    struct Queue *Next; // 尾指针
} *queue;

// 实现队列的头文件,队列元素为整型,链表实现
// 该头文件模仿C++中队列头文件的实现
// #include"HeaderFile.h"//引入头文件，其中已包含各个定义的结构体

queue CreateQ(); // 创建队列

DataType back(queue Q); // 返回队列中的最后一个元素

bool empty(queue Q); // 判断队列是否为空，如果队列空则返回真

DataType front(queue Q); // 返回队列的第一个元素

void pop(queue Q); // 删除队列中的第一个元素

void push(queue Q, DataType data); // 在队列末尾加入一个元素

int size(queue Q); // 返回队列中元素的个数

void show(queue Q); // 额外添加，将队列所有元素输出，测试用

//------下面是具体实现

queue CreateQ()
{                                                  // 创建队列
    queue Q = (queue)malloc(sizeof(struct Queue)); // 创建头节点/开辟空间
    Q->Next = NULL;                                // 头节点空置
    return Q;
}

DataType back(queue Q)
{ // 返回队列中的最后一个元素
    if (empty(Q))
        return Error; // 如果队列为空返回错误信息
    queue p = Q->Next;
    while (p->Next)
        p = p->Next; // 找到最后一个元素的位置
    return p->Data;  // 返回最后一个元素
}

bool empty(queue Q)
{ // 判断队列是否为空，如果队列空则返回真
    return Q->Next == NULL;
}

DataType front(queue Q)
{ // 返回队列的第一个元素
    if (empty(Q))
        return Error;     // 如果队列为空返回错误信息
    return Q->Next->Data; // 否则队列不为空直接返回第一个元素
}

void pop(queue Q)
{ // 删除队列中的第一个元素
    if (empty(Q))
        return;        // 如果队列为空直接退出
    queue p = Q->Next; // 删除第一个元素/结点
    Q->Next = p->Next;
    p->Next = NULL;
    free(p); // 将已删除的结点的空间释放
}

void push(queue Q, DataType data)
{                                                  // 在队列末尾加入一个元素
    queue p = (queue)malloc(sizeof(struct Queue)); // 创建结点
    p->Next = NULL;                                // 将准备插入的结点的尾指针指向空
    p->Data = data;                                // 存入数据
    if (Q->Next)
    { // 如果当前队列不为空
        queue q = Q->Next;
        while (q->Next)
            q = q->Next;
        q->Next = p; // 插入结点
    }
    else
        Q->Next = p; // 否则直接将要插入的结点作为第一个结点
}

int size(queue Q)
{                  // 返回队列中元素的个数
    int count = 0; // 开一个变量计数
    queue p = Q->Next;
    while (p)
        p = p->Next, count++; // 计数
    return count;             // 返回元素个数
}

void show(queue Q)
{ // 额外添加，将队列所有元素输出，测试用
    if (empty(Q))
    { // 如果队列为空直接退出
        printf("队列为空\n");
        return;
    }
    queue p = Q->Next; // 遍历输出
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

// 实现图的头文件，用邻接表实现
// #include"queue.h"//引入队列头文件，其中已包含头文件和结构体

// 定义/初始化一个图，如果文件中有路线也把路线插入图中
graph CreateG();

// 判断图是否为空
bool empty(graph G);

// 在图G中查找城市名称，如果不存在则返回错误信息ERROR，存在则返回该城市所在邻接表的下标位置
int Search_CityName(graph G, char city[]);

// 往图G中插入一条新的路线E
void Insert_Path(graph G, edge E);

// 将邻接表进行输出，测试用
void show(graph G);

// 将所有的路线进行输出
void Show_Path(graph G);

// 将图中的某条路线进行修改
void Modify_Path(graph G, edge E);

// 将图进行保存,格式为：城市1 城市2 路程 费用 时间
bool Save_File(graph G);

// 读取文件，将文件中的路线全部输进邻接表中
bool Read_File(graph G);

// 用该函数来递归查找P数组中的路径
void print_path(graph G, int i, int j);

// 用Folyd算法生成当前城市能到达的所有城市
void Floyd_path(graph G, char city[]);

// 用Folyd算法生成任意两个城市之间的费用最少的路线
void Floyd_Cost(graph G, char city1[], char city2[]);

// 用Folyd算法生成任意两个城市之间的路程最少的路线
void Floyd_Mileage(graph G, char city1[], char city2[]);

// 用Folyd算法生成任意两个城市之间的所用时间最少的路线
void Floyd_Time(graph G, char city1[], char city2[]);

// 用广度优先搜索算法搜索中转站最少的路线，需要用到队列
void Bfs(graph G, char city1[], char city2[]);

// 将v1到v2的中转站最少的路线打印出来
void Print_Path(graph G, int v1, int v2);

//----下面是具体实现的函数

// 定义/初始化一个图
graph CreateG()
{
    graph G = (graph)malloc(sizeof(struct GNode)); // 建立图/开辟空间
    G->Ne = 0;                                     // 初始边数为0
    G->Nv = 0;                                     // 初始的顶点/城市数目也为0
    for (int i = 0; i < MVNum; i++)                // 将图中的全部顶点的表头指针赋为空NULL
        G->G[i].FirstEdge = NULL;
    Read_File(G); // 将文件中的路线输入图中
    return G;     // 将图返回
}

// 判断图是否为空
bool empty(graph G)
{
    return G->Nv == 0;
}

// 在图G中查找城市名称，如果不存在则返回错误信息Error，存在则返回该城市所在邻接表的下标位置
int Search_CityName(graph G, char city[])
{
    if (empty(G))
        return Error;               // 如果当前图为空，则直接返回错误信息
    for (int i = 0; i < G->Nv; i++) // 否则进行查找
        if (strcmp(G->G[i].CityName, city) == 0)
            return i; // 找到了直接返回下标
    return Error;     // 没找到返回错误信息
}

// 往图G中插入一条新的路线
void Insert_Path(graph G, edge E)
{
    E->v1 = Search_CityName(G, E->city1); // 现在原先的邻接表中查找两城市的位置
    E->v2 = Search_CityName(G, E->city2);
    if (E->v1 == -1)
        E->v1 = G->Nv++; // 没找到就在图中加入新的点，同时图中的顶点数+1
    if (E->v2 == -1)
        E->v2 = G->Nv++;
    adjoin p = (adjoin)malloc(sizeof(struct AdjVNode)); // 开辟一个新的邻接点
    p->adjv = E->v2;
    p->cost = E->cost; // 给邻接点赋值：
    p->mileage = E->mileage;
    p->time = E->time;
    strcpy(p->CityName, E->city2);
    strcpy(G->G[E->v1].CityName, E->city1); // 将城市名称放入顶点数据
    adjoin s = G->G[E->v1].FirstEdge;       // 用尾插法将邻接点与邻接表进行连接
    if (s == NULL)
    {
        p->Next = G->G[E->v1].FirstEdge;
        G->G[E->v1].FirstEdge = p;
    }
    else
    {
        while (s->Next != NULL)
            s = s->Next;
        p->Next = s->Next;
        s->Next = p;
    }
    adjoin q = (adjoin)malloc(sizeof(struct AdjVNode)); // 无向边需要在边的两头都加入邻接点
    q->adjv = E->v1;
    q->cost = E->cost; // 给邻接点赋值
    q->mileage = E->mileage;
    q->time = E->time;
    strcpy(q->CityName, E->city1);
    strcpy(G->G[E->v2].CityName, E->city2); // 将城市名称放入顶点数据
    s = G->G[E->v2].FirstEdge;              // 用尾插法将邻接点与邻接表进行连接
    if (s == NULL)
    {
        q->Next = G->G[E->v2].FirstEdge;
        G->G[E->v2].FirstEdge = q;
    }
    else
    {
        while (s->Next != NULL)
            s = s->Next;
        q->Next = s->Next;
        s->Next = q;
    }
    G->Ne++; // 最后图的边的数目+1
}

// 将邻接表进行输出，测试用
void show(graph G)
{
    for (int i = 0; i < G->Nv; i++)
    {
        printf("%s 可以去的城市:", G->G[i].CityName);
        adjoin p = G->G[i].FirstEdge; // 将指针指向邻接表的该位置的表头结点的下一个结点
        while (p != NULL)
        {
            printf("%s（费用为：%d） ", p->CityName, p->cost);
            p = p->Next;
        }
        printf("\n\n");
    }
}

// 将图进行保存，格式为：城市1 城市2 路程 费用 时间
bool Save_File(graph G)
{
    bool vis[MVNum][MVNum] = {false};   // 开一个布尔类型的二维数组进行标记，防止重复输出相同的路线
    FILE *fpw = fopen("path.txt", "w"); // 以只写的形式打开文本文件
    // 若文件不存在则新建，否则，从起始位置开始写入文件，会覆盖文件原来的内容
    if (fpw == NULL)
        return false; // 如果打开文件失败则退出
    for (int i = 0; i < G->Nv; i++)
    {
        adjoin p = G->G[i].FirstEdge; // 将指针指向邻接表的该位置的表头结点的下一个结点
        while (p != NULL)
        {
            if (!vis[i][p->adjv] && !vis[p->adjv][i])
            {
                fprintf(fpw, "%s %s %d %d %d\n", G->G[i].CityName, p->CityName, p->mileage, p->cost, p->time);
                vis[i][p->adjv] = true;
                vis[p->adjv][i] = true;
            }
            p = p->Next;
        }
    }
    fclose(fpw); // 关闭文件指针
    return true;
}

// 读取文件，将文件中的路线全部输进图G中
bool Read_File(graph G)
{
    FILE *fpr = fopen("path.txt", "r");
    // 以只读的形式打开文本文件，不存在则退出
    edge E = (edge)malloc(sizeof(struct ENode)); // 给一条边开辟空间，用来进行读取输入
    if (fpr == NULL)
        return false; // 如果文件不存在或文件为空，则退出
    // 用while语句将所有的路线都插入图G中
    while (fscanf(fpr, "%s %s %d %d %d", E->city1, E->city2, &E->mileage, &E->cost, &E->time) != EOF)
        Insert_Path(G, E); // 直接将从文件中读出的路线插入图G中，并且不用保存
    fclose(fpr);           // 关闭文件指针
    return true;
}

// 将图G中的某条路线进行修改
void Modify_Path(graph G, edge E)
{
    E->v1 = Search_CityName(G, E->city1); // 现在原先的邻接表中查找两城市的位置
    E->v2 = Search_CityName(G, E->city2);
    if (E->v1 == -1 || E->v2 == -1)
    { // 如果有一个城市没有找到对应的邻接表中的位置，说明该路线不存在
        printf("该路线不存在！\n");
        return;
    }
    adjoin p = G->G[E->v1].FirstEdge; // 将城市1所在的邻接表的位置的表头指针赋给p
    while (p != NULL)
    {
        if (p->adjv == E->v2)
        {                      // 用指针p进行遍历查找城市2
            p->cost = E->cost; // 找到后进行数据修改
            p->mileage = E->mileage;
            p->time = E->time;
            break; // 找到了直接退出循环
        }
        p = p->Next; // 没找到继续找
    }
    p = G->G[E->v2].FirstEdge; // 将城市2所在的邻接表的位置的表头指针赋给p
    while (p != NULL)
    {
        if (p->adjv == E->v1)
        {                      // 用指针p进行遍历查找城市1
            p->cost = E->cost; // 找到后进行数据修改
            p->mileage = E->mileage;
            p->time = E->time;
            break; // 找到了直接退出循环
        }
        p = p->Next; // 没找到继续找
    }
    Save_File(G); // 将修改后的路线进行保存
}

// 将所有的路线进行输出
void Show_Path(graph G)
{
    system("cls");
    printf("-----------------------------------------------------路线总表-----------------------------------------------------------\n");
    printf("________________________________________________________________________________________________________________________\n");
    printf("|%10s\t\t|%10s\t\t|%10s\t\t|%10s\t\t|%10s\t\t|\n", "起点", "终点", "路程(千米)", "费用(元)", "时间(分)");
    printf("________________________________________________________________________________________________________________________\n");
    bool vis[MVNum][MVNum] = {false}; // 开一个布尔类型的二维数组进行标记，防止重复输出相同的路线
    for (int i = 0; i < G->Nv; i++)
    {
        adjoin p = G->G[i].FirstEdge; // 将指针指向邻接表的该位置的表头结点的下一个结点
        bool flag = false;            // 定义一个标记用于换行输出
        while (p != NULL)
        {
            if (!vis[i][p->adjv] && !vis[p->adjv][i])
            {
                // printf("%s到%s(反方向相同) 所需路程：%d 所需路费：%d 所需时间：%d", G->G[i].CityName, p->CityName, p->mileage, p->cost, p->time);
                printf("|%10s\t\t|%10s\t\t|%10d\t\t|%10d\t\t|%10d\t\t|", G->G[i].CityName, p->CityName, p->mileage, p->cost, p->time);
                vis[i][p->adjv] = true; // 将路线输出后进行标记
                vis[p->adjv][i] = true;
                flag = true;
            }
            p = p->Next;
            if (flag)
            { // 如果标记变为真，说明有了输出，进行换行
                printf("\n________________________________________________________________________________________________________________________\n");
                flag = false; // 重新标记为假
            }
        }
    }
}

// 用矩阵D来保存费用这个权值，用P来保存路径
// 开的空间比较大，要用用全局变量，否则在函数内部定义会造成堆栈溢出
long long D[MVNum][MVNum], P[MVNum][MVNum];

// 用Folyd算法生成当前城市能到达的所有城市
void Floyd_path(graph G, char city[])
{
    int v = -1;
    for (int i = 0; i < G->Nv; i++) // 对两个矩阵进行初始化
        if (strcmp(G->G[i].CityName, city) == 0)
        {
            v = i;
            break;
        }

    for (int i = 0; i < G->Nv; i++) // 对Path矩阵进行初始化
        for (int j = 0; j < G->Nv; j++)
        {
            P[i][j] = -1; //
        }
    // memset(P,-1,sizeof P);
    for (int i = 0; i < G->Nv; i++)
    {
        adjoin p = G->G[i].FirstEdge;
        while (p != NULL)
        {
            P[i][p->adjv] = 1;
            P[p->adjv][i] = 1;
            p = p->Next;
        }
    }

    for (int k = 0; k < G->Nv; k++) // floyd算法
        for (int i = 0; i < G->Nv; i++)
            for (int j = 0; j < G->Nv; j++)
                if (P[i][k] == 1 && P[k][j] == 1)
                {
                    P[i][j] = 1;
                }

    printf("%s 能够到达的所有城市:", G->G[v].CityName);
    for (int i = 0; i < G->Nv; i++)
    {
        if (P[v][i] == 1 && v != i)
            printf("%s ", G->G[i].CityName);
    }
    printf("\n\n");
}

// 用该函数来递归查找P数组中的路径
void print_path(graph G, int i, int j)
{
    int k = P[i][j]; // 找到上一个中转站/顶点（中转城市）
    if (k == -1)
        // 说明没有中转顶点，直接返回
        return;
    print_path(G, i, k); // 寻找i和k之间
    printf("%s->", G->G[k].CityName);
    print_path(G, k, j); // 寻找k和j之间
}

// 用Folyd算法生成任意两个城市之间的费用最少的路线
bool Floyd_Cost(graph G, int v1, int v2)
{
    for (int i = 0; i < G->Nv; i++) // 对两个矩阵进行初始化
        for (int j = 0; j < G->Nv; j++)
        {
            if (i == j)
                D[i][j] = 0; // 如果相同说明是同一点
            else
                D[i][j] = INT_MAX; // 否则先全部赋值为无穷大
            P[i][j] = -1;          // 一开始路径都没有
        }
    for (int i = 0; i < G->Nv; i++)
    { // 记录所有相邻城市之间的费用
        adjoin p = G->G[i].FirstEdge;
        while (p != NULL)
        {
            D[i][p->adjv] = p->cost; // 将边上的费用这个权值赋给数组D
            p = p->Next;
        }
    }
    for (int k = 0; k < G->Nv; k++) // floyd算法
        for (int i = 0; i < G->Nv; i++)
            for (int j = 0; j < G->Nv; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    // 因为路费不会是负数，所以不用加特判了
                    if (i != j)
                        P[i][j] = k;
                }
    if (D[v1][v2] >= INT_MAX)
        return false;
    // 如果最后的路线总费用大于等定义好的无穷大，那么说明路线不存在
    printf("从 %s 至 %s 花费最小的路线为:%s->", G->G[v1].CityName, G->G[v2].CityName, G->G[v1].CityName);
    print_path(G, v1, v2);
    printf("%s 共花费%d元\n\n", G->G[v2].CityName, D[v1][v2]);
    return true;
}

// 用Folyd算法生成任意两个城市之间的路程最少的路线
void Floyd_Mileage(graph G, int v1, int v2)
{
    for (int i = 0; i < G->Nv; i++) // 对两个矩阵进行初始化
        for (int j = 0; j < G->Nv; j++)
        {
            if (i == j)
                D[i][j] = 0; // 如果相同说明是同一点
            else
                D[i][j] = INT_MAX; // 否则先全部赋值为无穷大
            P[i][j] = -1;          // 一开始路径都没有
        }
    for (int i = 0; i < G->Nv; i++)
    { // 记录所有相邻城市之间的路程
        adjoin p = G->G[i].FirstEdge;
        while (p != NULL)
        {
            D[i][p->adjv] = p->mileage; // 将边上的费用这个权值赋给数组D
            p = p->Next;
        }
    }
    for (int k = 0; k < G->Nv; k++) // floyd算法
        for (int i = 0; i < G->Nv; i++)
            for (int j = 0; j < G->Nv; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    // 因为路程不会是负数，所以不用加特判了
                    if (i != j)
                        P[i][j] = k;
                }
    printf("从 %s 至 %s 路程最小的路线为:%s->", G->G[v1].CityName, G->G[v2].CityName, G->G[v1].CityName);
    print_path(G, v1, v2);
    printf("%s 共有%dkm的路程\n\n", G->G[v2].CityName, D[v1][v2]);
}

// 用Folyd算法生成任意两个城市之间的所用时间最少的路线
void Floyd_Time(graph G, int v1, int v2)
{
    for (int i = 0; i < G->Nv; i++) // 对两个矩阵进行初始化
        for (int j = 0; j < G->Nv; j++)
        {
            if (i == j)
                D[i][j] = 0; // 如果相同说明是同一点
            else
                D[i][j] = INT_MAX; // 否则先全部赋值为无穷大
            P[i][j] = -1;          // 一开始路径都没有
        }
    for (int i = 0; i < G->Nv; i++)
    { // 记录所有相邻城市之间的时间
        adjoin p = G->G[i].FirstEdge;
        while (p != NULL)
        {
            D[i][p->adjv] = p->time; // 将边上的费用这个权值赋给数组D
            p = p->Next;
        }
    }
    for (int k = 0; k < G->Nv; k++) // floyd算法
        for (int i = 0; i < G->Nv; i++)
            for (int j = 0; j < G->Nv; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    // 因为时间不会是负数，所以不用加特判了
                    if (i != j)
                        P[i][j] = k;
                }
    printf("从 %s 至 %s 所花时间最少的路线为:%s->", G->G[v1].CityName, G->G[v2].CityName, G->G[v1].CityName);
    print_path(G, v1, v2);
    printf("%s 共需时间%d分钟\n\n", G->G[v2].CityName, D[v1][v2]);
}

// 下面这三个数组用与Bfs也就是广搜，搜索中转站最少的路线
int d[MVNum] = {0}, p[MVNum] = {0};
bool vis[MVNum]; // 用vis数组标记已经遍历过的邻接点
// 用数组d来保存路线的长度,用数组P来保存广搜的路径

// 将v1到v2的中转站最少的路线打印出来,需要先执行Bfs函数
void Print_Path(graph G, int v1, int v2)
{
    if (v2 == v1)
        printf("%s", G->G[v1].CityName); // 递归结束标志
    // 刚进来时，v1肯定不等于v2，但是因为v1是起点，所以会递归到v1==v2时才会进行输出
    else if (p[v2] == -1)
        return;
    else
    {
        Print_Path(G, v1, p[v2]); // 这里进行递归，直到v1==v2
        printf("->%s", G->G[v2].CityName);
    }
}

// 用广度优先搜索算法搜索中转站最少的路线,需要用到队列
void Bfs(graph G, int v1, int v2)
{
    printf("从 %s 至 %s 中转站最少的路线为:", G->G[v1].CityName, G->G[v2].CityName);
    memset(vis, false, sizeof vis); // 将vis数组全部赋值为false
    memset(p, -1, sizeof p);        // 将数组p全部赋值为-1，表示没有初始路径
    queue q = CreateQ();            // 创建一个队列
    push(q, v1);                    // 入队
    vis[v1] = true;                 // 标记
    while (!empty(q))
    {                     // 当队列不为空时继续执行
        int v = front(q); // 将队头出列
        pop(q);           // 出队，队头出队后马上将队头删除
        adjoin t = G->G[v].FirstEdge;
        while (t != NULL)
        {
            if (!vis[t->adjv])
            {                          // 如果这个邻接点没有遍历过
                vis[t->adjv] = true;   // 进行标记
                p[t->adjv] = v;        // 记录父节点
                d[t->adjv] = d[v] + 1; // 中转站+1
                push(q, t->adjv);      // 入队
            }
            t = t->Next;
        }
    }
    Print_Path(G, v1, v2); // 将路径进行打印
    printf(" 中转站的个数为:%d \n\n", d[v2] - 1);
    // 输出中转站个数并进行换行，进行-1是因为d[v2]已经将v2也就是终点城市算进去了
}

// 这个头文件用来设计系统的界面
// #include"graph.h"//引入图的头文件

// 其实也可以直接定义一个管理员的结构体，但是因为已经实现了，就没管太多
char Ad_Name[15][20], ad_name[20];     // 存放管理员用户名称和输入管理员用户名称
char Ad_Number[15][20], ad_number[20]; // 用来存放管理员账号
char password[15][20], key[20];        // 用来存放管理员密码
int adsum = 0;                         // 使用一个变量来记录用户个数

void save_password(); // 保存管理员用户名、账号和密码

void hide_password(char *pswd, unsigned maxlen); // 隐藏密码进行输入

void Enter_Ad(); // 进入管理员界面，需要输入密码

void Welcome(); // 主菜单界面,无需密码进入

void Welcome_Print(); // 打印主菜单界面

void Welcome_Ad_Print(); // 打印管理员界面

void Welcome_Ad(graph G); // 进入管理员界面,需要进行登录

int Change_Password(); // 修改管理员密码

void Printflove(); // 打印爱心

void Goodbye(); // 结束程序

void Function_One(graph G); // 实现用户的功能1，查询城市路线

void Function_Three(graph G); // 实现用户的功能3

void Ad_Function_Two(graph G); // 实现用户/管理员的功能2,修改/更新路线

void Ad_Function_Three(graph G); // 实现管理员的功能3，添加新路线

void Ad_Function_Four(graph G); // 实现管理员的功能4，查询所有路线

void Ad_Function_Six(); // 实现管理员的功能6，注册管理员账号

void Ad_Function_Seven(); // 实现管理员功能7,查看管理员账号

void Ad_Functino_Eight(); // 实现管理员功能8,注销管理员账号

void Ad_Function_Nine(); // 实现管理员功能9,修改管理员用户名

// 将文件中存储的所有用户名和密码都读取进password和Ad_Name数组中
void Read_Ad_Password();

int Sreach_Adname(char adname[]); // 在数组Ad_name中找到用户名的位置

int Sreach_Adnumber(char adnumber[]); // 在数组Ad_Number中找到账号的位置

//-----下面是函数功能实现

void Welcome_Print()
{                  // 打印主菜单界面
    system("cls"); // 清屏
    time_t t;
    struct tm *p;
    time(&t);
    p = gmtime(&t);
    printf("\t\t\t\t**********************************************\n"); // 界面
    printf("\t\t\t\t**--------------%d年%02d月%02d日--------------**\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t\t**-----------------%02d时%02d分-----------------**\n", 8 + p->tm_hour, p->tm_min);
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**               欢迎进入！                 **\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**---------------用户功能菜单---------------**\n");
    printf("\t\t\t\t**       查询城市路线   ----------1         **\n");
    printf("\t\t\t\t**       查询所有路线   ----------2         **\n");
    printf("\t\t\t\t**       查询可到达城市 ----------3         **\n");
    printf("\t\t\t\t**       进入管理员界面 ----------4         **\n");
    printf("\t\t\t\t**       退出咨询系统   ----------0         **\n");
    printf("\t\t\t\t**********************************************\n");
}

void Welcome()
{ // 主菜单界面
    // 进入操作前先创建一个图，并将文件中的数据输进去
    graph G = CreateG();
    while (1)
    { // 操作需要可以持续进行，用一个死循环
        Welcome_Print();
        printf("请输入你所想查询信息的选项（数字）: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Function_One(G);
            break;
        case 2:
            Ad_Function_Four(G);
            break;
        case 3:
            Function_Three(G);
            break;
        case 4:
            Welcome_Ad(G);
            Welcome_Print();
            break;
        case 0:
            Goodbye();
            break;
        }
        printf("是否要继续进行操作？(是：1/否：0)\n");
        scanf("%d", &choice);
        if (choice == 0)
            Goodbye();
    }
}

void Welcome_Ad_Print()
{                  // 打印管理员界面
    system("cls"); // 清屏
    time_t t;
    struct tm *p;
    time(&t);
    p = gmtime(&t);
    printf("\t\t\t\t**********************************************\n"); // 界面
    printf("\t\t\t\t**--------------%d年%02d月%02d日--------------**\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t\t**-----------------%02d时%02d分-----------------**\n", 8 + p->tm_hour, p->tm_min);
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**               欢迎进入！                 **\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**-------------管理员功能菜单---------------**\n");
    printf("\t\t\t\t**       修改管理员密码 ----------1         **\n");
    printf("\t\t\t\t**       修改/更新路线  ----------2         **\n");
    printf("\t\t\t\t**       添加新路线     ----------3         **\n");
    printf("\t\t\t\t**       显示所有路线   ----------4         **\n");
    printf("\t\t\t\t**       退出管理员界面 ----------5         **\n");
    printf("\t\t\t\t**       注册管理员账号 ----------6         **\n");
    printf("\t\t\t\t**       查看管理员账号 ----------7         **\n");
    printf("\t\t\t\t**       注销管理员账号 ----------8         **\n");
    printf("\t\t\t\t**       修改用户名称   ----------9         **\n");
    printf("\t\t\t\t**       退出咨询系统   ----------0         **\n");
    printf("\t\t\t\t**********************************************\n");
}

void Welcome_Ad(graph G)
{                       // 进入管理员界面
    Read_Ad_Password(); // 先将文件中的管理员用户名和密码读取出来
    int choice;
    if (adsum == 0)
    {
        printf("当前系统没有管理员账号，是否进行注册？(是：1/否：0)\n");
        scanf("%d", &choice);
        if (choice == 1)
            Ad_Function_Six(); // 进行注册
        else
            return; // 否则退出管理员界面
    }
    Enter_Ad(); // 需要先进行登录
    while (1)
    {                       // 操作需要可以持续进行，用一个死循环
        Welcome_Ad_Print(); // 将管理员界面打印出来
        printf("请输入你想进行的操作（数字）: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Change_Password(); // 修改管理员的密码
            break;
        case 2:
            Ad_Function_Two(G); // 修改/更新路线
            break;
        case 3:
            Ad_Function_Three(G); // 加入新的路线
            break;
        case 4:
            Ad_Function_Four(G); // 查询所有路线
            break;
        case 5:
            return; // 要退出管理员界面，直接退出这个函数即可
            break;
        case 6:
            Ad_Function_Six(); // 注册管理员账号
            break;
        case 7:
            Ad_Function_Seven(); // 查看管理员账号
            break;
        case 8:
            Ad_Functino_Eight(); // 注销管理员账号
            break;
        case 9:
            Ad_Function_Nine(); // 修改管理员用户名
            break;
        case 0:
            Goodbye(); // 退出系统（直接结束整个程序）
            break;
        }
        printf("是否要继续进行操作？(是：1/否：0)\n");
        scanf("%d", &choice);
        if (choice == 0)
            Goodbye();
    }
}

// 进入管理员界面，需要输入密码
void Enter_Ad()
{
    system("cls"); // 清屏
    time_t t;
    struct tm *p;
    time(&t);
    p = gmtime(&t);
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**--------------%d年%02d月%02d日--------------**\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t\t****************当前时间%02d时%02d分%***************\n", 8 + p->tm_hour, p->tm_min);
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**               交通咨询系统               **\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t**     感谢使用本系统，希望您使用愉快！     **\n");
    printf("\t\t\t\t**********************************************\n");
    printf("进入管理员界面需要进行登录\n");
    int i, j;
    while (1)
    {
        printf("请输入管理员用户名或者账号：\n");
        scanf("%s", ad_number);
        i = Sreach_Adname(ad_number);
        j = Sreach_Adnumber(ad_number);
        if (i == -1 && j == -1)
            printf("不存在该用户名或账号！请重新输入!\n");
        else
        {
            if (i == -1)
                i = j;
            break;
        }
    }
    int sum = 0; // 开一个变量来记录输错密码的次数，错误此时超过5次关闭系统
    while (1)
    {
        printf("请输入管理员密码：\n");
        hide_password(key, 21);
        printf("\n");
        if (strcmp(key, password[i]) != 0)
        {
            sum++;
            if (sum >= 5)
            {
                printf("多次输入密码错误！系统关闭！\n");
                sum = 0;
                exit(0);
            }
            else
            {
                printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum);
            }
        }
        else
        {
            printf("登陆成功！\n");
            break;
        }
    }
    system("pause");
}

// 将修改后的账号密码保存
void save_password()
{
    FILE *fp = fopen("adname_password.txt", "w+"); // 打开管理员文件
    // “w+”：首先建立一个新文件，进行写操作，然后从头开始写(若文件存在，原内容将全部消失)
    for (int i = 0; i < adsum; i++)
        fprintf(fp, "%s %s %s\n", Ad_Name[i], Ad_Number[i], password[i]);
    // 将数组中的所有管理员用户名、账号和密码写入文件中
    fclose(fp); // 关闭文件
}

void hide_password(char *pswd, unsigned maxlen)
{ // 隐藏密码进行输入
    int index = 0;
    char buff = '\0';
    while ((buff = getch()) != '\r')
    {
        if (buff == '\b' && index != 0)
        {
            index--;
            printf("\b \b");
        }
        else if (index < maxlen - 1 && buff != '\b')
        {
            pswd[index++] = buff;
            putchar('*');
        }
    }
    pswd[index] = '\0';
}

int Change_Password()
{ // 修改密码
    int i;
    while (1)
    {
        printf("请输入要修改密码的管理员用户名:\n");
        scanf("%s", ad_name);
        i = Sreach_Adname(ad_name);
        if (i == -1)
            printf("不存在该管理员！请重新输入!\n");
        else
            break;
    }
    printf("请输入原来的密码：\n");
    while (1)
    {
        hide_password(key, 21); // 隐藏密码输入
        printf("\n");
        if (strcmp(key, password[i]) != 0)
        {
            printf("密码错误！\n");
        }
        else
            break;
    }
    printf("请输入想要更改的管理员密码：\n");
    hide_password(password[i], 21); // 隐藏密码输入
    save_password();                // 重新保存文件
    printf("\n修改成功！\n");
    return 0;
}

void Printflove()
{ // 打印爱心
    float a, x, y;
    for (y = 1.5f; y > -1.5f; y -= 0.1f)
    {
        for (x = -1.5f; x < 1.5f; x += 0.05f)
        {
            a = x * x + y * y - 1;
            char ch = a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ';
            putchar(ch);
        }
        printf("\n");
        printf("\t\t\t  ");
    }
}

void Goodbye()
{ // 结束程序
    system("cls");
    Printflove();
    printf("\t**********************************************\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**        欢迎下次使用！~再见！~~           **\n");
    printf("\t\t\t\t**                                          **\n");
    printf("\t\t\t\t**********************************************\n");
    exit(0);
}

void Function_One(graph G)
{                              // 实现用户的功能1，查询城市路线
    char city1[10], city2[10]; // 开两个数组输入两个城市名称
    printf("请输入两个城市的名称（起点和终点）：\n");
    scanf("%s%s", city1, city2);
    int v1 = Search_CityName(G, city1); // 现在原先的邻接表中查找两城市的位置
    int v2 = Search_CityName(G, city2);
    if (v1 == -1 || v2 == -1)
    { // 防止重复输出没有路线的信息，在查询之前就先进行判断
        // 如果两个城市中有一个或两个没找到在邻接表中的位置，说明该路线不存在
        printf("抱歉！暂时没有%s到达%s的路线！\n", city1, city2);
        return;
    }
    if (v1 == v2)
    {
        printf("您已经在该城市中，无需查找路线！\n");
        return;
    }
    // 直接调用已经写好的函数
    if (!Floyd_Cost(G, v1, v2)) // 费用最少
        printf("抱歉！暂时没有%s到达%s的路线！\n", city1, city2);
    else
    {
        Floyd_Mileage(G, v1, v2); // 路程最少
        Floyd_Time(G, v1, v2);    // 时间最少
        Bfs(G, v1, v2);           // 中转站最少
    }
}

// 实现用户的功能3，查询当前城市可以到达的城市
void Function_Three(graph G)
{
    char city[10];
    printf("请输入当前城市：\n");
    scanf("%s", city);
    int v = Search_CityName(G, city);
    if (v == -1)
    {
        printf("抱歉！暂时不存在该城市!\n");
        return;
    }
    Floyd_path(G, city);
}

// 实现管理员的功能2，修改/更新路线
void Ad_Function_Two(graph G)
{
    printf("请输入更新之后的路线：\n");
    printf("格式为：城市1 城市2 路程 费用 时间\n");
    edge E = (edge)malloc(sizeof(struct ENode));
    scanf("%s%s%d%d%d", E->city1, E->city2, &E->mileage, &E->cost, &E->time);
    E->v1 = Search_CityName(G, E->city1); // 现在原先的邻接表中查找两城市的位置
    E->v2 = Search_CityName(G, E->city2);
    if (E->v1 == -1 || E->v2 == -1)
    { // 如果有一个城市没有找到对应的邻接表中的位置，说明该路线不存在
        printf("该路线不存在！\n");
        return;
    }
    else
    {
        Modify_Path(G, E);
        printf("修改成功！\n");
    }
}

// 实现管理员的功能3，添加新路线
void Ad_Function_Three(graph G)
{
    printf("请输入新的路线：\n");
    printf("格式为：城市1 城市2 路程 费用 时间\n");
    edge E = (edge)malloc(sizeof(struct ENode));
    scanf("%s%s%d%d%d", E->city1, E->city2, &E->mileage, &E->cost, &E->time);
    Insert_Path(G, E);
    printf("添加路线成功！\n");
    Save_File(G); // 输入新的路线之后进行保存
}

// 实现管理员的功能4，查询所有路线
void Ad_Function_Four(graph G)
{
    Show_Path(G);
}

// 将文件中存储的所有用户名和密码都读取进password和Ad_Name数组中
void Read_Ad_Password()
{
    FILE *fpr = fopen("adname_password.txt", "r"); // 打开文件，如果文件不存在会自动创建文件
    int i = 0;
    adsum = 0; // 先将管理员人数清零，因为是重新将所有管理员再输入数组
    // 不清零会导致重复进入管理员界面的时会显示的人数超过10人
    if (fpr == NULL)
        return;
    while (fscanf(fpr, "%s %s %s", ad_name, ad_number, key) != EOF)
    {
        strcpy(Ad_Name[i], ad_name); // 将文件中的用户名、账号密码都写入数组中
        strcpy(Ad_Number[i], ad_number);
        strcpy(password[i++], key);
        adsum++; // 管理员用户个数++
    }
    fclose(fpr); // 关闭文件指针
}

// 实现管理员的功能6，注册管理员账号
void Ad_Function_Six()
{
    if (adsum >= 10)
    { // 如果当前管理员账号有10个，则不允许再添加管理员账号
        printf("管理员账号已满！无法再进行注册！\n");
    }
    else
    {
        while (1)
        {
            printf("请输入新的管理员用户名：\n");
            scanf("%s", ad_name);
            int i = Sreach_Adname(ad_name);
            if (i == -1)
            {
                strcpy(Ad_Name[adsum], ad_name);
                break;
            }
            else
                printf("该用户名已存在！请重新输入！\n");
        }
        while (1)
        {
            printf("请输入对应的管理员账号：\n");
            scanf("%s", ad_number);
            int i = Sreach_Adnumber(ad_number);
            if (i == -1)
            {
                strcpy(Ad_Number[adsum], ad_number);
                break;
            }
            else
                printf("该账号已存在！请重新输入！\n");
        }
        printf("请输入对应的管理员密码：\n");
        hide_password(key, 21); // 隐藏密码输入
        strcpy(password[adsum++], key);
        save_password(); // 将新注册的管理员账号进行保存，保存进文件中
        printf("\n注册成功！\n");
    }
    system("pause"); // 请按任意键继续
}

// 实现管理员功能7,查看管理员账号
void Ad_Function_Seven()
{
    system("cls");
    printf("-------------------------------管理员名单-------------------------------\n");
    printf("________________________________________________________________________\n");
    printf("|%10s\t\t|%10s\t\t|%10s\t\t|\n", "管理员用户名", "管理员账号", "管理员密码");
    printf("________________________________________________________________________\n");
    for (int i = 0; i < adsum; i++)
    {
        printf("|%10s\t\t|%10s\t\t|%10s\t\t|\n", Ad_Name[i], Ad_Number[i], password[i]);
        printf("________________________________________________________________________\n");
    }
    printf("当前管理员人数为：%d人\n", adsum);
}

// 实现管理员功能8,注销管理员账号
void Ad_Functino_Eight()
{
    printf("请输入想要注销的管理员用户名：\n");
    scanf("%s", ad_name);
    int i = Sreach_Adname(ad_name), choice;
    if (i == -1)
        printf("不存在该管理员用户名！\n");
    else
    {
        while (1)
        {
            printf("请输入对应的管理员密码：\n");
            hide_password(key, 21); // 隐藏密码输入
            if (strcmp(key, password[i]) != 0)
                printf("\n密码错误！\n");
            else
                break;
        }
        printf("\n请再次确认是否注销该管理员账号？(是：1/否：0)\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            for (int j = i; j < adsum - 1; j++)
            {
                strcpy(Ad_Name[j], Ad_Name[j + 1]);     // 将用户名前移
                strcpy(password[j], password[j + 1]);   // 将密码前移
                strcpy(Ad_Number[j], Ad_Number[j + 1]); // 将账号前移
            }
            adsum--;
            save_password(); // 保存新的数组
            printf("管理员账号注销成功！\n");
        }
        else
            return;
    }
}

// 实现管理员功能9,修改管理员用户名
void Ad_Function_Nine()
{
    printf("请输入要修改的管理员用户名：");
    scanf("%s", ad_name);
    int i = Sreach_Adname(ad_name);
    if (i == -1)
        printf("不存在该管理员用户名!");
    else
    {
        printf("请输入修改之后的管理员用户名：");
        scanf("%s", ad_name);
        strcpy(Ad_Name[i], ad_name);
        save_password(); // 将修改后的结果进行保存
        printf("修改用户名成功！\n");
    }
    // system("pause");//请按任意键继续
}

// 在数组Ad_Name中找到用户名的位置
int Sreach_Adname(char adname[])
{
    for (int i = 0; i < adsum; i++)
        if (strcmp(adname, Ad_Name[i]) == 0)
            return i; // 找到了直接返回该用户名的下标位置
    return Error;     // 没找到返回错误信息
}

// 在数组Ad_Number中找到账号的位置
int Sreach_Adnumber(char adnumber[])
{
    for (int i = 0; i < adsum; i++)
        if (strcmp(Ad_Number[i], adnumber) == 0)
            return i;
    return Error;
}

// 引入界面头文件，里面已经包含了图的实现
// #include"interface.h"

int main()
{

    Welcome();

    return 0;
}
