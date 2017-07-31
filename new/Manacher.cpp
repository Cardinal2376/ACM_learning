#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxx 20000050
char str[2*maxx];
char s[maxx];
int p[maxx];
//P 记录以每个字符为中心的最长回文半径
void Manacher(int *p,char *str,int len)
{
    int mx=0;
    int idx=0;
    for(int i=1; i<len; i++)
    {
        p[i]=mx>i?min(p[2*idx-i],mx-i):1;
        while(str[i+p[i]]==str[i-p[i]])
        p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            idx=i;
        }
    }
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int nn=strlen(s);//需要定义一个变量nn，如果每次调用strlen(s)，时间就会长
        int n=2*nn+2;
        str[0]='$';
        for(int i=0; i<=nn; i++)
        {
            str[2*i+1]='#';
            str[2*i+2]=s[i];
        }
        Manacher(p,str,n);
        int ans=1;
        for(int i=0; i<n; i++)
                    ans=max(ans,p[i]);
        printf("%d\n",ans-1);

    }
    return 0;
}
