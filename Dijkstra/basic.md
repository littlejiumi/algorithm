const int maxn = 1000;
const int INF = 1000000000;
//邻接矩阵版
int n,int G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int MIN = INF, u = -1;
		for (int j = 0; j < n; j++) {		
			if (vis[j]==false&&d[j] < MIN) {
				u = j;
				MIN = d[u];
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] < INF && d[v]>d[u] + G[u][v]) {
				d[v] = d[u] + G[u][v];
			}
		}
	}
}
//邻接表版
const int maxn = 1000;
const int INF = 1000000000;

struct node {
	int v, dis;//点权，边权
};
vector<node> Adj[maxn];
int n;
bool vis[maxn] = { false };
int d[maxn];   //从起点出发的距离

void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)return;
		vis[u] == true;
    //只有以下不同
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			if (vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
				d[v]=d[u] + Adj[u][j].dis;
			}
		}
	}


}

