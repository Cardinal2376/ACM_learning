#include<bits/stdc++.h>  
using namespace std;  
#define LL long long  
const int maxn = 1e5+7;  
const int mod = 1e9+7;  
vector<int>e[maxn];  
LL a[maxn],b[maxn],d[maxn];  
LL ans[maxn];  
int n,m;  
int main()  
{  
	while(scanf("%d%d",&n,&m)!=EOF)  
	{  
		for(int i = 0;i<=n;i++)  
			e[i].clear();  
		memset(d,0,sizeof(d));  
		memset(ans,0,sizeof(ans));  
		for(int i = 1;i<=n;i++)  
			scanf("%lld%lld",&a[i],&b[i]);  
		for(int i = 1;i<=m;i++)  
		{  
			int u,v;  
			scanf("%d%d",&u,&v);  
			e[v].push_back(u);  
			d[u]++;  
		}  
		queue<int>q;  
		for(int i = 1;i<=n;i++)  
			if(d[i]==0)q.push(i);  
		while(!q.empty())  
		{  
			int u = q.front();q.pop();  
			for(int i = 0;i<e[u].size();i++)  
			{  
				int v = e[u][i];  
				ans[v]=(ans[v]+(ans[u]+b[u])%mod)%mod;  
				if(--d[v]==0)  
					q.push(v);  
			}  
		}  
		LL res = 0;  
		for(int i = 1;i<=n;i++)  
			res = (res + 1LL*ans[i]*a[i]%mod)%mod;  
		printf("%lld\n",res);  
	}  
}  
