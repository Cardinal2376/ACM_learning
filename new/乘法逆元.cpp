//��չŷ����ã���չgcd��  
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{  
    if (a==0&&b==0) return -1;  
    if (b==0){x=1;y=0;return a;}  
    LL d=ex_gcd(b,a%b,y,x);  
    y-=a/b*x;  
    return d;  
}  
  
LL mod_inverse(LL a,LL n)//�˷���Ԫ  
{  
    LL x,y;  
    LL d = ex_gcd(a,n,x,y);  
    return (x%n+n)%n;  
}  

//p���������� ������p-2
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