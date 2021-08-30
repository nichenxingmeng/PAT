#include<iostream>
#include<vector>
using namespace std;

vector<int> add;

struct Node{
	int address, data, next;
}node[100000];

int main(){
	int start, n, k, address, start_;
	scanf("%d %d %d", &start, &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d %d", &node[address].data, &node[address].next);
	}
	start_ = start;
	while(node[start_].next != -1){
		if(node[start_].data < 0){
			add.push_back(start_);
		}
		start_ = node[start_].next;
	}
	start_ = start;
	while(node[start_].next != -1){
		if(node[start_].data >= 0 && node[start_].data <= k){
			add.push_back(start_);
		}
		start_ = node[start_].next;
	}
	start_ = start;
	while(node[start_].next != -1){
		if(node[start_].data > k){
			add.push_back(start_);
		}
		start_ = node[start_].next;
	}
	for(int i = 0; i < add.size(); i++){
		if(i != add.size() - 1){
			printf("%d %d %d\n", add[i], node[add[i]].data, add[i + 1]);
		} else{
			printf("%d %d %d", add[i], node[add[i]].data, -1);
		}
	}

	system("pause");
	return 0;
}