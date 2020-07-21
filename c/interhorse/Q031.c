#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-21

开学
成绩: 5 / 折扣: 0.8
题面描述
小明就要开学了，但小明的行李太多了以致于他不能自己全部拿到学校去，于是小明想要将一些行李邮寄到学校去。现在已知小明共有 N 件行李，每件行李的重量为 Wi ，共有 M 家快递公司可用。小明至多选择一家公司寄快递，第 i 家快递公司最多能邮寄重量总和为 ai 的行李，收取的费用为 ci 。小明自己最多可以拿总重量为 D 的行李，并且希望自己的花费越小越好。

请问小明能否将自己所有的行李拿到学校去？

输入数据
输入数据的第一行为一个正整数 T ，表示测试数据的组数。接下来是 T 组测试数据，每组测试数据的第一行为三个整数 N 、 M 和 D (1 ≤ T ≤ 100, 1 ≤ N, M, D ≤ 1000) 。接下来的一行为 N 个整数，表示 N 件行李的重量，接下来的 M 行中，每行有空格分隔的两个整数 ai 和 ci ，代表第 i 家快递公司最多邮寄的重量和费用 (0 ≤ wi ≤ 100, 0 ≤ ai ≤ 100000, 0 ≤ ci ≤ 1000) 。

输出数据
对于每一组输入数据，输出一行结果 ”Case #id: ans” ，表示第 id 组数据的结果是 ans ， id 从 1 开始。如果小明不能将自己所有的行李拿到学校去， ans 为“ QAQ ”，否则 ans 为小明的最小花费。

样例输入
1
2 2 10
5 6
5 10
6 5

样例输出
Case #1: 5

时间限制：1秒
内存限制：无限制
 */
void print(int **table, int a, int b);

int main() {
    // t, n, m, d
    int t, n, m, d;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &n, &m, &d);
        // 记录行李
        int packageArr[n];
        // 记录快递信息
        int expressArr[m][2];
        // 行李总和
        int packageSum = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &packageArr[j]);
            packageSum += packageArr[j];
        }
        for (int j = 0; j < m; j++) {
            scanf("%d %d", &expressArr[j][0], &expressArr[j][1]);
        }
        // 背包问题，不考虑价格。最大子集。动态规划。
        int table[n + 1][d + 1];
        for (int j = 0; j <= d; j++) {
            table[0][j] = 0;
        }
        for (int j = 1; j <= n; j++) {
            table[j][0] = 0;
            int max;
            for (int k = 1; k <= packageArr[j - 1] - 1; k++) {
                table[j][k] = table[j - 1][k];
            }

            for (int k = packageArr[j - 1]; k <= d; k++) {
                if (table[j - 1][k] > (table[j - 1][k - packageArr[j - 1]] + packageArr[j - 1])) {
                    max = table[j - 1][k];
                } else {
                    max = table[j - 1][k - packageArr[j - 1]] + packageArr[j - 1];
                }
                table[j][k] = max;
            }
        }

        // 计算是否需要快递，以及快递最低价
        int maxPackage = packageSum - table[n][d];
        int res = 0;
        int fee = 9999;
        if (maxPackage != 0) {
            for (int j = 0; j < m; j++) {
                if (expressArr[j][0] >= maxPackage) {
                    if (expressArr[j][1] < fee) {
                        fee = expressArr[j][1];
                        res = 1;
                    }
                }
            }
        } else {
            res = 1;
            fee = 0;
        }
        // 输出
        if (res) {
            printf("Case #%d: %d\n", i + 1, fee);
        } else {
            printf("Case #%d: QAQ\n", i + 1);
        }
    }
    return 0;
}