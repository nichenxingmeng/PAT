#include<iostream>
using namespace std;
const int maxn = 10010;
const int INF = 1000000000;
int num[maxn], dp[maxn];

int main(){
	int k, ed;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &num[i]);
		dp[i] = 0;
	}
	dp[0] = num[0];
	for(int i = 1; i < k; i++){
		dp[i] = max(num[i], dp[i - 1] + num[i]);
	}
	int max = -INF;
	for(int i = 0; i < k; i++){
		if(dp[i] > max){
			max = dp[i];
			ed = i;
		}
	}
	if(max >= 0){
		int temp = 0, st;
		for(int i = ed; i >= 0; i--){
			temp += num[i];
			if(temp == max){
				st = i;
				break;
			}
		}
		int panduan = 0;
		for(int i = st - 1; i >= 0; i--){
			panduan += num[i];
			if(panduan == 0){
				st = i;
			}
		}
		cout << max << " " << num[st] << " " << num[ed] << endl;
	} else{
		cout << "0 " << num[0] << " " << num[k - 1] << endl;
	}

	return 0;
}