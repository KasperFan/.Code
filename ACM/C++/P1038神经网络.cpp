#include <iostream> // io流头文件
#include <cstring>  // 字符串头文件
#include <queue>    // 队列头文件

using namespace std;

// 定义最大节点数
const int N = 110;
// 定义最大边数
const int M = N * N;
/*
 * 模拟链表，使用h[N] -> ne[h[N]] ->...-> ne[edge_n] -> -1 来记录点 n 的每一条出边
 * 使用e[edge_1] ... e[edge_n] 记录每一条边到达的出点
 * 使用w[edge_1] ... w[edge_n] 记录每一条边的权值W
 */
int h[N], e[M], w[M], ne[M], idx;
// 记录每一条边对应的C_i值、U_i值；每一个节点的入度和出度
int c[N], u[N], in[N], out[N];

// 拓扑排序队列
queue<int> q;

// 边的添加函数
void add(int a, int b, int c)
{
    /*
    将边 idx 的出点 b 赋给 e[idx]
    将边 idx 的边权值 W 赋给 w[idx]
    将边 idx 插入到记录点 a 出边的模拟链表 h 的头部
    */
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

// 初始化函数，将数组h初始化为-1
void init()
{
    // 将整个h数组中的每一个元素都初始化为 -1
    memset(h, -1, sizeof(h));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> u[i];
    }
    while (p--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        out[a]++;
        in[b]++;
    }
    // 遍历所有节点，找到入度为0的输入层节点将其置入队列
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
            /*
             * 由于输入层本身C_i值可向后传导为下一节点的C_j，
             * 故不作处理，将其置入队列
             */
            q.push(i);
        else
            // 非输入层有U_i限制，故先计算U_i的影响
            c[i] -= u[i];
    }
    while (!q.empty())
    {
        int j = q.front(); q.pop(); // 将队列头部节点取出给 j
        /*
         * 遍历节点 j 的每一条出边，记为 k
         * 对有符号整型 1111(-1) 按位取反(~)得 0000(0) 使条件不成立, 等价于 k != -1
         */
        for (int k = h[j]; ~k; k = ne[k])
        {
            // 将出边 i 的对应出点记为 k，对应的边权值记为 cc
            int i = e[k], cc = w[k];
            if (c[j] >= 0) // 如果当前节点有兴奋可传导
                /*
                 * 将其状态值C_i传导至该边出点，作为该出点的C_j值，
                 * 并根据该边的权值将兴奋状态叠加在该点上
                 */
                c[i] += cc * c[j];
            in[i]--;       // 将该边出点关于该出边的入度结算
            if (!in[i])    // 如果该点入度已结算完毕
                q.push(i); // 将该点置入队列，等待结算该点与其出点情况
        }
    }
    bool has = false;            // 是否有活跃输出层节点记录变量，初始化为否，
    for (int i = 1; i <= n; i++) // 遍历所有节点，寻找输出层节点
    {
        if (!out[i]) // 如果找到输出层节点
        {
            if (c[i] > 0) // 如果该节点兴奋
            {
                // printf("%d %d\n", i, c[i]);
                cout << i << " " << c[i] << endl; // 输出该点状态
                has = true;                       // 存在兴奋输出层节点，将记录更新
            }
        }
    }
    if (!has)                   // 如果最后没有输出层活跃节点
        // puts("NULL");        // puts是字符串函数，需要使用字符串库
        cout << "NULL" << endl; // 输出 NULL 作为答案
    return 0;
}