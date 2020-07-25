#include <stdio.h>
#include <math.h>

/*
Author Inter Horse
Date 2020-07-18

锻炼计划
成绩: 5 / 折扣: 0.8
题面描述

老顽童是一个热爱运动的人，每天都有小顽童来和他一起锻炼。为了让锻炼更有成效，他想要制定一份锻炼计划，让第 n 天的训练量要等于第 n 个正回文数 ( 第 1 个正回文数是 1) 。

老顽童已经打印好了计划表，但是他的计划表中有一些日子被遗漏了，他又不想重新计算，你可以帮他解决这个问题吗？

如果一个数的各位数字反向排列后仍然等于其本身，则把这样的数称为回文数 (palindrome number) ，如 12321 是回文数， 1232 不是回文数。

输入数据

第一行有一个整数 t (1 ≤ t ≤ 100000) ，表示有 t 组数据。

每组数据只有一行，为一个整数 n (1 ≤ n ≤ 400000) ，表示第 n 天。

输出数据

对于每组数据，输出一个整数，表示对应的训练量。

样例输入

5
1
2
3
12
23

样例输出

1
2
3
33
141

时间限制：1秒
内存限制：无限制
 */
int staticArr[12] = {0, 9, 18, 108, 198, 1098, 1998, 10998, 19998, 109998, 199998, 1099998};

void printBk(double ft, int mid);

int main() {
    // t, n
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int digits;
        int dif;
        for (int j = 1; j <= 11; j++) {
            if (n > staticArr[j - 1] && n <= staticArr[j]) {
                digits = j;
                dif = n - staticArr[j];
                int mid;
                double ft;
                if (digits % 2 == 0) {
                    mid = digits / 2;
                    ft = pow(10, mid) + dif - 1;
                    printf("%d", (int) ft);
                    printBk(ft, mid);
                } else {
                    mid = (digits + 1) / 2;
                    ft = pow(10, mid) + dif - 1;
                    printf("%d", (int) ft);
                    printBk(ft / 10, digits / 2);
                }
            }
        }
    }
    return 0;
}

/**
 * 打印后半段
 * @param ft
 * @param average
 */
void printBk(double ft, int mid) {
    for (int i = 0; i < mid; i++) {
        printf("%d", (int) ft % 10);
        ft /= 10;
    }
    printf("\n");
}