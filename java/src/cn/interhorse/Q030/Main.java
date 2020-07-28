package cn.interhorse.Q030;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-28
 * <p>
 * <p>
 * A Simple Problem
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 求 0~n 中有多少个整数 k 满足 (2 * k) XOR (3 * k) == k, 其中 XOR 为异或操作。
 * <p>
 * 输入数据
 * 输入数据的第一行为一个正整数 T(T<=30) ，表示测试数据的组数。
 * <p>
 * 接下来的 T 行中，每行为一组测试数据，包含一个正整数 n(n<=1000000000) 。
 * <p>
 * 输出数据
 * 对每一组输入数据，输出一行结果 ”Case #id: M” ，表示第 id 组数据的结果是 M ， id 从 1 开始。
 * <p>
 * 样例输入
 * 5
 * 0
 * 1
 * 2
 * 3
 * 4
 * <p>
 * 样例输出
 * Case #1: 1
 * Case #2: 2
 * Case #3: 3
 * Case #4: 3
 * Case #5: 4
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 *
 * 参考：http://www.voidcn.com/article/p-gwehpiqp-bqd.html
 */
public class Main {
    public static void main(String[] args) {
        int[][] baseTable = new int[51][2];
        baseTable[0][0] = 1;
        baseTable[1][0] = 1;
        baseTable[1][1] = 1;
        for (int i = 1; i < 50; i++) {
            baseTable[i + 1][1] += baseTable[i][0];
            baseTable[i + 1][0] += baseTable[i][1] + baseTable[i][0];
        }

        // t, n
        int t, n;
        int res, tmp;
        int index;
        int[] recordArr = new int[40];

        Scanner cin = new Scanner(System.in);
        t = cin.nextInt();
        for (int i = 0; i < t; i++) {
            n = cin.nextInt() + 1;
            index = 0;
            while (n != 0) {
                recordArr[index++] = n % 2;
                n /= 2;
            }
            res = 0;
            tmp = -1;
            while (index != 0) {
                int x = recordArr[--index];
                if (x == 1) {
                    res += baseTable[index][0] + baseTable[index][1];
                    if (tmp == 1) {
                        break;
                    }
                }
                tmp = x;
            }
            System.out.println(String.format("Case #%d: %d", i + 1, res));
        }
    }
}
