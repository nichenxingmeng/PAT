#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1000;
int prime[maxn], pnum = 0;
bool p[maxn] = {0};

void Find_Prime(){
	for(int i = 2; i < maxn; i++){
		if(! p[i]){
			prime[pnum++] = i;
			for(int j = 2; i * j < maxn; j++){
				p[i * j] = true;
			}
		}
	}
}

struct factor{
	int x, cnt;
}fac[10];

int main(){
	Find_Prime();
	int n;
	scanf("%d", &n);
	if(n == 1){
		printf("1=1");
	} else{
		printf("%d=", n);
		int num = 0;
		for(int i = 0; prime[i] <= sqrt(n); i++){
			if(n % prime[i] == 0){
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(n % prime[i] == 0){
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
		}
		if(n != 1){
			fac[num].x = n;
			fac[num].cnt = 1;
			num++;
		}
		for(int i = 0; i < num - 1; i++){
			printf("%d", fac[i].x);
			if(fac[i].cnt != 1){
				printf("^%d", fac[i].cnt);
			}
			printf("*");
		}
		printf("%d", fac[num - 1].x);
		if(fac[num - 1].cnt != 1){
			printf("^%d", fac[num - 1].cnt);
		}
	}
	
	return 0;
}