#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const int maxn = 100010;

int n, num[maxn], cnt = 0, ans = 0;
double p, r;
vector<int> Adj[maxn];
bool vis[maxn] = {false};

void DFS(int s){
	if(Adj[s].empty()){
		ans += (p * num[s]) * pow(1 + r / 100, cnt);
		return;
	}else{
		vis[s] = true;
		for(int i = 0; i < Adj[s].size(); i++){
			if(vis[Adj[s][i]] == false){
				cnt++;
				DFS(Adj[s][i]);
				cnt--;
			}
		}
	}
}

int main(){
	scanf("%d%lf%lf", &n, &p, &r);
	int k, kj;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0){
			scanf("%d", &num[i]);
		}else{
			for(int j = 0; j < k; j++){
				scanf("%d", kj);
				Adj[j].push_back(kj);
			}
		}
	}
	DFS(0);
	cout << ans << endl;

	return 0;
}