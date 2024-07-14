import java.util.Scanner;

public class Fibonacci {
    static int[] fi = new int[31];

    static int fib(int a) {
        if (fi[a] != 0) return fi[a];
        else {
            fi[a] = fib(a - 1) + fib(a - 2);
            return fi[a];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        fi[1] = fi[2] = 1;
        int n = sc.nextInt();
        while (n-- != 0) {
            int a = sc.nextInt();
            if (fi[a] != 0) {
                System.out.println(fi[a]);
            } else {
                for (int i = 1; i <= a; i++) {
                    if (fi[i] != 0) continue;
                    fi[i] = fi[i - 1] + fi[i - 2];
                }
                System.out.println(fi[a]);
            }
        }
    }
}
