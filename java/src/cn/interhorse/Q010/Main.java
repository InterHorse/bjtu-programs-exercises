package cn.interhorse.Q010;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-15
 * <p>
 * <p>
 * Infinity的棋盘密码
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * Infinity 解决 HG 大学的难题后，又来到了附近的 ZF 大学，这次他得到了三页纸的题目。
 * <p>
 * Infinity 迅速注意到了一个简短的密码。
 * <p>
 * 13 34 21 21 15 15
 * <p>
 * “每个数字都是 1 到 5 之间，两位一组，这很有可能是棋盘密码！”
 * <p>
 * Infinity 迅速画出了一张表格：
 * <p>
 * “对于每组的两个数字，第一个数字表示行数，第二个数字表示列数，可以对应出一个字母，比如 13 就是第一行第三列的 C 。”
 * <p>
 * “为什么 I 和 J 放在一格？”在一旁的小明问道。
 * <p>
 * “ 5*5 的格子放 26 个字母，肯定有一个字母放不下。棋盘密码设计之初，就把 I 和 J 放在了一格。要是碰到 24 ，我们只能通过上下文判断是 I 还是 J 了。 C…O…F…F…E…E, COFFEE ！快去问问 ZF 大学的咖啡厅在哪！”
 * <p>
 * 现在给你一些数字，请你用 Infinity 说的棋盘密码解开谜题。
 * <p>
 * 由于 I 比 J 常见，所以遇到 24 请一律按 I 处理。
 * <p>
 * 输入数据
 * 输入第一行是一个整数 n (1 <= n <= 100) ，表示数据的组数。
 * <p>
 * 接下来 n 行，每行第一个数表示密码的长度 mi (1 <= mi <= 100) ，接下来是 mi 个两位整数，表示一段棋盘密码，保证密码中只出现数字 1~5 。
 * <p>
 * 输出数据
 * 对每组测试数据输出单独的一行结果，形如 ” Case #x: ans ” ，表示第 x 组的结果为 ans ， ans 为 一行大写字母，表示密码的答案，详见样例。
 * <p>
 * 样例输入
 * 3
 * 6 13 34 21 21 15 15
 * 8 24 33 21 24 33 24 44 54
 * 5 23 15 31 31 34
 * <p>
 * 样例输出
 * Case #1: COFFEE
 * Case #2: INFINITY
 * Case #3: HELLO
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 */
public class Main {
    // 初始化密码表
    private static String[][] table = new String[][]{
            {"A", "B", "C", "D", "E"},
            {"F", "G", "H", "I", "K"},
            {"L", "M", "N", "O", "P"},
            {"Q", "R", "S", "T", "U"},
            {"V", "W", "X", "Y", "Z"}};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 循环 n
        int n = cin.nextInt();
        for (int i = 0; i < n; i++) {
            // 循环 m
            int m = cin.nextInt();
            int num;
            int x;
            int y;
            // 输出
            System.out.print(String.format("Case #%d: ", i + 1));
            for (int j = 0; j < m; j++) {
                num = cin.nextInt();
                String numStr = String.valueOf(num);
                x = Integer.parseInt(String.valueOf(numStr.charAt(0)));
                y = Integer.parseInt(String.valueOf(numStr.charAt(1)));
                System.out.print(String.format("%s", table[x - 1][y - 1]));
            }
            System.out.println();
        }
    }
}
