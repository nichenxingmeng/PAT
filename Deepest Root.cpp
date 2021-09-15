#include<iostream>
#include<vector>
using namespace std;

const int maxn = 10010;
int n, st, ed, father[maxn], fa[maxn];
bool vis[maxn];
vector<int> Adj[maxn];
int MAX = 0;
vector<int> temp;
vector<int> A;
vector<int> path;
int ans[maxn];

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

void DFS(int s){
    bool flag = false;
    for(int i = 0; i < Adj[s].size(); i++){
        if(vis[Adj[s][i]] == false){
            vis[Adj[s][i]] = true;
            path.push_back(Adj[s][i]);
            DFS(Adj[s][i]);
            vis[Adj[s][i]] = false;
            path.pop_back();
        }
    }
    if(!flag){
        if(path.size() > MAX){
            MAX = path.size();
            temp.clear();
            temp.push_back(s);
        } else if(path.size() == MAX){
            temp.push_back(s);
        }
        return;
    }
    return;
}

int main(){
	fill(fa, fa + maxn, 0);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &st, &ed);
		Adj[st].push_back(ed);
		Adj[ed].push_back(st);
		int fa1 = find(st);
		int fa2 = find(ed);
		if(fa1 != fa2){
			father[fa1] = fa2;
		}
	}
	for(int i = 1; i <= n; i++){
		fa[find(i)] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += fa[i];
	}
	if(cnt != 1){
		printf("Error: %d components", cnt);
        return 0;
	}
    
    path.clear();
    path.push_back(1);
    fill(vis, vis + maxn, false);
    vis[1] = true;
    DFS(1);
    A = temp;
    path.clear();
    temp.clear();
    path.push_back(A[0]);
    fill(vis, vis + maxn, false);
    vis[A[0]] = true;
    DFS(A[0]);
    
    
    fill(ans, ans + maxn, 0);
    for(int i = 0; i < temp.size(); i++){
        ans[temp[i]]++;
    }
    for(int i = 0; i < A.size(); i++){
        ans[A[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(ans[i] > 0){
            printf("%d\n", i);
        }
    }
    
	system("pause");
	return 0;
}