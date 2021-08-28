#include<iostream>
using namespace std;

const int maxn = 110000;
int prime[maxn], pnum = 0;
bool p[maxn] = {0};

void Find_Prime(){
	for(int i = 2; i < maxn; i++){
		if(! p[i]){
			prime[pnum++] = i;
			for(int j = 2; j * i < maxn; j++){
				p[j * i] = true;
			}
		}
	}
}

int main(){
	int m, n, temp = 0;
	scanf("%d %d", &m, &n);
	Find_Prime();
	for(int i = m - 1; i < n - 1; i++){
		if(temp < 9){
			printf("%d", prime[i]);
			printf(" ");
			temp += 1;
		} else{
			printf("%d", prime[i]);
			printf("\n");
			temp = 0;
		}
	}
	printf("%d", prime[n - 1]);

	return 0;
}