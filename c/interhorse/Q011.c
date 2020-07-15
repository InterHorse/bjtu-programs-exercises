#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-14

最大的数
成绩: 5 / 折扣: 0.8
题面描述
给你三个数 a, b, c ，求 a* b, b * c, c * a 三个数中的最大值

输入数据
第一行有一个整数 T ，代表接下来有 T 组数据，每一组数据占单独的一行，包括三个整数 a, b 和 c 。

输出数据
对于每组输入数据，在单独的行中输出 一行形如 "Case #id: a b c" 的结果 ，保证最大值不超过 32 位整数范围。

样例输入
3
1 1 1
1 2 2
3 1 2

样例输出
Case #1: 1
Case #2: 4
Case #3: 6

时间限制：1秒
内存限制：无限制
 */
int main() {
    // 循环 t
    int t;
    scanf("%d", &t);
    // 最小值
    int min;
    // 最小值索引
    int minIndex;
    // 乘积结果
    int res;
    // 存放 3 个数
    int arr[3];
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        // 找出最小值，那么另外两个值即要算乘积的两个值
        min = arr[0];
        minIndex = 0;
        for (int j = 1; j < 3; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        switch (minIndex) {
            case 0:
                res = arr[1] * arr[2];
                break;
            case 1:
                res = arr[0] * arr[2];
                break;
            case 2:
                res = arr[0] * arr[1];
                break;
        }
        // 输出
        printf("Case #%d: %d\n", i + 1, res);
    }
    return 0;
}