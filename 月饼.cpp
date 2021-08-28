#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1010;

struct mooncake{
	double weight;
	double price;
	double danjia;
}cake[maxn];

bool cmp(mooncake a, mooncake b){
	return a.danjia > b.danjia;
}

int main(){
	int n, need;
	double ans = 0;
	scanf("%d %d", &n, &need);
	for(int i = 0; i < n; i++){
		scanf("%lf", &cake[i].weight);
	}
	for(int i = 0; i < n; i++){
		scanf("%lf", &cake[i].price);
		cake[i].danjia = cake[i].price / cake[i].weight;
	}
	sort(cake, cake + n, cmp);
	for(int i = 0; i < n; i++){
		if(need < cake[i].weight){
			ans += need * cake[i].danjia;
			break;
		}
		else{
			ans += cake[i].price;
			need -= cake[i].weight;
		}
	}
	printf("%.2lf", ans);

	system("pause");
	return 0;
}
