#include<iostream>
using namespace std;

int main(){
	int n, now = 0, temp, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		if(temp - now > 0){
			ans += 6 * (temp - now);
		} else if(temp - now < 0){
			ans += 4 * (now - temp);
		} else{
			ans += 5;
		}
		now = temp;
		ans += 5;
	}
	cout << ans;

	system("pause");
	return 0;
}