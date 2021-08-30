#include<iostream>
#include<string>
using namespace std;

string science(string A, int n){
	while(A.length() > 1 && A[0] == '0'){
		A.erase(A.begin());
	}
	if(A[0] == '.'){
		A.insert(0, "0");
		int cnt = 0;
		for(int i = 0; i < A.length(); i++){
			if(A[i] == '0' || A[i] == '.') cnt++;
			else break;
		}

		if(cnt == A.length()){
			string ANS = "0.";
			for(int i = 0; i < n; i++){
				ANS.insert(2 + i, "0");
			}
			ANS.insert(2 + n, "*10^0");
			return ANS;
		}

		int ans = cnt - 2;
		
		char ans___[5] = {0};
		bool flag = false;
		if(ans != 0){
			char ans_[5];
			int ans__ = ans, i = 0;
			while(ans__){
				ans_[i++] = '0' + ans__ % 10;
				ans__ /= 10;
			}
			ans_[i] = '\0';
			for(int j = strlen(ans_) - 1; j >= 0; j--){
				ans___[strlen(ans_) - 1 - j] = ans_[j];
			}
		} else{
			flag = true;
			 ans___[0] = '0';
			 ans___[1] = '\0';
		}

		string ANS = "0.";
		if(A.length() - cnt >= n){
			ANS.insert(2, A.substr(cnt, n));
		} else{
			ANS.insert(2, A.substr(cnt, A.length()));
			for(int i = 0; i < n - A.length() + cnt; i++){
				ANS.insert(i + A.length() - cnt + 2, "0");
			}
		}
		if(!flag){
			ANS.insert(n + 2, "*10^-");
			ANS.insert(n + 7, ans___);
		} else{
			ANS.insert(n + 2, "*10^");
			ANS.insert(n + 6, ans___);
		}
		return ANS;
	} else{
		if(A[0] == '0'){
			string ANS = "0.";
			for(int i = 0; i < n; i++){
				ANS.insert(2 + i, "0");
			}
			ANS.insert(2 + n, "*10^0");
			return ANS;
		}
		int temp, ans, cnt;
		temp = A.find('.');
		if(temp == -1){
			ans = A.length();
		} else{
			ans = temp;
		}

		char ans_[4], ans___[4] = {0};
		int ans__ = ans, i = 0;
		while(ans__){
			ans_[i++] = '0' + ans__ % 10;
			ans__ /= 10;
		}
		ans_[i] = '\0';
		for(int j = strlen(ans_) - 1; j >= 0; j--){
			ans___[strlen(ans_) - 1 - j] = ans_[j];
		}

		cnt = A.find('.');
		if(cnt != - 1){
			A.erase(A.begin() + cnt);
		}

		string ANS = "0.";
		if(A.length() >= n){
			ANS.insert(2, A.substr(0, n));
		} else{
			ANS.insert(2, A);
			for(int i = 0; i < n - A.length(); i++){
				ANS.insert(i + A.length() + 2, "0");
			}
		}
		ANS.insert(n + 2, "*10^");
		ANS.insert(n + 6, ans___);
		return ANS;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	string A, B;
	cin >> A >> B;
	A = science(A, n);
	B = science(B, n);
	if(A == B){
		printf("YES ");
		cout << A;
	} else{
		printf("NO ");
		cout << A;
		printf(" ");
		cout << B;
	}

	system("pause");
	return 0;
}