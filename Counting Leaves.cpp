#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 105;

struct Node{
	int height;
	vector<int> child;
}node[maxn];

int height[maxn] = {0};

int main(){
	int n, m, id, k, child = 0, maxH = 1;
	scanf("%d%d", &n, &m);
	node[1].height = 1;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
	}
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(node[now].child.size() == 0){
			height[node[now].height]++;
		} else{
			for(int i = 0 ; i + node[now].child.begin() < node[now].child.end(); i++){
				node[node[now].child[i]].height = node[now].height + 1;
				if(node[node[now].child[i]].height > maxH) maxH = node[node[now].child[i]].height;
				q.push(node[now].child[i]);
			}
		}
	}
	for(int i = 1; i < maxH; i++){
		printf("%d ", height[i]);
	}
	printf("%d", height[maxH]);

	return 0;
}