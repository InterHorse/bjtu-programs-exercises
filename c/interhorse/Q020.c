#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-18

选课
成绩: 5 / 折扣: 0.8
题面描述

小刘所在的学校本学期共开设了 60 门课，并且每位同学会选修 5 门不同的课，小刘想知道是否存在一个 3 门课的集合，使得小刘所在班级有至少 p% （ p 为不超过 100 的非负整数） 的同学选修了这三门课。

输入数据

第一行有一个整数 t (1 ≤ t ≤ 20) ，表示有 t 组数据。

对于每组数据：

第一行有两个整数 n, p (2 ≤ n ≤ 100000,50 ≤ p ≤ 100) ， n 表示小明班级的人数；

接下来的 n 行，每行有 5 个整数 ai (0 ≤ ai ≤ 59) 表示该同学选修的课程号。

输出数据

对于每组数据，如果存在至少 p% 的同学选修相同的 3 门课程，输出一行“ yes ”，否则输出“ no ”。

样例输入

1
5 80
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

样例输出

yes

时间限制：1秒
内存限制：无限制
 */
void sort(int *arr, int length);

int main() {
    // t, n, p
    int t, n, p;
    scanf("%d", &t);
    int num;
    int classIds[5];
    int records[61][61][61];
    for (int i = 0; i < t; i++) {
        int res = 0;
        scanf("%d %d", &n, &p);
        num = n * p * 0.01;
        for (int j = 0; j < n; j++) {
            scanf("%d %d %d %d %d", &classIds[0], &classIds[1], &classIds[2], &classIds[3], &classIds[4]);
            // 从小到大排序
            sort(classIds, 5);
            if (res) {
                // 标识位提前跳出循环
                continue;
            }
            for (int k = 0; k < 3; k++) {
                for (int l = k + 1; l < 4; l++) {
                    for (int m = l + 1; m < 5; m++) {
                        // 记录一组选课的所有 3 次课的组合情况，并记录到三维数组中 +1
                        records[classIds[k]][classIds[l]][classIds[m]]++;
                        if (records[classIds[k]][classIds[l]][classIds[m]] >= num) {
                            res = 1;
                            break;
                        }
                    }
                    if (res) {
                        // 标识位提前跳出循环
                        break;
                    }
                }
                if (res) {
                    // 标识位提前跳出循环
                    break;
                }
            }
        }
        if (res) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

    }
    return 0;
}

/**
 * 冒泡排序 - 从小到大
 * @param arr
 * @param length
 */
void sort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
