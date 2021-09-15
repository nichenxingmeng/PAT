#include<iostream>
using namespace std;

const int maxn = 10005;
int temp[maxn];

int main(){
	int n, num;
	scanf("%d", &n);
	fill(temp, temp + maxn, 0);
	for(int i = 0; i < n; i++){
		scanf("%d", num);
		temp[num]++;
	}
	for(int i = 0; i < maxn; i++){
		if(temp[i] == 1){
			cout << i;
			return 0;
		}
	}
	cout << "None";

	return 0;
}