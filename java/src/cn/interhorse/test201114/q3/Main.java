package cn.interhorse.test201114.q3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int length = cin.nextInt();
        String num = cin.next();
        int maxPrime = -1;
        for (int i = 0; i < length; i++) {
            for (int j = 1; j < 9; j++) {
                if ((i + j) <= length) {
                    String sonNum = num.substring(i, i + j);
                    if (isHorseRaceLampPrime(sonNum) && Integer.parseInt(sonNum) > maxPrime) {
                        maxPrime = Integer.parseInt(sonNum);
                    }
                }
            }
        }
        System.out.println(maxPrime);
    }

    // 判断跑马灯质数
    static boolean isHorseRaceLampPrime(String num) {
        if (!isPrime(Integer.parseInt(num))) {
            return false;
        }
        for (int i = 1; i < num.length(); i++) {
            String newNum = num.substring(i) + num.substring(0, i);
            if (!isPrime(Integer.parseInt(newNum))) {
                return false;
            }
        }
        return true;
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
