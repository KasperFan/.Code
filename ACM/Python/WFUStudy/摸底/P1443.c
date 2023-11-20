/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-06 08:35:49
 * @LastEditTime: 2023-11-06 13:55:45
 * @FilePath: /Python/WFUStudy/摸底/P1443.c
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool; // 手搓一个布尔类型

typedef struct Node
{
    int x;             // 存储x坐标
    int y;             // 存储y坐标
    struct Node *next; // 存储队列中下一个节点(坐标点)的地址
} Node;
typedef Node Queue; // 将其起别名为队列类型

Queue *head = NULL, *tail = NULL; // 队列头尾节点地址
int queue_size = 0;               // 队列内元素数量

bool is_empty();
Queue *pop();
void append(int x, int y);

void bfs();

int n, m, x, y, step;
int map[410][410], is_visited[410][410];
int dx[] = {-2, -2, -1, +1, +2, +2, +1, -1};
int dy[] = {-1, +1, +2, +2, +1, -1, -2, -2};

int main()
{
    memset(map, -1, sizeof(map)); // 初始化，将所有点置为-1（后期遍历不到的就为-1）
    scanf("%d %d %d %d", &n, &m, &x, &y);
    append(x, y);
    is_visited[x][y] = true;
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%-5d ", map[i][j]);
        printf("\n");
    }
    return 0;
}

// 函数:判断队列是否为空
bool is_empty()
{
    // 如果队列内无元素则为真
    return queue_size == 0;
}

// 函数:弹出队首坐标点并返回
Queue *pop()
{
    Node *temp = head; // 取出头节点
    head = head->next; // 头节点指针往后移
    temp->next = NULL; // 切断取出节点与队列中表的联系
    queue_size--;      // 队列元素数量-1
    return temp;       // 将取出的点作为函数返回值返回给调用语句
}

// 函数:往队尾添加新坐标点
void append(int x, int y)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // 创建一张新表
    // 当前新表的下一节点一定为空，将其指针域置空防止野指针
    temp->next = NULL;
    // 将坐标点写入新表
    temp->x = x;
    temp->y = y;
    if (is_empty())         // 如果队列为空
        head = tail = temp; // 头尾都指向新的节点
    else                    // 否则
    {
        tail->next = temp; // 将新表插到队尾的下一处
        tail = tail->next; // 将队尾指针指向新的队尾
    }
    queue_size++; // 队列元素量计数+1
}

// 函数:广度搜索优先算法
void bfs()
{
    while (!is_empty()) // 当队列不为空时
    {
        int size = queue_size; // 记录队列中某一阶段的点的数量
        while (size--)         // 对某一阶段点重复操作
        {
            Node *temp = pop(); // 取出队首
            // 记录当前坐标点信息
            int nodex = temp->x;
            int nodey = temp->y;
            map[nodex][nodey] = step;        // 将对应的步数赋给当前点
            free(temp);                      // 由于不再用到这块表的内存，故释放掉
            temp = NULL;                     // 防止野指针
            is_visited[nodex][nodey] = true; // 将当前节点记为已访问
            for (int i = 0; i < 8; i++)      // 遍历8个方向
            {
                /*
                 * 遍历新点坐标，如果满足条件（边界判断、访问标记）
                 * 则将其置入队列作为下一阶段的点
                 */
                int nx = nodex + dx[i];
                int ny = nodey + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;
                if (!is_visited[nx][ny])
                {
                    is_visited[nx][ny] = true;
                    append(nx, ny);
                }
            }
        }
        step++; // 当前阶段所有点都遍历完后，将步数+1，准备遍历下一阶段所有点
    }
}
