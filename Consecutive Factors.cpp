#include<iostream>
#include<cmath>
using namespace std;

typedef long long LL;

int main(){
	LL n;
	scanf("%lld", &n);
	if(n < 6){
		printf("1\n%lld", n);
		return 0;
	}
	LL i = 2, j = 2, ans = 0, st, ed;
	while(i * j <= n){
		LL temp = 1;
		for(LL k = i; k <= j; k++){
			temp *= k;
		}
		if(temp <= n){
			if(n % temp == 0){
				if(j - i + 1 > ans){
					ans = j - i + 1;
					st = i;
					ed = j;
				}
			}else{
                i++;
                j = i + ans - 1;
            }
			j++;
		}else{
			i++;
            j = i + ans - 1;
		}
	}
    if(ans == 0){
        printf("1\n%lld", n);
		return 0;
    }
	cout << ans << endl;
	cout << st;
	for(LL i = st + 1; i <= ed; i++){
		printf("*%lld", i);
	}

	return 0;
}