#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool flag = false;
	if(s[0] == '-') printf("-");
	int cnt = 0;
	s.erase(s.begin() + 2);
	for(int i = 1; i < s.length(); i++){
		if(s[i] == 'E'){
			cnt = i;
			break;
		}
	}
	int temp = 0, e = 0;
	for(int i = 1; i < cnt; i++){
		temp = temp * 10 + s[i] - '0';
	}
	for(int i = cnt + 2; i < s.length(); i++){
		e = e * 10 + s[i] - '0';
	}
	string ans, ans_;

	if(s[cnt + 1] == '+'){
		if(cnt - 2 <= e){
			printf("%d", temp);
			for(int i = 0; i < e - cnt + 2; i++){
				printf("0");
			}
		} else{
			ans = s.substr(1, cnt - 1);
			int cnt_ = 0;
			for(int i = 0; i < ans.length(); i++){
				if(ans[i] == '0') cnt_++;
				else break;
			}

			if(cnt != 0){
				ans_ = ans.substr(cnt_, ans.length() - cnt_);
				ans_.insert(ans_.begin() + (1 + e - cnt_), '.');
				cout << ans_;
			} else{
				ans.insert(ans.begin() + 1 + e, '.');
				cout << ans;
			}
		}

	} else{
		if(e != 0){
			printf("0.");
			for(int i = 0; i < e - 1; i++){
				printf("0");
			}
			for(int i = 1; i < cnt; i++){
				printf("%c", s[i]);
			}
		}
		else{
			ans = s.substr(1, cnt - 1);
			ans.insert(ans.begin() + 1, '.');
			cout << ans;
		}
	}

	system("pause");
	return 0;
}