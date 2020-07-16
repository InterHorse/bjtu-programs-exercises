#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-16

世纪难题
成绩: 5 / 折扣: 0.8
题面描述

“晚饭吃什么？” Lazy_sheep 的女朋友问到。

“咱这不才吃完午饭嘛！” Lazy_sheep 看着餐厅的菜谱，无奈的回答。

作为一个世纪难题，“晚饭吃什么”一直困扰着 Lazy_sheep 。

已知餐厅菜谱上的每一道菜前都写有一个正整数作为菜品编号，而他女朋友能记起前 n 顿饭吃的是哪些菜。如果今天晚饭和前 n 顿饭中某一顿吃的菜相同的话，她就会不开心。

现在 Lazy_sheep 随口说出了某个编号 w ，请你帮忙判断会不会到导致女朋友不开心。

输入数据

第一行有一个整数 t (1 ≤ t ≤ 100) ，表示有 t 组数据。

对于每组数据：

第一行有一个正整数 w (1 ≤ w ≤ 50) ，表示 Lazy_sheep 说出的菜品编号；

第二行有一个正整数 n (1 ≤ n ≤ 20) ；

第三行有 n 个不同的正整数 ai (1 ≤ i ≤ n,1 ≤ ai ≤ 50) ，表示前 n 顿饭吃的菜品编号。

输出数据

对于每组数据：

如果 w 是前 n 顿饭吃过的菜品编号，输出一行“ unhappy ”，否则输出“ happy ”。

样例输入

2
1
3
1 2 3
5
5
1 8 7 4 6

样例输出

unhappy
happy

时间限制：1秒
内存限制：无限制
 */
int main() {
    // t, w, n
    int t, w, n;
    scanf("%d", &t);
    // 记录女朋友的菜号
    int girlfriendCode;
    // 记录女朋友是否开心 0: 不开心，1: 开心
    int isHappy;
    for (int i = 0; i < t; i++) {
        scanf("%d", &w);
        scanf("%d", &n);
        // 初始化为开心
        isHappy = 1;
        for (int j = 0; j < n; j++) {
            scanf("%d", &girlfriendCode);
            // 只要为不开心，本轮一直为不开心
            if (isHappy != 0) {
                if (w == girlfriendCode) {
                    // 菜号一样，不开心了
                    isHappy = 0;
                }
            }
        }
        if (isHappy) {
            printf("happy\n");
        } else {
            printf("unhappy\n");
        }
    }
    return 0;
}