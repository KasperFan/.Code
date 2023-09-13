/*
Name    :   Try.c
Time    :   2022/11/08 16:04:45
Author  :   Kasper Fan
Group   :   Weifang University
Contact :   fanwlx@foxmail.com
Desc    :   This file is created for solve OJ problem
*/

// #include <stdio.h>
// #define ull unsigned long long

// // int main()
// // {
// //     int i=3;
// //     i=i++;
// //     printf("%d",i);
// //     return 0;
// // }


// ull jie (ull n){
//     if (n<=1) return 1;
//     else return n*jie(n-1);
// }

// int main(int argc, char const *argv[])
// {
//     printf("%llu\n",jie(22));
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     printf("Hello,World!\n");
//     return 0;
// }

// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>
// int main(int argc, char const *argv[])
// {
//     FILE *fp;
//     fp = fopen("try.txt", "r");
//     int n;
//     fscanf(fp, "%d", &n);
//     // scanf("%d", &n);
//     int num[n];
//     double ans[n];
//     for (int i = 0; i < n; i++)
//     {
//         fscanf(fp, "%d", &num[i]);
//         // scanf("%d", &num[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= num[i]; j++)
//         {
//             if (j*j*j==num[i])
//             {
//                 printf("%.3lf\n", (double)j);
//                 break;
//             }
//         }
        
//     }

//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     scanf("%d %d", &a, &b);
//     c = a + b;
//     printf("c=%d", c);
//     return 0;
// }

// #include <stdio.h>
// enum Sex
// {
//     Male,
//     Female,
//     Secret
// };
// int main()
// {
//     printf("%d\n", Female);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    char *str = (char *)malloc(sizeof(char) * 20);
    for (int i = 0; i < 10; i++)
    {
        str[i] = '0' + 1;
    }

    printf("%s\n", str);
    free(str);
    str = NULL;
    return 0;
}