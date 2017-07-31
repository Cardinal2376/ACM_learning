#include<iostream>
#include<cstdio>
#include<cstring>
#define INT_MAX 2147483647
using namespace std;

const int MAXN = 1 << 17; //131072 

int n, dat[2 * MAXN - 1];

int init(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2 * n - 1; i++) dat[i] = 0;
    return n;
}

void add(int k, int a) {
    k += n - 1;
    dat[k] += a;
    while(k > 0) {
        k = (k - 1) / 2;
        dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
    }
}

void sub(int k, int a) {
    k += n - 1;
    dat[k] -= a;
    while(k > 0) {
        k = (k - 1) / 2;
        dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
    }
}

int query(int a, int b, int k, int l, int r) { //[a,b) 	节点编号 	当前查询范围
    if (r <= a || l >= b) {
        return 0;
    }
    if (a <= l && r <= b) {
        return dat[k];
    } else {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return vl + vr;
    }
}

void solve()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++) {
        int N;
        cin >> N;
        int n = init(N);
        for(int i = 0; i < N; i++) {
            int t;
            scanf("%d", &t);
            add(i, t);
        }
        char s[50];
        int num, val;
        printf("Case %d:\n", k);
        while(scanf("%s", s) != EOF) {
            if (strcmp(s,"End") == 0) {
                break;
            } else if (strcmp(s, "Query") == 0) {
                int a, b;
                scanf("%d%d", &a, &b);
                a--;
                cout << query(a, b, 0, 0, n) << endl;
            } else if (strcmp(s, "Sub") == 0) {
                int k, a;
                scanf("%d%d", &k, &a);
                k--;
                sub(k, a);
            } else if (strcmp(s, "Add") == 0) {
                int k, a;
                scanf("%d%d", &k, &a);
                k--;
                add(k, a);
            }
        }
    }

}

int main() {
    solve();
}
