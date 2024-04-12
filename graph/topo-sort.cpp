#include <stack>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 10;
int n;
int ind[MAXN];

void solve() {
    memset(ind, 0, sizeof(int) * (n + 10));

    // 栈或队列都可以实现，用于得到拓扑序或者判环
    stack<int> s;

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            s.push(i);
        }
    }

    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        for (int i = head[tmp]; i; i = e[i].nx) {
            ind[e[i].v]--;
            if(!ind[e[i].v]) s.push(e[i].v);
        }
    }
}
