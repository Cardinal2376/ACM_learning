#include <bits/stdc++.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int N = 1e5 + 10;
int n, fa, root, dfs_cnt;
int Left[N], Right[N];

struct node {
    int r, t, idx;
    bool operator < (const node& rhs) const {
        return r < rhs.r;
    }
}a[N];

vector<int> tree[N];

long long sum[N << 2], ans[N];

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int p, int add, int l, int r, int rt) {
    if (l == r) {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p > m) update(p, add, rson);
    else update(p, add, lson);
    pushup(rt);
}

long long query(int s, int e, int l, int r, int rt) {
    if (s <= l && e >= r) return sum[rt];
    int m = (l + r) >> 1;
    long long ret = 0;
    if (s <= m) ret += query(s, e, lson);
    if (e > m) ret += query(s, e, rson);
    return ret;
}

void dfs(int u, int pre) {
    Left[u] = ++dfs_cnt;
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++) {
        int v = tree[u][i];
        if (v == pre) continue;
        dfs(v, u);
    }
    Right[u] = dfs_cnt;
}

int main() {
    scanf("%d", &n);
    dfs_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &fa, &a[i].r, &a[i].t);
        a[i].idx = i;
        if (fa != -1)
            tree[fa].push_back(i);
        else
            root = i;
    }
    dfs(root, -1);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        int id = a[i].idx;
        ans[a[i].idx] = query(Left[id], Right[id], 1, n, 1);
        if (i + 1 <= n && a[i + 1].r != a[i].r) {
            if (i - 1 >= 1 && a[i - 1].r == a[i].r) {
                for (int j = i; j >= 1; --j) {
                    if (a[j].r == a[i].r)
                        update(Left[a[j].idx], a[j].t, 1, n, 1);
                    else
                        break;
                }
            } else {
                update(Left[id], a[i].t, 1, n, 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}