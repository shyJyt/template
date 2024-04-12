// vis 用来判断左部点是否在本次dfs中被访问过
int match[MAXN], vis[MAXN];

bool dfs(int u, int tag) {
    if (vis[u] == tag)
        return false;
    vis[u] = tag;

    for (int v : edge[u]) {
        // 目标尚未匹配或者已匹配的左部点换人成功
        if ((match[v] == 0) || dfs(match[v], tag)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dfs(i, i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}