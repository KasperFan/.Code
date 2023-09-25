/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-08-06 15:39:59
 * @LastEditTime: 2023-09-17 17:06:53
 * @FilePath: /C++/P1923.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
/*
Name    :   P1923.cpp
Time    :   2022/12/14 20:33:34
Author  :   Kasper Fan
Group   :   Weifang University
Contact :   fanwlx@foxmail.com
Desc    :   This file is created for learning C language Coding
*/

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array, array + n);
    while (array[k] == array[k + 1])
        k++;
    cout << array[k] << endl;
    return 0;
}
