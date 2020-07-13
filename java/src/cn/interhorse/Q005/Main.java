package cn.interhorse.Q005;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-13
 * <p>
 * <p>
 * 魔法
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 魔法部急缺一批魔法师，于是他们急急忙忙新招聘了一批魔法师，应聘魔法师在他们上交的简历里写了各自的学历。学历仅包括初级魔法、中级魔法和高级魔法三门课程的成绩情况，用百分制表达。如果一位魔法师在某门课程上及格 (>=60 分 ) 的话，他就能得到相应的职称并担任对应的职业。当然，有高级职称的人可以担任低级职业。由于交上来的简历太多了，魔法部的负责人找到了你，想让你帮忙计算，能担任初级、中级、高级魔法师的人分别有多少人 ?
 * <p>
 * 输入数据
 * 输入数据第一行为一个正整数 T ，表示测试数据的组数。 接下来是 T 组测试数据，每组测试数据的第一行为一个整数 n ，表示简历份数，随后的 n 行中，每行以低级、中级、高级的顺序表示三门课的成绩（ 1≤T≤100 ， 1≤n≤1000 ， 0≤ 成绩 ≤100 ）。
 * <p>
 * 输出数据
 * 对于每一组输入数据，输出一行形如 ”Case #id: a b c” 的结果 , 表示第 id 组数据结果是 a,b,c ， id 从 1 开始， a,b,c 表示三种人的数量。
 * <p>
 * 样例输入
 * 2
 * 3
 * 12 23 99
 * 66 66 77
 * 99 88 23
 * 2
 * 100 100 100
 * 100 100 100
 * <p>
 * 样例输出
 * Case #1: 3 3 2
 * Case #2: 2 2 2
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 循环次数
        int t = 0;
        if (cin.hasNextInt()) {
            t = cin.nextInt();
        }
        for (int i = 0; i < t; i++) {
            // 低、中、高人数
            int lowNum = 0;
            int mediumNum = 0;
            int highNum = 0;
            // 接收 n
            int n = cin.nextInt();
            for (int j = 0; j < n; j++) {
                // 接受分数
                int lowScore;
                int mediumScore;
                int highScore;

                lowScore = cin.nextInt();
                mediumScore = cin.nextInt();
                highScore = cin.nextInt();
                if (highScore >= 60) {
                    lowNum++;
                    mediumNum++;
                    highNum++;
                    continue;
                }
                if (mediumScore >= 60) {
                    lowNum++;
                    mediumNum++;
                    continue;
                }
                if (lowScore >= 60) {
                    lowNum++;
                }
            }
            System.out.println(String.format("Case #%d: %d %d %d", i + 1, lowNum, mediumNum, highNum));
        }
    }
}
