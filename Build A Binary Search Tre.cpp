#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct node{
	int lchild;
	int rchild;
};

map<int, int> temp;

node root[105];
int num[105];
vector<int> ans;

void in(int s){
	if(s == -1 ){
		return;
	}
    in(root[s].lchild);
	ans.push_back(s);
	in(root[s].rchild);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &root[i].lchild, &root[i].rchild);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	in(0);
	for(int i = 0; i < n; i++){
		temp[ans[i]] = num[i];
	}
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int temp_ = q.front();
        q.pop();
        if(temp_ == 0) printf("%d", temp[temp_]);
        else printf(" %d", temp[temp_]);
        if(root[temp_].lchild != -1) q.push(root[temp_].lchild);
        if(root[temp_].rchild != -1) q.push(root[temp_].rchild);
    }

	return 0;
}