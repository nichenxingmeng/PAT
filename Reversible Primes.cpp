#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;

int main(){
	int n, d;
	scanf("%d", &n);
	while(n > 0){
		scanf("%d", &d);
        bool flag = false;
        if(n == 1 || n == 0){
            flag = true;
            printf("No\n");
        }
            
		for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                printf("No\n");
                flag = true;
                break;
            }
        }
        
        LL ans = 0;
        while(n > 0){
            ans *= 10;
            ans += n % d;
            n /= d;
        }
        
        if(!flag){
            LL n_reverse = 0;
            while(ans > 0){
                n_reverse *= 10;
                n_reverse += ans % 10;
                ans /= 10;
            }
            
            LL ans_ = 0;
                while(n_reverse > 0){
                ans_ *= d;
                ans_ += n_reverse % 10;
                n_reverse /= 10;
            }

            if(ans_ == 1 || ans_ == 0){
                flag = true;
                printf("No\n");
            }
            
            for(int i = 2; i <= sqrt(ans_); i++){
                if(ans_ % i == 0){
                    printf("No\n");
                    flag = true;
                    break;
                }
            }
            if(!flag) printf("Yes\n");
        }
		scanf("%d", &n);
	}

	return 0;
}