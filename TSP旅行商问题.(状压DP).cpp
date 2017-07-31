#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 16;
const int INF = 0x3f3f3f3f;
int n;
int dp[1 << MAXN][MAXN];
int d[MAXN][MAXN];

int rec(int s, int v) {
    //记忆化
    if (dp[s][v] >= 0) {
        return dp[s][v];
    }

    //已经访问过所有节点并返回零号节点
    if (s == (1 << n) - 1 && v == 0) {
        return dp[s][v] = 0;
    }

    int res = INF;
    for (int u = 0; u < n; u++) {
        if (!(s >> u & 1)) {
            //下一步移动到顶点U
            res = min(res, rec(s | 1 << u, u) + d[v][u]);
        }
    }
    return dp[s][v] = res;
}

int solve() {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, 0));
}

void floyd() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        memset(d, INF, sizeof(d));
        int m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            if (d[x - 1][y - 1] > v) d[x - 1][y - 1] = d[y - 1][x - 1] = v;
        }
        //每个点只能走一次就是原本的TSP问题，可以走多次先求各点最短路转化为TSP
        //道理比如1 - 3, 1 - 2 那么 1 要走3次， TSP求不出 但是求一波Floyd以后， 3 - 2有条路了，相当于改变了图
        floyd();
        solve();
    }
    return 0;
}
