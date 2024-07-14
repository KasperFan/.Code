import java.io.*;
import java.util.*;

public class Work4 {
    public static void main(String[] args) throws IOException {
        File file = new File("/Users/kasperfan/Desktop/.Code/Learn/Python/data.txt");
        int cnt = 0, max = 0, min = Integer.MAX_VALUE, ave = 0;
        ArrayList<String> grades = new ArrayList<>();
        ArrayList<Integer> AQIs = new ArrayList<>();
        try (Scanner sc = new Scanner(file)) {
            sc.nextLine();
            while (sc.hasNext()) {
                grades.add(sc.next());
                AQIs.add(sc.nextInt());
            }
        }
        for (int i = 0; i < grades.size(); i++) {
            if (grades.get(i).equals("优")) {
                cnt++;
            }
            ave += AQIs.get(i);
            max = max < AQIs.get(i) ? AQIs.get(i) : max;
            min = min > AQIs.get(i) ? AQIs.get(i) : min;
        }
        System.out.println("北京市8月份空气质量为“优”的天数比例为：" + cnt / gcd(cnt, grades.size()) + ":" + grades.size() / gcd(cnt, grades.size()));
        System.out.println("北京市8月份平均空气质量指数为：" + String.format("%d", (int) (1.0 * ave / grades.size())));
        System.out.println("北京市8月份空气质量指数最好值为：" + min);
        System.out.println("北京市8月份空气质量指数最差值为：" + max);
    }

    public static int gcd(int m, int n) {
        if (m % n == 0) {
            return n;
        } else return gcd(n, m % n);
    }
}
