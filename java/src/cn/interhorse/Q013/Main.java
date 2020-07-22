package cn.interhorse.Q013;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Inter Horse
 * @date 2020-07-22
 * <p>
 * <p>
 * 找区间
 * 成绩: 5 / 折扣: 0.8
 * 题面描述
 * 给定n个数 a1,…,an，高老师想了解al,…,ar中有多少对相邻元素值相同。高老师把这个数目定义为区间[l,r]的价值，用v[l,r]表示。例如 1,1,1,2,2 这五个数所组成的区间的价值为3。
 * <p>
 * 现在高老师想知道在所有的v[l,r] (1≤l≤r≤n)中，第k小的值是多少。但高老师要和女朋友出去玩，于是他把这个问题甩给了你，请你帮他解决一下。
 * <p>
 * 输入数据
 * 第一行有一个整数t(1≤t≤30)，表示有t组数据。
 * <p>
 * 对于每组数据：
 * <p>
 * 第一行有两个整数n,k (1≤n≤2000,1≤k≤n(n+1)/2)；
 * <p>
 * 第二行有n个整数a1,…,an (1≤ai≤109)。
 * <p>
 * 输出数据
 * 对于每组数据：
 * <p>
 * 输出一个整数，表示第 k小的值。
 * <p>
 * 样例输入
 * 2
 * 4 7
 * 1 1 2 3
 * 3 5
 * 100 100 100
 * <p>
 * 样例输出
 * 0
 * 1
 * <p>
 * 时间限制: 1 s
 * 内存限制: 无限制
 */
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        // t,n,k
        int t, n, k;
        t = cin.nextInt();
        for (int i = 0; i < t; i++) {
            n = cin.nextInt();
            k = cin.nextInt();
            int arr[] = new int[n];
            arr[0] = cin.nextInt();
            List<Integer> numList = new ArrayList<>(16);
            for (int j = 1; j < n; j++) {
                arr[j] = cin.nextInt();
                if (arr[j] == arr[j - 1]) {
                    numList.add(1);
                } else {
                    numList.add(0);
                }
            }
            numList.add(0);
            int lt = 0;
            int rt = n - 1;
            while (lt < rt) {
                int mid = (lt + rt) / 2;
                if (getRangeN(mid, numList, n) >= k) {
                    rt = mid;
                } else {
                    lt = mid + 1;
                }
            }
            // 输出
            System.out.println(String.format("%d", lt));
        }
    }

    private static int getRangeN(int mid, List<Integer> numList, int n) {
        int num = 0;
        int index = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            while (index < n) {
                if (sum <= mid) {
                    sum += numList.get(index);
                    index++;
                } else {
                    break;
                }
            }
            sum -= numList.get(i);
            num += index - i;
        }
        return num;
    }
}
