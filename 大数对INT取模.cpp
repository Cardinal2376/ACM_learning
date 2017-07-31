#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;

char str[10000001];
int len;
int mod(const int & b)   //大数对一个int类型的变量进行取模运算
{
    int i,d=0;
    for (i = 0; i < len; i++)
    {
        d = ((d * 10)% b + str[i] - '0')% b;
    }
    return d;
}

int main(void)
{
    int k = 1;
    while(scanf("%s",str) != EOF)
    {
        len = strlen(str);
        printf("Case #%d: ", k++);
        int a = 73, b = 137;
        //cout << mod(a) << endl;
        //cout << mod(b) << endl;
        if ((mod(a) == 0) && (mod(b) == 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
