import java.io.*;

public class Work3 {
    static int heads = 35;
    static int foot = 94;
    static int chicken, rabbit;

    /**
     * 求鸡兔同笼问题，设鸡为chicken，兔为rabbit<br>
     * 易得等量条件：
     * <blockquote><pre>{@code
     * chicken + rabbit = heads
     * chicken * 2 + rabbit * 4 = foot
     * }</pre></blockquote>
     * 即可由上述条件得：
     * <blockquote><pre>{@code
     * chicken + rabbit = heads
     * => rabbit = heads - chicken
     * chicken * 2 + rabbit * 4 = foot
     * => chicken * 2 + (heads - chicken) * 4 = foot
     * => heads * 4 - chicken * 2 = foot
     * => chicken = (heads * 4 - foot) / 2
     * }</pre></blockquote>
     * 故而求得鸡、兔数量
     */
    public static void getAnswer() {
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)))) {
            int chicken = (heads * 4 - foot) / 2;
            int rabbit = heads - chicken;
            writer.println("chicken = " + chicken);
            writer.println("rabbit = " + rabbit);
            writer.flush();
        }
    }

    /**
     * 题目要求方法:纯粹的暴力枚举（选择、循环结构）
     */
    public static void getAnswer(String str) {
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)))) {
            for (rabbit = 0; rabbit < heads; rabbit++) {
                if ((chicken = heads - rabbit) * 2 + rabbit * 4 == foot) {
                    break;
                }
            }
            writer.println("chicken = " + chicken);
            writer.println("rabbit = " + rabbit);
            writer.flush();
        }
    }

    public static void main(String[] args) {
        getAnswer("force");
    }
}
