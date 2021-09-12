#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1005;
int G[maxn][maxn];
int father[maxn];
vector<int> change;

int find(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int main(){
	int n, m, k, u, v, city;
	fill(G[0], G[0] + maxn * maxn, 0);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
    
	for(int i = 0; i < k; i++){
		scanf("%d", &city);
		for(int j = 1; j <= n; j++){
			father[j] = j;
		}
        
        change.clear();
		for(int j = 1; j <= n; j++){
            if(G[j][city] == 1){
                G[j][city] = 0;
                G[city][j] = 0;
                change.push_back(j);
            }
		}
		int num = 0;
		int vis[maxn] = {0};
		for(int j = 1; j <= n; j++){
			for(int a = 1; a <= n; a ++){
				if(G[j][a] == 1){
					int fa1 = find(j);
					int fa2 = find(a);
					if(fa1 != fa2){
						father[fa2] = fa1; 
					}
				}
			}
		}
        
		for(int j = 1; j <= n; j++){
            if(j != city) vis[father[j]] = 1;
		}
		for(int j = 1; j <= n; j++){
			num += vis[j];
		}
        
        for(int j = 0; j < change.size(); j++){
            G[city][change[j]] = 1;
            G[change[j]][city] = 1;
        }
		printf("%d\n", num - 1);
	}

	return 0;
}