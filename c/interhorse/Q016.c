#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-16

小A的卡片
成绩: 5 / 折扣: 0.8
题面描述

小 A 是一个卡片收藏的爱好者，他有一个非常大的正方形卡箱，卡箱中有 n × n 个格子，每个格子中都放着一张卡片，为了方便寻找卡片，小 A 给每个卡片标上一个整数值。卡箱中卡片的值满足从左向右非递减，从上到下非递减。

现给你一个卡片的值，你能快速的找到卡片的位置吗？

输入数据

第一行有一个整数 t (1 ≤ t ≤ 10) ，表示有 t 组数据。

对于每组数据：

第一行有一个整数 n (1 ≤ n ≤ 1000) ，表示正方形卡箱的边长；

接下来有 n 行，每行有 n 个整数 aij (1 ≤ aij ≤ 109) ，表示正方形卡箱中卡片的值。

接下来一行为有一个整数 q (1 ≤ q ≤ 104) ，表示有 q 个询问。对于每个询问：

第一行有一个整数 x (1 ≤ x ≤ 109) 。

保证 ∑ n2 ≤ 2 × 106, ∑ q ≤ 2 × 104 。

输出数据

对个每个询问，如果卡箱中有这张卡片，输出它的位置 x y ，反之输出 -1 。

如果有多个卡片值相同，请输出 x 最小的，如果还有多个相同的，请输出 y 最大的。

样例输入

2
3
1 3 5
2 4 7
6 8 9
3
1
7
10
2
1 1
1 1
1
1

样例输出

1 1
2 3
-1
1 2

时间限制：1秒
内存限制：无限制
 */
int x;
int y;

int lookForNum(int **table, int num, int n);

int main() {
    // t, n, q
    int t, n, q;
    // 要找的数
    int requestedNum;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        // 建立卡箱
        int table[n][n];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &table[j][k]);
            }
        }
        scanf("%d", &q);
        for (int j = 0; j < q; j++) {
            scanf("%d", &requestedNum);
            if (lookForNum((int **) table, requestedNum, n) == -1) {
                printf("-1\n");
            } else {
                printf("%d %d\n", x + 1, y + 1);
            }
        }
    }
    return 0;
}

/**
 * 寻找卡片
 * @param table 卡箱
 * @param num 要找的数
 * @param n 卡箱边长
 * @return 如果找到了，返回1，否则返回0
 */
int lookForNum(int **table, int num, int n) {
    int res = -1;
    // 记录当前位置
    x = 0;
    y = 0;
    // 记录上次位置
    int lastX = 0;
    int lastY = 0;
    // 规则。先横着找，如果右边的数小于等于要找的数，则往右走1.
    // 如果右边的数笔要找的数大，则看下面的数。
    // 如果下面的数小于等于要找的数，则往下走1.
    // 如果右边和下面的数都比要找的数大，则往左走 1 步。
    // 继续判断下面的数。直到找到或者没找到。
    while (1) {
        if (num == *((int *) table + n * x + y)) {
            if (y + 1 < n && num == *((int *) table + n * x + (y + 1))) {
                lastY = y;
                lastX = x;
                y++;
            } else {
                res = 1;
                break;
            }
        } else {
            if (y + 1 < n && x + 1 < n) {
                if (y + 1 != lastY && num >= *((int *) table + n * x + (y + 1))) {
                    lastY = y;
                    lastX = x;
                    y++;
                } else if (x + 1 != lastX && num >= *((int *) table + n * (x + 1) + y)) {
                    lastX = x;
                    lastY = y;
                    x++;
                } else if (y - 1 >= 0) {
                    lastY = y;
                    lastX = x;
                    y--;
                } else {
                    break;
                }
            } else if (y + 1 < n) {
                if (y + 1 != lastY && num >= *((int *) table + n * x + (y + 1))) {
                    lastY = y;
                    lastX = x;
                    y++;
                } else {
                    break;
                }
            } else if (x + 1 < n) {
                if (x + 1 != lastX && num >= *((int *) table + n * (x + 1) + y)) {
                    lastX = x;
                    lastY = y;
                    x++;
                } else if (y - 1 >= 0) {
                    lastY = y;
                    lastX = x;
                    y--;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return res;
}