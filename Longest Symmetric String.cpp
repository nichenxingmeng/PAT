#include<iostream>
#include<string>
using namespace std;

const int maxn = 1005;

string str;
int dp[maxn][maxn];

int main(){
	getline(cin, str);
	int len = str.length(), ans = 1;

	for(int i = 0; i < len; i++){
		dp[i][i] = 1;
		if(i < len - 1){
			if(str[i] == str[i + 1]){
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}

	for(int L = 3; L <= len; L++){
		for(int i = 0; i + L - 1 < len; i++){
			int j = i + L - 1;
			if(str[i] == str[j] && dp[i + 1][j - 1] == 1){
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	cout << ans;

	return 0;
}