/*
Name    :   P5735.c
Time    :   2022/10/18 16:57:16
Author  :   Kasper Fan
Group   :   Weifang University
Contact :   fanwlx@foxmail.com
Desc    :   This file is created for learning C language Coding
*/

#include <stdio.h>
#include <math.h>

double zhouChang(double x[], double y[], double dis[]);

int main()
{
    double x[3], y[3], dis[3];
    
    for (int i = 0; i < 3; i++)
        scanf("%lf %lf", &x[i], &y[i]);
    printf("%.2lf\n", zhouChang(x, y, dis));
    return 0;
}

double zhouChang(double x[], double y[], double dis[])
{
    dis[0] = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2));
    dis[1] = sqrt(pow(x[2] - x[1], 2) + pow(y[2] - y[1], 2));
    dis[2] = sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2));
    return dis[0] + dis[1] + dis[2];
}