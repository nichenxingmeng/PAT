#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct node{
	int data, next;
}Node[100010];

int num[10010];
vector<int> ans1, ans2;

int main(){
	fill(num, num + 10010, 0);
	int st, n, address;
	scanf("%d%d", &st, &n);
    if(n == 0) return 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &Node[address].data, &Node[address].next);
	}
	ans1.push_back(st);
	num[abs(Node[st].data)]++;
	while(Node[st].next != -1){
		node temp = Node[Node[st].next];
		if(num[abs(temp.data)] > 0){
			ans2.push_back(Node[st].next);
		}else{
			ans1.push_back(Node[st].next);
		}
		num[abs(temp.data)]++;
		st = Node[st].next;
	}
    if(!ans1.empty()){
	    for(int i = 0; i < ans1.size() - 1; i++){
		    printf("%05d %d %05d\n", ans1[i], Node[ans1[i]].data, ans1[i + 1]);
	    }
	    printf("%05d %d -1\n", ans1[ans1.size() - 1], Node[ans1[ans1.size() - 1]].data);
    }
    if(!ans2.empty()){
	    for(int i = 0; i < ans2.size() - 1; i++){
		    printf("%05d %d %05d\n", ans2[i], Node[ans2[i]].data, ans2[i + 1]);
	    }
	    if(!ans2.empty()) printf("%05d %d -1\n", ans2[ans2.size() - 1], Node[ans2[ans2.size() - 1]].data);
    }

	system("pause");
	return 0;
}