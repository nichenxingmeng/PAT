#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool Prime(int n){
    if(n == 0 || n == 1) return false;
    if(n == 2 || n == 3) return true;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	string s;
	cin >> s;
	int temp = 0;
	bool flag = false;
	string ans;
	for(int i = 0; i < s.length() - k + 1; i++){
		for(int j = 0; j < k; j++){
			temp = temp * 10 + s[i + j] - '0';
		}
		if(Prime(temp)){
			ans = s.substr(i, k);
			cout << ans;
			flag = true;
			break;
		}
		temp = 0;
	}
	if(!flag) printf("404");

	return 0;
}