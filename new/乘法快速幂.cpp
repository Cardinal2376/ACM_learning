LL fast_multi(LL m, LL n, LL mod)//快速乘法 
{
    LL ans = 0;//注意初始化是0，不是1 
    while (n)
    {
        if (n & 1)
            ans += m;
        m = (m + m) % mod;//和快速幂一样，只不过这里是加 
        m %= mod;//取模，不要超出范围 
        ans %= mod;
        n >>= 1;
    }
    return ans;
}
LL fast_pow(LL a, LL n, LL mod)//快速幂 
{
    LL ans = 1;
    while (n)
    {
        if (n & 1)
            ans = fast_multi(ans, a, mod);//不能直接乘 
        a = fast_multi(a, a, mod);
        ans %= mod;
        a %= mod;
        n >>= 1;
    }
    return ans;
}