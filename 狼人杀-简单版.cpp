#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int m, temp, cnt, temp_, a;
	bool flag;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &temp);
		if(temp == 0) printf("0 0\n");
		else{
			cnt = 0;
			flag = false;
			temp_ = temp;
			while(temp_){
				temp_ /= 10;
				cnt++;
			}
			a = pow(10, cnt);
			for(int i = 1; i < 10; i++){
				if((i * temp * temp) % a == temp){
					printf("%d %d\n", i, i * temp * temp);
					flag = true;
					break;
				}
			}
			if(!flag) printf("No\n");
		}
	}

	system("pause");
	return 0;
}