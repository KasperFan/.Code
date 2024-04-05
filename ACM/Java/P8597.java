
/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2024-03-05 20:26:31
 * @LastEditTime: 2024-03-09 11:32:54
 * @FilePath: /Java/P8597.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
 */
import java.util.Scanner;

public class P8597 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String give, ans;
        int sum = 0, p = 0;
        give = sc.nextLine().strip();
        ans = sc.nextLine().strip();
        int l = give.length();
        StringBuilder sb = new StringBuilder(give);
        while (p < l) {
            if (sb.charAt(p) != ans.charAt(p)) {
                if (sb.charAt(p) == 'o') {
                    sb.replace(p, p + 1, "*");
                } else if (sb.charAt(p) == '*') {
                    sb.replace(p, p + 1, "o");
                }
                if (sb.charAt(p+1) == 'o') {
                    sb.replace(p+1, p + 2, "*");
                } else if (sb.charAt(p+1) == '*') {
                    sb.replace(p+1, p + 2, "o");
                }
                sum++;
            }
            p++;
        }
        System.out.println(sum);
        sc.close();
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