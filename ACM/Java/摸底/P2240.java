/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2024-02-07 11:22:25
 * @LastEditTime: 2024-02-07 12:15:52
 * @FilePath: /Java/摸底/P2240.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
 */
package 摸底;

import java.io.*;
import java.util.Arrays;

public class P2240 {
    static int N, T;
    static double ans;
    static int[] m = new int[100], v = new int[100];
    public static void main(String[] args) throws Exception {
        Read sc = new Read();
        N = sc.nextInt();
        T = sc.nextInt();
        CoinHeap[] coinHeaps = new CoinHeap[N];
        for (int i = 0; i < N; i++) {
            coinHeaps[i] = new CoinHeap(sc.nextInt(), sc.nextInt());
            // m[i] = sc.nextInt(); v[i] = sc.nextInt();
            // coinHeaps[i] = new CoinHeap(m[i], v[i]);
        }
        Arrays.sort(coinHeaps);
        for (int i = 0; i < coinHeaps.length; i++) {
            if (T >= coinHeaps[i].m) {
                ans += coinHeaps[i].v;
                T -= coinHeaps[i].m;
            } else if (T < coinHeaps[i].m) {
                ans += coinHeaps[i].p * T;
                T = 0;
                break;
            }
        }
        System.out.printf("%.2f\n", ans);
    }
    

    /**
    * Read
    */
    static class Read { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        public String nextLine() throws Exception {
            return br.readLine();
        }
        public int nextInt() throws Exception {
            st.nextToken();
            return (int) st.nval;
        }
        public double nextDouble() throws Exception {
            st.nextToken();
            return st.nval;
        }
    }

    /* 如何实现类对象间的排序 */
    static class CoinHeap implements Comparable<CoinHeap> { // 金币堆(比较的实现：实现“可比较的”接口)

        public int m, v; // 金币堆的重量m 和 金币堆的总价值v
        public double p; // 单位重量的价值p

        public CoinHeap(int m, int v) {
            this.m = m;
            this.v = v;
            this.p = v * 1.0 / m;
        }

        @Override // 方法重写
        public int compareTo(CoinHeap o) {
            if (this.p < o.p)
                return 1;
            else if (this.p > o.p)
                return -1;
            else
                return 0;
        }

        @Override
        public String toString() {
            return "CoinHeap [m=" + m + ", v=" + v + ", p=" + p + "]";
        }
    }
}