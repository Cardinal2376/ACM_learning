#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define maxn 200005
using namespace std;
typedef long long LL;
vector<LL> vec[maxn];
typedef pair<LL, LL> pii;
pii info[maxn];
LL c[maxn];
LL ans[maxn];
LL n;
LL Lowbit(LL x)  // 2^k
{
    return x&(-x);
}
void update(LL i, LL x)//i点增量为x
{
    while(i <= n)
    {
        c[i] += x;
        i += Lowbit(i);
    }
}
LL sum(LL x)//区间求和 [1,x]
{
    LL sum=0;
    while(x>0)
    {
        sum+=c[x];
        x-=Lowbit(x);
    }
    return sum;
}

LL Getsum(LL x1,LL x2) //求任意区间和
{
    return sum(x2) - sum(x1-1);
}
/*** 关键在于这个DFS
	这个DFS用的后序遍历，先求出遍历前的累计，再处理子树，再求遍历后的累计，两个相减就是节点值
	用这个方法可以巧妙地避免之前的值影响之后的值
	适用在全局变量上
	题目 ECNUOJ Test
	http://172.23.131.100/blog/entry/14/ E
	同题钟鸣做法：DFS序+排序插入
	线段树的高级做法
***/
void dfs(LL root) {
    LL tmp = sum(info[root].first - 1);
    for(LL i = 0; i < vec[root].size(); i++) {
        dfs(vec[root][i]);
    }
    ans[root] = sum(info[root].first - 1) - tmp;
    update(info[root].first, info[root].second);
}

int main()
{

    memset(c,0,sizeof(c));
    memset(ans,0,sizeof(ans));
    n = maxn;
    LL N;
    cin >> N;
    LL head;
    for(LL i = 1; i <= N; i++) {
        LL  m, r, t;
        scanf("%lld%lld%lld", &m, &r, &t);
        if (m == -1) {
            head = i;
        } else {
            vec[m].push_back(i);
        }
        info[i] = pii(r, t);
    }
    dfs(head);
    for(LL i = 1; i <= N; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}