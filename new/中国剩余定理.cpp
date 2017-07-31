//���Բ�������������
int n;
//��չgcd����һ������
void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b) {d = a, x = 1, y = 0;}
    else
    {
        ex_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
//ע��M�ķ�Χ
//���M��int����Ҫ��ll��M��ll���˷�Ҫ�ÿ��ٳ�
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

