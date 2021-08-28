#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN = 100010;
const int MOD = 1000000007;

int main(){
	char str[MAXN];
	scanf("%s", str);
	int len = strlen(str), ans = 0;
	int num_P[MAXN] = {0}, num_T[MAXN] = {0};

	if(str[0] == 'P') num_P[0] = 1;

	for(int i = 1; i < len; i++){
		if(str[i] == 'P') num_P[i] = num_P[i - 1] + 1;
		else num_P[i] = num_P[i - 1];
	}

	if(str[len - 1] == 'T') num_T[len - 1] = 1;

	for(int i = len - 2; i >= 0; i--){
		if(str[i] == 'T') num_T[i] = num_T[i + 1] + 1;
		else num_T[i] = num_T[i + 1];
	}

	for(int i = 0; i < len; i++){
		if(str[i] == 'A'){
			ans += (num_P[i] * num_T[i]) % MOD; 
			ans %= MOD;
		}
	}

	printf("%d", ans);
	return 0;
}