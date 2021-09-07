#include<iostream>
using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

int n;
int G[MAXV][MAXV], weight[MAXV][MAXV], d[MAXV], w[MAXV];
int pre[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
	fill(d, d + MAXV, INF);
    fill(w, w + MAXV, INF);
	for(int i = 0; i < n; i++) pre[i] = i;
	d[s] = 0;
    w[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
        vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[u][v];
					pre[v] = u;
				} else if(d[u] + G[u][v] == d[v]){
					if(w[u] + weight[u][v] < w[v]){
						w[v] = w[u] + weight[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

void DFS(int s, int v){
	if(v == s){
		printf("%d ", s);
		return;
	}
	DFS(s, pre[v]);
	printf("%d ", v);
}

int main(){
	int m, s, D;
	scanf("%d%d%d%d", &n, &m, &s, &D);
	int u, v, dis, cos;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d%d", &u, &v, &dis, &cos);
		G[u][v] = G[v][u] = dis;
		weight[u][v] = weight[v][u] = cos;
	}
	Dijkstra(s);
	DFS(s, D);
	printf("%d %d", d[D], w[D]);

	return 0;
}