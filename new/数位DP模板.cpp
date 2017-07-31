/*****************
	不要62
******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef int LL;
LL a[30];
LL dp[30][2];
LL z[30] = {1};
LL n;
LL dfs(LL pos, LL stat, bool limit) {
    if(pos == -1) return 1;
    if(!limit && dp[pos][stat] != -1) return dp[pos][stat];
    LL up = limit ? a[pos] : 9;
    LL ans = 0;
    for(LL i = 0; i <= up; i++) {
        if(i == 2 && stat) continue;
        if(i == 4) continue;
        ans += dfs(pos - 1, i == 6, limit && i == a[pos]);
    }
    if(!limit) dp[pos][stat] = ans;
    return ans;
}
LL solve(LL x) {
    LL pos = 0;
    while(x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, true);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    LL n1, n2;
    while(scanf("%d%d", &n1, &n2), n1 + n2) {
        printf("%d\n", solve(n2) - solve(n1 - 1));
    }
    return 0;
}

/*****************
	只要49
******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long  LL;
LL a[100];
LL dp[100][2];
LL z[100] = {1};
LL n;
LL dfs(LL pos, LL stat, bool limit) {
    if(pos == -1) return 0;
    if(!limit && dp[pos][stat] != -1) return dp[pos][stat];
    LL up = limit ? a[pos] : 9;
    LL ans = 0;
    for(LL i = 0; i <= up; i++) {
        if(stat && i == 9) {
            ans += limit ? (n % z[pos] + 1) : z[pos];
        } else {
            ans += dfs(pos - 1, i == 4, limit && i == a[pos]);
        }
    }
    if(!limit) dp[pos][stat] = ans;
    return ans;
}
LL solve(LL x) {
    LL pos = 0;
    while(x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, true);
}
int main()
{
    for(int i = 1;i < 30; i++) {
        z[i] = z[i - 1] * 10;
    }
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

第二种方法

LL n, dp[25][3];  
//dp[i][j]:长度为i，状态为j  
int digit[25];  
//nstatus: 0：不含49, 1：不含49但末尾是4, 2 :含49  
LL DFS(int pos, int status, int limit)  
{  
    if(pos <= 0) // 如果到了已经枚举了最后一位，并且在枚举的过程中有49序列出现  
        return status==2;//注意是 ==  
    if(!limit && dp[pos][status]!=-1)   //对于有限制的询问我们是不能够记忆化的  
        return dp[pos][status];  
    LL ans = 0;  
    int End = limit?digit[pos]:9;   // 确定这一位的上限是多少  
    for(int i = 0; i <= End; i++)   // 每一位有这么多的选择  
    {  
        int nstatus = status;       // 有点else s = statu 的意思  
  
        if(status==0 && i==4)//高位不含49，并且末尾不是4 ，现在末尾添4返回1状态  
            nstatus = 1;  
        else if(status==1 && i!=4 && i!=9)//高位不含49，且末尾是4，现在末尾添加的不是4返回0状态  
            nstatus = 0;  
        else if(status==1 && i==9)//高位不含49，且末尾是4，现在末尾添加9返回2状态  
            nstatus = 2;  
        ans+=DFS(pos-1, nstatus, limit && i==End);  
    }  
    if(!limit)  
        dp[pos][status]=ans;  
    return ans;  
}  

第三种方法·没有DFS的纯DP

LL dp[27][3];  
int c[27];  
//dp[i][j]:长度为i的数的第j种状态  
//dp[i][0]:长度为i但是不包含49的方案数  
//dp[i][1]:长度为i且不含49但是以9开头的数字的方案数  
//dp[i][2]:长度为i且包含49的方案数  
void init()  
{  
    memset(dp,0,sizeof(dp));  
    dp[0][0] = 1;  
    for(int i = 1; i <= 20; i++)  
    {  
        dp[i][0] = dp[i-1][0]*10-dp[i-1][1];  
        dp[i][1] = dp[i-1][0]*1;  
        dp[i][2] = dp[i-1][2]*10+dp[i-1][1];  
    }  
}  

/*****************
被13整除且包含“13”
******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef int LL;
LL a[30];
LL dp[30][15][3];
LL z[30] = {1};
LL n;
LL dfs(LL pos, LL mod, LL stat, bool limit) {
    if(pos == -1) return mod == 0 && stat == 2;
    if(!limit && dp[pos][mod][stat] != -1) return dp[pos][mod][stat];
    LL up = limit ? a[pos] : 9;
    LL ans = 0;
    for(LL i = 0; i <= up; i++) {
        LL ns = stat;
        if(stat == 0 && i == 1) ns = 1;
        if(stat == 1 && i != 1) ns = 0;
        if(stat == 1 && i == 3) ns = 2;
        ans += dfs(pos - 1, (mod * 10 + i) % 13, ns, limit && i == a[pos]);
    }
    if(!limit) dp[pos][mod][stat] = ans;
    return ans;
}
LL solve(LL x) {
    LL pos = 0;
    while(x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, 0, true);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    for(LL i = 1; i < 30; i++) {
        z[i] = z[i - 1] * 10;
    }
    while(cin >> n) {
        cout << solve(n)<< endl;
    }
    return 0;
}
