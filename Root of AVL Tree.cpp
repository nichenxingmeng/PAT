#include<iostream>
using namespace std;

const int maxn = 25;

int n, num[maxn];

struct node{
	int v, height;
	node* lchild;
	node* rchild;
};

int getHeight(node* root){
	if(root == NULL) return 0;
	return root->height;
}

int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int v){
	if(root == NULL){
        root = new node;
		root->v = v;
		root->height = 1;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(v < root->v){
		insert(root->lchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			}else if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

node* Create(int data[]){
	node* root = NULL;
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	}
	return root;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	node* root = Create(num);
	cout << root->v << endl;

	return 0;
}