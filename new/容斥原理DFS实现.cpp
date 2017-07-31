//题意找与n,m互质的第k个数
//思路：二分
//找到最小的x，使得小于或等于x的数中满足条件的数的个数大于或等于k
//预处理n,m的质因数表
//k是深度，也就是当前质因数位置
//t是奇偶判断
//s是质数乘积
//n是传进去的x
void dfs(LL k,LL t,LL s,LL n)  
{  
    if(k==num)  
    {  
        if(t&1) ans-=n/s;  
        else    ans+=n/s;  
        return;  
    }  
    dfs(k+1,t,s,n);  
    dfs(k+1,t+1,s*fac[k],n);  //fac[k]是质因数表
}

//二分调用
dfs(0,0,1,mid);

求（1，b）区间和（1，d）区间里面gcd(x, y) = k的数的对数（1<=x<=b , 1<= y <= d）。
b和d分别除以k之后的区间里面，只需要求gcd(x, y) = 1就可以了，这样子求出的数的对数不变。
这道题目还要求1-3 和 3-1 这种情况算成一种，因此只需要限制x<y就可以了

只需要枚举x，然后确定另一个区间里面有多少个y就可以了。因此问题转化成为区间（1， d）里面与x互素的数的个数
先求出x的所有质因数，因此（1，d）区间里面是x的质因数倍数的数都不会与x互素，因此，只需要求出这些数的个数，减掉就可以了。
如果w是x的素因子，则（1，d）中是w倍数的数共有d/w个。

容斥原理：
所有不与x互素的数的个数= 1个因子倍数的个数 - 2个因子乘积的倍数的个数 + 3个……-……

答案很大，用long long。
所有数的素因子，预先处理保存一下，不然会超时的。
#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <algorithm>  
using namespace std;  
#define N 100005  
typedef long long ll;  
vector<int> x[N];  
bool is[N];  
  
void prime() {  
    memset(is, false, sizeof(is));  
    for (int i=0; i<N; i++) x[i].clear();  
  
    for (int j=2; j<N; j+=2) x[j].push_back(2);  
    for (int i=3; i<N; i+=2)  
        if (!is[i]) {  
            for (int j=i; j<N; j+=i) {  
                is[j] = true;  
                x[j].push_back(i);  
            }  
        }  
}  
int work(int u, int s, int w) {  
    int cnt = 0, v = 1;  
    for (int i=0; i<x[w].size(); i++) {  
        if ((1<<i) & s) {  
            cnt++;  
            v *= x[w][i];  
        }  
    }  
    int all = u/v;  
    if (cnt % 2 == 0) return -all;  
    else return all;  
}  
  
int main() {  
  
    prime();  
  
    int T, a, b, c, d, k;  
    scanf("%d", &T);  
    for (int cas=1; cas<=T; cas++) {  
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);  
        if (k == 0) {  
            printf("Case %d: 0\n", cas);  
            continue;  
        }  
        b /= k, d /= k;  
  
        if (b > d) { a = b; b = d; d = a; }  
        long long ans = 0;  
        for (int i=1; i<=d; i++) {  
            k = min(i, b);  
            ans += k;  
            for (int j=1; j<(1<<x[i].size()); j++)  
                ans -= work(k, j, i);  
        }  
        printf("Case %d: %I64d\n", cas, ans);  
    }  
    return 0;  
}  