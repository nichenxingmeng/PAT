#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin >> s;
	while(s.length() < 3){
		s.insert(0, "0");
	}
	int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';
	for(int i = 0; i < a; i++){
		printf("B");
	}
	for(int i = 0; i < b; i++){
		printf("S");
	}
	for(int i = 1; i < c + 1; i++){
		printf("%d", i);
	}

	system("pause");
	return 0;
}
