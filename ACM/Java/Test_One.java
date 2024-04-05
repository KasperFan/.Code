/*
Name    :   P1605迷宫.java
Time    :   2023/02/21 22:11:27
Author  :   Kasper Fan
Group   :   Weifang University
Contact :   fanwlx@foxmail.com
Desc    :   This file is created for learning Java coding
*/

// package 作业.dfs;

import java.io.*;

public class Test_One {
    static int n, low, mid, high;
    static Read sc = new Read();

    public static void main(String[] args) throws Exception {
        n = sc.nextInt();
        if (n == 1) {System.out.println(n); return;}
        high = n;
        while (low < high) {
            mid = (low + high) / 2;
            if (len(mid) < n) low = mid + 1;
            else high = mid;
        }
        System.out.println(low);
    }
    
    public static int len(int x) {
        return (int) (x * Math.log10(x) + 1);
    }

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
}