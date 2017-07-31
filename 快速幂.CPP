//矩阵快速幂 +++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
struct mat//矩阵结构体，a表示内容，size大小
{
    LL a[105][105],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
mat mul(mat &m1,mat &m2,LL mod)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    LL i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m2.size;j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k] += m1.a[i][j] * m2.a[j][k];//mult(m1.a[i][j],m2.a[j][k],mod);
                    //ans.a[i][k] %= mod;
                }
    ans.size=m1.size;
    return ans;
}
mat pow(mat m,LL n,LL mod)//二分快速幂
{
    mat ans=mat();
    LL i;
    for(i=0;i<m.size;i++)ans.a[i][i]=1;
    ans.size=m.size;
    while(n > 0)
    {
        if(n&1)ans = mul(m,ans,mod);
        m = mul(m,m,mod);
        n >>= 1;
        //cout << n << endl;
    }
    return ans;
}
void print(mat m)//输出矩阵信息，debug用
{
    LL i,j;
    printf("%lld\n",m.size);
    for(i=0;i<m.size;i++)
    {
        for(j=0;j<m.size;j++)printf("%lld ",m.a[i][j]);
        printf("\n");
    }
}
LL mult(LL a,LL b,LL mod)//自己写大数乘法，利用位运算有效避免LL64或者高精度，这里a,b,mod只要不超过2^30就不会出问题
{
    LL exp=a%mod,res=0;
    while(b)
    {
        if(b&1)
        {
            res+=exp;
            if(res>=mod)res-=mod;
        }
        exp<<=1;
        if(exp>=mod)exp-=mod;
        b>>=1;
    }
    return res;
}
//563
//26880699

int main () {
    //freopen("in.txt", "r", stdin);
    LL n, m, k;
    while(scanf("%lld%lld%lld", &n, &m, &k), n + m + k) {
        mat T;
        T.size = n + 1;
        for(int i = 0; i < n + 1; i++) T.a[i][i] = 1;
        for(int i = 0; i < k; i++) {
            char s[10];
            scanf("%s", s);
            if (s[0] == 'g') {
                int x;
                scanf("%d", &x);
                T.a[x - 1][n]++;
            } else if (s[0] == 's') {
                int x, y;
                scanf("%d%d", &x, &y);
               int Temp;
                for(int j = 0; j < n + 1; j++) {
                    Temp = T.a[x - 1][j];
                    T.a[x - 1][j] = T.a[y - 1][j];
                    T.a[y - 1][j] = Temp;
                }
            } else if (s[0] == 'e') {
                int x;
                scanf("%d", &x);
                for(int j = 0; j < n + 1; j++) {
                    T.a[x - 1][j] = 0;
                }

            }
        }
        T = pow(T, m, m);
        mat ans;
        ans.size = n + 1;
        ans.a[n][0] = 1;
        ans = mul(T, ans, m);
        for(int i = 0; i < n; i++) {
            printf("%lld%c", ans.a[i][0], i == n - 1 ? '\n' : ' ');
        }
    }
  return 0;
}
