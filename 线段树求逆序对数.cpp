#include<iostream>
#include<cstdio>
#include<cstring>
#define INT_MAX 2147483647
using namespace std;

const int MAXN = 1 << 13; //1024 * 8

int n, dat[2 * MAXN - 1], num[MAXN]; // 维护dat表示大小为i的数有几个 ， num记录输入数据

int init(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2 * n - 1; i++) dat[i] = 0;
    for(int i = 0; i < n; i++) num[i] = -1;
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
    int N;
    while(cin >> N) {
        int n = init(N+1);
        int sum = 0;
        for(int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            num[i] = a;
            add(a, 1);
            sum += query(a+1, N+1, 0, 0, n); //求比它大的数的个数和 logN
        }
        int ans = sum;
        for(int i = 0; i < N - 1; i++) {
            sum = sum - 2 * num[i] + N - 1; // 循环移1位
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }

}

int main() {
    solve();
}
