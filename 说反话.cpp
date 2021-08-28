#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<string> ans; 

int main(){
	string s;
	getline(cin, s);
	s.push_back(' ');

	int begin = 0, cnt = 0;
	string temp, temp_;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ' '){
			if(begin == 0){
				temp_ = s.substr(begin, i - begin);
				begin = i + 1;
			} else{
				temp = s.substr(begin, i - begin);
				begin = i + 1;
				ans.push(temp);
			}
		}
	}

	while(!ans.empty()){
		cout << ans.top();
		printf(" ");
		ans.pop();
	}
	cout << temp_;

	system("pause");
	return 0;
}