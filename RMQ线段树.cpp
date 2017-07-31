#include<iostream>
#include<cstdio>
#include<cstring>
#include<limits.h>
using namespace std;

const int MAXN = 1 << 18;  //262144 

int n, dat[2 * MAXN - 1];

int init(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2 * n - 1; i++) dat[i] = -1;
    return n;
}

void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while(k > 0) {
        k = (k - 1) / 2;
        dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
    }
}

int dfs(int k) {  //保证每个点只算一遍
    if (dat[k] != -1) return dat[k];
    if (k < n - 1) {
        dat[k] = max(dfs(2 * k + 1), dfs(2 * k + 2));
        return dat[k];
    }
    return -1;
}

int query(int a, int b, int k, int l, int r) { //[a,b) 节点编号 当前查询范围
    if (r <= a || l >= b) {
        return -1;
    }
    if (a <= l && r <= b) {
        return dat[k];
    } else {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
}

void solve()
{
    int N, Q;
    while(cin >> N >> Q) {
        int n = init(N); // n必须取整个线段树，否则编号计算会出错
        for(int i = 0; i < N; i++) {
            scanf("%d", dat + n - 1 + i); // 先读入数据
        }
        dfs(0);
        for(int i = 0; i < Q; i++) {
            char s[5];
            int a, b;
            scanf("%s %d%d", s, &a, &b);
            if (strcmp(s, "Q") == 0) {
                printf("%d\n", query(a-1, b, 0, 0, n));
            } else if (strcmp(s, "U") == 0) {
                update(a-1, b);
            }
        }
    }
}

int main() {
	solve();
}