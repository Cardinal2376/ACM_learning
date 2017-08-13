/***************************
	Ford-Fulkerson�㷨 O(FE)
***************************/

//���ڱ�ʾ�ߵĽṹ�壨�յ㡢����������ߣ�
struct edge{int to, cap, rev;};

const int MAX_V = 505, MAX_M = 10005;
const int INF = 0x3f3f3f3f;
vector<edge> G[MAX_V]; //ͼ���ڽӱ�ʾ
bool used[MAX_V];      //DFS�õ��ķ��ʱ��

//��ͼ�����һ����S��T����Ϊcap�ı�
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

//ͨ��DFSѰ������·
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

//����S��T�������
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
	Dinic�㷨 O(V2E)
***************************/
//���ڱ�ʾ�ߵĽṹ�壨�յ㡢����������ߣ�
struct edge{int to, cap, rev;};

const int MAX_V = 505, MAX_M = 10005;
const int INF = 0x3f3f3f3f;
vector<edge> G[MAX_V];  //ͼ���ڽӱ�ʾ
int level[MAX_V];       //���㵽Դ��ľ�����
int iter[MAX_V];        //��ǰ��������֮ǰ�ı��Ѿ�û������

//��ͼ�����һ����S��T����Ϊcap�ı�
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

//ͨ��BFS�����Դ������ľ�����
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
//ͨ��DFSѰ������·
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

//����S��T�������
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
