/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-07-05 16:20:17
 * @LastEditTime: 2023-07-05 16:20:31
 * @FilePath: /ACM/Leetcode/1/1.c
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved.
 */

#include <uthash.h>

struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(int ikey)
{
    struct hashTable *tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival)
{
    struct hashTable *it = find(ikey);
    if (it == NULL)
    {
        struct hashTable *tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    }
    else
    {
        it->val = ival;
    }
}