DAG的单源最短路
d[i] = min{d[j] + (从j到i的边权)}
DFS + 记忆化 复杂度O(n)

Bellman-Ford算法
struct edge{int from, to, cost;}; //从顶点from指向顶点to的权值为cost的边

edge es[MAX_E];//边

int d[MAX_V];//最短距离

int V,E;//V是顶点数，E是边数

//求解从顶点s出发到所有点的最短距离
void shortest_path(int s) {
	for(int i = 0; i < V; i++) d[i] = INF;
	d[s] = 0;
	while(true) {
		bool update = false;
		for(int i = 0; i < E; i++) {
			edge e = es[i];
			if(d[e.form] != INF && d[e.to] > d[e.form] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update) break;
	}
}
每次遍历都会得到部分点的单源最短路
如果不存在从S可达的负圈，while循环最多执行V-1次,复杂度O(VE)
一开始对所有的点初始化为0可以检查所有的负圈

bool find_negative_loop() {
	memset(d, 0, sizeof(d));
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < E; j++) {
			edge e = es[j];
			if(d[e.to] > d[e.form] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				if(i == V - 1) return true;
			}
		}
	}
	return false;
}

int cost[MAX_V][MAX_V]; //
int d[MAX_V];
bool used[MAX_V];
int prev[MAX_V];
int V;

void dijkstra(int s) {
	fill(d, d + V, INF);
	fill(used, used + V, false);
	fill(prev, prev + V, -1);
	d[s] = 0;
	
	while(true) {
		int v = -1;
		for(int u = 0; u < V; u++) {
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if(v == -1) break;
		used[v] = true;
		for(int u = 0; u < V; u++) {
			if(d[u] > d[v] + cost[v][u]) {
				d[u] = d[v] + cost[v][u];
				prev[u] = v;
			}
		}
	}
}

vector<int> get_path(int t) {
	vector<int> path;
	for(; t != -1; t = prev[t]) path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}