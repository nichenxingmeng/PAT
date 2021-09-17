#include<iostream>
#include<vector>
using namespace std;

const int maxn = 105;

vector<int> Adj[maxn];
int len[maxn];
bool vis[maxn] = {false};

void DFS(int s, int length){
	if(Adj[s].empty()){
		len[length]++;
		return;
	}else{
		vis[s] = true;
		for(int i = 0; i < Adj[s].size(); i++){
			int temp = Adj[s][i];
			if(vis[temp] == false){
				DFS(temp, length + 1);
			}
		}
		vis[s] = false;
	}
}

int main(){
	fill(len, len + maxn, 0);
	int n, m, fa, k, child;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &fa, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			Adj[i].push_back(child);
		}
	}
	DFS(1, 1);
	int ans, max = -1;
	for(int i = 1; i <= n; i++){
		if(len[i] > max){
			ans = i;
			max = len[i];
		}
	}
	printf("%d %d", max, ans);

	return 0;
}