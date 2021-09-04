#include<iostream>
#include<algorithm>
using namespace std;

int num[100010];

bool cmp(int a, int b){
	return a < b;
}

int main(){
	int n, p, temp = 0;
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	sort(num, num + n, cmp);

	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= 0; j--){
			if(num[j] <= p * num[i]){
				if(j - i + 1 > temp){
					temp = j - i + 1;
				} 
			}
		}
	}
	cout << temp;

	system("pause");
	return 0;
}