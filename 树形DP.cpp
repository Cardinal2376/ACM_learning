#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

const int MAXN = 6e3 + 5;

int n;
int dp[MAXN][2] = {0}, father[MAXN] = {0};//dp[i][0]0表示不去，dp[i][1]1表示去了
bool vis[MAXN] = {0};


void tree_dp(int node) {
    vis[node] = 1;
    for(int i = 1; i <= n; i++) {
        if (!vis[i] && father[i] == node) {
            tree_dp(i);//递归调用孩子结点，从叶子结点开始dp
            //关键
            dp[node][1] += dp[i][0];//上司来,下属不来
            dp[node][0] += max(dp[i][1],dp[i][0]);//上司不来，下属来、不来
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &dp[i][1]);
    }
    int x, y;
    while(scanf("%d%d", &x, &y), x + y) {
        father[x] = y;
    }
    int root = 1;
    while(father[root]) {
        root = father[root];
    }
    tree_dp(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
}
