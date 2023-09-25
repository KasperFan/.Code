/*
Name    :   Hello,World!.cpp
Time    :   2022/10/04 20:15:14
Author  :   Kasper Fan
Group   :   Weifang University
Contact :   fanwlx@foxmail.com
Desc    :   This file is created for learning C language Coding
*/
#include<iostream>
using namespace std;
// int main()
// {
//     cout << "Hello,World!" << endl;
//     return 0;
// }
int main()
{
	__asm {
		push 0x00000021
		push 0x646c726f
		push 0x77202c6f
		push 0x6c6c6568
		push esp
		call $ + 5
		pop ebx
		add ebx, 11
		push ebx
		push printf
		ret
		add esp, 20
	}
    
	return 0;
}
