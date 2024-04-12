#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <climits>
#include <bitset>
#define mt make_tuple
#define ll long long
#define ull unsigned long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
int n, m, s;

// 链式前向星存图
struct edge {
    int v, nx;
    ll w;
} e[MAXM];
int head[MAXN], cnte;

void add(int u, int v, ll w) {
    e[++cnte] = {v, head[u], w};
    head[u] = cnte;
}

// dij，适用于非负边图
bool vis[MAXN];
ll dis[MAXN];

void dij(int s) {
    // 多测清空
    // 优先队列、队列、栈均不提供 clear()，因为这些是容器的适配器而不是容器。
    // deque 提供了 clear()
    // 每次都创建一个新的 pq
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    memset(vis, 0, sizeof(bool) * (n + 10));
    memset(dis, 0x3f, sizeof(ll) * (n + 10));

    dis[s] = 0LL;

    pq.push({0LL, s});

    while (!pq.empty()) {
        pli tmp = pq.top();
        pq.pop();

        ll tmpd = tmp.first;
        int now = tmp.second;

        if (vis[now]) continue;
        vis[now] = true;

        for (int i = head[now]; i; i = e[i].nx) {
            int to = e[i].v;
            if (dis[to] > e[i].w + tmpd) {
                dis[to] = e[i].w + tmpd;
                pq.push({dis[to], to});
            }
        }
    }

    return;
}

void solve() {
	cin >> n >> m >> s;

    // 清图
    cnte = 0;
    memset(head, 0, sizeof(int) * (n + 10));

	for (int i = 1; i <= m; i++) {
		int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
	}
	
	dij(s);
	
	for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }

    cout << '\n';
	
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--) {
		solve();
	}
	return 0;
}
