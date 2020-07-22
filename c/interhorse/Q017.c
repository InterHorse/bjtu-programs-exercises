#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-16

数学难题
成绩: 5 / 折扣: 0.8
题面描述

Griffin ：“啥？比赛命题。可是我好菜啊 ! ”

骚年，这还不简单，随便出道数学题就好啊？

于是 Griffin 就遍查网络，找到一个问题，可以表述为：

在字典 {1,2,…, n } 上，对于一个字符串，要求其 1 到 n 的 n! 个排列都是其子串，求这样的字符串的最短长度。

同学 A ：“喵喵喵？就不能说得通俗一点吗？”

那好吧，举个例子，假设有一个 n 集的连续剧 , 对应 n 张 DVD ，每张 DVD 不可区分，也不能通过剧情内容区分 DVD 集数，问至少要看多少张 DVD 才能确保一定以正确顺序连续观看一遍该连续剧？

For example ，假设现在 n=2 ，我们将两张 DVD 命名为 1,2 ，我们以 121 的顺序观看，这样无论 1 和 2 哪个是真正的第一集都能保证我们以最小的次数 3 连续观看完正确顺序的剧情。

输入数据

第一行有一个整数 t (1 ≤ t ≤ 5) ，表示有 t 组数据。

对于每组数据：

第一行为一个正整数 n (1 ≤ n ≤ 5) 。

输出数据

对于每组数据，输出一个整数，表示最短的长度。结果可能很大，请对 109+7 取模。

样例输入

2
1
2

样例输出

1
3

时间限制：1秒
内存限制：无限制
 */
int factorial(int n);

int main() {
    // t, n
    int t, n;
    int sum;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        sum = 0;
        // 公式：sum = 1! + 2! + 3! + ... + n!
        for (int j = 1; j <= n; j++) {
            sum += factorial(j);
        }
        sum = sum % 1000000007;
        printf("%d\n", sum);
    }
    return 0;
}

/**
 * 计算 n 的阶乘
 * @param n
 * @return
 */
int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}