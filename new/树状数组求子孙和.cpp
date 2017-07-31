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
void update(LL i, LL x)//i������Ϊx
{
    while(i <= n)
    {
        c[i] += x;
        i += Lowbit(i);
    }
}
LL sum(LL x)//������� [1,x]
{
    LL sum=0;
    while(x>0)
    {
        sum+=c[x];
        x-=Lowbit(x);
    }
    return sum;
}

LL Getsum(LL x1,LL x2) //�����������
{
    return sum(x2) - sum(x1-1);
}
/*** �ؼ��������DFS
	���DFS�õĺ�����������������ǰ���ۼƣ��ٴ��������������������ۼƣ�����������ǽڵ�ֵ
	�����������������ر���֮ǰ��ֵӰ��֮���ֵ
	������ȫ�ֱ�����
	��Ŀ ECNUOJ Test
	http://172.23.131.100/blog/entry/14/ E
	ͬ������������DFS��+�������
	�߶����ĸ߼�����
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