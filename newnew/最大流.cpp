/***************************
	Ford-Fulkerson算法 O(FE)
***************************/

//用于表示边的结构体（终点、容量、反向边）
struct edge{int to, cap, rev;};

const int MAX_V = 505, MAX_M = 10005;
const int INF = 0x3f3f3f3f;
vector<edge> G[MAX_V]; //图的邻接表示
bool used[MAX_V];      //DFS用到的访问标记

//向图中添加一条从S到T容量为cap的边
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

//通过DFS寻找增广路
int dfs(int v, int t, int f) {
    if(v == t) return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

//求解从S到T的最大流
int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        //printf("f : %d\n", f);
        if (f == 0) return flow;
        flow += f;
    }
}

/***************************
	Dinic算法 O(V2E)
***************************/
//用于表示边的结构体（终点、容量、反向边）
struct edge{int to, cap, rev;};

const int MAX_V = 505, MAX_M = 10005;
const int INF = 0x3f3f3f3f;
vector<edge> G[MAX_V];  //图的邻接表示
int level[MAX_V];       //顶点到源点的距离编号
int iter[MAX_V];        //当前弧，在其之前的边已经没有用了

//向图中添加一条从S到T容量为cap的边
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

//通过BFS计算从源点出发的距离标号
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
//通过DFS寻找增广路
int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

//求解从S到T的最大流
int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}
