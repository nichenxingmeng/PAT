#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int xiangshu;
	double xishu;
};
double num[1005] = {0};
vector<Node> num1;

int main(){
	int k;
	scanf("%d", &k);
	int a;
	double b;
	Node temp;
	for(int i = 0; i < k; i++){
		scanf("%d%lf", &a, &b);
		temp.xiangshu = a;
		temp.xishu = b;
		num1.push_back(temp);
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d%lf", &a, &b);
		for(int j = 0; j < num1.size(); j++){
			num[num1[j].xiangshu * a] += num1[j].xishu * b;
		}
	}
	int cnt = 0;
	for(int i = 1001; i >= 0; i--){
		if(num[i] != 0){
			cnt++;
		}
	}
	printf("%d ", cnt);
	for(int i = 1001; i >= 0; i--){
		if(num[i] != 0){
			cnt--;
			if(cnt != 0){
				printf("%d %lf ", i, num[i]);
			} else{
				printf("%d %lf\n", i, num[i]);
			}
		}
	}
	
	return 0;
}