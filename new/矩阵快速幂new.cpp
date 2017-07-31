//矩阵快速幂 +++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
struct mat//矩阵结构体，a表示内容，size大小
{
    LL a[101][101],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
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
mat mul(mat &m1,mat &m2,LL mod)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    LL i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m2.size;j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k] += m1.a[i][j] * m2.a[j][k] % mod + mod;//mult(m1.a[i][j],m2.a[j][k],mod);
                    ans.a[i][k] %= mod;
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

const LL MOD = 1000000007;

int main()
{
    LL n, k, x;
    cin >> n >> k;
    mat A, T;
    A.size = n;
    T.size = n;
    for(int i = 0; i < n; i++) {
       scanf("%lld", &A.a[n - 1 - i][0]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &T.a[0][i]);
    }
    for(int i = 0; i < n - 1; i++) {
        T.a[i + 1][i] = 1;
    }
    LL ans;
    if (k < n) {
        ans = A.a[n - k][0] % MOD;
    } else {
        T = pow(T, k - n, MOD);
        A = mul(T, A, MOD);
        ans = A.a[0][0];
    }
    printf("%lld\n", ans);
    return 0;
}