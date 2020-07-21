#include <stdio.h>
#include <stdlib.h>

/*
Author Inter Horse
Date 2020-07-21

弹幕游戏
成绩: 5 / 折扣: 0.8
题面描述
Ryan 最近迷上了弹幕游戏。所谓弹幕游戏，指的是玩家操控一位角色对来袭的大量敌人进行攻击，并在过程中升级、强化自我的能力，最终打败 Boss 的一类游戏。

“控制着主人公在枪林弹雨中穿行而不中弹的感觉真是太爽了！”—— Ryan

作为一个资深弹幕游戏玩家， Ryan 现在已经不再执着于不中弹，了，而是把目光转移到了所谓的“擦弹”这种高端游戏方式上。

“擦弹”是指玩家紧靠子弹而又不中弹的行为。如图所示。

图中“＊”表示子弹，“ . ”表示空位。主人公每次可以往上下左右方向移动一格。按照箭头的走法，就可以擦到紫色的子弹，擦弹数量为 4 。

注意，一个子弹即使被擦弹多次，但只会被计 1 次。

现在 Ryan 面前有一些固定不动的子弹，他想知道在不中弹的前提下，最大的擦弹数是多少。

输入数据
输入数据有多组，第一行是数据组数 T(T ≤ 50) 。每组数据的第一行为两个整数 n 和 m ，表示屏幕的规格是 n*m(n 行 m 列 ) 。第二行为两个整数 x 和 y ，表示主人公起始点在 x 行 y 列。接下来 n 行是一个 n*m 的矩阵，仅由 "*" 和 "." 组成 (1 <= n, m <= 500, 1 <= x <= n, 1 <= y <= m) 。保证起始点一定没有子弹，即矩阵的 (x,y) 处一定为 "." 。

输出数据
对每组数据在单独的一行中输出结果，格式为“ Case #k: result ” ( 冒号后有空格 ) ，表示第 k 组数据对应主人公最大的擦弹数量为 result 。

样例输入
3
4 4
4 3
...*
..**
...*
...*
3 5
2 3
.*.*.
*...*

.*.*.
3 3
2 2
***
*.*
***

样例输出
Case #1: 4
Case #2: 6
Case #3: 4

时间限制：1秒
内存限制：无限制
 */
// 搜索 BFS 链表
struct SearchLink {
    int x;
    int y;
    struct SearchLink *next;
};

int main() {
    // t, n, m, x, y
    int t, n, m, x, y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        scanf("%d %d", &x, &y);
        // 创建弹幕
        char table[n][m + 1];
        for (int j = 0; j < n; ++j) {
            scanf("%s", &table[j]);
        }
        int num = 0;

        // 初始化链表
        struct SearchLink *p = malloc(sizeof(struct SearchLink));
        struct SearchLink *q = p;
        p->x = x - 1;
        p->y = y - 1;
        p->next = NULL;
        table[x - 1][y - 1] = '1';
        do {
            // BFS 搜索，顺序：上右下左。
            // 遇到没有计算过的 *，则 num++。
            // 遇到没有走过的坐标，则加入到 BFS 链表中。
            // 直到 BFS 搜索结束。
            int cX = p->x;
            int cY = p->y;
            // 上
            if (cX - 1 >= 0) {
                if (table[cX - 1][cY] == '*') {
                    num++;
                    table[cX - 1][cY] = '2';
                }
                if (table[cX - 1][cY] == '.') {
                    table[cX - 1][cY] = '1';
                    struct SearchLink *r = malloc(sizeof(struct SearchLink));
                    r->x = cX - 1;
                    r->y = cY;
                    r->next = NULL;
                    q->next = r;
                    q = q->next;
                }
            }

            // 右
            if (cY + 1 < m) {
                if (table[cX][cY + 1] == '*') {
                    num++;
                    table[cX][cY + 1] = '2';
                }
                if (table[cX][cY + 1] == '.') {
                    table[cX][cY + 1] = '1';
                    struct SearchLink *r = malloc(sizeof(struct SearchLink));
                    r->x = cX;
                    r->y = cY + 1;
                    r->next = NULL;
                    q->next = r;
                    q = q->next;
                }
            }
            // 下
            if (cX + 1 < n) {
                if (table[cX + 1][cY] == '*') {
                    num++;
                    table[cX + 1][cY] = '2';
                }
                if (table[cX + 1][cY] == '.') {
                    table[cX + 1][cY] = '1';
                    struct SearchLink *r = malloc(sizeof(struct SearchLink));
                    r->x = cX + 1;
                    r->y = cY;
                    r->next = NULL;
                    q->next = r;
                    q = q->next;
                }
            }
            // 左
            if (cY - 1 >= 0) {
                if (table[cX][cY - 1] == '*') {
                    num++;
                    table[cX][cY - 1] = '2';
                }
                if (table[cX][cY - 1] == '.') {
                    table[cX][cY - 1] = '1';
                    struct SearchLink *r = malloc(sizeof(struct SearchLink));
                    r->x = cX;
                    r->y = cY - 1;
                    r->next = NULL;
                    q->next = r;
                    q = q->next;
                }
            }
            struct SearchLink *tmp = p;
            p = p->next;
            free(tmp);
        } while (p != NULL);
        printf("Case #%d: %d\n", i + 1, num);
    }
    return 0;
}