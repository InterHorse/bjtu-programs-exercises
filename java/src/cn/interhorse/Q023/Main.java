package cn.interhorse.Q023;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-18
 * <p>
 * <p>
 * Infinity的卡牌
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * Infinity 最近迷上了一款卡牌游戏。某天， Infinity 构建了一个卡组，卡组中所有不同的卡牌都有两张。然而 Infinity 在查看他的卡组的时候手一滑，不小心删掉了一张卡牌。 Infinity 很想知道少了哪张卡牌。
 * <p>
 * 由于 Infinity 的卡组实在是太大了，你能帮帮他吗？
 * <p>
 * 输入数据
 * 输入数据的第一行为一个整数 T(1 <= T <= 10) ，表示有 T 组测试数据。每组数据的第一行为一个整数 n(2 <= n <=100000) ， n 为偶数，表示一个卡组中卡牌的数量。接下来的一行有 n - 1 个整数，为剩余牌的编号，其中相同牌的编号相同，不同牌的编号不同。
 * <p>
 * 输出数据
 * 对于每组数据，在单独的一行中输出结果，为滑落牌的编号，格式见样例。
 * <p>
 * 样例输入
 * 2
 * 2
 * 1
 * 4
 * 1 1 2
 * <p>
 * 样例输出
 * Case #1: 1
 * Case #2: 2
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // t, n
        int t, n;
        t = cin.nextInt();
        int num;
        for (int i = 0; i < t; i++) {
            n = cin.nextInt();
            // 记录已出现的数字
            Map<Integer, Integer> numRecord = new HashMap<>(16);
            int indexArr[] = new int[n / 2];
            int index = 0;
            for (int j = 0; j < n - 1; j++) {
                num = cin.nextInt();
                if (numRecord.get(num) == null) {
                    indexArr[index++] = num;
                    numRecord.put(num, 1);
                } else {
                    numRecord.put(num, 2);
                }
            }
            for (int j = 0; j < n / 2; j++) {
                if (numRecord.get(indexArr[j]) == 1) {
                    System.out.println(String.format("Case #%d: %d", i + 1, indexArr[j]));
                }
            }
        }
    }
}
