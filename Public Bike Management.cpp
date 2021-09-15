#include<iostream>
#include<vector>
using namespace std;

const int INF = 1000000000;
const int maxn = 505;
int G[maxn][maxn], d[maxn], bike[maxn], b[maxn];
bool vis[maxn] = {false};
int c, n, s, m, st, ed, t;
int min1 = INF, min2 = INF, cnt;
vector<int> pre[maxn];
vector<int> temp;
vector<int> path;

void Dijkstra(int s){
	d[s] = 0;
	b[s] = 0;
	for(int i = 0; i <= n; i++){
		int u = -1, min = INF;
		for(int j = 0; j <= n; j++){
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	return;
}

void DFS(int v){
	if(v == 0){
        temp.push_back(v);

        int bring = 0, need, bycicle = 0;
		for(int i = temp.size() - 2; i >= 0; i--){
			if(bike[temp[i]] < c / 2){
				need = c / 2 - bike[temp[i]];
				if(bycicle < need){
					need -= bycicle;
					bycicle = 0;
				} else{
					bycicle -= need;
					need = 0;
				}
				if(need > 0){
					bring += need;
				}
			} else if(bike[temp[i]] > c / 2){
				need = bike[temp[i]] - c / 2;
				bycicle += need;
			}
		}
		if(bring < min1){
			min1 = bring;
			min2 = bycicle;
			path = temp;
		} else if(bring == min1){
			if(bycicle < min2){
				min2 = bycicle;
				path = temp;
			}
		}

		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
    temp.pop_back();
}

int main(){
	fill(G[0], G[0] + maxn * maxn, INF);
	fill(d, d + maxn, INF);
	fill(b, b + maxn, 0);
	scanf("%d%d%d%d", &c, &n, &s, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &bike[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &st, &ed, &t);
		G[st][ed] = G[ed][st] = t;
	}
    
	Dijkstra(0);
    DFS(s);

    printf("%d ", min1);
    for(int i = path.size() - 1; i > 0; i--){
        printf("%d->", path[i]);
    }
    printf("%d", path[0]);
	printf(" %d", min2);

	return 0;
}