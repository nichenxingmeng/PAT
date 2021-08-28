#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int num[4];

bool cmp(int a, int b){
	return a > b;
}

void num2list(int num[], int n){
	int temp = 0;
	for(int i = 0; i < 4; i++){
		temp = pow(10, 3 - i);
		num[i] = n / temp;
		n = n % temp;
	}
	return;
}

int main(){
	int n, ans = 0;
	scanf("%d", &n);
	num2list(num, n);

	do{
		sort(num, num + 4, cmp);
		ans = 0;
		for(int i = 0; i < 4; i++){
			ans += num[i] * pow(10, 3 - i);
			printf("%d", num[i]);
		}
		printf(" - ");
		for(int i = 3; i >= 0; i--){
			ans -= num[i] * pow(10, i);
			printf("%d", num[i]);
		}
		printf(" = ");
		num2list(num, ans);
		for(int i = 0; i < 4; i++){
			printf("%d", num[i]);
		}
		printf("\n");
	}while(ans != 0 && ans != 6174);

	system("pause");
	return 0;
}