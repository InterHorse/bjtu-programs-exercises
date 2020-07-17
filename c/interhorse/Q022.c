#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-17

Cube
成绩: 5 / 折扣: 0.8
题面描述
给定一个盒子，长宽高分别为 a, b, c(1 <= a, b, c <= 100) 。有一个长度为 L 的木棍 (1 <= L <= 100) ，只记长度，能不能放到这个盒子里 ?

输入数据
输入的第一行为一个正整数 T ，表示共有 T 组测试数据，随后的 T 行中每行为空格分隔的四个整数” a b c L ”，如上所述。

输出数据
对每组测试数据，在单独的行中输出问题答案“ YES ”或“ NO ”，见样例。

样例输入
2
1 2 3 1
5 5 5 100

样例输出
Case #1: YES
Case #2: NO

时间限制：1秒
内存限制：无限制
 */
int main() {
    // t, x, y, z, len: 木棍长度
    int t, x, y, z, len;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d %d", &x, &y, &z, &len);
        if (len * len > (x * x + y * y + z * z)) {
            printf("Case #%d: NO\n", i + 1);
        } else {
            printf("Case #%d: YES\n", i + 1);
        }
    }
    return 0;
}