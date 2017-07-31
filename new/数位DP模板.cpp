/*****************
	��Ҫ62
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
	ֻҪ49
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

�ڶ��ַ���

LL n, dp[25][3];  
//dp[i][j]:����Ϊi��״̬Ϊj  
int digit[25];  
//nstatus: 0������49, 1������49��ĩβ��4, 2 :��49  
LL DFS(int pos, int status, int limit)  
{  
    if(pos <= 0) // ��������Ѿ�ö�������һλ��������ö�ٵĹ�������49���г���  
        return status==2;//ע���� ==  
    if(!limit && dp[pos][status]!=-1)   //���������Ƶ�ѯ�������ǲ��ܹ����仯��  
        return dp[pos][status];  
    LL ans = 0;  
    int End = limit?digit[pos]:9;   // ȷ����һλ�������Ƕ���  
    for(int i = 0; i <= End; i++)   // ÿһλ����ô���ѡ��  
    {  
        int nstatus = status;       // �е�else s = statu ����˼  
  
        if(status==0 && i==4)//��λ����49������ĩβ����4 ������ĩβ��4����1״̬  
            nstatus = 1;  
        else if(status==1 && i!=4 && i!=9)//��λ����49����ĩβ��4������ĩβ��ӵĲ���4����0״̬  
            nstatus = 0;  
        else if(status==1 && i==9)//��λ����49����ĩβ��4������ĩβ���9����2״̬  
            nstatus = 2;  
        ans+=DFS(pos-1, nstatus, limit && i==End);  
    }  
    if(!limit)  
        dp[pos][status]=ans;  
    return ans;  
}  

�����ַ�����û��DFS�Ĵ�DP

LL dp[27][3];  
int c[27];  
//dp[i][j]:����Ϊi�����ĵ�j��״̬  
//dp[i][0]:����Ϊi���ǲ�����49�ķ�����  
//dp[i][1]:����Ϊi�Ҳ���49������9��ͷ�����ֵķ�����  
//dp[i][2]:����Ϊi�Ұ���49�ķ�����  
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
��13�����Ұ�����13��
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
