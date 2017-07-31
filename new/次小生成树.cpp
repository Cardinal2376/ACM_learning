#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<climits>  
#include<algorithm>  
using namespace std;  
#define N 510  
int map[N][N], lowcost[N], pre[N], max1[N][N], stack[N];  
bool visit[N];  
int n, m, sum;  
  
void prim() //Ĭ��1��MST��  
{  
    int temp, k;  
    int top; //������С�������Ľ��  
  
    memset(visit, false, sizeof(visit)); //��ʼ��  
    visit[1] = true;  
    sum = 0;  
    top = 0;  
    for(int i = 1; i <= n; ++i)  
    {  
        pre[i] = 1;  
        lowcost[i] = map[1][i];  
    }  
    lowcost[1] = 0;  
    stack[top++] = 1; //����MST�Ľ��  
  
    for(int i = 1; i <= n; ++i)  
    {  
        temp = INT_MAX;  
        for(int j = 1; j <= n; ++j)  
            if(!visit[j] && temp > lowcost[j])  
                temp = lowcost[k = j];  
        if(temp == INT_MAX)  
            break;  
        visit[k] = true;  
        sum += temp;  
        for(int j = 0; j < top; ++j) //�¼���㵽MST����·�����ֵ  
            max1[stack[j]][k] = max1[k][stack[j]] = max(max1[stack[j]][pre[k]], temp);  
        stack[top++] = k; //����MST�Ľ��  
  
        for(int j = 1; j <= n; ++j) //����  
            if(!visit[j] && lowcost[j] > map[k][j])  
            {  
                lowcost[j] = map[k][j];  
                pre[j] = k; //��¼ֱ��ǰ��  
            }  
    }  
}  
  
int main()  
{  
    int ncase;  
    int start, end, cost;  
    int minn;  
    scanf("%d", &ncase);  
    while(ncase--)  
    {  
        for(int i = 1; i < N; ++i) //��ʼ����Ϊ0,1������ѭ����������  
            for(int j = 1; j < N; ++j)  
            {  
                map[i][j] = INT_MAX;  
                max1[i][j] = 0;  
            }  
        scanf("%d%d", &n, &m);  
        for(int i = 1; i <= m; ++i)  
        {  
            scanf("%d%d%d", &start, &end, &cost);  
            //if(cost < map[start][end])(POJ��Ȼ�����رߵ�ʱ��ѡ����С��~~~)  
            map[start][end] = map[end][start] = cost;  
        }  
        prim();  
        minn = INT_MAX;  
        for(int i = 1; i <= n; ++i)  
            for(int j = 1; j <= n; ++j)  
                if(i != j && i != pre[j] && j != pre[i]) //ö��MST����ı�  
                    minn = min(minn, map[i][j] - max1[i][j]); //���{MST������-MST����Ȩֵ����}��Сֵ  
        if(minn != 0)  
            printf("No\n");  
        else  
            printf("Yes\n");  
    }  
    return 0;  
}   