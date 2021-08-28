#include<iostream>
using namespace std;

int main(){
	int n;
	char c;
	scanf("%d %c", &n, &c);
	for(int i = 0; i < n; i++){
		printf("%c", c);
	}
	printf("\n");
	int temp;
	if(n & 1) temp = n / 2 - 1;
	else temp = n / 2 - 2;
	for(int i = 0; i < temp; i++){
		for(int i = 0; i < n; i++){
			if(i == 0 || i == n - 1) printf("%c", c);
			else printf(" ");
		}
		printf("\n");
	}
	for(int i = 0; i < n; i++){
		printf("%c", c);
	}

	system("pause");
	return 0;
}