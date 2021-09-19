#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
	int v, height;
	node* lchild;
	node* rchild;
};

int getHeight(node* root){
	if(root == NULL) return 0;
	else return root->height;
}

void insert(node* &root, int v, int h){
	if(root == NULL){
		root = new node;
		root->height = h + 1;
		root->v = v;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(v <= root->v){
        insert(root->lchild, v, getHeight(root));
    }
	else{
        insert(root->rchild, v, getHeight(root));
    }
}

int num[1010];

int main(){
    fill(num, num + 1010, 0);
	int n, k;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		insert(root, k, 0);
	}
	int cnt;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		num[temp->height]++;
		if(temp->lchild != NULL) q.push(temp->lchild );
		if(temp->rchild != NULL) q.push(temp->rchild );
	}
    for(int i = 1009; i>= 0; i--){
        if(num[i] != 0){
            cnt = i;
            break;
        }
    }
	printf("%d + %d = %d", num[cnt], num[cnt - 1], num[cnt] + num[cnt - 1]);

	return 0;
}