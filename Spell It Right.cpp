#include<iostream>
#include<string>
#include<map>
using namespace std;

string n;
string ans[105];
map<int, string> mp;

int main(){
	mp[0] = "zero";
	mp[1] = "one";
	mp[2] = "two";
	mp[3] = "three";
	mp[4] = "four";
	mp[5] = "five";
	mp[6] = "six";
	mp[7] = "seven";
	mp[8] = "eight";
	mp[9] = "nine";
	cin >> n;
	int temp = 0;
	for(int i = 0; i < n.length(); i++){
		temp += n[i] - '0';
	}
    if(temp == 0){
        printf("zero");
        return 0;
    }
	int cnt = 0;
	while(temp != 0){
		ans[cnt] = mp[temp % 10];
		temp /= 10;
		cnt++;
	}
	for(int i = cnt - 1; i >= 0; i--){
		if(i != 0){
			cout << ans[i] << " ";
		} else{
			cout << ans[i];
		}
	}

	return 0;
}