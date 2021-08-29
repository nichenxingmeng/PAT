#include<iostream>

using namespace std;

int main(){
	int a, b;
	bool flag = false;
	while(cin >> a >> b){
		if(a && b){
			printf("%d %d", a * b, b - 1);
			flag = true;
			if(b != 1) printf(" ");
		}
	}
	if(!flag) printf("0 0");

	system("pause");
	return 0;
}