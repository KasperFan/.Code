<!--
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-11-10 23:44:07
 * @LastEditTime: 2023-11-11 17:18:15
 * @FilePath: /Fortran/Data_class/Fortran的数据类型.md
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
-->
<h1>Fortran的数据类型</h1>
数据类型是指记录文本、数值等数据的最小单位及方法

<font color=blue><b>整数（INTEGER）</b></font> 8 bits = 1 Byte
- 长整型（32 bits）：-$2^{31}$ ~ $2^{31}$-1
- 短整型（16 bits）：-$2^{15}$ ~ $2^{15}$-1

<font color=blue><b>实数（REAL）</b></font>
- 单精度（32 bits）：有效位数6～7位
-   最大 $±\ 3.4*10^{38}$，最小 $±\ 1.18*10^{-38}$
- 单精度（64 bits）：有效位数15～16位
    最大 $±\ 1.79*10^{308}$，最小 $±\ 2.23*10^{-308}$

<font color=blue><b>复数（COMPLEX）</b></font>
- 由两个浮点数$（a+bi）$来表示的数值，分为单精度复数和双精度复数两种

<font color=blue><b>字符（CHARACTER）</b></font>
- 记录字母、数字或任何特殊符号
- 记录一连串字符时称为 “字符串”

<font color=blue><b>逻辑判断（LOGICAL）</b></font>
- “是/真”（.<font color=blue>TRUE</font>.）和“非/否/假”（.<font color=blue>FALSE.</font>）

<font color=blue><b>派生类型</b></font>
- 基本类型的混合，意义明确，减少数组个数

<br>
<br>
<font color=red>不同类型的数据要经过转换才能互通互用，因为它们是用不同方法来存储的</font>


