#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char num[101];
	scanf("%s", num);

	int ans = 0;
	for(int i = 0; i < strlen(num); i++){
		ans += num[i] - '0';
	}
	char pinyin[11][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

	int cnt = 0;
	int temp[101];
	while(ans){
		temp[cnt++] = ans % 10;
		ans /= 10;
	}

	for(int i = cnt - 1; i >= 0; i--){
		if(i > 0) printf("%s ", pinyin[temp[i]]);
		else printf("%s", pinyin[temp[i]]);
	}

	return 0;
}