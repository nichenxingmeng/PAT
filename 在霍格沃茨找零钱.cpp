#include<iostream>
#include<string>
using namespace std;

int main(){
	string P, A, temp;
	cin >> P >> A;
	int p = 0, a = 0, begin = 0, g1 = 0, s1 = 0, k1 = 0, cnt = 0, g2 = 0, s2 = 0, k2 = 0;
	for(int i = 0; i < P.length(); i++){
		if(P[i] == '.'){
			if(cnt == 0){
				temp = P.substr(0, i);
				for(int i = 0; i < temp.length(); i++){
					g1 = g1 * 10 + (temp[i] - '0');
				}
				p += g1 * 17 * 29;
				begin = i + 1;
				cnt++;
				continue;
			}
			if(cnt == 1){
				temp = P.substr(begin, i - begin);
				for(int i = 0; i < temp.length(); i++){
					s1 = s1 * 10 + (temp[i] - '0');
				}
				p += s1 * 29;
				temp = P.substr(i + 1, P.length() - i - 1);
				for(int i = 0; i < temp.length(); i++){
					k1 = k1 * 10 + (temp[i] - '0');
				}
				p += k1;
				cnt++;
			}
		}
	}
	cnt = 0;
	begin = 0;
	for(int i = 0; i < A.length(); i++){
		if(A[i] == '.'){
			if(cnt == 0){
				temp = A.substr(0, i);
				for(int i = 0; i < temp.length(); i++){
					g2 = g2 * 10 + (temp[i] - '0');
				}
				a += g2 * 17 * 29;
				begin = i + 1;
				cnt++;
				continue;
			}
			if(cnt == 1){
				temp = A.substr(begin, i - begin);
				for(int i = 0; i < temp.length(); i++){
					s2 = s2 * 10 + (temp[i] - '0');
				}
				a += s2 * 29;
				temp = A.substr(i + 1, A.length() - i - 1);
				for(int i = 0; i < temp.length(); i++){
					k2 = k2 * 10 + (temp[i] - '0');
				}
				a += k2;
				cnt++;
			}
		}
	}
	int ans = a - p;
	if(ans > 0) printf("%d.%d.%d", ans / (17 * 29), (ans % (17 * 29)) / 29, ans % 29);
	else if(ans < 0){
		ans = p - a;
		printf("-");
		printf("%d.%d.%d", ans / (17 * 29), (ans % (17 * 29)) / 29, ans % 29);
	} else printf("0.0.0");

	system("pause");
	return 0;
}