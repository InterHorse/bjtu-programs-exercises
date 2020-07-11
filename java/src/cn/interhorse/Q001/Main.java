package cn.interhorse.Q001;

import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-11
 * <p>
 * A+B 示例
 * 时间限制: 1秒  内存限制: 无限制
 * 题面描述：
 * 给定两个整数 a 和 b ，计算它们的和 a + b
 * <p>
 * 输入：
 * 输入包含多组测试数据，每一行包含两个整数 a 和 b，如：
 * 5 12
 * <p>
 * 输出：
 * 控制台输出，对每行输入，在一行中输出 a + b 的和（请注意换行）。如：
 * <p>
 * 17
 * <p>
 * 示例输入：
 * 25 33
 * <p>
 * 示例输出：
 * 58
 * <p>
 * 提示：
 * <p>
 * C/C++程序请包含所需的头文件，请注意使用MS Visual Studio环境时，不要包含stdafx.h。C/C++测试编译环境为gcc/g++
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long a, b;
        while (cin.hasNextInt()) {
            a = cin.nextInt();
            b = cin.nextInt();
            System.out.println(a + b);
        }
    }
}
