/*
O(n2)�㷨�����������
Ԥ�������Ҫ����������������ϴ��������ɲ��ã�������ȡģ��Ҳ�ܷ��㣩��ʹ��C(a, b) = C(a - 1, b - 1) + C(a - 1, b - 1)���ƴ���
��Ϊ��������в��õ��Ƶļӷ����㣬���Բ�ȡģ��ʱ���������㵽a = 66
���ǣ��������һ�������ȡģ�Ĳ��������Կ��ǵ��ڴ����Ƶ�ʱ��һ����Լ��㵽a = 1000����һ�����������ڴ棩
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
O(n)�㷨�����׳�ȡģ+�˷���Ԫ
C(m,n) = n! / m! / (n - m)!
*/

/**
	���p��������ֱ��quick_mod(b, p-2) % p ����С��������Ԫ
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
���n,m�ܴ� �ﵽ1e18������p��С <= 1e5 �����ǿ����������p
Lucas����C(n, m) % p  =  C(n / p, m / p) * C(n%p, m%p) % p
*/
LL Lucas(LL n, LL m)  
{  
    if(m == 0) return 1;  
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;  
}

/*
�׳�Ԥ����
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
�������ż�Խ��ۣ�
�����n&m) == m ��ôc(m,n)��������������ż��
*/

