#include <stdio.h>

// int main()
// {
//     int hour1, minute1; // 时刻1的小时和分钟
//     int hour2, minute2; // 时刻2的小时和分钟

//     scanf("%d %d", &hour1, &minute1); // 输入时刻1
//     scanf("%d %d", &hour2, &minute2); // 输入时刻2

//     int t1 = hour1 * 60 + minute1; // 将时刻1中的小时转换为分钟
//     int t2 = hour2 * 60 + minute2; // 将时刻2中的小时转换为分钟

//     int t = t2 - t1;
//     /*
//         时刻2的分钟数 - 时刻1的分钟数 = 从时刻1开始到时刻2经过的分钟（时间差）
//         由输入：
//         3 20 => hour1, minute1
//         2 20 => hour2, minute2
//         应为 t1 - t2
//      */

//     printf("时间差是%d小时%d分。", t / 60, t % 60);
//     // t / 60 整型除取整得时间差转换成小时数
//     // t % 60 取余数得剩下的分钟数
// }

int main(int argc, char const *argv[])
{
    int a = 34, b = 67, max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    return 0;
}
