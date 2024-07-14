/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-12-06 14:29:04
 * @LastEditTime: 2023-12-06 16:41:30
 * @FilePath: /Python/WFUStudy/11-25大一测试/P2895_Meteor_Shower_S.cpp
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <stdio.h>
#include <string.h>

typedef struct point
{
    int x, y;
} Point;

Point queue[90010];

int map[350][350],
    is_visited[350][350],
    head, tail,
    M, X, Y, T,
    nx, ny,
    dx[5] = {-1, +1, 0, 0, 0},
    dy[5] = {0, 0, -1, +1, 0};

int bfs();

int main()
{
    freopen("./P2895_14.in", "r", stdin);
    freopen("./out.out", "w+", stdout);
    memset(map, -1, sizeof(map));
    scanf("%d\n", &M);
    while (M--)
    {
        scanf("%d %d %d\n", &X, &Y, &T);
        for (int i = 0; i < 5; i++)
        {
            nx = X + dx[i], ny = Y + dy[i];
            if (nx < 0 || ny < 0) continue;
            map[nx][ny] = (map[nx][ny] == -1 || map [nx][ny] > T) ? T : map[nx][ny];
        }
    }
    printf("%d\n", bfs());
    return 0;
}

int bfs() {
    int step = 0, size;
    is_visited[0][0] = 1;
    queue[tail].x = 0, queue[tail++].y = 0;
    while (tail - head > 0)
    {
        size = tail - head;
        for (int _ = 0; _ < size; _++)
        {
            int nodex = queue[head].x, nodey = queue[head++].y;
            if (map[nodex][nodey] == -1) return step;
            else if (map[nodex][nodey] <= step) continue;
            for (int i = 0; i < 4; i++)
            {
                nx = nodex + dx[i], ny = nodey + dy[i];
                if (nx < 0 || ny < 0) continue;
                if (!is_visited[nx][ny]) {
                    is_visited[nx][ny] = 1;
                    queue[tail].x = nx, queue[tail++].y = ny;
                }
            }
        }
        step++;
    }
    return -1;
}
