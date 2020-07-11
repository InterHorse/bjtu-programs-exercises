package cn.interhorse.Q002;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-11
 * <p>
 * 绕圆圈
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 小明报名参加了趣味运动会，运动会游戏规则如下：在一个环形跑道上，等距离放置着 N 个小球，小球按照顺时针方向从起点开始依次编号为 1 到 N ，在最短时间内取走放在跑道上尽可能多小球的选手获胜。举办方要求每个选手只能按照顺时针方向，跳过 M-1 个号码取后走下一个小球。如当 N=5 、 M=3 时，小明能够取走所有的小球，取走的顺序依次为 1->4->2->5->3 。当 N=6 、 M=2 时，小明只能取走 3 个小球 1->3->5 。小明想知道在一场比赛中他最多能取走多少小球，当然，小明是知道怎么做的，但是他忙着补作业，所以这个简单的问题就交 (shuai guo) 给你了。
 * <p>
 * 输入数据
 * 输入数据的第一行为一个整数 T ，表示有 T 组测试样例。每组样例为单独的一行，包括两个整数 N 和 M 。
 * <p>
 * 输出数据
 * 对每一组输入数据，输出一行结果 ”Case #id: M” ，表示第 id 组数据的结果是 M ， id 从 1 开始。
 * <p>
 * 样例输入
 * 3
 * 5 3
 * 6 2
 * 10 6
 * <p>
 * 样例输出
 * Case #1: 5
 * Case #2: 3
 * Case #3: 5
 * <p>
 * 时间限制 1秒
 * 内存限制 64MB
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
            // 接收 n 和 m
            int n = cin.nextInt();
            int m = cin.nextInt();
            // 小球个数
            int nums = 0;
            if (n == 0) {
                continue;
            }

            // 初始化取走小球个数，至少为 1
            nums = 1;
            // 取模计算，回到原点则跳出
            int index = (1 + m) % n;
            while (index != 1) {
                nums++;
                index = (index + m) % n;
            }
            System.out.println("Case #" + (i + 1) + ": " + nums);
        }
    }
}
