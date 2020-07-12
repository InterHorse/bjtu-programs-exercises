package cn.interhorse.Q003;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-12
 * <p>
 * <p>
 * 互素
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 小明很喜欢学数学，并且喜欢做一些奇怪的题，这天他想知道对于给定的 N ，有多少个 M 满足“ M<=N, gcd(N,M)==1, M 是偶数”。请你编写程序帮助小明解决这个问题。
 * <p>
 * 输入数据
 * 输入数据第一行为一个正整数 T ，表示测试数据的组数。 接下来的 T 组测试数据中， 每组测试数据为一行，包含一个整数 N （1≤T≤100， 1≤N≤10000 ）。
 * <p>
 * 输出数据
 * 对于每一组输入数据，在单独的一行中输出 ”Case #id: M”, 表示第 id 组数据结果是 M ， id 从 1 开始；
 * <p>
 * 样例输入
 * 4
 * 1
 * 2
 * 11
 * 23
 * <p>
 * 样例输出
 * Case #1: 0
 * Case #2: 0
 * Case #3: 5
 * Case #4: 11
 * <p>
 * Hint:
 * gcd(a,b)==1 表示 a 与 b 的最大公约数为 1 ，即 a 与 b 互素。
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
            int nums = 0;
            // 直接从 2 开始，以步长为 2 循环
            if (n > 1) {
                for (int j = 2; j <= n; j = j + 2) {
                    int gcd = gcd(j, n);
                    if (gcd == 1) {
                        nums++;
                    }
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + nums);
        }
    }

    /**
     * 求最大公约数 - 辗转相除法（欧几里得算法）
     *
     * @param num1
     * @param num2
     * @return
     */
    public static int gcd(int num1, int num2) {
        // 先求余数，假定第一个数较大；如果第二个较大，在第二轮调用时会颠倒过来
        int remainder = num1 % num2;
        // 如果为 0，则直接得出
        if (remainder == 0) {
            return num2;
        }
        // 递归调用
        return gcd(num2, remainder);
    }
}
