package cn.interhorse.Q006;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-13
 * <p>
 * <p>
 * calfcamel的2333
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 为祝贺新一批的研究生入学，队长让大家为新人命题训练其程序设计能力。有人问队长能不能黑，队长说可以黑但是不能黑那啥。大家很失望 2333 ，于是 calfcamel 决定出一道 2333 的题目。
 * <p>
 * 给你一个小于 60 位的整数 p ，求大于 p 的最小的数 p1 ，使得 p1 中包含数 2333 。
 * <p>
 * 输入数据
 * 输入数据的第一行为一个正整数 T ，表示有 T 组数据。随后的 T 行中每行包括一个小于 60 位的整数 p （ T <= 50 ， 1 <= p <10^60 ，即 10 的 60 次方）。
 * <p>
 * 输出数据
 * 对每组输入数据单独输出一行结果，第 x 行结果形如 ”Case #x: a“ ，其中 x 为组号，从 1 开始， a 为对应的结果。
 * <p>
 * 样例输入
 * 2
 * 100
 * 1000000000000
 * <p>
 * 样例输出
 * Case #1: 2333
 * Case #2: 1000000002333
 * <p>
 * 时间限制: 1 s
 * 内存限制: 128 MB
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 循环次数
        int t;
        t = cin.nextInt();
        for (int i = 0; i < t; i++) {
            // p
            StringBuilder p = new StringBuilder(cin.next());
            for (; ; ) {
                // 执行 +1 操作
                inc(p, p.length() - 1);
                if (p.toString().contains("2333")) {
                    // 如果字符串中包含 2333，则输出
                    System.out.println(String.format("Case #%d: %s", i + 1, p.toString()));
                    break;
                }
            }

        }
    }

    /**
     * 字符串 p 在 q 位 +1
     *
     * @param p
     * @param q
     * @return
     */
    private static void inc(StringBuilder p, int q) {
        if (q < 0) {
            // 如果索引 q 小于 0，说明位数不够了，需要在前面加 1，并直接返回
            p.insert(0, "1");
            return;
        }
        // 尾数 + 1
        int num = Integer.parseInt(String.valueOf(p.charAt(q)));
        if (num + 1 < 10) {
            // 如果尾数小于 10，则在该位 +1
            p.setCharAt(q, String.valueOf(num + 1).charAt(0));
        } else {
            // 如果尾数大于 10，则该位置为 0，并在前一位执行 +1 操作
            p.setCharAt(q, '0');
            q--;
            inc(p, q);
        }
    }
}
