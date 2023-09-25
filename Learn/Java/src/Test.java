public class Test {
    public static void main(String[] args) {
        int a = 0;
        int b = 0;
        for (int i = 1; i <= 5; i++) {
            a = i % 2;
            while (a-- >= 0) {
                b++;
            }
        }
        System.out.println("b = " + b);
        System.out.println("a = " + a);
    }
}
