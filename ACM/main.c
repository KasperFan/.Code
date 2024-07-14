#include <stdio.h>
#include <math.h>

double dis(int x1, int y1, int x2, int y2)
{
    return (sqrt(pow((x2 - x1),2) + pow((y2 - y1),2)));
}

double x1, y1, x2, y2, x3, y3;

int main()
{
    
    scanf("%lf %lf\n%lf %lf\n%lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double sum, a, b, c;
    a = dis(x1, y1, x2, y2);
    b = dis(x1, y1, x3, y3);
    c = dis(x2, y2, x3, y3);
    sum = a + b + c;
    printf("%.2lf\n", sum);
    return 0;
}

// 23.234 12.123
// -99.99 99.99
// -1 -100
