#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-14

求和
成绩: 5 / 折扣: 0.8
题面描述
某一天， calfcamel 问二哥，有道数学题怎么做呀？二哥看了一下说我不会呀，于是二哥找到了你，请你帮他解决这个问题，这样二哥就可以鄙视 calfcamel 数学菜了。

给你一个长度为 n 的整数序列 a ，对该序列有 q 个查询，每次询问涉及序列中从 left 到 right 之间的数，包括 left 和 right ，请给出公式

sum formula

的结果。即输出 [left, right] 这段区间中，第一个数乘以 1 ，第二个数乘以 2 ，第三个数乘以 3 ，……的和。

输入数据
输入数据的第一行为一个正整数 T ，表示有 T 组数据。对于每组数据：

第一行是一个整数 n(n <= 100000) ；

第二行有 n 个整数构成的序列 a ，其中每个数均在 0 到 100000 之间；

第三行为一个整数 q(0<q <=100000) ，表示询问的数目；

接下来 q 行中，每行为两个整数 left 和 right ，表示查询的区间。

输出数据
对于每一组数据，先单独输出一行 ”Case #x: ” ， x 为当前组的编号，从 1 开始。

随后的 q 行中，每行输出对应查询的答案。

样例输入
2
3
1 2 3
1
1 3
5
1 2 3 4 5
3
1 5
2 4
3 5

样例输出
Case #1:
14
Case #2:
55
20
26

提示
数据量比较大， C/C++ 请使用 scanf 读入，使用 cin 可能会超时，序列求和结果可能超出 32 位整数表达范围。

时间限制：1秒
内存限制：无限制
 */
int main() {
    // 循环 t
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        // n
        int n;
        scanf("%d", &n);
        // 接收整数序列
        int input;
        // 存放序列前 i 的和
        long long sum1[n + 1];
        // 存放序列前 sum2[i] * i 的和
        long long sum2[n + 1];
        for (int j = 1; j <= n; j++) {
            scanf("%d", &input);
            // 计算前 sum1[i] 的和
            sum1[j] = sum1[j - 1] + input;
            // 计算前 sum2[i] * i 的和
            sum2[j] = sum2[j - 1] + input * j;
        }
        int q;
        scanf("%d", &q);
        printf("Case #%d: \n", i + 1);
        for (int j = 0; j < q; j++) {
            // 左右指针索引
            int lt;
            int rt;
            scanf("%d %d", &lt, &rt);
            long long res;
            // 根据公式计算结果
            // res = sum2[rt] - sum2[lt - 1] - (sum1[rt] - sum1[lt - 1]) * (lt - 1)
            res = sum2[rt] - sum2[lt - 1] - (sum1[rt] - sum1[lt - 1]) * (lt - 1);
            printf("%lld\n", res);
        }
    }
    return 0;
}