#include<iostream>
using namespace std;

struct Node{
	bool flag;
	double num;
	Node(){
		flag = false;
		num = 0;
	}
}node[1010];

int main(){
	int k1, k2, n, cnt = 0;
	double a;
	scanf("%d", &k1);
	for(int i = 0; i < k1; i++){
		scanf("%d", &n);
		scanf("%lf", &a);
		node[n].flag = true;
		node[n].num += a;
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; i++){
		scanf("%d", &n);
		scanf("%lf", &a);
		node[n].flag = true;
		node[n].num += a;
	}
	for(int i = 0; i < 1010; i++){
		if(node[i].num != 0) cnt++;
	}
	printf("%d", cnt);
	for(int i = 1009; i >= 0; i--){
		if(node[i].num != 0){
			printf(" %d %.1lf", i, node[i].num);
		}
	}

	return 0;
}