#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-20

懒羊羊吃青草
成绩: 5 / 折扣: 0.8
题面描述
懒羊羊是一只非常能吃的羊，它在青青草原上发现一块巨大的正方形草地，但灰太狼已经抢先一步在草地上布下了若干陷阱。正方形草地位于直角坐标系中，左下角坐标为 (1, 1) ，右上角坐标为 (m, m) ，草地内只有整数坐标点上才长有青草。懒羊羊发现，对于一棵坐标为 (x, y) 处的青草，只有 (x*y) Mod m>0 时，草旁边才有一个陷阱， Mod 为取余数操作。

聪明的你是否能帮懒羊羊算一算，这块草地上共有多少陷阱。

输入数据
输入数据的第一行为一个正整数 T(T<=50) ，表示测试数据的组数。接下来是 T 行测试数据，每行中有一个整数 m(m<=100000) 。

输出数据
对于每一组测试数据，输出一行” Case id: M ”，表示第 id 组测试数据结果为， id 从 1 开始。

样例输入
5
1
3
4
6
1403

样例输出
Case #1: 0
Case #2: 4
Case #3: 8
Case #4: 21
Case #5: 1962964

时间限制：1秒
内存限制：无限制
 */
int gcd(int num1, int num2);

int main() {
    // t, m
    int t, m;
    scanf("%d", &t);
    long long int sum;
    for (int i = 0; i < t; i++) {
        scanf("%d", &m);
        sum = 0;
        for (int j = 0; j < m; j++) {
            // 每一行的陷阱数 = m - gcd(j + 1, m)
            sum += m - gcd(j + 1, m);
        }
        // 输出
        printf("Case #%d: %lld\n", i + 1, sum);
    }
    return 0;
}

/**
 * 求最大公约数 - 辗转相除法（欧几里得算法）
 * @param num1
 * @param num2
 * @return
 */
int gcd(int num1, int num2) {
    // 先求余数，假定第一个数较大；如果第二个较大，在第二轮调用时会颠倒过来
    int remainder = num1 % num2;
    // 如果为 0，则直接得出
    if (remainder == 0) {
        return num2;
    }
    // 递归调用
    return gcd(num2, remainder);
}