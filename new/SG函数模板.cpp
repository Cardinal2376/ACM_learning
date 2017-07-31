/**********************
ÿ�����ݶ��ı����
**********************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef int LL;
const int MAXN = 1e4 + 5;
const int MAXM = 1e4;
int sg[MAXN];
bool Hash[MAXN];
int f[MAXN];
int N;
void getsg(int n){
    memset(sg,0,sizeof sg);
    for (int i=1;i<=MAXM;i++){
        memset(Hash,false,sizeof Hash);
        for(int j = 0; j < N && i >= f[j]; j++) {
            Hash[sg[i-f[j]]] = true;
			/****************�Ϻ���ѧУ����ѵ���岻Ҫ����
				�ⲻ��һ�Ѳ����ѣ�����ÿ������ת�Ƶ�״̬����ǡ�
			****************/
        }
        for (int j=0;j<=MAXM;j++){
            if (!Hash[j]){
                sg[i]=j; break;
            }
        }
        //cout << i << " " << sg[i] << endl;
    }
}
int main() {
    //freopen("out.txt", "w", stdout);
    while(cin >> N, N) {
        for(int i = 0; i < N; i++) {
            scanf("%d", f + i);
        }
        sort(f, f + N);//һ��Ҫ����
        getsg(MAXM);
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int n;
            cin >> n;
            int ans = 0;
            for(int i = 0; i < n; i++) {
                int x;
                scanf("%d", &x);
                ans ^= sg[x];
            }
            printf("%s", ans ? "W" : "L");
        }
        printf("\n");
    }
    return 0;
}

/***************
���������̺����ƶ�������һ��������һ����һֱ�ڼ�С��NIM���Ӽ��
***************/

/***********************
��һ���������԰�һ�Ѳ�����ѣ�ö�ٲ�ֵ�
***********************/
for(int j = 0; j <= i - x; j++) {
	Hash[sg[j] ^ sg[i - x - j]] = 1;
}

/***********************
�������һ�������䣬��Ҫ����ȫ��1�������
ȫ��1������ż����ȫ��1��ֱͬ��NIM
***********************/

/********************
��ά��һ����ֳ��������SG[][]��ά
0�У�0�����⴦��ֱ�����ó���ԭ��ľ��롣

2 2
.#
..
2 2
.#
.#
0 0
*********************/

/******************
�����������ϲ����ѣ�����ȡ��1��
******************/
���϶��ϲ���һ����һ����ȡ
���ȫ����1�����ֿ��Ա�֤NIMʤ����������Ⱥϲ�
��ȫΪ1�����ֿ���ȡ��һ��һ�ѵģ��൱�ڲ��������Ρ�
��ʱ��DFS+���仯���������
dp[i][j]��1�ĸ���Ϊiʱ������ȫ�ϲ�����һ��j��
���еĲ���������
��ĳ��ֻ��һ���ģ�ȡ��
������ֻ��һ���ģ��ϲ�
��ĳ��ֻ��һ���ģ��ϲ�������һ����
�Ѳ���һ���ģ�ȡ��һ��
int dfs(int i, int j) {  
    if (dp[i][j] != -1)  
        return dp[i][j];  
    if (j == 1)  
        return dp[i][j] = dfs(i+1, 0);  
    dp[i][j] = 0;  
    if (i >= 1 && !dfs(i-1, j))  
        dp[i][j] = 1;  
    else if (j >= 1 && !dfs(i, j-1))  
        dp[i][j] = 1;  
    else if (i >= 1 && j > 0 && !dfs(i-1, j+1))  
        dp[i][j] = 1;  
    else if (i >= 2 && ((j >= 1 && !dfs(i-2, j+3)) || (j == 0 && !dfs(i-2, 2))))  
        dp[i][j] = 1;  
    return dp[i][j];  
}

/****************
31 ��Ϸ
1~6��4��
****************/
ֱ����������˵���仯Ҳ����

