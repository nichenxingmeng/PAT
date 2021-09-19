#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node{
	int lchild, rchild;
};

Node node[15]; 
int father[15];
int root;
bool flag = false;

int change(string str){
	int ans = 0, cnt = 1;
	for(int i = str.size() - 1; i>= 0; i--){
		ans += (str[i] - '0') * cnt;
		cnt *= 10;
	}
    return ans;
}

void DFS(int s){
    if(node[s].lchild == -1 && node[s].rchild == -1){
        if(!flag) printf("%d", s);
        else printf(" %d", s);
        flag = true;
        return;
    }
    if(node[s].lchild != -1) DFS(node[s].lchild);
    if(!flag) printf("%d", s);
    else printf(" %d", s);
    flag = true;
    if(node[s].rchild != -1) DFS(node[s].rchild);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		father[i] = i;
	}
	string lc, rc;
	int lc_, rc_;
	for(int i = 0; i < n; i++){
		cin >> lc >> rc;
		if(lc == "-"){
			lc_ = -1;
		}else{
			lc_ = change(lc); 
			father[lc_] = i;
		}
		if(rc == "-"){
			rc_ = -1;
		}else{
			rc_ = change(rc); 
			father[rc_] = i;
		}
		node[i].rchild = lc_;
		node[i].lchild = rc_;
	}
	for(int i = 0; i < n; i++){
		if(father[i] == i){
            root = i;
            break;
        }
	}
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(temp == root) printf("%d", temp);
        else printf(" %d", temp);
        if(node[temp].lchild != -1) q.push(node[temp].lchild);
        if(node[temp].rchild != -1) q.push(node[temp].rchild);
    }
    printf("\n");
    DFS(root);

	return 0;
}