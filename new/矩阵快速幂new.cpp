//��������� +++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
struct mat//����ṹ�壬a��ʾ���ݣ�size��С
{
    LL a[101][101],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
void print(mat m)//���������Ϣ��debug��
{
    LL i,j;
    printf("%lld\n",m.size);
    for(i=0;i<m.size;i++)
    {
        for(j=0;j<m.size;j++)printf("%lld ",m.a[i][j]);
        printf("\n");
    }
}
LL mult(LL a,LL b,LL mod)//�Լ�д�����˷�������λ������Ч����LL64���߸߾��ȣ�����a,b,modֻҪ������2^30�Ͳ��������
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
mat mul(mat &m1,mat &m2,LL mod)//������Ⱦ���ĳ˷�������ϡ�������0������������Ż�
{
    mat ans=mat();
    LL i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m2.size;j++)
            if(m1.a[i][j])//ϡ������Ż�
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k] += m1.a[i][j] * m2.a[j][k] % mod + mod;//mult(m1.a[i][j],m2.a[j][k],mod);
                    ans.a[i][k] %= mod;
                }
    ans.size=m1.size;
    return ans;
}
mat pow(mat m,LL n,LL mod)//���ֿ�����
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