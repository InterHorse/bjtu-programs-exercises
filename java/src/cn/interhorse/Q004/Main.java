package cn.interhorse.Q004;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-12
 * <p>
 * <p>
 * 连续数的和
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 对于一个给定的正整数 n ，请你找出一共有多少种方式使 n 表示为若干个连续正整数的和，要求至少包括两个正整数。如 n=15 时，可以有 3 种方式：（ 1+2+3+4+5 ），（ 4+5+6 ），（ 7+8 ）。
 * <p>
 * 输入数据
 * 输入数据第一行为一个正整数 T ，表示测试数据的组数。 随后的 T 行中，每行包括一组测试数据，为一个整数 n（1≤T≤1000,n≤10^9）。
 * <p>
 * 输出数据
 * 对每一组输入数据，输出一行结果 ”Case #id: M” ，表示第 id 组数据的结果是 M ， id 从 1 开始。
 * <p>
 * 样例输入
 * 2
 * 3
 * 15
 * <p>
 * 样例输出
 * Case #1: 1
 * Case #2: 3
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 循环次数
        int loops = 0;
        if (cin.hasNextInt()) {
            loops = cin.nextInt();
        }
        for (int i = 0; i < loops; i++) {
            // 接收 n
            int n = cin.nextInt();
            // 记录符合条件的方式数
            int nums = 0;
            // x + (x + 1) + (x + 2) + ... = n
            // x = n / a - (a - 1) / 2
            // a 最大为 n / 2 + 1
            // 从 a = 2 开始穷举
            int maxNum = n / 2 + 1;
            for (int j = 2; j <= maxNum; j++) {
                int x = n / j - (j - 1) / 2;
                // 如果 x 已经开始 <= 0 了，不必再往下穷举了
                if (x <= 0) {
                    break;
                }
                // 回代验算，此处用求和公式
                int res = (x + x + j - 1) * j / 2;
                // 如果值相等，则方式数 +1
                if (res == n) {
                    nums++;
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + nums);
        }
    }
}
