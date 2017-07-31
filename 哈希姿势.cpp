#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const LL SEED = 2009;
//13331 12323 53077
vector<int> ve[N];
map<LL,int> mymap;

LL dfs(int x)
{
    LL p = 1;
    for(int i = 0; i < ve[x].size(); i++) {
        int y = ve[x][i];
        LL tmp = dfs(y);
        p += tmp * SEED;
    }
    mymap[p]++;
    return p;
}
int main()
{
    int n;
    while(cin >> n)
    {
        mymap.clear();
        for(int i = 1; i <= n; i++) {
            ve[i].clear();
        }
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            ve[x].push_back(y);
        }
        dfs(1);
        LL ans = 0;
        for(map<LL,int>::iterator it = mymap.begin(); it != mymap.end();it++)
        {
            LL tmp = it->second;
            ans += tmp * (tmp - 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
