#include<iostream>
#include<string>
#include<map>
using namespace std;

const int maxn = 205;
const int INF = 1000000000;

int n, k, s, num = 0, cnt[maxn];
int G[maxn][maxn], d[maxn], happy[maxn], h[maxn], pre[maxn], len[maxn];
bool vis[maxn] = {false};
map<string, int> string2int;
map<int, string> int2string;

void Dijkstra(int s){
	d[s] = 0;
	len[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, min = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					h[v] = h[u] + happy[v];
					len[v] = len[u] + 1;
					pre[v] = u;
					cnt[v] = cnt[u];
				}else if(d[u] + G[u][v] == d[v]){
					cnt[v] += cnt[u];
					if(h[u] + happy[v] > h[v]){
						h[v] = h[u] + happy[v];
						len[v] = len[u] + 1;
						pre[v] = u;
					}else if(h[u] + happy[v] == h[v]){
						if(len[u] + 1 < len[v]){
							len[v] = len[u] + 1;
							pre[v] = u; 
						}
					}
				}
			}
		}
	}
}

int change(string str){
	if(string2int.find(str) != string2int.end()){
		return string2int[str];
	}else{
		string2int[str] = num;
		int2string[num++] = str;
		return num - 1;
	}
}

void DFS(int v){
	if(v == 0){
		cout << int2string[0];
		return;
	}else{
		DFS(pre[v]);
		cout << "->" << int2string[v];
	}
}

int main(){
	string s_string;
	fill(G[0], G[0] + maxn * maxn, INF);
	fill(d, d + maxn, INF);
	fill(h, h + maxn, 0);
    fill(happy, happy + maxn, 0);
	fill(len, len + maxn, INF);
    fill(cnt, cnt + maxn, 1);
	scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        pre[i] = i;
    }
	cin >> s_string;
	s = change(s_string);
	for(int i = 0; i < n - 1; i++){
		cin >> s_string;
		scanf("%d", &happy[change(s_string)]);
	}
	string u_str, v_str;
	int u, v;
	for(int i = 0; i < k; i++){
		cin >> u_str >> v_str;
		u = string2int[u_str];
		v = string2int[v_str];
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(0);
    int ans = string2int["ROM"];
	printf("%d %d %d %d\n", cnt[ans], d[ans], h[ans], h[ans] / len[ans]);
	DFS(string2int["ROM"]);

	return 0;
}