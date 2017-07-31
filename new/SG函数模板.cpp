/**********************
每组数据都改变策略
**********************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef int LL;
const int MAXN = 1e4 + 5;
const int MAXM = 1e4;
int sg[MAXN];
bool Hash[MAXN];
int f[MAXN];
int N;
void getsg(int n){
    memset(sg,0,sizeof sg);
    for (int i=1;i<=MAXM;i++){
        memset(Hash,false,sizeof Hash);
        for(int j = 0; j < N && i >= f[j]; j++) {
            Hash[sg[i-f[j]]] = true;
			/****************上海大学校赛教训，板不要理解错。
				这不是一堆拆两堆，这是每个可以转移的状态都标记。
			****************/
        }
        for (int j=0;j<=MAXM;j++){
            if (!Hash[j]){
                sg[i]=j; break;
            }
        }
        //cout << i << " " << sg[i] << endl;
    }
}
int main() {
    //freopen("out.txt", "w", stdout);
    while(cin >> N, N) {
        for(int i = 0; i < N; i++) {
            scanf("%d", f + i);
        }
        sort(f, f + N);//一定要排序
        getsg(MAXM);
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int n;
            cin >> n;
            int ans = 0;
            for(int i = 0; i < n; i++) {
                int x;
                scanf("%d", &x);
                ans ^= sg[x];
            }
            printf("%s", ans ? "W" : "L");
        }
        printf("\n");
    }
    return 0;
}

/***************
独立的棋盘横向移动，看成一个子向另一个子一直在减小，NIM两子间距
***************/

/***********************
有一个操作可以把一堆拆成两堆，枚举拆分点
***********************/
for(int j = 0; j <= i - x; j++) {
	Hash[sg[j] ^ sg[i - x - j]] = 1;
}

/***********************
拿走最后一个的人输，需要特判全是1的情况。
全是1，分奇偶。不全是1，同直接NIM
***********************/

/********************
两维的一样拆分成两个异或。SG[][]两维
0行，0列特殊处理。直接设置成离原点的距离。

2 2
.#
..
2 2
.#
.#
0 0
*********************/

/******************
两个操作，合并两堆，或者取掉1个
******************/
最后肯定合并成一堆再一个个取
如果全大于1，先手可以保证NIM胜利的情况下先合并
不全为1，后手可以取完一个一堆的，相当于操作了两次。
此时，DFS+记忆化搜索来解决
dp[i][j]当1的个数为i时，其他全合并起来一共j个
其中的操作包括：
把某堆只有一个的，取走
把两堆只有一个的，合并
把某堆只有一个的，合并给不是一个的
把不是一个的，取走一个
int dfs(int i, int j) {  
    if (dp[i][j] != -1)  
        return dp[i][j];  
    if (j == 1)  
        return dp[i][j] = dfs(i+1, 0);  
    dp[i][j] = 0;  
    if (i >= 1 && !dfs(i-1, j))  
        dp[i][j] = 1;  
    else if (j >= 1 && !dfs(i, j-1))  
        dp[i][j] = 1;  
    else if (i >= 1 && j > 0 && !dfs(i-1, j+1))  
        dp[i][j] = 1;  
    else if (i >= 2 && ((j >= 1 && !dfs(i-2, j+3)) || (j == 0 && !dfs(i-2, 2))))  
        dp[i][j] = 1;  
    return dp[i][j];  
}

/****************
31 游戏
1~6各4张
****************/
直接搜索，据说记忆化也不用

