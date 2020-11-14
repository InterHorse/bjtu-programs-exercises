package cn.interhorse.test201114.q2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 输入 n
        String n = cin.nextLine();
        System.out.println(cal(Long.parseLong(n)));
    }

    // 计算分裂 0 的个数
    private static long cal(long num) {
        if (num == 0) {
            return 1;
        } else if (num == 1) {
            return 0;
        } else if (num % 2 == 1) {
            // 如果是奇数
            return cal((num - 1) / 2) * 2;
        } else if (num % 2 == 0) {
            // 如果是偶数
            return cal(num / 2) * 2 + 1;
        } else {
            return 0;
        }
    }
}
