//��������n,m���ʵĵ�k����
//˼·������
//�ҵ���С��x��ʹ��С�ڻ����x�������������������ĸ������ڻ����k
//Ԥ����n,m����������
//k����ȣ�Ҳ���ǵ�ǰ������λ��
//t����ż�ж�
//s�������˻�
//n�Ǵ���ȥ��x
void dfs(LL k,LL t,LL s,LL n)  
{  
    if(k==num)  
    {  
        if(t&1) ans-=n/s;  
        else    ans+=n/s;  
        return;  
    }  
    dfs(k+1,t,s,n);  
    dfs(k+1,t+1,s*fac[k],n);  //fac[k]����������
}

//���ֵ���
dfs(0,0,1,mid);

��1��b������ͣ�1��d����������gcd(x, y) = k�����Ķ�����1<=x<=b , 1<= y <= d����
b��d�ֱ����k֮����������棬ֻ��Ҫ��gcd(x, y) = 1�Ϳ����ˣ���������������Ķ������䡣
�����Ŀ��Ҫ��1-3 �� 3-1 ����������һ�֣����ֻ��Ҫ����x<y�Ϳ�����

ֻ��Ҫö��x��Ȼ��ȷ����һ�����������ж��ٸ�y�Ϳ����ˡ��������ת����Ϊ���䣨1�� d��������x���ص����ĸ���
�����x����������������ˣ�1��d������������x������������������������x���أ���ˣ�ֻ��Ҫ�����Щ���ĸ����������Ϳ����ˡ�
���w��x�������ӣ���1��d������w������������d/w����

�ݳ�ԭ��
���в���x���ص����ĸ���= 1�����ӱ����ĸ��� - 2�����ӳ˻��ı����ĸ��� + 3������-����

�𰸺ܴ���long long��
�������������ӣ�Ԥ�ȴ�����һ�£���Ȼ�ᳬʱ�ġ�
#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <algorithm>  
using namespace std;  
#define N 100005  
typedef long long ll;  
vector<int> x[N];  
bool is[N];  
  
void prime() {  
    memset(is, false, sizeof(is));  
    for (int i=0; i<N; i++) x[i].clear();  
  
    for (int j=2; j<N; j+=2) x[j].push_back(2);  
    for (int i=3; i<N; i+=2)  
        if (!is[i]) {  
            for (int j=i; j<N; j+=i) {  
                is[j] = true;  
                x[j].push_back(i);  
            }  
        }  
}  
int work(int u, int s, int w) {  
    int cnt = 0, v = 1;  
    for (int i=0; i<x[w].size(); i++) {  
        if ((1<<i) & s) {  
            cnt++;  
            v *= x[w][i];  
        }  
    }  
    int all = u/v;  
    if (cnt % 2 == 0) return -all;  
    else return all;  
}  
  
int main() {  
  
    prime();  
  
    int T, a, b, c, d, k;  
    scanf("%d", &T);  
    for (int cas=1; cas<=T; cas++) {  
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);  
        if (k == 0) {  
            printf("Case %d: 0\n", cas);  
            continue;  
        }  
        b /= k, d /= k;  
  
        if (b > d) { a = b; b = d; d = a; }  
        long long ans = 0;  
        for (int i=1; i<=d; i++) {  
            k = min(i, b);  
            ans += k;  
            for (int j=1; j<(1<<x[i].size()); j++)  
                ans -= work(k, j, i);  
        }  
        printf("Case %d: %I64d\n", cas, ans);  
    }  
    return 0;  
}  