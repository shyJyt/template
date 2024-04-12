int fa[MAXN];

int find(int x) {
    if (fa[x] == x) {
        return fa[x];
    }
    else return fa[x] = find(fa[x]);
}

void merge(int i, int j) {
    int fai = find(i), faj = find(j);
    fa[faj] = fai;
}

struct edge {
    int u, v, w;
} e[MAXM];
int cnte;

bool cmp(edge a, edge b) {
    return a.w < b.w; 
}

// 取边，而 prim 是取点
void kruskal() {
    // 按边权从小到大取
    sort(e + 1, e + cnte + 1, cmp);
    for (int i = 1; i < cnte; i++) {
        int fau = find(e[i].u);
        int fav = find(e[i].v);
        // 如果不成环就加入
        if (fau != fav) {
            merge(e[i].u, e[i].v);
        }
    }
}