/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2024-01-18 10:39:21
 * @LastEditTime: 2024-01-18 23:56:50
 * @FilePath: /Java/Problem221030PG05.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved.
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Problem221030PG05 {
    static FastRead sc = new FastRead(); // 快读
    static Queue<Integer> q = new LinkedList<>(); // 拓扑排序队列
    static ArrayList<ArrayList<Integer>> edge = new ArrayList<>(1010 * 1010); // 第一维用于存储所有的信息，第二维用于存储每个点的去点
    static int[][] graph = new int[1010][1010], // 图矩阵
            indegree = new int[1010][1010], // 每个点的入度
            outdegree = new int[1010][1010]; // 每个点的出度
    static int N, M; // 矩阵的行列数
    static int[] dx = {-1, +1, 0, 0}, // 四个方向的行偏移量
            dy = {0, 0, -1, +1}; // 四个方向的列偏移量

    public static void main(String[] args) {
        N = sc.nextInt(); // 输入矩阵的行数
        M = sc.nextInt(); // 输入矩阵的列数
        // 输入矩阵的内容
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) { // 遍历图上的每一个点(x, y)
                // 由于每个点最多只有4个邻结点，故针对每个点对应一个4长度的动态数组ArrayList
                edge.add(new ArrayList<>(4));
                for (int i = 0; i < 4; i++) { // 枚举4个方向，找可能相邻点
                    int nx = x + dx[i], ny = y + dy[i]; // 新点坐标(nx, ny)
                    // 如果新点坐标不符合条件且邻接新点坐标处的值不小于当前点值，跳过
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] >= graph[x][y]) continue;
                    // 如果符合条件，则处理两点间关系
                    add(x, y, nx, ny);
                }
            }
        }

        System.out.println(topoSort()); // 将拓扑排序的结果输出
    }

    public static void add(int x, int y, int nx, int ny) {
        indegree[nx][ny]++; // 邻接点入度+1
        outdegree[x][y]++; // 中心点出度+1
        edge.get(x * M + y).add(nx * M + ny); // 将该邻接点坐标信息一维化后放入中心点数组中。
    }

    public static int topoSort() {
        // 遍历全图，将所有入度为0的起始点置入队列。
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (indegree[x][y] == 0) {
                    q.add(x * M + y);
                }
            }
        }

        int step = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            // 取出所有某一阶段点，计算并处理其下一点关系
            for (int i = 0; i < size; i++) {
                int temp = q.poll();
                int nodeX = temp / M, nodeY = temp % M;
                // 遍历其所有可行邻接点，结算下一点入度关系
                for (int j : edge.get(nodeX * M + nodeY)) {
                    indegree[j / M][j % M]--;
                    // 若出现某点的入度关系为0，将其置入拓扑排序队列
                    if (indegree[j / M][j % M] == 0) q.add(j);
                }
            }
            // 处理完某一阶段点后，距离数+1
            step++;
        }
        return step; // 处理完所有路径后返回路径（此时为最长）
    }

    // 快读部分
    static class FastRead {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static StreamTokenizer st = new StreamTokenizer(br);

        public int nextInt() {
            try {
                st.nextToken();
            } catch (Exception e) {
                // TODO: handle exception
            }
            return (int) st.nval;
        }
    }
}
