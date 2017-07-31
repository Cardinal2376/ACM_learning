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
  
void prim() //默认1在MST中  
{  
    int temp, k;  
    int top; //保存最小生成树的结点  
  
    memset(visit, false, sizeof(visit)); //初始化  
    visit[1] = true;  
    sum = 0;  
    top = 0;  
    for(int i = 1; i <= n; ++i)  
    {  
        pre[i] = 1;  
        lowcost[i] = map[1][i];  
    }  
    lowcost[1] = 0;  
    stack[top++] = 1; //保存MST的结点  
  
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
        for(int j = 0; j < top; ++j) //新加入点到MST各点路径最大值  
            max1[stack[j]][k] = max1[k][stack[j]] = max(max1[stack[j]][pre[k]], temp);  
        stack[top++] = k; //保存MST的结点  
  
        for(int j = 1; j <= n; ++j) //更新  
            if(!visit[j] && lowcost[j] > map[k][j])  
            {  
                lowcost[j] = map[k][j];  
                pre[j] = k; //记录直接前驱  
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
        for(int i = 1; i < N; ++i) //初始化不为0,1必须用循环。。。。  
            for(int j = 1; j < N; ++j)  
            {  
                map[i][j] = INT_MAX;  
                max1[i][j] = 0;  
            }  
        scanf("%d%d", &n, &m);  
        for(int i = 1; i <= m; ++i)  
        {  
            scanf("%d%d%d", &start, &end, &cost);  
            //if(cost < map[start][end])(POJ竟然出现重边的时候不选择最小的~~~)  
            map[start][end] = map[end][start] = cost;  
        }  
        prim();  
        minn = INT_MAX;  
        for(int i = 1; i <= n; ++i)  
            for(int j = 1; j <= n; ++j)  
                if(i != j && i != pre[j] && j != pre[i]) //枚举MST以外的边  
                    minn = min(minn, map[i][j] - max1[i][j]); //求出{MST外加入边-MST环上权值最大边}最小值  
        if(minn != 0)  
            printf("No\n");  
        else  
            printf("Yes\n");  
    }  
    return 0;  
}   