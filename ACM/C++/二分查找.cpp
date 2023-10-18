/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-26 18:28:57
 * @LastEditTime: 2023-09-26 18:45:40
 * @FilePath: /C++/二分查找.cpp
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */
#include <bits/extc++.h>

using namespace std;

int arr[] = {4, 5, 61, 8, 1, 3, 7, 1, 3, 7, 43, 6, 4, 9, 6, 4};

int binarySearch(int a[], int target, int left, int right);

int main(int argc, char const *argv[])
{
    sort(arr, arr+sizeof(arr)/sizeof(int));
    cout << binarySearch(arr, 81, 0, (int)(sizeof(arr) / sizeof(int))) << endl;
    return 0;
}

int binarySearch(int a[], int target, int left, int right) {
    int middleIndex = (left + right) / 2;
    if (a[middleIndex] == target)
    {
        return middleIndex;
    }else if (a[middleIndex] > target)
    {
        return binarySearch(a, target, left, middleIndex - 1);
    }else
    {
        return binarySearch(a, target, middleIndex + 1, right);
    }
    return - 1;
}