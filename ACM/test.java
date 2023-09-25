import java.math.BigInteger;
import java.util.Scanner;

public class test {

    public static void main(String[] args) {
        String[] a = new String[]{"new String[4]","fjy","ftukvc"};
        int[][] arr = {};
        System.out.println(arr[0][0]);
        try (Scanner sc = new Scanner(System.in)) {
            BigInteger bi = new BigInteger(sc.nextLine(), 8);
            System.out.println(bi.toString(16));
        }
    }
}