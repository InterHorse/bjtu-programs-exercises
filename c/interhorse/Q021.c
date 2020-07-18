#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-18

郁金香
成绩: 5 / 折扣: 0.8
题面描述

春天到了，校园里开满了郁金香。 Infinity 经过花坛的时候，常常会停下来数郁金香玩。

Infinity 会分别统计不同颜色的花出现的次数，并把它们按照出现次数从多到少排序。

这次 Infinity 来到了一个很大的花坛前，和往常一样继续数郁金香。

不料，他数到一半时突然忘记数到哪了。 Infinity 不想从头开始数了，你能帮帮他吗？

输入数据

第一行有一个整数 t (1 ≤ t ≤ 100) ，表示有 t 组数据。

对于每组数据：

第一行有两个整数 n, m (1 ≤ n, m ≤ 100) ，表示花坛的长和宽；

接下来 n 行，每行有一个长度为 m 且由大写字母组成的的字符串，表示对应位置出现的花的种类。其中，相同的字母表示相同的花，不同的字母表示不同的花。

输出数据

对于每组数据：

第一行输出一个整数 k ，表示花坛中一共有 k 种不同的花。

接下来 k 行，每行输出一个整数 x 和一个字符 c ，表示出现了 x 个种类为 c 的花。

你需要按花出现的次数从大到小的顺序输出，如果多种花数量相同，请按花的种类从小到大输出。

样例输入

1
3 3
ABC
BBC
CCC

样例输出

3
5 C
3 B
1 A

时间限制：1秒
内存限制：无限制
 */
void sort(int *recordNum, int *recordIndex, int length);

int main() {
    // t, n, m
    int t, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        char str[m + 1];
        // 记录原始郁金香及其个数
        int recordNum[26] = {0};
        int recordIndex[26] = {0};
        // 记录郁金香种类
        int species = 0;
        for (int j = 0; j < n; j++) {
            scanf("%s", str);
            for (int k = 0; k < m; k++) {
                // 将大写字母转化为索引 A = 65
                if (recordNum[str[k] - 65] == 0) {
                    species++;
                }
                recordNum[str[k] - 65]++;
                recordIndex[str[k] - 65] = str[k] - 65;
            }
        }
        // 从大到小排序
        sort(recordNum, recordIndex, 26);
        // 输出
        printf("%d\n", species);
        for (int j = 0; j < 26; j++) {
            if (recordNum[j] != 0) {
                printf("%d %c\n", recordNum[j], recordIndex[j] + 65);
            } else {
                break;
            }
        }
    }
    return 0;
}

/**
 * 冒泡排序 - 从大到小
 * @param arr
 * @param length
 */
void sort(int *recordNum, int *recordIndex, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (recordNum[j] == 0 || recordNum[j] < recordNum[j + 1]) {
                int tmp = recordNum[j];
                recordNum[j] = recordNum[j + 1];
                recordNum[j + 1] = tmp;
                tmp = recordIndex[j];
                recordIndex[j] = recordIndex[j + 1];
                recordIndex[j + 1] = tmp;
            }
        }
    }
}