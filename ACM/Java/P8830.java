/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2024-03-20 20:30:53
 * @LastEditTime: 2024-04-05 21:15:17
 * @FilePath: /Java/P8830.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
 */
import java.io.*;
import java.util.Scanner;
import java.util.LinkedList;

public class P8830 {

    public static void main(String[] args) throws IOException {
        Read sc = new Read();
        // Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = sc.nextInt();
        double ans = 0, temp, max = -1, min = 101;
        for (int i = 1; i <= n; i++) {
            temp = sc.nextDouble();
            max = Math.max(max, temp);
            min = Math.min(min, temp);
            ans += temp;
            if (i >= 3) {
                sb.append(String.format("%.2f\n", (ans - min - max) / (i - 2)));
            }
        }
        writer.println(sb.toString());
        writer.flush();
    }
    /**
    * Read
    */
    static class Read { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        public String nextLine() throws IOException {
            return br.readLine();
        }
        public int nextInt() throws IOException {
            st.nextToken();
            return (int) st.nval;
        }
        public double nextDouble() throws IOException {
            st.nextToken();
            return st.nval;
        }
    }
}
