#include<iostream>
using namespace std;

int num[105];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	m = m % n;
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	for(int i = n - m; i < n; i++){
		printf("%d ", num[i]);
	}
	for(int i = 0; i < n - m - 1; i++){
		printf("%d ", num[i]);
	}
	printf("%d", num[n - m - 1]);

	system("pause");
	return 0;
}
