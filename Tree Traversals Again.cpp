#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> temp;
vector<int> in;
vector<int> pre;
vector<int> post;

void postorder(int root, int start, int end){
	if(start > end) return;
	int i = start;
	while(i < end && in[i] != pre[root]) i++;
	postorder(root + 1, start, i - 1);
	postorder(root + 1 + i - start, i + 1, end);
	post.push_back(pre[root]);
}

int main(){
	int n, x;
	scanf("%d", &n);
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		if(str == "Push"){
			scanf("%d", &x);
			temp.push_back(x);
			pre.push_back(x);
		}else{
			in.push_back(temp[temp.size() - 1]);
			temp.pop_back();
		}
	}
	postorder(0, 0, n - 1);
	printf("%d", post[0]);
	for(int i = 1; i < n; i++){
		printf(" %d", post[i]);
	}

	return 0;
}