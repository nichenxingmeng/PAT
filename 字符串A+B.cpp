#include<iostream>
#include<string>
using namespace std;


bool s[500] = {false};

int main(){
	string a, b;
	getline(cin, a);
	getline(cin, b);
	char temp = 0;
	for(int i = 0; i < a.length(); i++){
		if(s[a[i] - temp] == false){
			printf("%c", a[i]);
			s[a[i] - temp] = true;
		}
	}
	for(int i = 0; i < b.length(); i++){
		if(s[b[i] - temp] == false){
			printf("%c", b[i]);
			s[b[i] - temp] = true;
		}
	}

	system("pause");
	return 0;
}