#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-14

A+B 示例
时间限制: 1秒  内存限制: 无限制
题面描述：
给定两个整数 a 和 b ，计算它们的和 a + b

输入：
输入包含多组测试数据，每一行包含两个整数 a 和 b，如：
5 12

输出：
控制台输出，对每行输入，在一行中输出 a + b 的和（请注意换行）。如：

17

示例输入：
25 33

示例输出：
58

提示：

C/C++程序请包含所需的头文件，请注意使用MS Visual Studio环境时，不要包含stdafx.h。C/C++测试编译环境为gcc/g++

时间限制：1秒
内存限制：无限制
 */
int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
        printf("%d\n", a + b);
    return 0;
}