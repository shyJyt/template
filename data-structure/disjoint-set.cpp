// 获取所在集合的根元素时，务必使用一次 find(x)，因为 fa[x] 此时可能还未被压缩。
// 或者说判断两点 x, y 是否在一个集合，应该是 find(x) == find(y)，而不是 fa[x] == fa[y]
int fa[MAXN];

// 路径压缩，直接将 fa[x] 设为集合的根节点
int find(int x) {
    if (fa[x] == x) {
        return fa[x];
    }
    else return fa[x] = find(fa[x]);
}

// 未采用启发式合并
void merge(int i, int j) {
    int fai = find(i), faj = find(j);
    fa[faj] = fai;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    return;
}