/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2024-03-19 20:01:32
 * @LastEditTime: 2024-03-19 20:18:04
 * @FilePath: /Java/P4305.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
 */

import java.io.*;
import java.util.LinkedHashSet;
import java.util.Set;

public class P4305 {
    public static void main(String[] args) throws Exception {
        Read sc = new Read();
        PrintWriter p = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        Set<Integer> set = new LinkedHashSet<>();
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            while (n-- > 0) {
                set.add(sc.nextInt());
            }
            for (int integer : set.toArray(new Integer[0])) {
                p.print(integer + " ");
            }
            p.println();
            set.clear();
        }
        p.flush();
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
}
