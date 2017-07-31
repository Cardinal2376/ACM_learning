//可以不满足两两互质
int n;
//扩展gcd多了一个变量
void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b) {d = a, x = 1, y = 0;}
    else
    {
        ex_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
//注意M的范围
//如果M是int，都要开ll，M是ll，乘法要用快速乘
LL ex_crt(LL *m, LL *r, int n)
{
    LL M = m[1], R = r[1], x, y, d;
    for (int i = 2; i <= n; ++i)
    {
        ex_gcd(M, m[i], d, x, y);
        if ((r[i] - R) % d) return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R > 0 ? R : R + M;
}

