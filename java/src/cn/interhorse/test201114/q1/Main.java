package cn.interhorse.test201114.q1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 输入 n
        int n = cin.nextInt();
        System.out.println(cal(n) + 1);
    }

    // 计算索引
    private static int cal(int num) {
        if (num >= 2) {
            int tmp = cal(num / 2);
            return 2 * tmp + (num % 2 + tmp % 2) % 2;
        } else {
            return num;
        }
    }
}
