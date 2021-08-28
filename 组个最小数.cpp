#include<iostream>

using namespace std;

int main(){
	int n = 1, num[10], ans[55];
	for(int i = 0; i < 10; i++){
		scanf("%d", &num[i]);
	}
	for(int i = 1; i < 10; i++){
		if(num[i] != 0){
			ans[0] = i;
			num[i] -= 1;
			break;
		}
	}
	for(int i = 0; i < 10; i++){
		for(int j = 1; j <= num[i]; j++){
			ans[n] = i;
			n += 1;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d", ans[i]);
	}

	system("pause");
	return 0;
}