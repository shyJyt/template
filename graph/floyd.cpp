// 求任意两点间最短路
// 适用于任何图，前提最短路存在，也就是无负环
// 动态规划，压缩掉了第一维，也就是只考虑前 k 个节点进行松弛

// 枚举中间点
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] > dis[i][k] + dis[k][j])
                dis[i][j] = dis[i][k] + dis[k][j];
        }
    }
}