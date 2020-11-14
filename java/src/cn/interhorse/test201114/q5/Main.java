package cn.interhorse.test201114.q5;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 输入 n
        int t = cin.nextInt();
        for (int i = 0; i < t; i++) {
            // 年月日
            cin.nextInt();
            int month = cin.nextInt();
            int day = cin.nextInt();
            if ((month == 9 && day == 30) || (month == 11 && day == 30) || (month + day) % 2 == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
