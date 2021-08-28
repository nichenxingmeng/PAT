#include<iostream>
#include<map>
#include<string>
using namespace std;

map<int, int> mp;

int main(){
	mp[0] = 0;
	mp[1] = 0;
	mp[2] = 0;
	mp[3] = 0;
	mp[4] = 0;
	mp[5] = 0;
	mp[6] = 0;
	mp[7] = 0;
	mp[8] = 0;
	mp[9] = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		mp[s[i] - '0']++;
	}
	int cnt = 0;
	for(int i = 0; i < 10; i++){
		if(mp[i] != 0) cnt = i;
	}
	for(int i = 0; i < 10; i++){
		if(mp[i] != 0){
			if(i != cnt) printf("%d:%d\n", i, mp[i]);
			else printf("%d:%d", i, mp[i]);
		}
	}

	system("pause");
	return 0;
}