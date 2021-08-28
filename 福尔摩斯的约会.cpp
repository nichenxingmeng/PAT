#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

map<int, string> mp;

int main(){
	mp[1] = "MON";
	mp[2] = "TUE";
	mp[3] = "WED";
	mp[4] = "THU";
	mp[5] = "FRI";
	mp[6] = "SAT";
	mp[7] = "SUN";
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int cnt = 0;
	for(int i = 0; i < min(a.length(), b.length()); i++){
		if(a[i] == b[i]){
			if(cnt == 0){
				if(a[i] >= 'A' && a[i] <= 'G') {
					cout << mp[a[i] - 'A' + 1];
					printf(" ");
					cnt++;
				}
			} else{
				if(a[i] >= '0' && a[i] <= '9'){
					printf("0%d", a[i] - '0');
					break;
				} else if(a[i] >= 'A' && a[i] <= 'N'){
					printf("%d", a[i] - 'A' + 10);
					break;
				}
			}
		}
	}
	printf(":");
	for(int i = 0; i < min(c.length(), d.length()); i++){
		if(c[i] == d[i]){
			if(c[i] >= 'A' && c[i] <= 'Z'){
				printf("%02d", i);
				break;
			} else if(c[i] >= 'a' && c[i] <= 'z'){
				printf("%02d", i);
				break;
			}
		}
	}

	system("pause");
	return 0;
}

