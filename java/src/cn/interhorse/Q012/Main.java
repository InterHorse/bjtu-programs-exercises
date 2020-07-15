package cn.interhorse.Q012;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-15
 * <p>
 * <p>
 * 找朋友
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * <p>
 * 找呀 找呀 找朋友
 * 找到一个好朋友
 * 敬个礼 握握手
 * 你是我的好朋友
 * <p>
 * 春天到了，大家都找自己的好朋友出去玩耍，然而大家都不甘示弱，要比比谁最先能找到自己的好朋友。
 * <p>
 * 给出一个 n × m 的地图，上面有 k 对好朋友，分别用 'a','A','b','B', … …表示。其中大写字母 'A' 和小写字母 'a' 是一对好朋友。
 * <p>
 * 小写字母在单位时间内可以向上、向下、向左或向右移动一格（可以穿过障碍物），大写字母不能移动。
 * <p>
 * 请问最快找到好朋友（对应的大写字母）的小写字母是谁？
 * <p>
 * 输入数据
 * <p>
 * 第一行有一个整数 t (1 ≤ t ≤ 100) ，表示有 t 组数据。
 * <p>
 * 对于每组数据：
 * <p>
 * 第一行有三个正整数 n , m, k (1 ≤ n,m ≤ 100, 1 ≤ k ≤ 26) ，表示地图的行数、列数和好朋友的对数；
 * <p>
 * 接下来有 n 行，每行有一个长为 m 的字符串，表示地图。 '.' 表示什么都没有，对应的大写字母和小写字母表示一对好朋友。
 * <p>
 * 输出数据
 * <p>
 * 输出 t 行，每行一个小写字母，表示最快找到好朋友的小写字母。
 * <p>
 * 如果有多个小写字母同时找到好朋友，则输出字典序最小的小写字母。
 * <p>
 * 样例输入
 * <p>
 * 3
 * 2 5 2
 * aBA..
 * ....b
 * 3 4 3
 * a..A
 * b.B.
 * c.C.
 * 4 4 2
 * b..A
 * .B..
 * ....
 * ...a
 * <p>
 * 样例输出
 * <p>
 * a
 * b
 * b
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 循环 t
        int t = cin.nextInt();
        // 三个数
        int n, m, k;
        for (int i = 0; i < t; i++) {
            n = cin.nextInt();
            m = cin.nextInt();
            k = cin.nextInt();
            // 最小距离的字母
            String res = null;
            // 最小距离，初始化为 0
            int distance = 0;
            // 存放位置表
            String[][] table = new String[n][m];
            // 记录同一字母第一次出现的位置，key 为小写字母，value 为坐标
            Map<String, int[]> record = new HashMap<>(k);
            for (int j = 0; j < n; j++) {
                // 输入的值转化为数组
                table[j] = cin.next().split("");
            }
            // 遍历位置表
            for (int j = 0; j < n; j++) {
                for (int h = 0; h < m; h++) {
                    // 字母作小写化
                    String letter = table[j][h].toLowerCase();
                    if (letter.equals(".")) {
                        continue;
                    }
                    if (record.get(letter) == null) {
                        // 如果该字母首次出现，则记录首次出现的坐标
                        record.put(letter, new int[]{j, h});
                    } else {
                        // 如果字母不是首次出现，则计算距离
                        int[] oldCo = record.get(letter);
                        int currentDis = Math.abs(j - oldCo[0]) + Math.abs(h - oldCo[1]);
                        if (distance == 0) {
                            // distance 为 0，说明 distance 尚未赋过值，本次为首次赋值
                            distance = currentDis;
                            res = letter;
                        } else {
                            // 判断距离
                            if (currentDis < distance) {
                                // 当前距离小于最小距离，则替换
                                distance = currentDis;
                                res = letter;
                            } else if (distance == currentDis) {
                                // 如果当前距离等于最小距离，判断当前字母顺序是否比目前最小距离字母还要小
                                if (letter.charAt(0) < res.charAt(0)) {
                                    res = letter;
                                }
                            }
                        }
                    }
                }
            }
            System.out.println(res);
        }
    }
}
