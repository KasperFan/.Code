import java.io.*;

public class Work5 {
    static int[][] yanghui = new int[11][11];
    static PrintWriter p = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.err)));

    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            yanghui[i][1] = 1;
            yanghui[i][i] = 1;
        }
        for (int i = 2; i <= 10; i++) {
            for (int j = 2; j <= i; j++) {
                yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
            }
        }
        for (int i = 1; i <= 10; i++) {
            for (int j = 10; j > i; j--) {
                p.print("\t");
            }
            for (int j = 1; j <= i; j++) {
                p.print(yanghui[i][j]+"\t\t");
            }
            p.println();
        }
        p.flush();
    }
}
