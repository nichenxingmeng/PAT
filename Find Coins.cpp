#include<iostream>
using namespace std;

const int maxn = 1001;
int temp[maxn];

int main(){
	int n, m, num;
	scanf("%d%d", &n, &m);
	fill(temp, temp + maxn, 0);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		temp[num]++;
	}
	for(int i = 0; i < maxn; i++){
		if(temp[i] > 0){
			if(i != m - i){
                if(temp[m - i] > 0){
				    printf("%d %d", i, m - i);
				    return 0;
                }
			} else{
                if(temp[m - i] > 1)
                    {
				    printf("%d %d", i, m - i);
				    return 0;
                }
            }
		}
	}
	printf("No Solution");

	return 0;
}