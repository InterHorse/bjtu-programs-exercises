package cn.interhorse.test201114.q4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // 输入 n
        int t = cin.nextInt();
        for (int i = 0; i < t; i++) {
            int n = cin.nextInt();
            System.out.println(isRSA(n) ? "YES" : "NO");
        }
    }

    // 判断是不是符合 RSA 安全
    private static boolean isRSA(int num) {
        for (int i = 2; i <= (num / i); i++) {
            if (isPrime(i) && (num % i == 0) && isPrime(num / i)) {
                return true;
            }

        }
        return false;
    }

    // 判断素数
    private static boolean isPrime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
