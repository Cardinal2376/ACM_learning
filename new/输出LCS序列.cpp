#include <string.h>  
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <stdlib.h>  
#include <string>  
#include <vector>  
using namespace std;  
string s1,s2;  
string lcs2(string s1,string s2)  
{  
    if(s1==""||s2=="")  
        return "";  
    int m=s1.size()+1;  
    int n=s2.size()+1;  
    printf("%d %d\n",m,n);  
    int lcs[m][n];  
    memset(lcs,0,sizeof(lcs));  
    for(int i=1;i<m;i++)  
        for(int j=1;j<n;j++)  
        {  
            if(s1[i-1]==s2[j-1])  
                lcs[i][j]=lcs[i-1][j-1]+1;  
            else  
                lcs[i][j]=lcs[i-1][j]>=lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1];//取上侧或左侧的最大值  
        }  
        int i=m-2;  
        int j=n-2;  
        string ss="";  
        while(i!=-1&&j!=-1)  
        {  
            if(s1[i]==s2[j])  
            {  
                //printf("%c\n",s1[i]);  
                ss+=s1[i];  
                i--;  
                j--;  
            }  
            else  
            {  
                if(lcs[i+1][j+1]==lcs[i][j])  
                {  
                    i--;  
                    j--;  
                }  
                else  
                {  
                    if(lcs[i][j+1]>=lcs[i+1][j])  
                        i--;  
                    else  
                        j--;  
                }  
            }  
        }  
        reverse(ss.begin(),ss.end());//将字符串倒置  
        return ss;  
}  
int main()  
{  
    while(cin>>s1>>s2)  
    {  
        string s=lcs2(s1,s2);  
        cout << s<<endl;  
    }  
    return 0;  
}  