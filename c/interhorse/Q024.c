#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-20

十字架
成绩: 5 / 折扣: 0.8
题面描述
给出一个数 n ，打印 n 层十字架。如下图所示为 n = 1 时的十字架 :

..$$$$$..
..$...$..
$$$.$.$$$
$...$...$
$.$$$$$.$
$...$...$
$$$.$.$$$
..$...$..
..$$$$$..

输入数据
输入数据的第一行为一个正整数 T ，表示有 T 组数据。

接下来的 T 行中每行为一个正整数 n ，表示输入的层数 (T <= 20, 0 < n <= 20) 。

输出数据
输出 T 组结果，每一组输出的第一行为 "Case #x:" ，冒号后面没有空格，

随后为该组数据的答案。

样例输入
2
1
2

样例输出
Case 1:
..$$$$$..
..$...$..
$$$.$.$$$
$...$...$

$.$$$$$.$
$...$...$
$$$.$.$$$
..$...$..
..$$$$$..
Case 2:
..$$$$$$$$$..
..$.......$..
$$$.$$$$$.$$$
$...$...$...$
$.$$$.$.$$$.$
$.$...$...$.$
$.$.$$$$$.$.$
$.$...$...$.$
$.$$$.$.$$$.$
$...$...$...$
$$$.$$$$$.$$$
..$.......$..
..$$$$$$$$$..

时间限制：1秒
内存限制：无限制
 */
char ele[2] = {'.', '$'};
// 普通上1 普通下2 普通左3 普通右4
// 特殊上5 特殊下6 特殊左7 特殊右8
int route[12] = {1, 8, 5, 4, 6, 8, 2, 7, 6, 3, 5, 7};

void print(char **table, int a);

int main() {
    // t, n
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int a = 9 + 4 * (n - 1);
        char table[a][a];
        int loopTimes = n * 2;
        // 初始化十字架，最中间的十字
        table[a / 2][a / 2] = '$';
        table[a / 2 + 1][a / 2] = '$';
        table[a / 2 + 2][a / 2] = '$';
        table[a / 2 - 1][a / 2] = '$';
        table[a / 2 - 2][a / 2] = '$';
        table[a / 2][a / 2 + 1] = '$';
        table[a / 2][a / 2 + 2] = '$';
        table[a / 2][a / 2 - 1] = '$';
        table[a / 2][a / 2 - 2] = '$';
        // 循环画轮廓
        for (int j = 0; j < loopTimes; j++) {
            // 初始化起点
            int x = a / 2 + j + 1;
            int y = a / 2 - 2 - (j + 1);
            // 当前赋值元素
            char element = ele[j % 2];
            // 按路线走
            for (int k = 0; k < 12; k++) {
                switch (route[k]) {
                    case 1:
                        for (int l = 0; l < 3 + 2 * j; l++) {
                            table[x][y] = element;
                            if (l != 2 + 2 * j) {
                                x--;
                            }
                        }
                        break;
                    case 2:
                        for (int l = 0; l < 3 + 2 * j; l++) {
                            table[x][y] = element;
                            if (l != 2 + 2 * j) {
                                x++;
                            }
                        }
                        break;
                    case 3:
                        for (int l = 0; l < 3 + 2 * j; l++) {
                            table[x][y] = element;
                            if (l != 2 + 2 * j) {
                                y--;
                            }
                        }
                        break;
                    case 4:
                        for (int l = 0; l < 3 + 2 * j; l++) {
                            table[x][y] = element;
                            if (l != 2 + 2 * j) {
                                y++;
                            }
                        }
                        break;
                    case 5:
                        for (int l = 0; l < 3; l++) {
                            table[x][y] = element;
                            if (l != 2) {
                                x--;
                            }
                        }
                        break;
                    case 6:
                        for (int l = 0; l < 3; l++) {
                            table[x][y] = element;
                            if (l != 2) {
                                x++;
                            }
                        }
                        break;
                    case 7:
                        for (int l = 0; l < 3; l++) {
                            table[x][y] = element;
                            if (l != 2) {
                                y--;
                            }
                        }
                        break;
                    case 8:
                        for (int l = 0; l < 3; l++) {
                            table[x][y] = element;
                            if (l != 2) {
                                y++;
                            }
                        }
                        break;
                }
            }
        }
        // 四角处理
        table[0][0] = '.';
        table[0][1] = '.';
        table[1][0] = '.';
        table[1][1] = '.';

        table[0][a - 1] = '.';
        table[0][a - 2] = '.';
        table[1][a - 1] = '.';
        table[1][a - 2] = '.';

        table[a - 1][a - 1] = '.';
        table[a - 1][a - 2] = '.';
        table[a - 2][a - 1] = '.';
        table[a - 2][a - 2] = '.';

        table[a - 1][0] = '.';
        table[a - 2][0] = '.';
        table[a - 1][1] = '.';
        table[a - 2][1] = '.';

        // 输出
        printf("Case #%d:\n", i + 1);
        print((char **) table, a);
    }
    return 0;
}

void print(char **table, int a) {
    for (int j = 0; j < a; j++) {
        for (int k = 0; k < a; k++) {
            printf("%c", *((char *) table + a * j + k));
        }
        printf("\n");
    }
}
