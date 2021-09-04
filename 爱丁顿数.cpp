#include<iostream>
using namespace std;

const int maxn = 15;

int main(){
	int n;
	scanf("%d", &n);
	int num[maxn] = {0}, ans;
	for(int i = 0; i < n; i++){
		scanf("%d", &ans);
		num[ans]++;
	}
	int cnt = n - num[0], temp = 0;
	for(int i = 0; i < maxn - 1; i++){
		cnt -= num[i + 1];
		if(cnt >= i + 1){
			temp = i + 1;
		}
	}
	printf("%d", temp);

	system("pause");
	return 0;
}