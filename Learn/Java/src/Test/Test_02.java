package src.Test;

import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

public class Test_02 {
    public static void main(String[] args) {
        System.out.println();
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
