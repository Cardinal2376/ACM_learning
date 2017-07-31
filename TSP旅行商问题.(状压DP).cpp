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
    //���仯
    if (dp[s][v] >= 0) {
        return dp[s][v];
    }

    //�Ѿ����ʹ����нڵ㲢������Žڵ�
    if (s == (1 << n) - 1 && v == 0) {
        return dp[s][v] = 0;
    }

    int res = INF;
    for (int u = 0; u < n; u++) {
        if (!(s >> u & 1)) {
            //��һ���ƶ�������U
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
        //ÿ����ֻ����һ�ξ���ԭ����TSP���⣬�����߶������������·ת��ΪTSP
        //�������1 - 3, 1 - 2 ��ô 1 Ҫ��3�Σ� TSP�󲻳� ������һ��Floyd�Ժ� 3 - 2����·�ˣ��൱�ڸı���ͼ
        floyd();
        solve();
    }
    return 0;
}
