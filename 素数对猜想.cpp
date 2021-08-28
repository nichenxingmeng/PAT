#include<iostream>
using namespace std;

const int maxn = 100010;
int prime[maxn];
bool p[maxn] = {false};

void Prime(){
	int cnt = 0;
	for(int i = 2; i < maxn; i++){
		if(!p[i]){
			prime[cnt++] = i;
			for(int j = 2; j * i < maxn; j++){
				p[j * i] = true;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);

	Prime();

	int ans = 0, cnt = 0;
	for(int i = 0; prime[i] <= n; i++){
		if((prime[i + 1] - prime[i]) == 2) ans++;
		cnt++;
	}
	if((prime[cnt] - prime[cnt - 1]) == 2) ans--;
	printf("%d", ans);

	system("pause");
	return 0;
}