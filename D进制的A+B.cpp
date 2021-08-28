#include<iostream>
using namespace std;

int main(){
	int A, B, D, sum, i = 0;
	int ans[51];
	scanf("%d %d %d", &A, &B, &D);
	sum = A + B;
	do{
		ans[i] = sum % D;
		i++;
		sum /= D;
	} while(sum != 0);
	for(int j = i - 1; j >= 0; j--){
		printf("%d", ans[j]);
	}

	system("pause");
	return 0;
}