DAG�ĵ�Դ���·
d[i] = min{d[j] + (��j��i�ı�Ȩ)}
DFS + ���仯 ���Ӷ�O(n)

Bellman-Ford�㷨
struct edge{int from, to, cost;}; //�Ӷ���fromָ�򶥵�to��ȨֵΪcost�ı�

edge es[MAX_E];//��

int d[MAX_V];//��̾���

int V,E;//V�Ƕ�������E�Ǳ���

//���Ӷ���s���������е����̾���
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
ÿ�α�������õ����ֵ�ĵ�Դ���·
��������ڴ�S�ɴ�ĸ�Ȧ��whileѭ�����ִ��V-1��,���Ӷ�O(VE)
һ��ʼ�����еĵ��ʼ��Ϊ0���Լ�����еĸ�Ȧ

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