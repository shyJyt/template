int n, m, dis[MAXN], vis[MAXN], cnt[MAXN];
vector<pair<int, int>> g[MAXN];


// 队列优化的 Bellman-Ford 算法
// 负权边最短路，也可以判断源点能否到负环，注意是源点能否到而不是图上是否存在
bool spfa(int s) {
	memset(dis, 0x3f, sizeof(int) * (n + 10));
	dis[s] = 0, vis[s] = 1;
	
    // 只有上一次被松弛的结点，所连接的边，才有可能引起下一次的松弛操作
    // 用队列来维护「哪些结点可能会引起松弛操作」
	queue<int> qq;
	qq.push(s);
	
	while(!qq.empty()) {
		int u = qq.front();
		qq.pop();
        // 允许重复入队
		vis[u] = 0;
		for(auto tmp : g[u]) {
			int v = tmp.first, w = tmp.second;
			if(dis[v] < dis[u] + w) {
				dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                // 在不经过负环的情况下，最短路至多经过 n - 1 条边
                // 因此如果经过了多于 n 条边，一定说明经过了负环
                if (cnt[v] >= n) return false;

				if(!vis[v]) {
					qq.push(v);
					vis[v] = 1;
				}
			}
		}
	}

	return true; 
}
