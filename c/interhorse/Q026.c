#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-20

小明的作业
成绩: 5 / 折扣: 0.8
题面描述
小明每天都有很多作业要写，今天的作业内容是将一些分数写成小数的形式。众所周知，有些分数可以写成有限小数，比如 1 / 2 = 0.5 ，而有些分数会写成无限循环小数的形式，比如 1 / 3 = 0.33333 ……，小明觉得这个作业太麻烦了，于是请你来编程帮他完成这个作业。

输入数据
输入数据的第一行为一个正整数 T ，表示测试数据的组数。接下来有 T 行测试数据，每行测试数据为空格分隔的两个正整数 a, b ，代表分数 a / b( 1 ≤ T ≤ 20, 0 ≤ a ≤ b) 。

输出数据
对于每一组输入数据，输出一行结果。先输出” Case #id: ”，表示第 id 组数据， id 从 1 开始。如果该组数据能够写成有限小数，则在同一行中输出“ heiheihei ”，否则输出到该无限循环小数的第一个循环节结束。保证数据中所有无限小数均是 0.abcabc ……这样的形式，不会有形如 0.abcbc ……的小数，且循环节长度不超过 9 。

样例输入
4
1 2
1 3
1 4
2 3

样例输出
Case 1: heiheihei
Case 2: 0.3
Case 3: heiheihei
Case 4: 0.6

时间限制：1秒
内存限制：无限制
 */
int main() {
    // t, a, b
    int t, a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        int remainsArr[9] = {0};
        int resArr[9] = {0};
        // 第一个出现的余数
        int firstNum;
        // 结果 0 为无循环小时，1 为有循环小数
        int res = 0;
        // 初始化
        int remains = a;
        for (int j = 0; j < 10;j++) {
            // 当前余数
            int tmpRemains = remains * 10 % b;
            // 当前小数位结果
            int tmpRes = remains * 10 / b;
            // 计算余数并赋值给 remains
            remains = remains * 10 % b;
            if (remains == 0) {
                // 如果余数为 0，则跳出，res = 0
                break;
            }
            if (j == 0) {
                // 首次将第一个得到的余数赋值给 firstNum，如果之后有某个余数再碰到 firstNum，则说明有循环
                firstNum = tmpRemains;
            } else {
                if (tmpRemains == firstNum) {
                    res = 1;
                    break;
                }
            }
            // 记录小数位结果和余数
            remainsArr[j] = tmpRemains;
            resArr[j] = tmpRes;
        }
        // 输出
        if (res == 0) {
            printf("Case #%d: heiheihei\n", i + 1);
        } else {
            printf("Case #%d: 0.", i + 1);
            for (int j = 0; j < 9; j++) {
                if (remainsArr[j] == 0) {
                    break;
                }
                printf("%d", resArr[j]);
            }
            printf("\n");
        }

    }
    return 0;
}