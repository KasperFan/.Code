import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;

public class P4017 {

    public static void main(String[] args) throws Exception {
        
        // 数据量大小，考虑使用快读
        Read sc = new Read();
        int n = sc.nextInt(), m = sc.nextInt(), mod = 80112002, ans = 0;

        // 记录每种生物食谱
        LinkedList<LinkedList<Integer>> Edge = new LinkedList<LinkedList<Integer>>();
        // 记录每种生物的入度和出度
        int[] indegree = new int[n + 1];
        int[] outdegree = new int[n + 1];
        // 记录每种生物的食物链条数
        int[] dp = new int[n + 1];
        // 拓扑排序队列
        ArrayList<Integer> queue = new ArrayList<Integer>();

        // 初始化每种生物的食谱
        for (int i = 0; i <= m; i++) {
            Edge.add(new LinkedList<Integer>());
        }
        // 接收并处理生物间吃与被吃关系
        for (int i = 0; i < m; i++) {
            // 被吃的生物A和吃A的生物B
            int A = sc.nextInt(), B = sc.nextInt();
            // B的入度+1
            indegree[B]++;
            // A的出度+1
            outdegree[A]++;
            // 将A加入到B的食谱中
            Edge.get(B).add(A);
        }
        // 遍历找到最高级消费者
        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0) { // 如果找到了
                queue.add(i);// 将其加入到排序队列
                dp[i] = 1; // 因为是最高级消费者，必有一条最大食物链
            }
        }
        // 拓扑排序部分
        while (!queue.isEmpty()) { // 当排序数列内部不为空时
            int node = queue.remove(0); // 取出第一个动物的信息，记为node
            while (!Edge.get(node).isEmpty()) { // 当node的食谱不为空时
                int pre = Edge.get(node).removeFirst(); // 依次获取其食谱中的被捕食者
                dp[pre] += dp[node]; // 其被捕食者应与其共享所有链，故将其链数加到被捕食者链数记录中
                dp[pre] %= mod; // 避免结果过大，对mod求模
                outdegree[pre]--; // 该被捕食者与其捕食者关系结算完毕，将其之间出度关系抹去
                if (outdegree[pre] == 0) { // 如果结算完毕后该被捕食者出度也为0
                    queue.add(pre); // 则将其加入到排序队列
                }
            }
        }
        for (int i = 1; i <= n; i++) { // 寻找入度为0的生产者
            if (indegree[i] != 0) {
                continue;
            }
            // 如果找到，就将答案加上从生产者开始的所有链数
            ans += dp[i];
        }
        ans %= mod; // 取模避免超出范围
        System.out.println(ans); // 输出结果
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