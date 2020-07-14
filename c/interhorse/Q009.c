#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-14

懒羊羊的作业
成绩: 5 / 折扣: 0.8
题面描述
看过国产动画片的同学都知道，懒羊羊是一只非常懒的羊，整天除了吃就是睡，根本没有时间做作业。明天就是周一了，村长慢羊羊留的作业：把 n 个整数从大到小排序，它还没开始写，真是一件让羊悲伤的事呀。但是，懒羊羊又是一只相当“机智”的羊，它发现村长年纪大了，这么多作业根本判不过来，只会检查作业的开头和结尾。所以懒羊羊想出了一个办法：把最大的数和第一个数交换，再把最小的数与最后一个数交换，其他的数位置不变。按这种方法得到的整数数列就可以瞒过村长啦。但是即使这样，懒羊羊也懒得去做，所以它来求助爱编程的你们啦。

输入数据
第一行为 T ，表示有 T 组数据。

接下来 T 行，每行的第一个数为一个整数 n ，表示该行随后有 n 个整数，为要进行上述操作的 n 个数（保证这 n 个数中最大的数只有一个，最小的数也只有一个， T<=50;2<=n<=10000 ）。

输出数据
对每组测试数据输出单独的一行结果，形如 ” Case #x: ans ” ，表示第 x 组的结果为 ans 。

样例输入
2
5 2 3 1 5 4
6 9 11 2 0 7 2

样例输出
Case #1: 5 3 4 2 1
Case #2: 11 9 2 2 7 0

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
        // 记录输入值
        int input;
        // 记录数组
        int arr[n];
        // 最大值、最小值
        int max;
        int min;
        // 最大值、最小值索引
        int maxIndex;
        int minIndex;
        scanf("%d", &input);
        // 初始化
        arr[0] = input;
        max = arr[0];
        min = arr[0];
        maxIndex = 0;
        minIndex = 0;
        for (int j = 1; j < n; j++) {
            scanf("%d", &input);
            // 找最大值和最小值
            arr[j] = input;
            if (arr[j] > max) {
                max = arr[j];
                maxIndex = j;
            } else if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        // 替换
        int tmp1;
        int tmp2;
        tmp1 = arr[minIndex];
        tmp2 = arr[maxIndex];
        arr[minIndex] = arr[n - 1];
        arr[maxIndex] = arr[0];
        arr[0] = tmp2;
        arr[n - 1] = tmp1;
        // 输出
        printf("Case #%d:", i + 1);
        for (int j = 0; j < n; j++) {
            printf(" %d", arr[j]);
        }
        printf("\n");
    }
    return 0;
}