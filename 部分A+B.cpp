#include<iostream>
#include<string>
using namespace std;

int main(){
	string a, b;
	char numa, numb;
	cin >> a >> numa >> b >> numb;
	int Pa = 0, Pb = 0;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == numa){
			Pa = Pa * 10 + numa - '0';
		}
	}
	for(int i = 0; i < b.length(); i++){
		if(b[i] == numb){
			Pb = Pb * 10 + numb - '0';
		}
	}
	cout << Pa + Pb;

	system("pause");
	return 0;
}