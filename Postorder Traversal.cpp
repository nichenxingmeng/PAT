#include<iostream>
#include<vector>
using namespace std;

const int maxn = 50010;
int pre[maxn], in[maxn];
vector<int> post;

void postOrder(int preL, int preR, int inL, int inR){
	if(preL > preR || inL > inR){
        return;
    }
	int root = inL;
	while(in[root] != pre[preL]) root++;
	postOrder(preL + 1, preL + root - inL, inL, root - 1);
	postOrder(preL + root - inL + 1, preR, root + 1, inR);
	post.push_back(in[root]);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}
	postOrder(0, n - 1, 0, n - 1);
	printf("%d", post[0]);

	return 0;
}