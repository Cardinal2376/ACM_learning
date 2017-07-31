LL fast_multi(LL m, LL n, LL mod)//���ٳ˷� 
{
    LL ans = 0;//ע���ʼ����0������1 
    while (n)
    {
        if (n & 1)
            ans += m;
        m = (m + m) % mod;//�Ϳ�����һ����ֻ���������Ǽ� 
        m %= mod;//ȡģ����Ҫ������Χ 
        ans %= mod;
        n >>= 1;
    }
    return ans;
}
LL fast_pow(LL a, LL n, LL mod)//������ 
{
    LL ans = 1;
    while (n)
    {
        if (n & 1)
            ans = fast_multi(ans, a, mod);//����ֱ�ӳ� 
        a = fast_multi(a, a, mod);
        ans %= mod;
        a %= mod;
        n >>= 1;
    }
    return ans;
}