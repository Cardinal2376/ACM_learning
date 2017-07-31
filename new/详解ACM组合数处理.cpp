/*
O(n2)算法——杨辉三角
预处理出需要的组合数，如需计算较大的组合数可采用（经常会取模，也很方便）。使用C(a, b) = C(a - 1, b - 1) + C(a - 1, b - 1)递推处理
因为计算过程中采用递推的加法运算，所以不取模的时候最大可以算到a = 66
但是，这种情况一般伴随着取模的操作，所以考虑到内存限制的时候，一般可以计算到a = 1000（不一定，受限于内存）
*/
const int MAXN1 = 1000;  
const int MAXN2 = 1000;  
LL f[MAXN1][MAXN2];  
  
void init()  
{  
    REP(i, 0, MAXN1)  
        f[i][0] = 1;  
    REP(i, 1, MAXN1)  
    {  
        REP(j, 1, min(i, MAXN2 - 1))  
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;  
    }  
}

/*
O(n)算法——阶乘取模+乘法逆元
C(m,n) = n! / m! / (n - m)!
*/

/**
	如果p是质数，直接quick_mod(b, p-2) % p 费马小定理求逆元
**/
LL quick_mod(LL a, LL b)  
{  
    LL ans = 1;  
    a %= p;  
    while(b)  
    {  
        if(b & 1)  
        {  
            ans = ans * a % p;  
            b--;  
        }  
        b >>= 1;  
        a = a * a % p;  
    }  
    return ans;  
}

LL C(LL n, LL m)  
{  
    if(m > n) return 0;  
    LL ans = 1;  
    for(int i=1; i<=m; i++)  
    {  
        LL a = (n + i - m) % p;  
        LL b = i % p;  
        ans = ans * (a * quick_mod(b, p-2) % p) % p;  
    }  
    return ans;  
}  

/*
如果n,m很大 达到1e18，但是p很小 <= 1e5 ，我们可以利用这个p
Lucas定理：C(n, m) % p  =  C(n / p, m / p) * C(n%p, m%p) % p
*/
LL Lucas(LL n, LL m)  
{  
    if(m == 0) return 1;  
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;  
}

/*
阶乘预处理
*/
void Init()  
{  
    fac[0]  = 1;  
    for(int i=1; i<=n; i++)  
        fac[i] = (fac[i-1] * i) % MOD;  
}
  
LL C(LL n,LL m,LL p,LL fac[])  
{  
    if(n < m) return 0;  
    return fac[n] * quick_mod(fac[m] * fac[n-m], p - 2, p) % p;  
}

/*
组合数奇偶性结论：
如果（n&m) == m 那么c(m,n)是奇数，否则是偶数
*/

